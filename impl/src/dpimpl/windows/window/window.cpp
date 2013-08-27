#include "dpimpl/windows/window/window.h"
#include "dp/window/window.h"
#include "dp/window/windowflags.h"
#include "dp/common/primitives.h"

namespace dp {
    WindowImpl * newWindowImpl(
        Window &        _window
        , const Utf32 & _TITLE
        , ULong         _width
        , ULong         _height
        , WindowFlags   _flags
    )
    {
        //TODO
        return nullptr;
    }

    void free(
        WindowImpl &    _impl
    )
    {
        //TODO
    }
}
