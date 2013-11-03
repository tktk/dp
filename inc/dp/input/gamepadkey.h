#ifndef DP_INPUT_GAMEPADKEY_H
#define DP_INPUT_GAMEPADKEY_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

#include <memory>

DPKEYSTRUCT( dp, GamePadKey )

namespace dp {
    DPEXPORT GamePadKey * clone(
        const GamePadKey &
    );

    DPEXPORT Bool equals(
        const GamePadKey &
        , const GamePadKey &
    );

    typedef Unique< GamePadKey >::type GamePadKeyUnique;

    typedef std::shared_ptr< GamePadKey > GamePadKeyShared;

    typedef std::weak_ptr< GamePadKey > GamePadKeyWeak;
}

#endif  // DP_INPUT_GAMEPADKEY_H
