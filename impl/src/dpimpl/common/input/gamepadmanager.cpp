#include "dpimpl/util/export.h"
#include "dp/input/gamepadmanager.h"

#include "dpimpl/common/input/gamepadmanager.h"
#include "dpimpl/common/input/gamepadmanagerinfo.h"
#include "dp/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <new>
#include <utility>

namespace dp {
    GamePadManager * newGamePadManager(
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
            clone(
                _INFO
            )
        );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  implUnique = manager.implUnique;
        implUnique.reset( new( std::nothrow )GamePadManagerImpl );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        if( initializeGamePadManagerImpl(
            manager
        ) == false ) {
            return nullptr;
        }

        return managerUnique.release();
    }

    void free(
        GamePadManager &  _manager
    )
    {
        delete &_manager;
    }

    void callConnectEventHandler(
        GamePadManager &        _manager
        , GamePadKeyUnique &&   _keyUnique
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
        GamePadManagerImpl &    _impl
    )
    {
        delete &_impl;
    }
}
