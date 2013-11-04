#include "dpimpl/util/export.h"
#include "dp/audio/speakermanager.h"

#include "dpimpl/common/audio/speakermanager.h"
#include "dpimpl/common/audio/speakermanagerinfo.h"
#include "dp/audio/speakerkey.h"
#include "dp/common/primitives.h"

#include <new>
#include <utility>

template<>
void dpFree(
    const dp::SpeakerManager &  _MANAGER
)
{
    delete &_MANAGER;
}

template<>
void dpFree(
    const dp::SpeakerManagerImpl &  _IMPL
)
{
    delete &_IMPL;
}

namespace dp {
    SpeakerManager * newSpeakerManager(
        const SpeakerManagerInfo &  _INFO
    )
    {
        auto    managerUnique = unique( new( std::nothrow )SpeakerManager );
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
        implUnique.reset( new( std::nothrow )SpeakerManagerImpl );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        if( initializeSpeakerManagerImpl(
            manager
        ) == false ) {
            return nullptr;
        }

        return managerUnique.release();
    }

    void callConnectEventHandler(
        SpeakerManager &        _manager
        , SpeakerKeyUnique &&   _keyUnique
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
