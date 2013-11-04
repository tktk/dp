#ifndef DP_DISPLAY_DISPLAYMANAGER_H
#define DP_DISPLAY_DISPLAYMANAGER_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/display/displaykey.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

#include <functional>

DPSTRUCT( dp, DisplayManager )

DPSTRUCT( dp, DisplayManagerInfo )

namespace dp {
    typedef std::function<
        void(
            DisplayManager &
            , DisplayKeyUnique &&
            , Bool
        )
    > DisplayManagerConnectEventHandler;

    DPEXPORT DisplayManager * newDisplayManager(
        const DisplayManagerInfo &
    );

    DPEXPORT DisplayManagerInfo * newDisplayManagerInfo(
    );

    DPEXPORT DisplayManagerInfo * clone(
        const DisplayManagerInfo &
    );

    DPEXPORT const DisplayManagerConnectEventHandler & getConnectEventHandler(
        const DisplayManagerInfo &
    );

    DPEXPORT void setConnectEventHandler(
        DisplayManagerInfo &
        , const DisplayManagerConnectEventHandler &
    );

    typedef Unique< DisplayManager >::type DisplayManagerUnique;

    typedef Shared< DisplayManager >::type DisplayManagerShared;

    typedef Weak< DisplayManager >::type DisplayManagerWeak;

    typedef Unique< DisplayManagerInfo >::type DisplayManagerInfoUnique;

    typedef Shared< DisplayManagerInfo >::type DisplayManagerInfoShared;

    typedef Weak< DisplayManagerInfo >::type DisplayManagerInfoWeak;
}

#endif  // DP_DISPLAY_DISPLAYMANAGER_H
