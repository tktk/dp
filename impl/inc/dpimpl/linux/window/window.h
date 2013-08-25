#ifndef DPIMPL_LINUX_WINDOW_WINDOW_H
#define DPIMPL_LINUX_WINDOW_WINDOW_H

#include "dpimpl/linux/common/xlib.h"
#include "dp/common/thread.h"
#include "dp/common/primitives.h"

#include <memory>
#include <thread>

namespace dp {
    void initializeWindow(
    );

    struct DestroyXWindow
    {
        void operator()(
            ::Window *  _window
        )
        {
            auto &  xDisplay = getXDisplay();

            XDestroyWindow(
                &xDisplay
                , *_window
            );
        }
    };

    typedef std::unique_ptr<
        ::Window
        , DestroyXWindow
    > XWindowDestroyer;

    struct WindowImpl
    {
        Bool    ended;

        ::Window            xWindow;
        XWindowDestroyer    xWindowDestroyer;

        std::thread     thread;
        ThreadJoiner    threadJoiner;
    };
}

#endif  // DPIMPL_LINUX_WINDOW_WINDOW_H
