#include "dpimpl/util/export.h"
#include "dp/input/gamepadkey.h"

#include "dpimpl/linux/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <new>

namespace {
    dp::GamePadKey * gamePadKeyNew(
        const dp::String &  _PATH
    )
    {
        dp::GamePadKeyUnique    keyUnique( new( std::nothrow )dp::GamePadKey );
        if( keyUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  key = *keyUnique;

        key.path.assign( _PATH );

        return keyUnique.release();
    }
}

namespace dp {
    GamePadKey * gamePadKeyClone(
        const GamePadKey &  _OTHER
    )
    {
        return ::gamePadKeyNew(
            _OTHER.path
        );
    }

    Bool gamePadKeyEquals(
        const GamePadKey &      _KEY1
        , const GamePadKey &    _KEY2
    )
    {
        return _KEY1.path == _KEY2.path;
    }

    Bool gamePadKeyLess(
        const GamePadKey &      _KEY1
        , const GamePadKey &    _KEY2
    )
    {
        return _KEY1.path < _KEY2.path;
    }

    GamePadKey * gamePadKeyNew(
        const StringChar *  _PATH
    )
    {
        return ::gamePadKeyNew(
            String( _PATH )
        );
    }
}
