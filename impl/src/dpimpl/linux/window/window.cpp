#include "dpimpl/linux/window/window.h"
#include "dpimpl/common/window/window.h"
#include "dp/window/window.h"
#include "dp/window/windowflags.h"
#include "dpimpl/linux/common/xlib.h"
#include "dp/common/stringconverter.h"
#include "dp/common/primitives.h"

#include <new>
#include <thread>
#include <utility>
#include <errno.h>

namespace {
    Atom    WM_DELETE_WINDOW;

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
            , 0//X
            , 0//Y
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
