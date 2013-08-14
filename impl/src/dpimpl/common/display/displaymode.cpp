#include "dpimpl/util/export.h"
#include "dp/display/displaymode.h"

#include "dpimpl/common/display/displaymode.h"
#include "dp/common/primitives.h"

namespace dp {
    void displayModeDelete(
        DisplayMode &   _mode
    )
    {
        delete &_mode;
    }

    ULong displayModeGetWidth(
        const DisplayMode & _MODE
    )
    {
        return _MODE.width;
    }

    ULong displayModeGetHeight(
        const DisplayMode & _MODE
    )
    {
        return _MODE.height;
    }

    Float displayModeGetRefreshRate(
        const DisplayMode & _MODE
    )
    {
        return _MODE.refreshRate;
    }
}
