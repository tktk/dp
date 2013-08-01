#ifndef DPIMPL_LINUX_INPUT_GAMEPADMANAGER_H
#define DPIMPL_LINUX_INPUT_GAMEPADMANAGER_H

#include "dp/common/primitives.h"
#include "dp/common/thread.h"

#include <thread>

namespace dp {
    struct GamePadManagerImpl
    {
        Bool            ended;
        std::thread     thread;
        ThreadJoinPtr   threadJoiner;
    };
}

#endif  // DPIMPL_LINUX_INPUT_GAMEPADMANAGER_H
