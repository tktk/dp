#include "dpimpl/util/export.h"
#include "dp/display/displaymodekey.h"

#include "dp/display/displaykey.h"
#include "dp/common/primitives.h"

template<>
dp::Bool less(
    const dp::DisplayModeKey &
    , const dp::DisplayModeKey &
)
{
    //TODO
    return false;
}

namespace dp {
    DisplayModeKey * clone(
        const DisplayModeKey &
    )
    {
        //TODO
        return nullptr;
    }

    Bool equals(
        const DisplayModeKey &
        , const DisplayModeKey &
    )
    {
        //TODO
        return false;
    }

    Bool enumDisplayModeKeyUniques(
        const DisplayKey &
        , DisplayModeKeyUniques &
    )
    {
        //TODO
        return false;
    }
}
