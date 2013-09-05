#include "dpimpl/util/export.h"
#include "dp/window/window.h"

#include "dpimpl/linux/window/window.h"
#include "dpimpl/common/window/window.h"
#include "dp/window/windowflags.h"
#include "dpimpl/linux/common/xlib.h"
#include "dp/common/stringconverter.h"
#include "dp/common/primitives.h"

#include "dpimpl/linux/window/xutil.h"
#include <X11/Xatom.h>
#include <new>
#include <thread>
#include <utility>
#include <errno.h>
#include <mutex>
#include <condition_variable>

namespace {
    Atom    WM_DELETE_WINDOW;

    Atom    _NET_WM_STATE;
    Atom    _NET_WM_STATE_ABOVE;

    struct Position
    {
        dp::Bool    initialized;
        dp::Long    x;
        dp::Long    y;

        Position(
        )
            : initialized( false )
        {
        }
    };

    struct Size
    {
        dp::Bool    initialized;
        dp::ULong   width;
        dp::ULong   height;

        Size(
        )
            : initialized( false )
        {
        }
    };

    struct Rect
    {
        dp::ULong   x;
        dp::ULong   y;
        dp::ULong   width;
        dp::ULong   height;

        Rect(
        )
            : width( 0 )
            , height( 0 )
        {
        }
    };

    void unresizable(
        ::Display &         _xDisplay
        , const ::Window &  _X_WINDOW
        , const dp::ULong & _WIDTH
        , const dp::ULong & _HEIGHT
    )
    {
        XSizeHints  sizeHints;

        sizeHints.min_width = sizeHints.max_width = _WIDTH;
        sizeHints.min_height = sizeHints.max_height = _HEIGHT;

        sizeHints.flags = PMaxSize | PMinSize;

        XSetWMNormalHints(
            &_xDisplay
            , _X_WINDOW
            , &sizeHints
        );
    }

    void alwaysOnTop(
        ::Display &         _xDisplay
        , const ::Window &  _X_WINDOW
    )
    {
        XChangeProperty(
            &_xDisplay
            , _X_WINDOW
            , _NET_WM_STATE
            , XA_ATOM
            , 32
            , PropModeReplace
            , reinterpret_cast< dp::UByte * >( &_NET_WM_STATE_ABOVE )
            , 1
        );
    }

    void setTitle(
        ::Display &             _xDisplay
        , const ::Window &      _X_WINDOW
        , const dp::String &    _TITLE_STRING
    )
    {
        XStoreName(
            &_xDisplay
            , _X_WINDOW
            , _TITLE_STRING.c_str()
        );
    }

    ::Bool isMainThreadEvent(
        ::Display *
        , XEvent *  _event
        , XPointer  _arg
    )
    {
        const auto &    WINDOW = *reinterpret_cast< const ::Window * >( _arg );

        return _event->xany.window == WINDOW;
    }

    dp::Bool copyWhenChanged(
        Size &          _size
        , const Size &  _SIZE_FROM_MAIN_THREAD
    )
    {
        const auto  CHANGED =
            _SIZE_FROM_MAIN_THREAD.initialized &&
            (
                _size.initialized == false ||
                _size.width != _SIZE_FROM_MAIN_THREAD.width ||
                _size.height != _SIZE_FROM_MAIN_THREAD.height
            )
        ;

        if( CHANGED ) {
            _size = _SIZE_FROM_MAIN_THREAD;
        }

        return CHANGED;
    }

    void copyAndClear(
        Rect &      _invalidateRect
        , Rect &    _invalidateRectFromMainThread
    )
    {
        _invalidateRect = _invalidateRectFromMainThread;

        // 幅を0にして無効領域を初期化
        _invalidateRectFromMainThread.width = 0;
    }

    void waitPaintThread(
        std::mutex &                _mutex
        , std::condition_variable & _cond
        , const Size &              _SIZE_FROM_MAIN_THREAD
        , Rect &                    _invalidateRectFromMainThread
        , const dp::Bool &          _ENDED
        , Size &                    _size
        , dp::Bool &                _sizeChanged
        , Rect &                    _invalidateRect
        , dp::Bool &                _exposed
    )
    {
        std::unique_lock< std::mutex >  lock( _mutex );

        _cond.wait(
            lock
            , [
                &_SIZE_FROM_MAIN_THREAD
                , &_invalidateRectFromMainThread
                , &_ENDED
                , &_size
                , &_sizeChanged
                , &_invalidateRect
                , &_exposed
            ]
            {
                _sizeChanged = copyWhenChanged(
                    _size
                    , _SIZE_FROM_MAIN_THREAD
                );

                copyAndClear(
                    _invalidateRect
                    , _invalidateRectFromMainThread
                );

                _exposed = _invalidateRect.width > 0 && _invalidateRect.height > 0;

                return _ENDED || _sizeChanged || _exposed;
            }
        );
    }

