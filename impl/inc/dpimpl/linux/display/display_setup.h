#ifndef DPIMPL_LINUX_DISPLAY_DISPLAY_SETUP_H
#define DPIMPL_LINUX_DISPLAY_DISPLAY_SETUP_H

#include "dpimpl/linux/display/x11.h"

namespace dp {
    inline void initializeDisplay(
    )
    {
        initializeX11();
    }

    inline void finalizeDisplay(
    )
    {
        finalizeX11();
    }
}

#endif  // DPIMPL_LINUX_DISPLAY_DISPLAY_SETUP_H
