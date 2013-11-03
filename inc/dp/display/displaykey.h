#ifndef DP_DISPLAY_DISPLAYKEY_H
#define DP_DISPLAY_DISPLAYKEY_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

#include <memory>

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

    typedef std::shared_ptr< DisplayKey > DisplayKeyShared;

    typedef std::weak_ptr< DisplayKey > DisplayKeyWeak;
}

#endif  // DP_DISPLAY_DISPLAYKEY_H
