#ifndef DPIMPL_COMMON_WINDOW_WINDOWINFO_H
#define DPIMPL_COMMON_WINDOW_WINDOWINFO_H

#include "dp/window/window.h"

namespace dp {
    struct WindowInfo
    {
        WindowCloseEventHandler         closeEventHandler;
        WindowPositionEventHandler      positionEventHandler;
        WindowSizeEventHandler          sizeEventHandler;
        WindowBeginPaintEventHandler    beginPaintEventHandler;
        WindowEndPaintEventHandler      endPaintEventHandler;
        WindowPaintEventHandler         paintEventHandler;
        WindowKeyEventHandler           keyEventHandler;
        WindowMouseButtonEventHandler   mouseButtonEventHandler;
        WindowMouseMotionEventHandler   mouseMotionEventHandler;
    };
}

#endif  // DPIMPL_COMMON_WINDOW_WINDOWINFO_H
