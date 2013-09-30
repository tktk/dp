#ifndef DPIMPL_LINUX_XLIB_XLIB_SETUP_H
#define DPIMPL_LINUX_XLIB_XLIB_SETUP_H

#include "dpimpl/linux/xlib/xlib.h"

namespace dp {
    inline void initializeXlib_(
    )
    {
        initializeXlib();
    }

    inline void finalizeXlib_(
    )
    {
        finalizeXlib();
    }
}

#endif  // DPIMPL_LINUX_XLIB_XLIB_SETUP_H
