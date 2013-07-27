#ifndef DP_INPUT_GAMEPADMANAGER_H
#define DP_INPUT_GAMEPADMANAGER_H

#include "dp/common/primitives.h"
#include "dp/input/gamepadkey.h"
#include "dp/util/import.h"

#include <mutex>
#include <functional>
#include <memory>

namespace dp {
    struct GamePadManager;

    struct GamePadManagerInfo;

    typedef std::function<
        void(
            GamePadManager &
            , const GamePadKey &
            , Bool
        )
    > GamePadManagerConnectEventHandler;

    DPEXPORT GamePadManager * gamePadManagerNew(
        const GamePadManagerInfo &
    );

    DPEXPORT void gamePadManagerDelete(
        GamePadManager &
    );

    DPEXPORT const GamePadManagerInfo & gamePadManagerGetInfo(
        const GamePadManager &
    );

    DPEXPORT GamePadManagerInfo & gamePadManagerGetInfoMutable(
        GamePadManager &
    );

    DPEXPORT std::mutex & gamePadManagerGetMutexForConnectEventHandler(
        GamePadManager &
    );

    DPEXPORT GamePadManagerInfo * gamePadManagerInfoNew(
    );

    DPEXPORT GamePadManagerInfo * gamePadManagerInfoClone(
        const GamePadManagerInfo &
    );

    DPEXPORT void gamePadManagerInfoDelete(
        GamePadManagerInfo &
    );

    DPEXPORT void gamePadManagerInfoCopy(
        GamePadManagerInfo &
        , const GamePadManagerInfo &
    );

    DPEXPORT const GamePadManagerConnectEventHandler & gamePadManagerInfoGetConnectEventHandler(
        const GamePadManagerInfo &
    );

    DPEXPORT void gamePadManagerInfoSetConnectEventHandler(
        GamePadManagerInfo &
        , const GamePadManagerConnectEventHandler &
    );

    struct GamePadManagerDeleter
    {
        void operator()(
            GamePadManager *    _manager
        )
        {
            gamePadManagerDelete( *_manager );
        }
    };

    typedef std::unique_ptr<
        GamePadManager
        , GamePadManagerDeleter
    > GamePadManagerPtr;

    struct GamePadManagerInfoDeleter
    {
        void operator()(
            GamePadManagerInfo *    _info
        )
        {
            gamePadManagerInfoDelete( *_info );
        }
    };

    typedef std::unique_ptr<
        GamePadManagerInfo
        , GamePadManagerInfoDeleter
    > GamePadManagerInfoPtr;
}

#endif  // DP_INPUT_GAMEPADMANAGER_H
