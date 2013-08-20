#ifndef DP_DISPLAY_DISPLAYMODEKEY_H
#define DP_DISPLAY_DISPLAYMODEKEY_H

#include "dp/display/displaykey.h"
#include "dp/common/functional.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <memory>
#include <vector>

namespace dp {
    struct DisplayModeKey;

    DPEXPORT DisplayModeKey * clone(
        const DisplayModeKey &
    );

    DPEXPORT void free(
        DisplayModeKey &
    );

    DPEXPORT Bool equals(
        const DisplayModeKey &
        , const DisplayModeKey &
    );

    DPEXPORT Bool less(
        const DisplayModeKey &
        , const DisplayModeKey &
    );

    typedef std::unique_ptr<
        DisplayModeKey
        , Free< DisplayModeKey >
    > DisplayModeKeyUnique;

    typedef std::shared_ptr< DisplayModeKey > DisplayModeKeyShared;

    typedef std::weak_ptr< DisplayModeKey > DisplayModeKeyWeak;

    typedef std::vector< DisplayModeKeyUnique > DisplayModeKeyUniques;

    DPEXPORT Bool enumDisplayModeKeyUniques(
        const DisplayKey &
        , DisplayModeKeyUniques &
    );
}

#endif  // DP_DISPLAY_DISPLAYMODEKEY_H