    void paintThreadProcMainLoop(
        dp::Window &                _window
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , const Size &              _SIZE_FROM_MAIN_THREAD
        , Rect &                    _invalidateRectFromMainThread
    )
    {
        auto &  impl = *( _window.implUnique );

        const auto &    ENDED = impl.ended;

        Size        size;
        dp::Bool    sizeChanged;

        Rect        invalidateRect;
        dp::Bool    exposed;

        while( 1 ) {
            waitPaintThread(
                _mutex
                , _cond
                , _SIZE_FROM_MAIN_THREAD
                , _invalidateRectFromMainThread
                , ENDED
                , size
                , sizeChanged
                , invalidateRect
                , exposed
            );

            if( ENDED ) {
                break;
            }

            if( sizeChanged ) {
                dp::callSizeEventHandler(
                    _window
                    , size.width
                    , size.height
                );
            }

            if( exposed ) {
                dp::callPaintEventHandler(
                    _window
                    , invalidateRect.x
                    , invalidateRect.y
                    , invalidateRect.width
                    , invalidateRect.height
                );
            }
        }
    }

    void paintThreadProc(
        dp::Window &                _window
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , const Size &              _SIZE_FROM_MAIN_THREAD
        , Rect &                    _invalidateRectFromMainThread
    )
    {
        dp::callBeginPaintEventHandler(
            _window
        );

        paintThreadProcMainLoop(
            _window
            , _mutex
            , _cond
            , _SIZE_FROM_MAIN_THREAD
            , _invalidateRectFromMainThread
        );

        dp::callEndPaintEventHandler(
            _window
        );
    }

    void clientMessage(
        dp::Window &                    _window
        , const XClientMessageEvent &   _EVENT
    )
    {
        const auto &    ATOM = static_cast< Atom >( _EVENT.data.l[ 0 ] );

        if( ATOM == WM_DELETE_WINDOW ) {
            dp::callCloseEventHandler(
                _window
            );
        }
    }

    void updateRange(
        dp::ULong &         _from
        , dp::ULong &       _volume
        , const dp::Int &   _NEW_FROM
        , const dp::Int &   _NEW_VOLUME
    )
    {
        const auto      OLD_FROM = _from;
        const dp::ULong OLD_VOLUME = _volume;

        const auto      OLD_TO = OLD_FROM + OLD_VOLUME;
        const dp::ULong NEW_TO = _NEW_FROM + _NEW_VOLUME;

        const auto &    TO = OLD_TO > NEW_TO ? OLD_TO : NEW_TO;

        if( OLD_FROM > _NEW_FROM ) {
            _from = _NEW_FROM;
        }

        _volume = TO - _from;
    }

    void expose(
        dp::Window &                _window
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , Rect &                    _invalidateRect
        , const XExposeEvent &      _EVENT
    )
    {
        std::unique_lock< std::mutex >  lock( _mutex );

        if( _invalidateRect.width <= 0 || _invalidateRect.height <= 0 ) {
            _invalidateRect.x = _EVENT.x;
            _invalidateRect.y = _EVENT.y;
            _invalidateRect.width = _EVENT.width;
            _invalidateRect.height = _EVENT.height;
        } else {
            updateRange(
                _invalidateRect.x
                , _invalidateRect.width
                , _EVENT.x
                , _EVENT.width
            );
            updateRange(
                _invalidateRect.y
                , _invalidateRect.height
                , _EVENT.y
                , _EVENT.height
            );
        }

        _cond.notify_one();
    }

    void checkSize(
        dp::Window &                _window
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , Size &                    _size
        , const XConfigureEvent &   _EVENT
    )
    {
        const auto &    NEW_WIDTH = _EVENT.width;
        const auto &    NEW_HEIGHT = _EVENT.height;

        if(
            _size.initialized == false ||
            _size.width != NEW_WIDTH ||
            _size.height != NEW_HEIGHT
        ) {
            std::unique_lock< std::mutex >  lock( _mutex );

            _size.initialized = true;
            _size.width = NEW_WIDTH;
            _size.height = NEW_HEIGHT;

            _cond.notify_one();
        }
    }

    void checkPosition(
        dp::Window &                _window
        , Position &                _position
        , const XConfigureEvent &   _EVENT
    )
    {
        const auto &    NEW_X = _EVENT.x;
        const auto &    NEW_Y = _EVENT.y;

        if(
            _position.initialized == false ||
            _position.x != NEW_X ||
            _position.y != NEW_Y
        ) {
            _position.initialized = true;
            _position.x = NEW_X;
            _position.y = NEW_Y;

            dp::callPositionEventHandler(
                _window
                , _position.x
                , _position.y
            );
        }
    }

