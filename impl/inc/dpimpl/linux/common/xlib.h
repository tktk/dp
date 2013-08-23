#ifndef DPIMPL_LINUX_COMMON_XLIB_H
#define DPIMPL_LINUX_COMMON_XLIB_H

#define Bool int

#include <X11/Xlib.h>

#undef  Bool

#include "dp/util/import.h"

#include <memory>

namespace dp {
    struct FreeX11Display
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
        , FreeX11Display
    > X11DisplayUnique;

    inline ::Display * x11DisplayNew(
    )
    {
        return XOpenDisplay( nullptr );
    }

    void initializeXlib(
    );

    void finalizeXlib(
    );

    DPEXPORT ::Display & getX11Display(
    );

    DPEXPORT ::Window & getX11Window(
    );
}

#endif  // DPIMPL_LINUX_COMMON_XLIB_H
