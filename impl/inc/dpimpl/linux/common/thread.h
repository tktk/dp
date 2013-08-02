﻿#ifndef DPIMPL_LINUX_COMMON_THREAD_H
#define DPIMPL_LINUX_COMMON_THREAD_H

#include <thread>
#include <pthread.h>
#include <memory>

namespace dp {
    struct ThreadCanceller
    {
        void operator()(
            std::thread *   _thread
        )
        {
            pthread_cancel( _thread->native_handle() );
        }
    };

    typedef std::unique_ptr<
        std::thread
        , ThreadCanceller
    > ThreadCancelPtr;
}

#endif  // DPIMPL_LINUX_COMMON_THREAD_H