    void configureNotify(
        dp::Window &                _window
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , Size &                    _size
        , Position &                _position
        , const XConfigureEvent &   _EVENT
    )
    {
        checkSize(
            _window
            , _mutex
            , _cond
            , _size
            , _EVENT
        );
        checkPosition(
            _window
            , _position
            , _EVENT
        );
    }

    void mainThreadProc(
        dp::Window &                _window
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , Size &                    _size
        , Rect &                    _invalidateRect
    )
    {
        Position    position;

        auto &  impl = *( _window.implUnique );

        const auto &    ENDED = impl.ended;

        auto &  xDisplay = dp::getXDisplay();
        auto &  xWindow = impl.xWindow;

        XEvent  event;
        while( 1 ) {
            XIfEvent(
                &xDisplay
                , &event
                , isMainThreadEvent
                , reinterpret_cast< XPointer >( &xWindow )
            );

            if( ENDED ) {
                break;
            }

            switch( event.type ) {
            case ClientMessage:
                clientMessage(
                    _window
                    , event.xclient
                );
                break;

            case Expose:
                expose(
                    _window
                    , _mutex
                    , _cond
                    , _invalidateRect
                    , event.xexpose
                );
                break;

            case ConfigureNotify:
                configureNotify(
                    _window
                    , _mutex
                    , _cond
                    , _size
                    , position
                    , event.xconfigure
                );
                break;

            //TODO

            default:
                // ここに到達することはない
                break;
            }
        }
    }

    void notifyPaintThread(
        std::mutex &                _mutex
        , std::condition_variable & _cond
    )
    {
        std::unique_lock< std::mutex >  lock( _mutex );

        _cond.notify_one();
    }

    void threadProc(
        dp::Window &        _window
    )
    {
        std::mutex              mutex;
        std::condition_variable cond;

        Size    size;
        Rect    invalidateRect;

        std::thread paintThread(
            [
                &_window
                , &mutex
                , &cond
                , &size
                , &invalidateRect
            ]
            {
                paintThreadProc(
                    _window
                    , mutex
                    , cond
                    , size
                    , invalidateRect
                );
            }
        );
        dp::ThreadJoiner    threadJoiner( &paintThread );

        mainThreadProc(
            _window
            , mutex
            , cond
            , size
            , invalidateRect
        );

        notifyPaintThread(
            mutex
            , cond
        );
    }

    Bool initializeWindowImpl(
        dp::Window &        _window
        , const dp::Utf32 & _TITLE
        , dp::ULong         _width
        , dp::ULong         _height
        , dp::WindowFlags   _flags
    )
    {
        dp::String  titleString;
        if( dp::toString(
            titleString
            , _TITLE
        ) == false ) {
            return false;
        }

        auto &  impl = *( _window.implUnique );

        impl.ended = false;

        auto &  xWindow = impl.xWindow;

        auto &  xDisplay = dp::getXDisplay();
        auto &  xRootWindow = dp::getXRootWindow();

        XSetWindowAttributes    attributes;

        attributes.event_mask =
            ExposureMask |
            StructureNotifyMask
        ;

        errno = 0;
        xWindow = XCreateWindow(
            &xDisplay
            , xRootWindow
            , 0
            , 0
            , _width
            , _height
            , 0
            , CopyFromParent
            , InputOutput
            , DefaultVisual(
                &xDisplay
                , DefaultScreen( &xDisplay )
            )
            , CWEventMask
            , &attributes
        );
        if( errno != 0 ) {
            return false;
        }

        impl.xWindowDestroyer.reset( &xWindow );

        XSetWMProtocols(
            &xDisplay
            , xWindow
            , &WM_DELETE_WINDOW
            , 1
        );

        if( ( _flags & dp::WindowFlags::UNRESIZABLE ) != 0 ) {
            unresizable(
                xDisplay
                , xWindow
                , _width
                , _height
            );
        }

        if( ( _flags & dp::WindowFlags::ALWAYS_ON_TOP ) != 0 ) {
            alwaysOnTop(
                xDisplay
                , xWindow
            );
        }

        setTitle(
            xDisplay
            , xWindow
            , titleString
        );

        XMapWindow(
            &xDisplay
            , xWindow
        );

        impl.thread = std::move(
            std::thread(
                [
                    &_window
                ]
                {
                    threadProc(
                        _window
                    );
                }
            )
        );
        impl.threadJoiner.reset( &( impl.thread ) );
        //TODO スレッドを終了させるためのユニークポインタも用意するべき

        return true;
    }

    void sendEvent(
        XEvent &    _event
        , dp::Int   _eventMask
    )
    {
        auto &  xDisplay = _event.xany.display;
        auto &  xWindow = _event.xany.window;

        XSendEvent(
            xDisplay
            , xWindow
            , False
            , _eventMask
            , &_event
        );
    }

