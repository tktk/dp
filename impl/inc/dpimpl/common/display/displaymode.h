#ifndef DPIMPL_COMMON_DISPLAY_DISPLAYMODE_H
#define DPIMPL_COMMON_DISPLAY_DISPLAYMODE_H

#include "dp/display/displaymodekey.h"
#include "dp/common/primitives.h"

namespace dp {
    Bool getWidthAndHeightFromModeKey(
        ULong &
        , ULong &
        , const DisplayModeKey &
    );

    struct DisplayMode
    {
        ULong   width;
        ULong   height;

        Float   refreshRate;
    };
}

#endif  // DPIMPL_COMMON_DISPLAY_DISPLAYMODE_H
