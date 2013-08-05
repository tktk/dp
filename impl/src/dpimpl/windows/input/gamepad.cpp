#include "dpimpl/util/export.h"
#include "dp/input/gamepad.h"

#include "dpimpl/windows/input/gamepad.h"
#include "dpimpl/common/input/gamepad.h"
#include "dpimpl/windows/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <new>

namespace dp {
    Bool gamePadGetName(
        const GamePad & _GAME_PAD
        , Utf32 &       _name
    )
    {
        //TODO
        return false;
    }

    Bool gamePadGetButtons(
        const GamePad & _GAME_PAD
        , ULong &       _buttons
    )
    {
        //TODO
        return false;
    }

    Bool gamePadGetAxes(
        const GamePad & _GAME_PAD
        , ULong &       _axes
    )
    {
        //TODO
        return false;
    }

    GamePadImpl * gamePadImplNew(
        GamePad &
        , const GamePadKey &
    )
    {
        GamePadImplUnique   implUnique( new( std::nothrow )GamePadImpl );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        //TODO

        return implUnique.release();
    }

    void gamePadImplDelete(
        GamePadImpl &   _impl
    )
    {
        delete &_impl;
    }
}
