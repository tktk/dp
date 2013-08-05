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
            , GamePadKeyUnique &&
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
        ) const
        {
            gamePadManagerDelete( *_manager );
        }
    };

    typedef std::unique_ptr<
        GamePadManager
        , GamePadManagerDeleter
    > GamePadManagerUnique;

    typedef std::shared_ptr< GamePadManager > GamePadManagerShared;

    inline GamePadManagerShared gamePadManagerShared(
        GamePadManager &    _manager
    )
    {
        return GamePadManagerShared(
            &_manager
            , GamePadManagerDeleter()
        );
    }

    typedef std::weak_ptr< GamePadManager > GamePadManagerWeak;

    struct GamePadManagerInfoDeleter
    {
        void operator()(
            GamePadManagerInfo *    _info
        ) const
        {
            gamePadManagerInfoDelete( *_info );
        }
    };

    typedef std::unique_ptr<
        GamePadManagerInfo
        , GamePadManagerInfoDeleter
    > GamePadManagerInfoUnique;

    typedef std::shared_ptr< GamePadManagerInfo > GamePadManagerInfoShared;

    inline GamePadManagerInfoShared gamePadManagerInfoShared(
        GamePadManagerInfo &    _info
    )
    {
        return GamePadManagerInfoShared(
            &_info
            , GamePadManagerInfoDeleter()
        );
    }

    typedef std::weak_ptr< GamePadManagerInfo > GamePadManagerInfoWeak;
}

#endif  // DP_INPUT_GAMEPADMANAGER_H
