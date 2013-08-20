#ifndef DP_INPUT_GAMEPADMANAGER_H
#define DP_INPUT_GAMEPADMANAGER_H

#include "dp/common/memory.h"
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

    DPEXPORT GamePadManager * newGamePadManager(
        const GamePadManagerInfo &
    );

    DPEXPORT void free(
        GamePadManager &
    );

    DPEXPORT const GamePadManagerInfo & getInfo(
        const GamePadManager &
    );

    DPEXPORT GamePadManagerInfo & getInfoMutable(
        GamePadManager &
    );

    DPEXPORT std::mutex & getMutexForConnectEventHandler(
        GamePadManager &
    );

    DPEXPORT GamePadManagerInfo * newGamePadManagerInfo(
    );

    DPEXPORT GamePadManagerInfo * clone(
        const GamePadManagerInfo &
    );

    DPEXPORT void free(
        GamePadManagerInfo &
    );

    DPEXPORT const GamePadManagerConnectEventHandler & getConnectEventHandler(
        const GamePadManagerInfo &
    );

    DPEXPORT void setConnectEventHandler(
        GamePadManagerInfo &
        , const GamePadManagerConnectEventHandler &
    );

    typedef Unique< GamePadManager >::type GamePadManagerUnique;

    typedef std::shared_ptr< GamePadManager > GamePadManagerShared;

    typedef std::weak_ptr< GamePadManager > GamePadManagerWeak;

    typedef Unique< GamePadManagerInfo >::type GamePadManagerInfoUnique;

    typedef std::shared_ptr< GamePadManagerInfo > GamePadManagerInfoShared;

    typedef std::weak_ptr< GamePadManagerInfo > GamePadManagerInfoWeak;
}

#endif  // DP_INPUT_GAMEPADMANAGER_H
