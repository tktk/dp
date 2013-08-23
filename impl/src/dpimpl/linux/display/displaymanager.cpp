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
#include <vector>

namespace {
    void callConnectEventHandler(
        dp::DisplayManager &    _manager
        , const RRCrtc &        _CRTC
        , dp::Bool              _connected
    )
    {
        dp::DisplayKeyUnique    keyUnique(
            dp::newDisplayKey(
                _CRTC
            )
        );
        if( keyUnique.get() == nullptr ) {
            return;
        }

        dp::callConnectEventHandler(
            _manager
            , std::move( keyUnique )
            , _connected
        );
    }

    dp::Bool isConnectedDisplay(
        ::Display &             _xDisplay
        , XRRScreenResources &  _screenResources
        , const RRCrtc &        _CRTC
    )
    {
        dp::CrtcInfoUnique  crtcInfoUnique(
            dp::crtcInfoNew(
                _xDisplay
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
        , ::Display &           _xDisplay
        , ::Window &            _xWindow
    )
    {
        dp::ScreenResourcesUnique   screenResourcesUnique(
            dp::screenResourcesNew(
                _xDisplay
                , _xWindow
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
                _xDisplay
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
        , ::Display &               _xDisplay
    )
    {
        const auto &    ENDED = _impl.ended;

        dp::Int eventBase;
        dp::Int errorBase;
        if( XRRQueryExtension(
            &_xDisplay
            , &eventBase
            , &errorBase
        ) != True ) {
            return;
        }

        XEvent          event;
        const auto &    NOTIFY_EVENT = reinterpret_cast< const XRRNotifyEvent & >( event );

        while( 1 ) {
            XNextEvent(
                &_xDisplay
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
        auto &  xDisplay = *( _impl.xDisplayUnique );

        auto &  xWindow = _impl.xWindow;

        XRRSelectInput(
            &xDisplay
            , xWindow
            , RRCrtcChangeNotifyMask
        );

        initDisplays(
            _manager
            , xDisplay
            , xWindow
        );

        monitorDisplays(
            _manager
            , _impl
            , xDisplay
        );
    }

    void setEnd(
        dp::DisplayManagerImpl &    _impl
    )
    {
        _impl.ended = true;

        auto &  xDisplay = *( _impl.xDisplayUnique );
        auto &  xWindow = _impl.xWindow;

        XEvent  event;
        event.type = ClientMessage;
        event.xclient.display = &xDisplay;
        event.xclient.window = xWindow;
        event.xclient.format = 8;

        XSendEvent(
            &xDisplay
            , xWindow
            , False
            , StructureNotifyMask
            , &event
        );
        XFlush( &xDisplay );
    }
}

namespace dp {
    DisplayManagerImpl * newDisplayManagerImpl(
        DisplayManager &    _manager
    )
    {
        DisplayManagerImplUnique    implUnique( new( std::nothrow )DisplayManagerImpl );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  impl = *implUnique;

        auto &  xDisplayUnique = impl.xDisplayUnique;
        xDisplayUnique.reset( newXDisplay() );
        if( xDisplayUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  xDisplay = *xDisplayUnique;

        auto &  xWindow = impl.xWindow;

        xWindow = DefaultRootWindow( &xDisplay );

        // スレッド終了イベント用にStructureNotifyMaskを許可
        XSelectInput(
            &xDisplay
            , xWindow
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

    void free(
        DisplayManagerImpl &    _impl
    )
    {
        setEnd(
            _impl
        );

        delete &_impl;
    }
}
