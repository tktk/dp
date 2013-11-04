#include "dp/util/export.h"
#include "dp/input/gamepadkey.h"

#include "dpimpl/windows/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <new>

namespace {
    dp::GamePadKey * newGamePadKey(
        //TODO
    )
    {
        auto    keyUnique = dp::unique( new( std::nothrow )dp::GamePadKey );
        if( keyUnique.get() == nullptr ) {
            return nullptr;
        }

        //TODO

        return keyUnique.release();
    }
}

template<>
dp::Bool dpLess(
    const dp::GamePadKey &      _KEY1
    , const dp::GamePadKey &    _KEY2
)
{
    //TODO
    return false;
}

namespace dp {
    GamePadKey * clone(
        const GamePadKey &  _OTHER
    )
    {
        return ::newGamePadKey(
            //TODO
        );
    }

    Bool equals(
        const GamePadKey &      _KEY1
        , const GamePadKey &    _KEY2
    )
    {
        //TODO
        return false;
    }

    GamePadKey * newGamePadKey(
        //TODO
    )
    {
        return ::newGamePadKey(
            //TODO
        );
    }
}
