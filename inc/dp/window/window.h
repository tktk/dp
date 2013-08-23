#ifndef DP_WINDOW_WINDOW_H
#define DP_WINDOW_WINDOW_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <mutex>
#include <memory>

namespace dp {
    struct Window;

    struct WindowInfo;

    DPEXPORT Window * newWindow(
        const WindowInfo &
        , const Utf32 &
        , ULong
        , ULong
    );

    //TODO 位置指定とかフラグ指定とか

    DPEXPORT void free(
        Window &
    );

    //TODO

    DPEXPORT WindowInfo * newWindowInfo(
    );

    DPEXPORT WindowInfo * clone(
        const WindowInfo &
    );

    DPEXPORT void free(
        WindowInfo &
    );

    //TODO

    typedef Unique< Window >::type WindowUnique;

    typedef std::shared_ptr< Window > WindowShared;

    typedef std::weak_ptr< Window > WindowWeak;

    typedef Unique< WindowInfo >::type WindowInfoUnique;

    typedef std::shared_ptr< WindowInfo > WindowInfoShared;

    typedef std::weak_ptr< WindowInfo > WindowInfoWeak;
}

#endif  // DP_WINDOW_WINDOW_H
