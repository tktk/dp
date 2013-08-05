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
#include "dp/common/primitives.h"

#include <memory>
#include <mutex>

namespace dp {
    struct GamePadImpl;

    GamePadImpl * gamePadImplNew(
        GamePad &
        , const GamePadKey &
    );

    void gamePadImplDelete(
        GamePadImpl &
    );

    struct GamePadImplDelete
    {
        void operator()(
            GamePadImpl *   _impl
        ) const
        {
            gamePadImplDelete( *_impl );
        }
    };

    typedef std::unique_ptr<
        GamePadImpl
        , GamePadImplDelete
    > GamePadImplUnique;

    struct GamePad
    {
        GamePadInfoUnique   infoUnique;
        std::mutex          mutexForButtonEventHandler;
        std::mutex          mutexForAxisEventHandler;

        GamePadImplUnique   implUnique;
    };
}

#endif  // DPIMPL_COMMON_INPUT_GAMEPAD_H
