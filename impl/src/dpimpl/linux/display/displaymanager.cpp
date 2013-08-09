#include "dpimpl/linux/display/displaymanager.h"
#include "dpimpl/common/display/displaymanager.h"
#include "dp/display/displaymanager.h"
#include "dpimpl/linux/display/displaykey.h"
#include "dp/display/displaykey.h"
#include "dp/common/primitives.h"

#include "dpimpl/linux/display/xlib.h"
#include "dpimpl/linux/display/xrandr.h"
#include <new>
#include <memory>

namespace {
    struct X11DisplayDelete
    {
        void operator()(
            ::Display * _display
        )
        {
            XCloseDisplay( _display );
        }
    };

    typedef std::unique_ptr<
        ::Display
        , X11DisplayDelete
    > X11DisplayUnique;

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
        , ::Display &           _display
        , ::Window &            _window
    )
    {
        ScreenResourcesUnique   screenResourcesUnique(
            screenResourcesNew(
                _display
                , _window
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
                _display
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

    void monitorDisplays(
        //TODO
    )
    {
        //TODO
    }

    void threadProc(
        dp::DisplayManager &        _manager
        , dp::DisplayManagerImpl &  _impl
    )
    {
        X11DisplayUnique    displayUnique( x11DisplayNew() );
        if( displayUnique.get() == nullptr ) {
            return;
        }

        auto &  display = *displayUnique;

        auto    window = DefaultRootWindow( &display );

        XRRSelectInput(
            &display
            , window
            , RRCrtcChangeNotifyMask
        );

        initDisplays(
            _manager
            , display
            , window
        );

        monitorDisplays(
            //TODO
        );
    }

    void setEnd(
        dp::DisplayManagerImpl &    _impl
    )
    {
        auto &  mutex = _impl.mutex;

        std::unique_lock< std::mutex >  lock( mutex );

        _impl.ended = true;

        _impl.cond.notify_one();
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

        return nullptr;
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
