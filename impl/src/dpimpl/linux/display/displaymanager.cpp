#include "dpimpl/linux/display/displaymanager.h"
#include "dpimpl/common/display/displaymanager.h"
#include "dp/display/displaymanager.h"
#include "dpimpl/linux/display/displaykey.h"
#include "dp/display/displaykey.h"
#include "dp/common/primitives.h"
#include "dp/common/thread.h"
#include "dpimpl/linux/common/thread.h"

#include "dpimpl/linux/common/xlib.h"
#include "dpimpl/linux/display/xrandr.h"
#include <new>
#include <memory>
#include <vector>

namespace {
    ::Display * x11DisplayNew(
    )
    {
        return XOpenDisplay( nullptr );
    }

    struct ScreenResourcesDelete
    {
        void operator()(
            XRRScreenResources *    _screenResources
        )
        {
            XRRFreeScreenResources( _screenResources );
        }
    };

    typedef std::unique_ptr<
        XRRScreenResources
        , ScreenResourcesDelete
    > ScreenResourcesUnique;

    XRRScreenResources * screenResourcesNew(
        ::Display &     _display
        , ::Window &    _window
    )
    {
        return XRRGetScreenResources(
            &_display
            , _window
        );
    }

    struct CrtcInfoDelete
    {
        void operator()(
            XRRCrtcInfo *   _info
        )
        {
            XRRFreeCrtcInfo( _info );
        }
    };

    typedef std::unique_ptr<
        XRRCrtcInfo
        , CrtcInfoDelete
    > CrtcInfoUnique;

    XRRCrtcInfo * crtcInfoNew(
        ::Display &             _display
        , XRRScreenResources &  _screenResources
        , const RRCrtc &        _CRTC
    )
    {
        return XRRGetCrtcInfo(
            &_display
            , &_screenResources
            , _CRTC
        );
    }

    void callConnectEventHandler(
        dp::DisplayManager &    _manager
        , const RRCrtc &        _CRTC
        , dp::Bool              _connected
    )
    {
        dp::DisplayKeyUnique    keyUnique(
            dp::displayKeyNew(
                _CRTC
            )
        );
        if( keyUnique.get() == nullptr ) {
            return;
        }

        dp::displayManagerCallConnectEventHandler(
            _manager
            , std::move( keyUnique )
            , _connected
        );
    }

    dp::Bool isConnectedDisplay(
        ::Display &             _display
        , XRRScreenResources &  _screenResources
        , const RRCrtc &        _CRTC
    )
    {
        CrtcInfoUnique  crtcInfoUnique(
            crtcInfoNew(
                _display
                , _screenResources
                , _CRTC
            )
        );
        if( crtcInfoUnique.get() == nullptr ) {
            return false;
        }

        auto &  crtcInfo = *crtcInfoUnique;

        if( crtcInfo.mode == None ) {
            return false;
        }

        return true;
    }

    void initDisplays(
        dp::DisplayManager &    _manager
        , ::Display &           _x11Display
        , ::Window &            _x11Window
    )
    {
        ScreenResourcesUnique   screenResourcesUnique(
            screenResourcesNew(
                _x11Display
                , _x11Window
            )
        );
        if( screenResourcesUnique.get() == nullptr ) {
            return;
        }

        auto &  screenResources = *screenResourcesUnique;

        auto    crtcsCount = screenResources.ncrtc;

        for( decltype( crtcsCount ) i = 0 ; i < crtcsCount ; i++ ) {
            const auto &    CRTC = screenResources.crtcs[ i ];

            if( isConnectedDisplay(
                _x11Display
                , screenResources
                , CRTC
            ) == false ) {
                continue;
            }

            callConnectEventHandler(
                _manager
                , CRTC
                , true
            );
        }
    }

