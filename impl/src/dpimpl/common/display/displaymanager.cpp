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
    DisplayManager * newDisplayManager(
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
            clone(
                _INFO
            )
        );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  implUnique = manager.implUnique;
        implUnique.reset(
            newDisplayManagerImpl(
                manager
            )
        );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        return managerUnique.release();
    }

    void free(
        DisplayManager &    _manager
    )
    {
        delete &_manager;
    }

    const DisplayManagerInfo & getInfo(
        const DisplayManager &  _MANAGER
    )
    {
        return *( _MANAGER.infoUnique );
    }

    DisplayManagerInfo & getInfoMutable(
        DisplayManager &    _manager
    )
    {
        return *( _manager.infoUnique );
    }

    std::mutex & getMutexForConnectEventHandler(
        DisplayManager &    _manager
    )
    {
        return _manager.mutexForConnectEventHandler;
    }

    void callConnectEventHandler(
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
