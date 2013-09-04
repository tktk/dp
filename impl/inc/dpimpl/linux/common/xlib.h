#ifndef DPIMPL_LINUX_COMMON_XLIB_H
#define DPIMPL_LINUX_COMMON_XLIB_H

#define Bool int

#include <X11/Xlib.h>

#undef  Bool

typedef int Bool;

#include "dp/util/import.h"

#include <memory>

namespace dp {
    struct FreeXDisplay
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
        , FreeXDisplay
    > XDisplayUnique;

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

#endif  // DPIMPL_LINUX_COMMON_XLIB_H
