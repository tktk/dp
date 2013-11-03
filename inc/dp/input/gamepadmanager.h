#ifndef DP_INPUT_GAMEPADMANAGER_H
#define DP_INPUT_GAMEPADMANAGER_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/input/gamepadkey.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

#include <functional>
#include <memory>

DPSTRUCT( dp, GamePadManager )

DPSTRUCT( dp, GamePadManagerInfo )

namespace dp {
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

    DPEXPORT GamePadManagerInfo * newGamePadManagerInfo(
    );

    DPEXPORT GamePadManagerInfo * clone(
        const GamePadManagerInfo &
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