    void sendEndEvent(
        dp::WindowImpl &    _impl
    )
    {
        auto &  xDisplay = dp::getXDisplay();

        XEvent  event;
        event.xclient.display = &xDisplay;
        event.xclient.window = _impl.xWindow;
        event.xclient.type = ClientMessage;
        event.xclient.format = 8;

        sendEvent(
            event
            , NoEventMask
        );

        XFlush( &xDisplay );
    }

    void setEnd(
        dp::WindowImpl &    _impl
    )
    {
        _impl.ended = true;

        sendEndEvent(
            _impl
        );
    }
}

namespace dp {
    void initializeWindow(
    )
    {
        auto &  xDisplay = getXDisplay();

        WM_DELETE_WINDOW = XInternAtom(
            &xDisplay
            , "WM_DELETE_WINDOW"
            , True
        );

        _NET_WM_STATE_ABOVE = XInternAtom(
            &xDisplay
            , "_NET_WM_STATE_ABOVE"
            , True
        );

        _NET_WM_STATE= XInternAtom(
            &xDisplay
            , "_NET_WM_STATE"
            , True
        );
    }

    Bool initializeWindowImpl(
        Window &        _window
        , const Utf32 & _TITLE
        , ULong         _width
        , ULong         _height
        , WindowFlags   _flags
    )
    {
        if( ::initializeWindowImpl(
            _window
            , _TITLE
            , _width
            , _height
            , _flags
        ) == false ) {
            return false;
        }

        auto &  xDisplay = getXDisplay();

        XFlush( &xDisplay );

        return true;
    }

    Bool initializeWindowImpl(
        Window &        _window
        , const Utf32 & _TITLE
        , Long          _x
        , Long          _y
        , ULong         _width
        , ULong         _height
        , WindowFlags   _flags
    )
    {
        if( ::initializeWindowImpl(
            _window
            , _TITLE
            , _width
            , _height
            , _flags
        ) == false ) {
            return false;
        }

        auto &  xWindow = _window.implUnique->xWindow;

        auto &  xDisplay = getXDisplay();

        XMoveWindow(
            &xDisplay
            , xWindow
            , _x
            , _y
        );

        XFlush( &xDisplay );

        return true;
    }

    void free(
        WindowImpl &    _impl
    )
    {
        //TODO WindowImplのメンバのdeleterで処理するべき
        setEnd(
            _impl
        );

        delete &_impl;
    }

    void close(
        Window &    _window
    )
    {
        auto &  xDisplay = dp::getXDisplay();
        auto &  xWindow = _window.implUnique->xWindow;

        XEvent  event;
        event.xclient.display = &xDisplay;
        event.xclient.window = xWindow;
        event.xclient.type = ClientMessage;
        event.xclient.format = 32;
        event.xclient.data.l[ 0 ] = WM_DELETE_WINDOW;

        sendEvent(
            event
            , NoEventMask
        );

        XFlush( &xDisplay );
    }

    Bool setTitle(
        Window &        _window
        , const Utf32 & _TITLE
    )
    {
        String  titleString;
        if( toString(
            titleString
            , _TITLE
        ) == false ) {
            return false;
        }

        auto &  xDisplay = getXDisplay();
        auto &  xWindow = _window.implUnique->xWindow;

        ::setTitle(
            xDisplay
            , xWindow
            , titleString
        );

        XFlush( &xDisplay );

        return true;
    }

    void setPosition(
        Window &    _window
        , Long      _x
        , Long      _y
    )
    {
        auto &  xDisplay = getXDisplay();
        auto &  xWindow = _window.implUnique->xWindow;

        XMoveWindow(
            &xDisplay
            , xWindow
            , _x
            , _y
        );
        XFlush( &xDisplay );
    }

    void setSize(
        Window &    _window
        , ULong     _width
        , ULong     _height
    )
    {
        auto &  xDisplay = getXDisplay();
        auto &  xWindow = _window.implUnique->xWindow;

        XResizeWindow(
            &xDisplay
            , xWindow
            , _width
            , _height
        );
        XFlush( &xDisplay );
    }

    void repaint(
        Window &    _window
        , ULong     _x
        , ULong     _y
        , ULong     _width
        , ULong     _height
    )
    {
        auto &  xDisplay = getXDisplay();
        auto &  xWindow = _window.implUnique->xWindow;

        XEvent  event;

        auto &  exposeEvent = event.xexpose;

        exposeEvent.type = Expose;
        exposeEvent.display = &xDisplay;
        exposeEvent.window = xWindow;
        exposeEvent.x = _x;
        exposeEvent.y = _y;
        exposeEvent.width = _width;
        exposeEvent.height = _height;
        exposeEvent.count = 0;

        sendEvent(
            event
            , ExposureMask
        );

        XFlush( &xDisplay );
    }
}
