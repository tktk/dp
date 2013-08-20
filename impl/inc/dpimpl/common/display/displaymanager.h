﻿#ifndef DPIMPL_COMMON_DISPLAY_DISPLAYMANAGER_H
#define DPIMPL_COMMON_DISPLAY_DISPLAYMANAGER_H

#if defined LINUX   // OS
#include "dpimpl/linux/display/displaymanager.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/display/displaymanager.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#include "dp/display/displaymanager.h"
#include "dp/display/displaykey.h"
#include "dp/common/functional.h"
#include "dp/common/primitives.h"

#include <memory>
#include <mutex>

namespace dp {
    void callConnectEventHandler(
        DisplayManager &
        , DisplayKeyUnique &&
        , Bool
    );

    struct DisplayManagerImpl;

    DisplayManagerImpl * newDisplayManagerImpl(
        DisplayManager &
    );

    void free(
        DisplayManagerImpl &
    );

    typedef std::unique_ptr<
        DisplayManagerImpl
        , Free< DisplayManagerImpl >
    > DisplayManagerImplUnique;

    struct DisplayManager
    {
        DisplayManagerInfoUnique    infoUnique;
        std::mutex                  mutexForConnectEventHandler;

        DisplayManagerImplUnique    implUnique;
    };
}

#endif  // DPIMPL_COMMON_DISPLAY_DISPLAYMANAGER_H
