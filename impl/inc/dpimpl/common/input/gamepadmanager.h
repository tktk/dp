#ifndef DPIMPL_COMMON_INPUT_GAMEPADMANAGER_H
#define DPIMPL_COMMON_INPUT_GAMEPADMANAGER_H

#if defined LINUX   // OS
#include "dpimpl/linux/input/gamepadmanager.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/input/gamepadmanager.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#include "dp/input/gamepadmanager.h"
#include "dpimpl/common/input/gamepadmanagerinfo.h"
#include "dp/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <memory>
#include <mutex>

namespace dp {
    void gamePadManagerCallConnectEventHandler(
        GamePadManager &
        , const GamePadKey &
        , Bool
    );

    struct GamePadManagerImpl;

    GamePadManagerImpl * gamePadManagerImplNew(
        GamePadManager &
    );

    void gamePadManagerImplDelete(
        GamePadManagerImpl &
    );

    struct GamePadManagerImplDeleter
    {
        void operator()(
            GamePadManagerImpl *    _impl
        )
        {
            gamePadManagerImplDelete( *_impl );
        }
    };

    typedef std::unique_ptr<
        GamePadManagerImpl
        , GamePadManagerImplDeleter
    > GamePadManagerImplPtr;

    struct GamePadManager
    {
        GamePadManagerInfoPtr   infoPtr;
        std::mutex              mutexForConnectEventHandler;

        GamePadManagerImplPtr   implPtr;
    };
}

#endif  // DPIMPL_COMMON_INPUT_GAMEPADMANAGER_H
