#ifndef DPIMPL_LINUX_DISPLAY_DISPLAYMANAGER_H
#define DPIMPL_LINUX_DISPLAY_DISPLAYMANAGER_H

#include "dp/common/primitives.h"
#include "dp/common/thread.h"

#include "dpimpl/linux/common/xlib.h"
#include <thread>

namespace dp {
    struct DisplayManagerImpl
    {
        Bool    ended;

        X11DisplayUnique    x11DisplayUnique;
        ::Window            x11Window;

        std::thread     thread;
        ThreadJoiner    threadJoiner;
    };
}

#endif  // DPIMPL_LINUX_DISPLAY_DISPLAYMANAGER_H
