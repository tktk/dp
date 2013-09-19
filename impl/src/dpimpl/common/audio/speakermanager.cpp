#include "dpimpl/util/export.h"
#include "dp/audio/speakermanager.h"

#include "dpimpl/common/audio/speakermanager.h"
#include "dpimpl/common/audio/speakermanagerinfo.h"
#include "dp/audio/speakerkey.h"
#include "dp/common/primitives.h"

#include <mutex>
#include <new>
#include <utility>

namespace dp {
    SpeakerManager * newSpeakerManager(
        const SpeakerManagerInfo &  _INFO
    )
    {
        SpeakerManagerUnique    managerUnique( new( std::nothrow )SpeakerManager );
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

    void free(
        SpeakerManager &    _manager
    )
    {
        delete &_manager;
    }

    const SpeakerManagerInfo & getInfo(
        const SpeakerManager &  _MANAGER
    )
    {
        return *( _MANAGER.infoUnique );
    }

    SpeakerManagerInfo & getInfoMutable(
        SpeakerManager &    _manager
    )
    {
        return *( _manager.infoUnique );
    }

    std::mutex & getMutexForConnectEventHandler(
        SpeakerManager &    _manager
    )
    {
        return _manager.mutexForConnectEventHandler;
    }

    void callConnectEventHandler(
        SpeakerManager &        _manager
        , SpeakerKeyUnique &&   _keyUnique
        , Bool                  _connected
    )
    {
        std::unique_lock< decltype( _manager.mutexForConnectEventHandler ) >    lock( _manager.mutexForConnectEventHandler );

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
        SpeakerManagerImpl &    _impl
    )
    {
        delete &_impl;
    }
}
