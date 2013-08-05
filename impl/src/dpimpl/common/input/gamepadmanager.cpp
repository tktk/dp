#include "dpimpl/util/export.h"
#include "dp/input/gamepadmanager.h"

#include "dpimpl/common/input/gamepadmanager.h"
#include "dp/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <mutex>
#include <new>
#include <utility>

namespace dp {
    GamePadManager * gamePadManagerNew(
        const GamePadManagerInfo &  _INFO
    )
    {
        GamePadManagerUnique    managerUnique( new( std::nothrow )GamePadManager );
        if( managerUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  manager = *managerUnique;

        auto &  infoUnique = manager.infoUnique;
        infoUnique.reset(
            gamePadManagerInfoClone(
                _INFO
            )
        );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  implUnique = manager.implUnique;
        implUnique.reset(
            gamePadManagerImplNew(
                manager
            )
        );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        return managerUnique.release();
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
        return *( _MANAGER.infoUnique );
    }

    GamePadManagerInfo & gamePadManagerGetInfoMutable(
        GamePadManager &    _manager
    )
    {
        return *( _manager.infoUnique );
    }

    std::mutex & gamePadManagerGetMutexForConnectEventHandler(
        GamePadManager &    _manager
    )
    {
        return _manager.mutexForConnectEventHandler;
    }

    void gamePadManagerCallConnectEventHandler(
        GamePadManager &        _manager
        , GamePadKeyUnique &&   _keyUnique
        , Bool                  _connected
    )
    {
        std::unique_lock< decltype( _manager.mutexForConnectEventHandler ) > lock( _manager.mutexForConnectEventHandler );

        const auto &    EVENT_HANDLER = _manager.infoUnique->connectEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _manager
                , std::move( _keyUnique )
                , _connected
            );
        }
    }
}
