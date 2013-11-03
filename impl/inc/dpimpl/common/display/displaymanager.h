#ifndef DPIMPL_COMMON_DISPLAY_DISPLAYMANAGER_H
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
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/struct.h"

DPSTRUCT( dp, DisplayManagerImpl )

namespace dp {
    void callConnectEventHandler(
        DisplayManager &
        , DisplayKeyUnique &&
        , Bool
    );

    Bool initializeDisplayManagerImpl(
        DisplayManager &
    );

    typedef Unique< DisplayManagerImpl >::type DisplayManagerImplUnique;

    struct DisplayManager
    {
        DisplayManagerInfoUnique    infoUnique;
        DisplayManagerImplUnique    implUnique;
    };
}

#endif  // DPIMPL_COMMON_DISPLAY_DISPLAYMANAGER_H
