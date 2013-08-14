﻿#ifndef DPIMPL_LINUX_DISPLAY_X11_H
#define DPIMPL_LINUX_DISPLAY_X11_H

#include "dpimpl/linux/common/xlib.h"

#include <memory>

namespace dp {
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

    inline ::Display * x11DisplayNew(
    )
    {
        return XOpenDisplay( nullptr );
    }

    void initializeX11(
    );

    void finalizeX11(
    );

    ::Display & getX11Display(
    );

    ::Window & getX11Window(
    );
}

#endif  // DPIMPL_LINUX_DISPLAY_X11_H