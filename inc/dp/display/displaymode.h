#ifndef DP_DISPLAY_DISPLAYMODE_H
#define DP_DISPLAY_DISPLAYMODE_H

#include "dp/display/displaymodekey.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

DPSTRUCT( dp, DisplayMode )

namespace dp {
    DPEXPORT DisplayMode * newDisplayMode(
        const DisplayModeKey &
    );

    DPEXPORT Int getWidth(
        const DisplayMode &
    );

    DPEXPORT Int getHeight(
        const DisplayMode &
    );

    DPEXPORT Float getRefreshRate(
        const DisplayMode &
    );

    typedef Unique< DisplayMode >::type DisplayModeUnique;

    typedef Shared< DisplayMode >::type DisplayModeShared;

    typedef Weak< DisplayMode >::type DisplayModeWeak;
}

#endif  // DP_DISPLAY_DISPLAYMODE_H
