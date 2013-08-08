#include "dpimpl/util/export.h"
#include "dp/display/displaymanager.h"

#include "dpimpl/common/display/displaymanager.h"
#include "dpimpl/common/display/displaymanagerinfo.h"
#include "dp/display/displaykey.h"
#include "dp/common/primitives.h"

#include <mutex>
#include <new>
#include <utility>

namespace dp {
    DisplayManager * displayManagerNew(
        const DisplayManagerInfo &  _INFO
    )
    {
        DisplayManagerUnique    managerUnique( new( std::nothrow )DisplayManager );
        if( managerUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  manager = *managerUnique;

        auto &  infoUnique = manager.infoUnique;
        infoUnique.reset(
            displayManagerInfoClone(
                _INFO
            )
        );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  implUnique = manager.implUnique;
        implUnique.reset(
            displayManagerImplNew(
                manager
            )
        );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        return managerUnique.release();
    }

    void displayManagerDelete(
        DisplayManager &    _manager
    )
    {
        delete &_manager;
    }

    const DisplayManagerInfo & displayManagerGetInfo(
        const DisplayManager &  _MANAGER
    )
    {
        return *( _MANAGER.infoUnique );
    }

    DisplayManagerInfo & displayManagerGetInfoMutable(
        DisplayManager &    _manager
    )
    {
        return *( _manager.infoUnique );
    }

    std::mutex & displayManagerGetMutexForConnectEventHandler(
        DisplayManager &    _manager
    )
    {
        return _manager.mutexForConnectEventHandler;
    }

    void displayManagerCallConnectEventHandler(
        DisplayManager &        _manager
        , DisplayKeyUnique &&   _keyUnique
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
