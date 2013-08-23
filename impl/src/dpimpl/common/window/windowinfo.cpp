#include "dpimpl/util/export.h"
#include "dp/window/window.h"

namespace {
    dp::WindowInfo * newWindowInfo(
    )
    {
        //TODO
        return nullptr;
    }
}

namespace dp {
    WindowInfo * newWindowInfo(
    )
    {
        return ::newWindowInfo(
        );
    }

    WindowInfo * clone(
        const WindowInfo &
    )
    {
        return ::newWindowInfo(
        );
    }

    void free(
        WindowInfo &
    )
    {
        //TODO
    }
}
