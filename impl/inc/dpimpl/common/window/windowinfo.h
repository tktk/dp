#ifndef DPIMPL_COMMON_WINDOW_WINDOWINFO_H
#define DPIMPL_COMMON_WINDOW_WINDOWINFO_H

#include "dp/window/window.h"

namespace dp {
    struct WindowInfo
    {
        WindowClosingEventHandler   closingEventHandler;
        WindowPositionEventHandler  positionEventHandler;
        WindowSizeEventHandler      sizeEventHandler;
    };
}

#endif  // DPIMPL_COMMON_WINDOW_WINDOWINFO_H
