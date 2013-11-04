#include "dp/util/export.h"
#include "dp/input/gamepadmanager.h"

#include "dpimpl/common/input/gamepadmanager.h"
#include "dpimpl/common/input/gamepadmanagerinfo.h"
#include "dp/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <new>
#include <utility>

template<>
void dpFree(
    const dp::GamePadManager &  _MANAGER
)
{
    delete &_MANAGER;
}

template<>
void dpFree(
    const dp::GamePadManagerImpl &  _IMPL
)
{
    delete &_IMPL;
}

namespace dp {
    GamePadManager * newGamePadManager(
        const GamePadManagerInfo &  _INFO
    )
    {
        auto    managerUnique = unique( new( std::nothrow )GamePadManager );
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
}
