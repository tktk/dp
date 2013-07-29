#include "dpimpl/util/export.h"
#include "dp/input/gamepadmanager.h"

#include "dpimpl/common/input/gamepadmanager.h"
#include "dp/common/primitives.h"

#include <mutex>
#include <new>
#include <utility>

namespace dp {
    GamePadManager * gamePadManagerNew(
        const GamePadManagerInfo &  _INFO
    )
    {
        GamePadManagerPtr   managerPtr( new( std::nothrow )GamePadManager );
        if( managerPtr.get() == nullptr ) {
            return nullptr;
        }

        auto &  manager = *managerPtr;

        GamePadManagerInfoPtr  infoPtr( gamePadManagerInfoClone( _INFO ) );
        if( infoPtr.get() == nullptr ) {
            return nullptr;
        }

        manager.infoPtr = std::move( infoPtr );

        GamePadManagerImplPtr   implPtr(
            gamePadManagerImplNew(
                manager
            )
        );
        if( implPtr.get() == nullptr ) {
            return nullptr;
        }

        manager.implPtr = std::move( implPtr );

        return managerPtr.release();
    }

    void gamePadManagerDelete(
        GamePadManager &  _manager
    )
    {
        delete &_manager;
    }

    const GamePadManagerInfo & gamePadManagerGetInfo(
        const GamePadManager &  _MANAGER
    )
    {
        return *( _MANAGER.infoPtr );
    }

    GamePadManagerInfo & gamePadManagerGetInfoMutable(
        GamePadManager &    _manager
    )
    {
        return *( _manager.infoPtr );
    }

    std::mutex & gamePadManagerGetMutexForConnectEventHandler(
        GamePadManager &    _manager
    )
    {
        return _manager.mutexForConnectEventHandler;
    }
}
