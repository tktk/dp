#ifndef DPIMPL_LINUX_DISPLAY_DISPLAYMODEKEY_H
#define DPIMPL_LINUX_DISPLAY_DISPLAYMODEKEY_H

#include "dp/display/displaymodekey.h"

#include "dpimpl/linux/display/xrandr.h"

namespace dp {
    struct DisplayModeKey
    {
        RRMode  mode;
    };

    DisplayModeKey * newDisplayModeKey(
        const RRMode &
    );
}

#endif  // DPIMPL_LINUX_DISPLAY_DISPLAYMODEKEY_H
