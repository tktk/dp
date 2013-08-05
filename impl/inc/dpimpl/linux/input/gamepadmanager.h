#ifndef DPIMPL_LINUX_INPUT_GAMEPADMANAGER_H
#define DPIMPL_LINUX_INPUT_GAMEPADMANAGER_H

#include "dp/common/primitives.h"
#include "dp/common/thread.h"

#include <mutex>
#include <condition_variable>
#include <thread>

namespace dp {
    struct GamePadManagerImpl
    {
        std::mutex              mutex;
        std::condition_variable cond;
        Bool                    ended;

        std::thread     thread;
        ThreadJoiner    threadJoiner;
    };
}

#endif  // DPIMPL_LINUX_INPUT_GAMEPADMANAGER_H
