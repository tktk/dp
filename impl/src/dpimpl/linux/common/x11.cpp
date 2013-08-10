#include "dpimpl/linux/common/x11.h"

#include "dpimpl/linux/common/xlib.h"

namespace dp {
    void initializeX11(
    )
    {
        XInitThreads();
    }
}
