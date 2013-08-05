#ifndef DP_INPUT_GAMEPAD_H
#define DP_INPUT_GAMEPAD_H

#include "dp/input/gamepadkey.h"
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

    DPEXPORT GamePad * gamePadNew(
        const GamePadKey &
        , const GamePadInfo &
    );

    DPEXPORT void gamePadDelete(
        GamePad &
    );

    DPEXPORT Bool gamePadGetName(
        const GamePad &
        , Utf32 &
    );

    DPEXPORT Bool gamePadGetButtons(
        const GamePad &
        , ULong &
    );

    DPEXPORT Bool gamePadGetAxes(
        const GamePad &
        , ULong &
    );

    DPEXPORT const GamePadInfo & gamePadGetInfo(
        const GamePad &
    );

    DPEXPORT GamePadInfo & gamePadGetInfoMutable(
        GamePad &
    );

    DPEXPORT std::mutex & gamePadGetMutexForButtonEventHandler(
        GamePad &
    );

    DPEXPORT std::mutex & gamePadGetMutexForAxisEventHandler(
        GamePad &
    );

    DPEXPORT GamePadInfo * gamePadInfoNew(
    );

    DPEXPORT GamePadInfo * gamePadInfoClone(
        const GamePadInfo &
    );

    DPEXPORT void gamePadInfoDelete(
        GamePadInfo &
    );

    DPEXPORT const GamePadButtonEventHandler & gamePadInfoGetButtonEventHandler(
        const GamePadInfo &
    );

    DPEXPORT void gamePadInfoSetButtonEventHandler(
        GamePadInfo &
        , const GamePadButtonEventHandler &
    );

    DPEXPORT const GamePadAxisEventHandler & gamePadInfoGetAxisEventHandler(
        const GamePadInfo &
    );

    DPEXPORT void gamePadInfoSetAxisEventHandler(
        GamePadInfo &
        , const GamePadAxisEventHandler &
    );

    struct GamePadDelete
    {
        void operator()(
            GamePad *   _gamePad
        ) const
        {
            gamePadDelete( *_gamePad );
        }
    };

    typedef std::unique_ptr<
        GamePad
        , GamePadDelete
    > GamePadUnique;

    typedef std::shared_ptr< GamePad > GamePadShared;

    inline GamePadShared gamePadShared(
        GamePad &   _gamePad
    )
    {
        return GamePadShared(
            &_gamePad
            , GamePadDelete()
        );
    }

    typedef std::weak_ptr< GamePad > GamePadWeak;

    struct GamePadInfoDelete
    {
        void operator()(
            GamePadInfo *   _info
        ) const
        {
            gamePadInfoDelete( *_info );
        }
    };

    typedef std::unique_ptr<
        GamePadInfo
        , GamePadInfoDelete
    > GamePadInfoUnique;

    typedef std::shared_ptr< GamePadInfo > GamePadInfoShared;

    inline GamePadInfoShared gamePadInfoShared(
        GamePadInfo &   _info
    )
    {
        return GamePadInfoShared(
            &_info
            , GamePadInfoDelete()
        );
    }

    typedef std::weak_ptr< GamePadInfo > GamePadInfoWeak;
}

#endif  // DP_INPUT_GAMEPAD_H
