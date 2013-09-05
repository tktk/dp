#include "dpimpl/util/export.h"
#include "dp/input/gamepad.h"

#include "dpimpl/windows/input/gamepad.h"
#include "dpimpl/common/input/gamepad.h"
#include "dpimpl/windows/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <new>

namespace dp {
    Bool getName(
        const GamePad & _GAME_PAD
        , Utf32 &       _name
    )
    {
        //TODO
        return false;
    }

    Bool getButtons(
        const GamePad & _GAME_PAD
        , ULong &       _buttons
    )
    {
        //TODO
        return false;
    }

    Bool getAxes(
        const GamePad & _GAME_PAD
        , ULong &       _axes
    )
    {
        //TODO
        return false;
    }

    Bool initializeGamePadImpl(
        GamePad &
        , const GamePadKey &
    )
    {
        //TODO
        return false;
    }
}
