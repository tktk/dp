﻿#ifndef DPIMPL_COMMON_WINDOW_WINDOW_H
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
#include "dp/window/key.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/struct.h"

DPSTRUCT( dp, WindowImpl )

namespace dp {
    void callCloseEventHandler(
        Window &
    );

    void callPositionEventHandler(
        Window &
        , Int
        , Int
    );

    void callSizeEventHandler(
        Window &
        , Int
        , Int
    );

    void callBeginPaintEventHandler(
        Window &
    );

    void callEndPaintEventHandler(
        Window &
    );

    void callPaintEventHandler(
        Window &
        , Int
        , Int
        , Int
        , Int
    );

    void callKeyEventHandler(
        Window &
        , Key
        , const Utf32Char *
        , Bool
    );

    void callMouseButtonEventHandler(
        Window &
        , ULong
        , Bool
    );

    void callMouseMotionEventHandler(
        Window &
        , Int
        , Int
    );

    Bool initializeWindowImpl(
        Window &
        , const Utf32 &
        , Int
        , Int
        , WindowFlags
    );

    Bool initializeWindowImpl(
        Window &
        , const Utf32 &
        , Int
        , Int
        , Int
        , Int
        , WindowFlags
    );

    typedef Unique< WindowImpl >::type WindowImplUnique;

    struct Window
    {
        WindowInfoUnique    infoUnique;
        WindowImplUnique    implUnique;
    };
}

#endif  // DPIMPL_COMMON_WINDOW_WINDOW_H
