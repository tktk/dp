#ifndef DP_DISPLAY_DISPLAYMODE_H
#define DP_DISPLAY_DISPLAYMODE_H

#include "dp/display/displaymodekey.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <memory>

namespace dp {
    struct DisplayMode;

    DPEXPORT DisplayMode * newDisplayMode(
        const DisplayModeKey &
    );

    DPEXPORT void free(
        DisplayMode &
    );

    DPEXPORT ULong getWidth(
        const DisplayMode &
    );

    DPEXPORT ULong getHeight(
        const DisplayMode &
    );

    DPEXPORT Float getRefreshRate(
        const DisplayMode &
    );

    typedef Unique< DisplayMode >::type DisplayModeUnique;

    typedef std::shared_ptr< DisplayMode > DisplayModeShared;

    typedef std::weak_ptr< DisplayMode > DisplayModeWeak;
}

#endif  // DP_DISPLAY_DISPLAYMODE_H
