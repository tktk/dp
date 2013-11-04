#include "dpimpl/util/export.h"
#include "dp/display/displaymode.h"

#include "dpimpl/common/display/displaymode.h"
#include "dp/common/primitives.h"

template<>
void dpFree(
    const dp::DisplayMode & _MODE
)
{
    delete &_MODE;
}

namespace dp {
    Int getWidth(
        const DisplayMode & _MODE
    )
    {
        return _MODE.width;
    }

    Int getHeight(
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
