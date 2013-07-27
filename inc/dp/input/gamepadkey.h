#ifndef DP_INPUT_GAMEPADKEY_H
#define DP_INPUT_GAMEPADKEY_H

#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <memory>

namespace dp {
    struct GamePadKey;

    DPEXPORT GamePadKey * gamePadKeyClone(
        const GamePadKey &
    );

    DPEXPORT void gamePadKeyDelete(
        GamePadKey &
    );

    DPEXPORT Bool gamePadKeyEquals(
        const GamePadKey &
        , const GamePadKey &
    );

    DPEXPORT Bool gamePadKeyLess(
        const GamePadKey &
        , const GamePadKey &
    );

    struct GamePadKeyDeleter
    {
        void operator()(
            GamePadKey *    _key
        )
        {
            gamePadKeyDelete( *_key );
        }
    };

    typedef std::unique_ptr<
        GamePadKey
        , GamePadKeyDeleter
    > GamePadKeyPtr;

    struct GamePadKeyPtrComparer
    {
        Bool operator()(
            const GamePadKeyPtr &   _PTR1
            , const GamePadKeyPtr & _PTR2
        )
        {
            return gamePadKeyLess(
                *_PTR1
                , *_PTR2
            );
        }
    };
}

#endif  // DP_INPUT_GAMEPADKEY_H
