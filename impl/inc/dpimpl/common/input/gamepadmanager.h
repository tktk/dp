#ifndef DPIMPL_COMMON_INPUT_GAMEPADMANAGER_H
#define DPIMPL_COMMON_INPUT_GAMEPADMANAGER_H

#if defined LINUX   // OS
#include "dpimpl/linux/input/gamepadmanager.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/input/gamepadmanager.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#include "dp/input/gamepadmanager.h"
#include "dp/input/gamepadkey.h"
#include "dp/common/functional.h"
#include "dp/common/primitives.h"

#include <memory>
#include <mutex>

namespace dp {
    void callConnectEventHandler(
        GamePadManager &
        , GamePadKeyUnique &&
        , Bool
    );

    struct GamePadManagerImpl;

    GamePadManagerImpl * newGamePadManagerImpl(
        GamePadManager &
    );

    void free(
        GamePadManagerImpl &
    );

    typedef std::unique_ptr<
        GamePadManagerImpl
        , Free< GamePadManagerImpl >
    > GamePadManagerImplUnique;

    struct GamePadManager
    {
        GamePadManagerInfoUnique    infoUnique;
        std::mutex                  mutexForConnectEventHandler;

        GamePadManagerImplUnique    implUnique;
    };
}

#endif  // DPIMPL_COMMON_INPUT_GAMEPADMANAGER_H
