#ifndef DPIMPL_LINUX_DISPLAY_XRANDR_H
#define DPIMPL_LINUX_DISPLAY_XRANDR_H

#define Bool int

#include <X11/extensions/Xrandr.h>

#undef  Bool

#include "dpimpl/linux/common/xlib.h"

namespace dp {
    struct FreeScreenResources
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
        , FreeScreenResources
    > ScreenResourcesUnique;

    inline XRRScreenResources * newScreenResources(
        ::Display &     _xDisplay
        , ::Window &    _xWindow
    )
    {
        return XRRGetScreenResources(
            &_xDisplay
            , _xWindow
        );
    }

    struct FreeCrtcInfo
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
        , FreeCrtcInfo
    > CrtcInfoUnique;

    inline XRRCrtcInfo * newCrtcInfo(
        ::Display &             _xDisplay
        , XRRScreenResources &  _screenResources
        , const RRCrtc &        _CRTC
    )
    {
        return XRRGetCrtcInfo(
            &_xDisplay
            , &_screenResources
            , _CRTC
        );
    }

    struct FreeOutputInfo
    {
        void operator()(
            XRROutputInfo * _info
        )
        {
            XRRFreeOutputInfo( _info );
        }
    };

    typedef std::unique_ptr<
        XRROutputInfo
        , FreeOutputInfo
    > OutputInfoUnique;

    inline XRROutputInfo * newOutputInfo(
        ::Display &             _xDisplay
        , XRRScreenResources &  _screenResources
        , const RROutput &      _OUTPUT
    )
    {
        return XRRGetOutputInfo(
            &_xDisplay
            , &_screenResources
            , _OUTPUT
        );
    }
}

#endif  // DPIMPL_LINUX_DISPLAY_XRANDR_H
