#ifndef DPIMPL_LINUX_DISPLAY_DISPLAYMANAGER_H
#define DPIMPL_LINUX_DISPLAY_DISPLAYMANAGER_H

#include "dp/common/primitives.h"
#include "dp/common/thread.h"

#include "dpimpl/linux/xlib/xlib.h"
#include <thread>
#include <memory>

namespace dp {
    struct DisplayManagerImpl
    {
    private:
        struct ExitThread
        {
            void operator()(
                DisplayManagerImpl *
            ) const;
        };

        typedef std::unique_ptr<
            DisplayManagerImpl
            , ExitThread
        > ThreadExiter;

    public:
        Bool    ended;

        XDisplayUnique  xDisplayUnique;
        ::Window        xWindow;

        std::thread     thread;
        ThreadJoiner    threadJoiner;
        ThreadExiter    threadExiter;
    };
}

#endif  // DPIMPL_LINUX_DISPLAY_DISPLAYMANAGER_H
