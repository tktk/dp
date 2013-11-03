#ifndef DPIMPL_COMMON_INPUT_GAMEPAD_H
#define DPIMPL_COMMON_INPUT_GAMEPAD_H

#if defined LINUX   // OS
#include "dpimpl/linux/input/gamepad.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/input/gamepad.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#include "dp/input/gamepad.h"
#include "dp/input/gamepadkey.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/struct.h"

DPSTRUCT( dp, GamePadImpl )

namespace dp {
    void callButtonEventHandler(
        GamePad &
        , ULong
        , Bool
    );

    void callAxisEventHandler(
        GamePad &
        , ULong
        , Long
    );

    Bool initializeGamePadImpl(
        GamePad &
        , const GamePadKey &
    );

    typedef Unique< GamePadImpl >::type GamePadImplUnique;

    struct GamePad
    {
        GamePadInfoUnique   infoUnique;
        GamePadImplUnique   implUnique;
    };
}

#endif  // DPIMPL_COMMON_INPUT_GAMEPAD_H
