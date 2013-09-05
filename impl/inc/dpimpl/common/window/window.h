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
#include "dp/window/windowflags.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"

#include <mutex>

namespace dp {
    void callCloseEventHandler(
        Window &
    );

    void callPositionEventHandler(
        Window &
        , Long
        , Long
    );

    void callSizeEventHandler(
        Window &
        , ULong
        , ULong
    );

    void callBeginPaintEventHandler(
        Window &
    );

    void callEndPaintEventHandler(
        Window &
    );

    void callPaintEventHandler(
        Window &
        , ULong
        , ULong
        , ULong
        , ULong
    );

    struct WindowImpl;

    Bool initializeWindowImpl(
        Window &
        , const Utf32 &
        , ULong
        , ULong
        , WindowFlags
    );

    Bool initializeWindowImpl(
        Window &
        , const Utf32 &
        , Long
        , Long
        , ULong
        , ULong
        , WindowFlags
    );

    void free(
        WindowImpl &
    );

    typedef Unique< WindowImpl >::type WindowImplUnique;

    struct Window
    {
        WindowInfoUnique    infoUnique;
        std::mutex          mutexForCloseEventHandler;
        std::mutex          mutexForPositionEventHandler;
        std::mutex          mutexForSizeEventHandler;
        std::mutex          mutexForBeginPaintEventHandler;
        std::mutex          mutexForEndPaintEventHandler;
        std::mutex          mutexForPaintEventHandler;

        WindowImplUnique    implUnique;
    };
}

#endif  // DPIMPL_COMMON_WINDOW_WINDOW_H
