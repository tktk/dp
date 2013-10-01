﻿#include "dpimpl/util/export.h"
#include "dp/audio/audioplayer.h"

#include "dpimpl/common/audio/audioplayer.h"
#include "dpimpl/common/audio/audioplayerinfo.h"
#include "dp/audio/speakerkey.h"
#include "dp/audio/audioformat.h"
#include "dp/common/primitives.h"

#include <new>

namespace dp {
    AudioPlayer * newAudioPlayer(
        const SpeakerKey &          _KEY
        , const AudioPlayerInfo &   _INFO
        , AudioFormat               _audioFormat
        , UInt                      _sampleRate
        , UInt                      _channels
    )
    {
        AudioPlayerUnique   audioPlayerUnique( new( std::nothrow )AudioPlayer );
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

    void free(
        AudioPlayer &   _audioPlayer
    )
    {
        delete &_audioPlayer;
    }

    const AudioPlayerInfo & getInfo(
        const AudioPlayer & _AUDIO_PLAYER
    )
    {
        return *( _AUDIO_PLAYER.infoUnique );
    }

    AudioPlayerInfo & getInfoMutable(
        AudioPlayer &   _audioPlayer
    )
    {
        return *( _audioPlayer.infoUnique );
    }

    std::mutex & getMutexForPlayEventHandler(
        AudioPlayer &   _audioPlayer
    )
    {
        return _audioPlayer.mutexForPlayEventHandler;
    }

    std::mutex & getMutexForEndEventHandler(
        AudioPlayer &   _audioPlayer
    )
    {
        return _audioPlayer.mutexForEndEventHandler;
    }

    ULong callPlayEventHandler(
        AudioPlayer &   _audioPlayer
        , void *        _buffer
        , ULong         _bufferSize
    )
    {
        std::unique_lock< decltype( _audioPlayer.mutexForPlayEventHandler ) >   lock( _audioPlayer.mutexForPlayEventHandler );

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

    void callEndEventHandler(
        AudioPlayer &   _audioPlayer
    )
    {
        std::unique_lock< decltype( _audioPlayer.mutexForEndEventHandler ) >    lock( _audioPlayer.mutexForEndEventHandler );

        const auto &    EVENT_HANDLER = _audioPlayer.infoUnique->endEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _audioPlayer
            );
        }
    }

    void free(
        AudioPlayerImpl &   _impl
    )
    {
        delete &_impl;
    }
}