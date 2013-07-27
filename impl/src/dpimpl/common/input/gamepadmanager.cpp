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
        GamePadManagerPtr   manager( new( std::nothrow )GamePadManager );
        if( manager.get() == nullptr ) {
            return nullptr;
        }

        GamePadManagerInfoPtr  info( gamePadManagerInfoClone( _INFO ) );
        if( info.get() == nullptr ) {
            return nullptr;
        }

        manager->info = std::move( info );

        GamePadManagerImplPtr   impl(
            gamePadManagerImplNew(
                *manager
            )
        );
        if( impl.get() == nullptr ) {
            return nullptr;
        }

        manager->impl = std::move( impl );

        return manager.release();
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
        return *( _MANAGER.info );
    }

    GamePadManagerInfo & gamePadManagerGetInfoMutable(
        GamePadManager &    _manager
    )
    {
        return *( _manager.info );
    }

    std::mutex & gamePadManagerGetMutexForConnectEventHandler(
        GamePadManager &    _manager
    )
    {
        return _manager.mutexForConnectEventHandler;
    }
}
