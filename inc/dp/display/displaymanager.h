#ifndef DP_DISPLAY_DISPLAYMANAGER_H
#define DP_DISPLAY_DISPLAYMANAGER_H

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

    DPEXPORT DisplayManager * displayManagerNew(
        const DisplayManagerInfo &
    );

    DPEXPORT void displayManagerDelete(
        DisplayManager &
    );

    DPEXPORT const DisplayManagerInfo & displayManagerGetInfo(
        const DisplayManager &
    );

    DPEXPORT DisplayManagerInfo & displayManagerGetInfoMutable(
        DisplayManager &
    );

    DPEXPORT std::mutex & displayManagerGetMutexForConnectEventHandler(
        DisplayManager &
    );

    DPEXPORT DisplayManagerInfo * displayManagerInfoNew(
    );

    DPEXPORT DisplayManagerInfo * displayManagerInfoClone(
        const DisplayManagerInfo &
    );

    DPEXPORT void displayManagerInfoDelete(
        DisplayManagerInfo &
    );

    DPEXPORT const DisplayManagerConnectEventHandler & displayManagerInfoGetConnectEventHandler(
        const DisplayManagerInfo &
    );

    DPEXPORT void displayManagerInfoSetConnectEventHandler(
        DisplayManagerInfo &
        , const DisplayManagerConnectEventHandler &
    );

    struct DisplayManagerDelete
    {
        void operator()(
            DisplayManager *    _manager
        ) const
        {
            displayManagerDelete( *_manager );
        }
    };

    typedef std::unique_ptr<
        DisplayManager
        , DisplayManagerDelete
    > DisplayManagerUnique;

    typedef std::shared_ptr< DisplayManager > DisplayManagerShared;

    inline DisplayManagerShared displayManagerShared(
        DisplayManager &    _manager
    )
    {
        return DisplayManagerShared(
            &_manager
            , DisplayManagerDelete()
        );
    }

    typedef std::weak_ptr< DisplayManager > DisplayManagerWeak;

    struct DisplayManagerInfoDelete
    {
        void operator()(
            DisplayManagerInfo *    _info
        ) const
        {
            displayManagerInfoDelete( *_info );
        }
    };

    typedef std::unique_ptr<
        DisplayManagerInfo
        , DisplayManagerInfoDelete
    > DisplayManagerInfoUnique;

    typedef std::shared_ptr< DisplayManagerInfo > DisplayManagerInfoShared;

    inline DisplayManagerInfoShared displayManagerInfoShared(
        DisplayManagerInfo &    _info
    )
    {
        return DisplayManagerInfoShared(
            &_info
            , DisplayManagerInfoDelete()
        );
    }

    typedef std::weak_ptr< DisplayManagerInfo > DisplayManagerInfoWeak;
}

#endif  // DP_DISPLAY_DISPLAYMANAGER_H
