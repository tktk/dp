#ifndef DP_INPUT_GAMEPAD_H
#define DP_INPUT_GAMEPAD_H

#include "dp/input/gamepadkey.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

#include <functional>

DPSTRUCT( dp, GamePad )

DPSTRUCT( dp, GamePadInfo )

namespace dp {
    typedef std::function<
        void(
            GamePad &
            , ULong
            , Bool
        )
    > GamePadButtonEventHandler;

    typedef std::function<
        void(
            GamePad &
            , ULong
            , Long
        )
    > GamePadAxisEventHandler;

    DPEXPORT GamePad * newGamePad(
        const GamePadKey &
        , const GamePadInfo &
    );

    DPEXPORT Bool getName(
        const GamePad &
        , Utf32 &
    );

    DPEXPORT Bool getButtons(
        const GamePad &
        , ULong &
    );

    DPEXPORT Bool getAxes(
        const GamePad &
        , ULong &
    );

    DPEXPORT GamePadInfo * newGamePadInfo(
    );

    DPEXPORT GamePadInfo * clone(
        const GamePadInfo &
    );

    DPEXPORT const GamePadButtonEventHandler & getButtonEventHandler(
        const GamePadInfo &
    );

    DPEXPORT void setButtonEventHandler(
        GamePadInfo &
        , const GamePadButtonEventHandler &
    );

    DPEXPORT const GamePadAxisEventHandler & getAxisEventHandler(
        const GamePadInfo &
    );

    DPEXPORT void setAxisEventHandler(
        GamePadInfo &
        , const GamePadAxisEventHandler &
    );

    typedef Unique< GamePad >::type GamePadUnique;

    typedef Shared< GamePad >::type GamePadShared;

    typedef Weak< GamePad >::type GamePadWeak;

    typedef Unique< GamePadInfo >::type GamePadInfoUnique;

    typedef Shared< GamePadInfo >::type GamePadInfoShared;

    typedef Weak< GamePadInfo >::type GamePadInfoWeak;
}

#endif  // DP_INPUT_GAMEPAD_H
