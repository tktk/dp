#ifndef DP_INPUT_GAMEPAD_H
#define DP_INPUT_GAMEPAD_H

#include "dp/input/gamepadkey.h"
#include "dp/common/functional.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <mutex>
#include <functional>
#include <memory>

namespace dp {
    struct GamePad;

    struct GamePadInfo;

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

    DPEXPORT void free(
        GamePad &
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

    DPEXPORT const GamePadInfo & getInfo(
        const GamePad &
    );

    DPEXPORT GamePadInfo & getInfoMutable(
        GamePad &
    );

    DPEXPORT std::mutex & getMutexForButtonEventHandler(
        GamePad &
    );

    DPEXPORT std::mutex & getMutexForAxisEventHandler(
        GamePad &
    );

    DPEXPORT GamePadInfo * newGamePadInfo(
    );

    DPEXPORT GamePadInfo * clone(
        const GamePadInfo &
    );

    DPEXPORT void free(
        GamePadInfo &
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

    typedef std::unique_ptr<
        GamePad
        , Free< GamePad >
    > GamePadUnique;

    typedef std::shared_ptr< GamePad > GamePadShared;

    typedef std::weak_ptr< GamePad > GamePadWeak;

    typedef std::unique_ptr<
        GamePadInfo
        , Free< GamePadInfo >
    > GamePadInfoUnique;

    typedef std::shared_ptr< GamePadInfo > GamePadInfoShared;

    typedef std::weak_ptr< GamePadInfo > GamePadInfoWeak;
}

#endif  // DP_INPUT_GAMEPAD_H
