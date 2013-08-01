#ifndef DPIMPL_LINUX_INPUT_GAMEPADMANAGER_H
#define DPIMPL_LINUX_INPUT_GAMEPADMANAGER_H

#include "dp/common/primitives.h"

#include <thread>

namespace dp {
    struct GamePadManagerImpl
    {
        Bool        ended;
        std::thread thread;
    };
}

#endif  // DPIMPL_LINUX_INPUT_GAMEPADMANAGER_H
