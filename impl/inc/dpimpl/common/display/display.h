#ifndef DPIMPL_COMMON_DISPLAY_DISPLAY_H
#define DPIMPL_COMMON_DISPLAY_DISPLAY_H

#include "dp/display/displaymodekey.h"
#include "dp/display/displayrotate.h"
#include "dp/common/primitives.h"

namespace dp {
    struct Display
    {
        DisplayModeKeyUnique    modeKeyUnique;

        Int width;
        Int height;

        Int x;
        Int y;

        DisplayRotate   rotate;
    };
}

#endif  // DPIMPL_COMMON_DISPLAY_DISPLAY_H
