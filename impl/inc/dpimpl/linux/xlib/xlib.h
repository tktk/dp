#ifndef DPIMPL_LINUX_XLIB_XLIB_H
#define DPIMPL_LINUX_XLIB_XLIB_H

#define Bool int

#include <X11/Xlib.h>

#undef  Bool

typedef int Bool;

#include "dp/common/memory.h"
#include "dp/util/import.h"

template<>
inline void dpFree(
    const ::Display &   _DISPLAY
)
{
    XCloseDisplay( const_cast< ::Display * >( &_DISPLAY ) );
}

namespace dp {
    typedef dp::Unique< ::Display >::type XDisplayUnique;

    inline ::Display * newXDisplay(
    )
    {
        return XOpenDisplay( nullptr );
    }

    void initializeXlib(
    );

    void finalizeXlib(
    );

    DPEXPORT ::Display & getXDisplay(
    );

    DPEXPORT ::Window & getXRootWindow(
    );
}

#endif  // DPIMPL_LINUX_XLIB_XLIB_H
