#include "dpimpl/util/export.h"
#include "dp/input/gamepadkey.h"

#include "dpimpl/windows/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <new>

namespace {
    dp::GamePadKey * gamePadKeyNew(
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
    GamePadKey * gamePadKeyClone(
        const GamePadKey &  _OTHER
    )
    {
        return ::gamePadKeyNew(
            //TODO
        );
    }

    Bool gamePadKeyEquals(
        const GamePadKey &      _KEY1
        , const GamePadKey &    _KEY2
    )
    {
        //TODO
        return false;
    }

    Bool gamePadKeyLess(
        const GamePadKey &      _KEY1
        , const GamePadKey &    _KEY2
    )
    {
        //TODO
        return false;
    }

    GamePadKey * gamePadKeyNew(
        //TODO
    )
    {
        return ::gamePadKeyNew(
            //TODO
        );
    }
}
