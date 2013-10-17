#include "dpimpl/linux/display/displaymanager.h"
#include "dpimpl/common/display/displaymanager.h"
#include "dp/display/displaymanager.h"
#include "dpimpl/linux/display/displaykey.h"
#include "dp/display/displaykey.h"
#include "dp/common/primitives.h"
#include "dp/common/thread.h"
#include "dpimpl/linux/common/thread.h"

#include "dpimpl/linux/xlib/xlib.h"
#include "dpimpl/linux/display/xrandr.h"
#include <vector>

namespace {
    void callConnectEventHandler(
        dp::DisplayManager &    _manager
        , const RRCrtc &        _CRTC
        , dp::Bool              _connected
    )
    {
        auto    keyUnique = dp::unique(
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
            dp::newCrtcInfo(
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
            dp::newScreenResources(
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
        dp::DisplayManager &    _manager
        , ::Display &           _xDisplay
    )
    {
        auto &  impl = *( _manager.implUnique );

        const auto &    ENDED = impl.ended;

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
        dp::DisplayManager &    _manager
    )
    {
        auto &  impl = *( _manager.implUnique );

        auto &  xDisplay = *( impl.xDisplayUnique );

        auto &  xWindow = impl.xWindow;

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
            , xDisplay
        );
    }
}

namespace dp {
    Bool initializeDisplayManagerImpl(
        DisplayManager &    _manager
    )
    {
        auto &  impl = *( _manager.implUnique );

        auto &  xDisplayUnique = impl.xDisplayUnique;
        xDisplayUnique.reset( newXDisplay() );
        if( xDisplayUnique.get() == nullptr ) {
            return false;
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
                ]
                {
                    threadProc(
                        _manager
                    );
                }
            )
        );
        impl.threadJoiner.reset( &( impl.thread ) );
        impl.threadExiter.reset( &impl );

        return true;
    }

    void DisplayManagerImpl::ExitThread::operator()(
        DisplayManagerImpl *    _impl
    ) const
    {
        _impl->ended = true;

        auto &  xDisplay = *( _impl->xDisplayUnique );
        auto &  xWindow = _impl->xWindow;

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
