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
        ) const
        {
            gamePadKeyDelete( *_key );
        }
    };

    typedef std::unique_ptr<
        GamePadKey
        , GamePadKeyDeleter
    > GamePadKeyUnique;

    typedef std::shared_ptr< GamePadKey > GamePadKeyShared;

    inline GamePadKeyShared gamePadKeyShared(
        GamePadKey &    _key
    )
    {
        return GamePadKeyShared(
            &_key
            , GamePadKeyDeleter()
        );
    }

    typedef std::weak_ptr< GamePadKey > GamePadKeyWeak;

    template< typename T >
    struct GamePadKeyLess
    {
        Bool operator()(
            const T &   _KEY1
            , const T & _KEY2
        ) const
        {
            return gamePadKeyLess(
                *_KEY1
                , *_KEY2
            );
        }
    };
}

#endif  // DP_INPUT_GAMEPADKEY_H
