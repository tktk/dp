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
        dp::GamePadKeyPtr   keyPtr( new( std::nothrow )dp::GamePadKey );
        if( keyPtr.get() == nullptr ) {
            return nullptr;
        }

        auto &  key = *keyPtr;

        key.path.assign( _PATH );

        return keyPtr.release();
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

    const String & gamePadKeyGetPath(
        const GamePadKey &  _KEY
    )
    {
        return _KEY.path;
    }
}
