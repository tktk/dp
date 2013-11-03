#ifndef DPIMPL_LINUX_DISPLAY_XRANDR_H
#define DPIMPL_LINUX_DISPLAY_XRANDR_H

#define Bool int

#include <X11/extensions/Xrandr.h>

#undef  Bool

typedef int Bool;

#include "dpimpl/linux/xlib/xlib.h"
#include "dp/common/memory.h"

template<>
inline void free(
    const XRRScreenResources &  _RESOURCES
)
{
    XRRFreeScreenResources( const_cast< XRRScreenResources * >( &_RESOURCES ) );
}

template<>
inline void free(
    const XRRCrtcInfo & _INFO
)
{
    XRRFreeCrtcInfo( const_cast< XRRCrtcInfo * >( &_INFO ) );
}

template<>
inline void free(
    const XRROutputInfo &   _INFO
)
{
    XRRFreeOutputInfo( const_cast< XRROutputInfo * >( &_INFO ) );
}

namespace dp {
    typedef dp::Unique< XRRScreenResources >::type ScreenResourcesUnique;

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

    typedef dp::Unique< XRRCrtcInfo >::type CrtcInfoUnique;

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

    typedef dp::Unique< XRROutputInfo >::type OutputInfoUnique;

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
