#ifndef DP_INPUT_GAMEPADKEY_H
#define DP_INPUT_GAMEPADKEY_H

#include "dp/common/functional.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <memory>

namespace dp {
    struct GamePadKey;

    DPEXPORT GamePadKey * clone(
        const GamePadKey &
    );

    DPEXPORT void free(
        GamePadKey &
    );

    DPEXPORT Bool equals(
        const GamePadKey &
        , const GamePadKey &
    );

    DPEXPORT Bool less(
        const GamePadKey &
        , const GamePadKey &
    );

    typedef std::unique_ptr<
        GamePadKey
        , Free< GamePadKey >
    > GamePadKeyUnique;

    typedef std::shared_ptr< GamePadKey > GamePadKeyShared;

    typedef std::weak_ptr< GamePadKey > GamePadKeyWeak;
}

#endif  // DP_INPUT_GAMEPADKEY_H
