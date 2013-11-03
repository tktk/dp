#include "dpimpl/util/export.h"
#include "dp/input/gamepadkey.h"

#include "dpimpl/linux/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <new>

namespace {
    dp::GamePadKey * newGamePadKey(
        const dp::String &  _PATH
    )
    {
        auto    keyUnique = dp::unique( new( std::nothrow )dp::GamePadKey );
        if( keyUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  key = *keyUnique;

        key.path.assign( _PATH );

        return keyUnique.release();
    }
}

template<>
dp::Bool less(
    const dp::GamePadKey &      _KEY1
    , const dp::GamePadKey &    _KEY2
)
{
    return _KEY1.path < _KEY2.path;
}

namespace dp {
    GamePadKey * clone(
        const GamePadKey &  _OTHER
    )
    {
        return ::newGamePadKey(
            _OTHER.path
        );
    }

    Bool equals(
        const GamePadKey &      _KEY1
        , const GamePadKey &    _KEY2
    )
    {
        return _KEY1.path == _KEY2.path;
    }

    GamePadKey * newGamePadKey(
        const StringChar *  _PATH
    )
    {
        return ::newGamePadKey(
            String( _PATH )
        );
    }
}
