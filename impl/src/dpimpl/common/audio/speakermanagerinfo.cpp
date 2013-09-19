#include "dpimpl/util/export.h"
#include "dp/audio/speakermanager.h"

#include "dpimpl/common/audio/speakermanagerinfo.h"

#include <new>

namespace {
    dp::SpeakerManagerInfo * newSpeakerManagerInfo(
        const dp::SpeakerManagerConnectEventHandler &   _CONNECT_EVENT_HANDLER
    )
    {
        dp::SpeakerManagerInfoUnique    infoUnique( new( std::nothrow )dp::SpeakerManagerInfo );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoUnique;

        info.connectEventHandler = _CONNECT_EVENT_HANDLER;

        return infoUnique.release();
    }
}

namespace dp {
    SpeakerManagerInfo * newSpeakerManagerInfo(
    )
    {
        return ::newSpeakerManagerInfo(
            nullptr
        );
    }

    SpeakerManagerInfo * clone(
        const SpeakerManagerInfo &  _OTHER
    )
    {
        return ::newSpeakerManagerInfo(
            _OTHER.connectEventHandler
        );
    }

    void free(
        SpeakerManagerInfo &    _info
    )
    {
        delete &_info;
    }

    const SpeakerManagerConnectEventHandler & getConnectEventHandler(
        const SpeakerManagerInfo &  _INFO
    )
    {
        return _INFO.connectEventHandler;
    }

    void setConnectEventHandler(
        SpeakerManagerInfo &                        _info
        , const SpeakerManagerConnectEventHandler & _EVENT_HANDLER
    )
    {
        _info.connectEventHandler = _EVENT_HANDLER;
    }
}
