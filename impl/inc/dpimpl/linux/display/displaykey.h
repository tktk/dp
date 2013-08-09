#ifndef DPIMPL_LINUX_DISPLAY_DISPLAYKEY_H
#define DPIMPL_LINUX_DISPLAY_DISPLAYKEY_H

#include "dp/display/displaykey.h"

#include "dpimpl/linux/display/xrandr.h"

namespace dp {
    struct DisplayKey
    {
        RRCrtc  crtc;
    };

    DisplayKey * displayKeyNew(
        const RRCrtc &
    );
}

#endif  // DPIMPL_LINUX_DISPLAY_DISPLAYKEY_H
