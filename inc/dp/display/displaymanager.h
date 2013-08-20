#ifndef DP_DISPLAY_DISPLAYMANAGER_H
#define DP_DISPLAY_DISPLAYMANAGER_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/display/displaykey.h"
#include "dp/util/import.h"

#include <mutex>
#include <functional>
#include <memory>

namespace dp {
    struct DisplayManager;

    struct DisplayManagerInfo;

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

    DPEXPORT void free(
        DisplayManager &
    );

    DPEXPORT const DisplayManagerInfo & getInfo(
        const DisplayManager &
    );

    DPEXPORT DisplayManagerInfo & getInfoMutable(
        DisplayManager &
    );

    DPEXPORT std::mutex & getMutexForConnectEventHandler(
        DisplayManager &
    );

    DPEXPORT DisplayManagerInfo * newDisplayManagerInfo(
    );

    DPEXPORT DisplayManagerInfo * clone(
        const DisplayManagerInfo &
    );

    DPEXPORT void free(
        DisplayManagerInfo &
    );

    DPEXPORT const DisplayManagerConnectEventHandler & getConnectEventHandler(
        const DisplayManagerInfo &
    );

    DPEXPORT void setConnectEventHandler(
        DisplayManagerInfo &
        , const DisplayManagerConnectEventHandler &
    );

    typedef Unique< DisplayManager >::type DisplayManagerUnique;

    typedef std::shared_ptr< DisplayManager > DisplayManagerShared;

    typedef std::weak_ptr< DisplayManager > DisplayManagerWeak;

    typedef Unique< DisplayManagerInfo >::type DisplayManagerInfoUnique;

    typedef std::shared_ptr< DisplayManagerInfo > DisplayManagerInfoShared;

    typedef std::weak_ptr< DisplayManagerInfo > DisplayManagerInfoWeak;
}

#endif  // DP_DISPLAY_DISPLAYMANAGER_H
