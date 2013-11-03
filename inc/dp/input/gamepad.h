#ifndef DP_INPUT_GAMEPAD_H
#define DP_INPUT_GAMEPAD_H

#include "dp/input/gamepadkey.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

#include <functional>
#include <memory>

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

    typedef std::shared_ptr< GamePad > GamePadShared;

    typedef std::weak_ptr< GamePad > GamePadWeak;

    typedef Unique< GamePadInfo >::type GamePadInfoUnique;

    typedef std::shared_ptr< GamePadInfo > GamePadInfoShared;

    typedef std::weak_ptr< GamePadInfo > GamePadInfoWeak;
}

#endif  // DP_INPUT_GAMEPAD_H