    void eventProcCrtcChange(
        dp::DisplayManager &        _manager
        , const XRRNotifyEvent &    _NOTIFY_EVENT
    )
    {
        const auto &    EVENT = reinterpret_cast< const XRRCrtcChangeNotifyEvent & >( _NOTIFY_EVENT );

        const auto  CONNECTED = EVENT.mode != None;

        callConnectEventHandler(
            _manager
            , EVENT.crtc
            , CONNECTED
        );
    }

    void eventProc(
        dp::DisplayManager &        _manager
        , const XRRNotifyEvent &    _NOTIFY_EVENT
    )
    {
        switch( _NOTIFY_EVENT.subtype ) {
        case RRNotify_CrtcChange:
            eventProcCrtcChange(
                _manager
                , _NOTIFY_EVENT
            );
            break;

        default:
            // ここに到達することはない
            break;
        }
    }

    void monitorDisplays(
        dp::DisplayManager &        _manager
        , dp::DisplayManagerImpl &  _impl
        , ::Display &               _x11Display
    )
    {
        const auto &    ENDED = _impl.ended;

        dp::Int eventBase;
        dp::Int errorBase;
        if( XRRQueryExtension(
            &_x11Display
            , &eventBase
            , &errorBase
        ) != True ) {
            return;
        }

        XEvent          event;
        const auto &    NOTIFY_EVENT = reinterpret_cast< const XRRNotifyEvent & >( event );

        while( 1 ) {
            XNextEvent(
                &_x11Display
                , &event
            );

            if( ENDED ) {
                break;
            }

            if( event.type - eventBase != RRNotify ) {
                continue;
            }

            eventProc(
                _manager
                , NOTIFY_EVENT
            );
        }
    }

    void threadProc(
        dp::DisplayManager &        _manager
        , dp::DisplayManagerImpl &  _impl
    )
    {
        auto &  x11Display = *( _impl.x11DisplayUnique );

        auto &  x11Window = _impl.x11Window;

        XRRSelectInput(
            &x11Display
            , x11Window
            , RRCrtcChangeNotifyMask
        );

        initDisplays(
            _manager
            , x11Display
            , x11Window
        );

        monitorDisplays(
            _manager
            , _impl
            , x11Display
        );
    }

    void setEnd(
        dp::DisplayManagerImpl &    _impl
    )
    {
        _impl.ended = true;

        auto &  x11Display = *( _impl.x11DisplayUnique );
        auto &  x11Window = _impl.x11Window;

        XEvent  event;
        event.type = ClientMessage;
        event.xclient.display = &x11Display;
        event.xclient.window = x11Window;
        event.xclient.format = 8;

        XSendEvent(
            &x11Display
            , x11Window
            , False
            , StructureNotifyMask
            , &event
        );
        XFlush( &x11Display );
    }
}

namespace dp {
    DisplayManagerImpl * displayManagerImplNew(
        DisplayManager &    _manager
    )
    {
        DisplayManagerImplUnique    implUnique( new( std::nothrow )DisplayManagerImpl );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  impl = *implUnique;

        auto &  x11DisplayUnique = impl.x11DisplayUnique;
        x11DisplayUnique.reset( x11DisplayNew() );
        if( x11DisplayUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  x11Display = *x11DisplayUnique;

        auto &  x11Window = impl.x11Window;

        x11Window = DefaultRootWindow( &x11Display );

        // スレッド終了イベント用にStructureNotifyMaskを許可
        XSelectInput(
            &x11Display
            , x11Window
            , StructureNotifyMask
        );

        impl.ended = false;

        impl.thread = std::move(
            std::thread(
                [
                    &_manager
                    , &impl
                ]
                {
                    threadProc(
                        _manager
                        , impl
                    );
                }
            )
        );
        impl.threadJoiner.reset( &( impl.thread ) );

        return implUnique.release();
    }

    void displayManagerImplDelete(
        DisplayManagerImpl &    _impl
    )
    {
        setEnd(
            _impl
        );

        delete &_impl;
    }
}
