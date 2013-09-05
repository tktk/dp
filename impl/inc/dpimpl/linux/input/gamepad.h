#ifndef DPIMPL_LINUX_INPUT_GAMEPAD_H
#define DPIMPL_LINUX_INPUT_GAMEPAD_H

#include "dp/common/primitives.h"
#include "dp/common/thread.h"
#include "dpimpl/linux/common/descriptorcloser.h"

#include <mutex>
#include <condition_variable>
#include <thread>
#include <memory>

namespace dp {
    struct GamePadImpl
    {
    private:
        struct ExitThread
        {
            void operator()(
                GamePadImpl *
            ) const;
        };

        typedef std::unique_ptr<
            GamePadImpl
            , ExitThread
        > ThreadExiter;

    public:
        std::mutex              mutex;
        std::condition_variable cond;
        Bool                    ended;

        Int                 descriptor;
        DescriptorCloser    descriptorCloser;

        std::thread     thread;
        ThreadJoiner    threadJoiner;
        ThreadExiter    threadExiter;
    };
}

#endif  // DPIMPL_LINUX_INPUT_GAMEPAD_H
