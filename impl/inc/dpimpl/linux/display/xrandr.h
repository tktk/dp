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

    inline XRRScreenResources * screenResourcesNew(
        ::Display &     _x11Display
        , ::Window &    _x11Window
    )
    {
        return XRRGetScreenResources(
            &_x11Display
            , _x11Window
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

    inline XRRCrtcInfo * crtcInfoNew(
        ::Display &             _x11Display
        , XRRScreenResources &  _screenResources
        , const RRCrtc &        _CRTC
    )
    {
        return XRRGetCrtcInfo(
            &_x11Display
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

    inline XRROutputInfo * outputInfoNew(
        ::Display &             _x11Display
        , XRRScreenResources &  _screenResources
        , const RROutput &      _OUTPUT
    )
    {
        return XRRGetOutputInfo(
            &_x11Display
            , &_screenResources
            , _OUTPUT
        );
    }
}

#endif  // DPIMPL_LINUX_DISPLAY_XRANDR_H
