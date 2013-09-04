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

    void clientMessage(
        dp::Window &        _window
        , const XEvent &    _EVENT
    )
    {
        const auto &    ATOM = static_cast< Atom >( _EVENT.xclient.data.l[ 0 ] );

        if( ATOM == WM_DELETE_WINDOW ) {
            dp::callCloseEventHandler(
                _window
            );
        }
    }

    void checkSize(
        dp::Window &                _window
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , Size &                    _size
        , const XEvent &            _EVENT
    )
    {
        const auto &    NEW_WIDTH = _EVENT.xconfigure.width;
        const auto &    NEW_HEIGHT = _EVENT.xconfigure.height;

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
        dp::Window &        _window
        , Position &        _position
        , const XEvent &    _EVENT
    )
    {
        const auto &    NEW_X = _EVENT.xconfigure.x;
        const auto &    NEW_Y = _EVENT.xconfigure.y;

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
        , const XEvent &            _EVENT
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

    dp::Bool copyWhenChanged(
        Size &          _size
        , const Size &  _NEW_SIZE
    )
    {
        const auto  CHANGED =
            _NEW_SIZE.initialized &&
            (
                _size.initialized == false ||
                _size.width != _NEW_SIZE.width ||
                _size.height != _NEW_SIZE.height
            )
        ;

        if( CHANGED ) {
            _size = _NEW_SIZE;
        }

        return CHANGED;
    }

    void waitPaintThread(
        std::mutex &                _mutex
        , std::condition_variable & _cond
        , const Size &              _NEW_SIZE
        , Size &                    _size
        , dp::Bool &                _sizeChanged
        , const dp::Bool &          _ENDED
    )
    {
        std::unique_lock< std::mutex >  lock( _mutex );

        _cond.wait(
            lock
            , [
                &_NEW_SIZE
                , &_size
                , &_sizeChanged
                , &_ENDED
            ]
            {
                _sizeChanged = copyWhenChanged(
                    _size
                    , _NEW_SIZE
                );

                return _ENDED || _sizeChanged;
            }
        );
    }

    void paintThreadProcMainLoop(
        dp::Window &                _window
        , dp::WindowImpl &          _impl
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , const Size &              _NEW_SIZE
    )
    {
        Size        size;
        dp::Bool    sizeChanged;

        const auto &    ENDED = _impl.ended;

        while( 1 ) {
            waitPaintThread(
                _mutex
                , _cond
                , _NEW_SIZE
                , size
                , sizeChanged
                , ENDED
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

            //TODO 描画イベントハンドラ呼び出し
        }
    }

    void paintThreadProc(
        dp::Window &                _window
        , dp::WindowImpl &          _impl
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , const Size &              _NEW_SIZE
    )
    {
        //TODO 描画開始イベントハンドラ呼び出し

        paintThreadProcMainLoop(
            _window
            , _impl
            , _mutex
            , _cond
            , _NEW_SIZE
        );

        //TODO 描画終了イベントハンドラ呼び出し
    }

    void mainThreadProc(
        dp::Window &                _window
        , dp::WindowImpl &          _impl
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , Size &                    _size
    )
    {
        Position    position;

        const auto &    ENDED = _impl.ended;

        auto &  xDisplay = dp::getXDisplay();
        auto &  xWindow = _impl.xWindow;

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
                    , event
                );
                break;

            case ConfigureNotify:
                configureNotify(
                    _window
                    , _mutex
                    , _cond
                    , _size
                    , position
                    , event
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
        , dp::WindowImpl &  _impl
    )
    {
        std::mutex              mutex;
        std::condition_variable cond;

        Size    size;

        std::thread paintThread(
            [
                &_window
                , &_impl
                , &mutex
                , &cond
                , &size
            ]
            {
                paintThreadProc(
                    _window
                    , _impl
                    , mutex
                    , cond
                    , size
                );
            }
        );
        dp::ThreadJoiner    threadJoiner( &paintThread );

        mainThreadProc(
            _window
            , _impl
            , mutex
            , cond
            , size
        );

        notifyPaintThread(
            mutex
            , cond
        );
    }

    dp::WindowImpl * newWindowImpl(
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
            return nullptr;
        }

        dp::WindowImplUnique    implUnique( new( std::nothrow )dp::WindowImpl );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  impl = *implUnique;

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
            return nullptr;
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
                    , &impl
                ]
                {
                    threadProc(
                        _window
                        , impl
                    );
                }
            )
        );
        impl.threadJoiner.reset( &( impl.thread ) );

        return implUnique.release();
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

    WindowImpl * newWindowImpl(
        Window &        _window
        , const Utf32 & _TITLE
        , ULong         _width
        , ULong         _height
        , WindowFlags   _flags
    )
    {
        WindowImplUnique    implUnique(
            ::newWindowImpl(
                _window
                , _TITLE
                , _width
                , _height
                , _flags
            )
        );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  xDisplay = getXDisplay();

        XFlush( &xDisplay );

        return implUnique.release();
    }

    WindowImpl * newWindowImpl(
        Window &        _window
        , const Utf32 & _TITLE
        , Long          _x
        , Long          _y
        , ULong         _width
        , ULong         _height
        , WindowFlags   _flags
    )
    {
        WindowImplUnique    implUnique(
            ::newWindowImpl(
                _window
                , _TITLE
                , _width
                , _height
                , _flags
            )
        );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  impl = *implUnique;

        auto &  xWindow = impl.xWindow;

        auto &  xDisplay = getXDisplay();

        XMoveWindow(
            &xDisplay
            , xWindow
            , _x
            , _y
        );

        XFlush( &xDisplay );

        return implUnique.release();
    }

    void free(
        WindowImpl &    _impl
    )
    {
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
}
