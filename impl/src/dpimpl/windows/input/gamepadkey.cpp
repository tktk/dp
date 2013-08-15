#include "dpimpl/util/export.h"
#include "dp/input/gamepadkey.h"

#include "dpimpl/windows/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <new>

namespace {
    dp::GamePadKey * newGamePadKey(
        //TODO
    )
    {
        dp::GamePadKeyUnique    keyUnique( new( std::nothrow )dp::GamePadKey );
        if( keyUnique.get() == nullptr ) {
            return nullptr;
        }

        //TODO

        return keyUnique.release();
    }
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

    Bool less(
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
