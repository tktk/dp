#ifndef DPIMPL_COMMON_DISPLAY_DISPLAYMODE_H
#define DPIMPL_COMMON_DISPLAY_DISPLAYMODE_H

#include "dp/display/displaymodekey.h"
#include "dp/common/primitives.h"

namespace dp {
    Bool displayModeGetWidthAndHeightFromModeKey(
        const DisplayModeKey &
        , ULong &
        , ULong &
    );

    struct DisplayMode
    {
        ULong   width;
        ULong   height;

        Float   refreshRate;
    };
}

#endif  // DPIMPL_COMMON_DISPLAY_DISPLAYMODE_H
