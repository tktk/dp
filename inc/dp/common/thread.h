#ifndef DP_COMMON_THREAD_H
#define DP_COMMON_THREAD_H

#include <thread>
#include <memory>

namespace dp {
    struct ThreadJoin
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
        , ThreadJoin
    > ThreadJoiner;

    struct ThreadDetach
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
        , ThreadDetach
    > ThreadDetacher;
}

#endif  // DP_COMMON_THREAD_H
