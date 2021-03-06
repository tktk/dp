﻿#ifndef DP_DISPLAY_DISPLAYMODEKEY_H
#define DP_DISPLAY_DISPLAYMODEKEY_H

#include "dp/display/displaykey.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

#include <vector>

DPKEYSTRUCT( dp, DisplayModeKey )

namespace dp {
    DPEXPORT DisplayModeKey * clone(
        const DisplayModeKey &
    );

    DPEXPORT Bool equals(
        const DisplayModeKey &
        , const DisplayModeKey &
    );

    typedef Unique< DisplayModeKey >::type DisplayModeKeyUnique;

    typedef Shared< DisplayModeKey >::type DisplayModeKeyShared;

    typedef Weak< DisplayModeKey >::type DisplayModeKeyWeak;

    typedef std::vector< DisplayModeKeyUnique > DisplayModeKeyUniques;

    DPEXPORT Bool enumDisplayModeKeyUniques(
        const DisplayKey &
        , DisplayModeKeyUniques &
    );
}

#endif  // DP_DISPLAY_DISPLAYMODEKEY_H
