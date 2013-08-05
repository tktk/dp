#ifndef DP_COMMON_THREAD_H
#define DP_COMMON_THREAD_H

#include <thread>
#include <memory>

namespace dp {
    struct ThreadJoiner
    {
        void operator()(
            std::thread *   _thread
        ) const
        {
            _thread->join();
        }
    };

    typedef std::unique_ptr<
        std::thread
        , ThreadJoiner
    > ThreadJoinPtr;

    struct ThreadDetacher
    {
        void operator()(
            std::thread *   _thread
        ) const
        {
            _thread->detach();
        }
    };

    typedef std::unique_ptr<
        std::thread
        , ThreadDetacher
    > ThreadDetachPtr;
}

#endif  // DP_COMMON_THREAD_H
