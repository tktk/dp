#include "dpimpl/util/export.h"
#include "dp/display/displaymode.h"

#include "dpimpl/common/display/displaymode.h"
#include "dp/common/primitives.h"

namespace dp {
    void free(
        DisplayMode &   _mode
    )
    {
        delete &_mode;
    }

    ULong getWidth(
        const DisplayMode & _MODE
    )
    {
        return _MODE.width;
    }

    ULong getHeight(
        const DisplayMode & _MODE
    )
    {
        return _MODE.height;
    }

    Float getRefreshRate(
        const DisplayMode & _MODE
    )
    {
        return _MODE.refreshRate;
    }
}
