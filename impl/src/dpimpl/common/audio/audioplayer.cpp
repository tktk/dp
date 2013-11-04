#include "dp/util/export.h"
#include "dp/audio/audioplayer.h"

#include "dpimpl/common/audio/audioplayer.h"
#include "dpimpl/common/audio/audioplayerinfo.h"
#include "dp/audio/speakerkey.h"
#include "dp/audio/audioformat.h"
#include "dp/common/primitives.h"

#include <new>

template<>
void dpFree(
    const dp::AudioPlayer & _AUDIO_PLAYER
)
{
    delete &_AUDIO_PLAYER;
}

template<>
void dpFree(
    const dp::AudioPlayerImpl & _IMPL
)
{
    delete &_IMPL;
}

namespace dp {
    AudioPlayer * newAudioPlayer(
        const SpeakerKey &          _KEY
        , const AudioPlayerInfo &   _INFO
        , AudioFormat               _audioFormat
        , UInt                      _sampleRate
        , UInt                      _channels
    )
    {
        auto    audioPlayerUnique = unique( new( std::nothrow )AudioPlayer );
        if( audioPlayerUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  audioPlayer = *audioPlayerUnique;

        auto &  infoUnique = audioPlayer.infoUnique;
        infoUnique.reset(
            clone(
                _INFO
            )
        );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  implUnique = audioPlayer.implUnique;
        implUnique.reset( new( std::nothrow )AudioPlayerImpl );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        if( initializeAudioPlayerImpl(
            audioPlayer
            , _KEY
            , _audioFormat
            , _sampleRate
            , _channels
        ) == false ) {
            return nullptr;
        }

        return audioPlayerUnique.release();
    }

    void callStartEventHandler(
        AudioPlayer &   _audioPlayer
    )
    {
        const auto &    EVENT_HANDLER = _audioPlayer.infoUnique->startEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _audioPlayer
            );
        }
    }

    void callEndEventHandler(
        AudioPlayer &   _audioPlayer
    )
    {
        const auto &    EVENT_HANDLER = _audioPlayer.infoUnique->endEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _audioPlayer
            );
        }
    }

    ULong callPlayEventHandler(
        AudioPlayer &   _audioPlayer
        , void *        _buffer
        , ULong         _bufferSize
    )
    {
        const auto &    EVENT_HANDLER = _audioPlayer.infoUnique->playEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            return EVENT_HANDLER(
                _audioPlayer
                , _buffer
                , _bufferSize
            );
        } else {
            return 0;
        }
    }
}
