#ifndef DP_DISPLAY_DISPLAYKEY_H
#define DP_DISPLAY_DISPLAYKEY_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

DPKEYSTRUCT( dp, DisplayKey )

namespace dp {
    DPEXPORT DisplayKey * clone(
        const DisplayKey &
    );

    DPEXPORT Bool equals(
        const DisplayKey &
        , const DisplayKey &
    );

    typedef Unique< DisplayKey >::type DisplayKeyUnique;

    typedef Shared< DisplayKey >::type DisplayKeyShared;

    typedef Weak< DisplayKey >::type DisplayKeyWeak;
}

#endif  // DP_DISPLAY_DISPLAYKEY_H
