#ifndef DPIMPL_LINUX_INPUT_GAMEPADMANAGER_H
#define DPIMPL_LINUX_INPUT_GAMEPADMANAGER_H

#include "dp/common/primitives.h"
#include "dp/common/thread.h"

#include <mutex>
#include <condition_variable>
#include <thread>
#include <memory>

namespace dp {
    struct GamePadManagerImpl
    {
    private:
        struct ExitThread
        {
            void operator()(
                GamePadManagerImpl *
            ) const;
        };

        typedef std::unique_ptr<
            GamePadManagerImpl
            , ExitThread
        > ThreadExiter;

    public:
        std::mutex              mutex;
        std::condition_variable cond;
        Bool                    ended;

        std::thread     thread;
        ThreadJoiner    threadJoiner;
        ThreadExiter    threadExiter;
    };
}

#endif  // DPIMPL_LINUX_INPUT_GAMEPADMANAGER_H
