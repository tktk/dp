#include "dpimpl/util/export.h"
#include "dp/audio/audioplayer.h"

#include "dpimpl/common/audio/audioplayerinfo.h"

#include <new>

namespace {
    dp::AudioPlayerInfo * newAudioPlayerInfo(
        const dp::AudioPlayerPlayEventHandler &     _PLAY_EVENT_HANDLER
        , const dp::AudioPlayerEndEventHandler &    _END_EVENT_HANDLER
    )
    {
        dp::AudioPlayerInfoUnique   infoUnique( new( std::nothrow )dp::AudioPlayerInfo );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoUnique;

        info.playEventHandler = _PLAY_EVENT_HANDLER;
        info.endEventHandler = _END_EVENT_HANDLER;

        return infoUnique.release();
    }
}

namespace dp {
    AudioPlayerInfo * newAudioPlayerInfo(
    )
    {
        return ::newAudioPlayerInfo(
            nullptr
            , nullptr
        );
    }

    AudioPlayerInfo * clone(
        const AudioPlayerInfo & _OTHER
    )
    {
        return ::newAudioPlayerInfo(
            _OTHER.playEventHandler
            , _OTHER.endEventHandler
        );
    }

    void free(
        AudioPlayerInfo &   _info
    )
    {
        delete &_info;
    }

    const AudioPlayerPlayEventHandler & getPlayEventHandler(
        const AudioPlayerInfo & _INFO
    )
    {
        return _INFO.playEventHandler;
    }

    void setPlayEventHandler(
        AudioPlayerInfo &                       _info
        , const AudioPlayerPlayEventHandler &   _EVENT_HANDLER
    )
    {
        _info.playEventHandler = _EVENT_HANDLER;
    }

    const AudioPlayerEndEventHandler & getEndEventHandler(
        const AudioPlayerInfo & _INFO
    )
    {
        return _INFO.endEventHandler;
    }

    void setEndEventHandler(
        AudioPlayerInfo &                       _info
        , const AudioPlayerEndEventHandler &    _EVENT_HANDLER
    )
    {
        _info.endEventHandler = _EVENT_HANDLER;
    }
}
