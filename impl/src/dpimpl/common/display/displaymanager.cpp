#include "dpimpl/util/export.h"
#include "dp/display/displaymanager.h"

#include "dpimpl/common/display/displaymanager.h"
#include "dpimpl/common/display/displaymanagerinfo.h"
#include "dp/display/displaykey.h"
#include "dp/common/primitives.h"

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
        implUnique.reset( new( std::nothrow )DisplayManagerImpl );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        if( initializeDisplayManagerImpl(
            manager
        ) == false ) {
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

    void callConnectEventHandler(
        DisplayManager &        _manager
        , DisplayKeyUnique &&   _keyUnique
        , Bool                  _connected
    )
    {
        const auto &    EVENT_HANDLER = _manager.infoUnique->connectEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _manager
                , std::move( _keyUnique )
                , _connected
            );
        }
    }

    void free(
        DisplayManagerImpl &    _impl
    )
    {
        delete &_impl;
    }
}
