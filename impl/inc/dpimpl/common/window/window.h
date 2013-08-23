#ifndef DPIMPL_COMMON_WINDOW_WINDOW_H
#define DPIMPL_COMMON_WINDOW_WINDOW_H

#if defined LINUX   // OS
#include "dpimpl/linux/window/window.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/window/window.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#include "dp/window/window.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"

#include <mutex>

namespace dp {
    struct WindowImpl;

    WindowImpl * newWindowImpl(
        Window &
    );

    void free(
        WindowImpl &
    );

    typedef Unique< WindowImpl >::type WindowImplUnique;

    struct Window
    {
        WindowInfoUnique    infoUnique;

        WindowImplUnique    implUnique;
    };
}

#endif  // DPIMPL_COMMON_WINDOW_WINDOW_H
