#ifndef DPIMPL_LINUX_WINDOW_WINDOW_H
#define DPIMPL_LINUX_WINDOW_WINDOW_H

#include "dp/common/thread.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include "dpimpl/linux/xlib/xlib.h"
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

            XFlush( &xDisplay );
        }
    };

    typedef std::unique_ptr<
        ::Window
        , DestroyXWindow
    > XWindowDestroyer;

    struct WindowImpl
    {
    private:
        struct ExitThread
        {
            void operator()(
                WindowImpl *
            ) const;
        };

        typedef std::unique_ptr<
            WindowImpl
            , ExitThread
        > ThreadExiter;

    public:
        Bool    ended;

        ::Window            xWindow;
        XWindowDestroyer    xWindowDestroyer;

        std::thread     thread;
        ThreadJoiner    threadJoiner;
        ThreadExiter    threadExiter;
    };

    DPEXPORT const ::Window & getXWindow(
        const Window &
    );
}

#endif  // DPIMPL_LINUX_WINDOW_WINDOW_H
