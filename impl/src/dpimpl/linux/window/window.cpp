#include "dpimpl/linux/window/window.h"
#include "dpimpl/common/window/window.h"
#include "dp/window/window.h"
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

namespace {
    Atom    WM_DELETE_WINDOW;

    Atom    _NET_WM_STATE;
    Atom    _NET_WM_STATE_ABOVE;

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

    dp::Bool isWindowEvent(
        const XEvent *      _EVENT
        , const XPointer    _ARG
    )
    {
        return _EVENT->xany.window == *reinterpret_cast< const ::Window * >( _ARG );
    }

    dp::Bool isPaintThreadEvent(
        const XEvent *  _EVENT
    )
    {
        return _EVENT->type == Expose;
    }

    Bool isMainThreadEvent(
        ::Display *
        , XEvent *  _event
        , XPointer  _arg
    )
    {
        return isWindowEvent(
            _event
            , _arg
        ) && ( isPaintThreadEvent( _event ) == false );
    }

    void mainThreadProc(
        dp::Window &        _window
        , dp::WindowImpl &  _impl
    )
    {
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
                {
                    const auto &    ATOM = static_cast< Atom >( event.xclient.data.l[ 0 ] );

                    if( ATOM == WM_DELETE_WINDOW ) {
                        dp::callClosingEventHandler(
                            _window
                        );
                    }
                }
                break;

            //TODO

            default:
                // ここに到達することはない
                break;
            }
        }
    }

    void threadProc(
        dp::Window &        _window
        , dp::WindowImpl &  _impl
    )
    {
        //TODO ペイントスレッドの起動

        mainThreadProc(
            _window
            , _impl
        );
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
        XFlush( xDisplay );
    }

    void sendEventToMainThread(
        XEvent &    _event
    )
    {
        _event.type = ClientMessage;
        _event.xclient.format = 8;

        sendEvent(
            _event
            , NoEventMask
        );
    }

    void sendEventToPaintThread(
        XEvent &    _event
    )
    {
        _event.type = Expose;

        sendEvent(
            _event
            , ExposureMask
        );
    }

    void sendEndEvent(
        dp::WindowImpl &    _impl
    )
    {
        auto &  xDisplay = dp::getXDisplay();

        XEvent  event;
        event.xany.display = &xDisplay;
        event.xany.window = _impl.xWindow;

        sendEventToMainThread(
            event
        );
        sendEventToPaintThread(
            event
        );
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
        String  titleString;
        if( toString(
            titleString
            , _TITLE
        ) == false ) {
            return nullptr;
        }

        WindowImplUnique    implUnique( new( std::nothrow )WindowImpl );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  impl = *implUnique;

        impl.ended = false;

        auto &  xWindow = impl.xWindow;

        auto &  xDisplay = getXDisplay();
        auto &  xRootWindow = getXRootWindow();

        XSetWindowAttributes    attributes;

        attributes.event_mask =
            ExposureMask
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

        if( ( _flags & WindowFlags::UNRESIZABLE ) != 0 ) {
            unresizable(
                xDisplay
                , xWindow
                , _width
                , _height
            );
        }

        if( ( _flags & WindowFlags::ALWAYS_ON_TOP ) != 0 ) {
            alwaysOnTop(
                xDisplay
                , xWindow
            );
        }

        XStoreName(
            &xDisplay
            , xWindow
            , titleString.c_str()
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
            newWindowImpl(
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
}
