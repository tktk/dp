#include "dpimpl/util/export.h"
#include "dp/input/gamepadmanager.h"

#include "dpimpl/common/input/gamepadmanager.h"
#include "dp/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <mutex>
#include <new>

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

        auto &  infoPtr = manager.infoPtr;
        infoPtr.reset(
            gamePadManagerInfoClone(
                _INFO
            )
        );
        if( infoPtr.get() == nullptr ) {
            return nullptr;
        }

        auto &  implPtr = manager.implPtr;
        implPtr.reset(
            gamePadManagerImplNew(
                manager
            )
        );
        if( implPtr.get() == nullptr ) {
            return nullptr;
        }

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

    void gamePadManagerCallConnectEventHandler(
        GamePadManager &        _manager
        , const GamePadKey &    _KEY
        , Bool                  _connected
    )
    {
        std::unique_lock< decltype( _manager.mutexForConnectEventHandler ) > lock( _manager.mutexForConnectEventHandler );

        const auto &    EVENT_HANDLER = _manager.infoPtr->connectEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _manager
                , _KEY
                , _connected
            );
        }
    }
}
