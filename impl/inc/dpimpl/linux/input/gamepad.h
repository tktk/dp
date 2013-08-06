#ifndef DPIMPL_LINUX_INPUT_GAMEPAD_H
#define DPIMPL_LINUX_INPUT_GAMEPAD_H

#include "dp/common/primitives.h"
#include "dp/common/thread.h"
#include "dpimpl/linux/common/descriptorcloser.h"

#include <mutex>
#include <condition_variable>
#include <thread>

namespace dp {
    struct GamePadImpl
    {
        std::mutex              mutex;
        std::condition_variable cond;
        Bool                    ended;

        Int                 descriptor;
        DescriptorCloser    descriptorCloser;

        std::thread     thread;
        ThreadJoiner    threadJoiner;
    };
}

#endif  // DPIMPL_LINUX_INPUT_GAMEPAD_H
