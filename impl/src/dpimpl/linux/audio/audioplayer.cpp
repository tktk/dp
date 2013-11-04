#include "dp/util/export.h"
#include "dp/audio/audioplayer.h"

#include "dpimpl/linux/audio/audioplayer.h"
#include "dpimpl/linux/audio/pulseaudio.h"
#include "dpimpl/common/audio/audioplayer.h"
#include "dpimpl/linux/audio/speakerkey.h"
#include "dp/audio/audioformat.h"
#include "dp/common/primitives.h"

#include <pulse/stream.h>
#include <pulse/sample.h>
#include <pulse/operation.h>
#include <thread>
#include <vector>

namespace {
    dp::PAContextUnique         paContextUnique;
    dp::PAContextDisconnector   paContextDisconnector;

    void paContextStateCallback(
        pa_context *
        , void *
    )
    {
        dp::paNotify();
    }

    pa_context * getPAContext(
    )
    {
        auto &  paContext = *paContextUnique;

        dp::PALock  lock;

        while( 1 ) {
            auto    state = pa_context_get_state( &paContext );
            switch( state ) {
            case PA_CONTEXT_CONNECTING:
            case PA_CONTEXT_AUTHORIZING:
            case PA_CONTEXT_SETTING_NAME:
                dp::paWait();
                break;

            case PA_CONTEXT_READY:
                return &paContext;
                break;

            default:
                return nullptr;
                break;
            }
        }
    }

    void paStreamWriteCallback(
        pa_stream * _paStream
        , size_t
        , void *
    )
    {
        dp::paNotify();
    }

    dp::Bool getWritableSize(
        size_t &            _writableSize
        , pa_stream &       _paStream
        , const dp::Bool &  _ENDED
    )
    {
        dp::PALock  lock;

        while( 1 ) {
            if( _ENDED ) {
                return false;
            }

            _writableSize = pa_stream_writable_size( &_paStream );
            if( _writableSize > 0 ) {
                break;
            }

            dp::paWait();
        }

        return true;
    }

    void play(
        dp::AudioPlayer &   _audioPlayer
    )
    {
        dp::callStartEventHandler(
            _audioPlayer
        );

        auto &  impl = *( _audioPlayer.implUnique );

        auto &  paStream = *( impl.paStreamUnique );

        const auto &    ENDED = impl.ended;

        std::vector< dp::Byte > buffer;

        while( 1 ) {
            size_t  bufferSize;
            if( getWritableSize(
                bufferSize
                , paStream
                , ENDED
            ) == false ) {
                break;
            }

            if( buffer.size() < bufferSize ) {
                buffer.resize( bufferSize );
            }

            auto    bufferPtr = buffer.data();

            const auto  WRITTEN_SIZE = dp::callPlayEventHandler(
                _audioPlayer
                , bufferPtr
                , bufferSize
            );
            if( WRITTEN_SIZE <= 0 ) {
                break;
            }

            if( dp::write(
                paStream
                , bufferPtr
                , WRITTEN_SIZE
            ) == false ) {
                break;
            }
        }

        dp::PAOperationUnique   paOperationUnique(
            pa_stream_drain(
                &paStream
                , nullptr
                , nullptr
            )
        );
        if( paOperationUnique.get() == nullptr ) {
            return;
        }

        auto &  paOperation = *paOperationUnique;

        dp::wait(
            paOperation
        );

        dp::callEndEventHandler(
            _audioPlayer
        );
    }

    void paStreamReady(
        dp::AudioPlayer &   _audioPlayer
    )
    {
        auto &  impl = *( _audioPlayer.implUnique );

        auto &  paStream = *( impl.paStreamUnique );

        pa_stream_set_write_callback(
            &paStream
            , paStreamWriteCallback
            , nullptr
        );

        impl.ended = false;

        auto &  thread = impl.thread;
        thread = std::move(
            std::thread(
                [
                    &_audioPlayer
                ]
                {
                    play(
                        _audioPlayer
                    );
                }
            )
        );
        impl.threadJoiner.reset( &thread );
        impl.threadExiter.reset( &impl );
    }

    void paStreamStateCallback(
        pa_stream * _paStream
        , void *    _audioPlayer
    )
    {
        auto &  audioPlayer = *static_cast< dp::AudioPlayer * >( _audioPlayer );

        switch( pa_stream_get_state( _paStream ) ) {
        case PA_STREAM_READY:
            paStreamReady(
                audioPlayer
            );
            break;

        default:
            break;
        }
    }

    dp::Bool toSampleFormat(
        pa_sample_format_t &    _sampleFormat
        , dp::AudioFormat       _audioFormat
    )
    {
        switch( _audioFormat ) {
        case dp::AudioFormat::U8:
            _sampleFormat = PA_SAMPLE_U8;
            break;

        case dp::AudioFormat::S16LE:
            _sampleFormat = PA_SAMPLE_S16LE;
            break;

        default:
            return false;
            break;
        }

        return true;
    }
}

namespace dp {
    void initializeAudioPlayer(
    )
    {
        paContextUnique.reset( newPAContext() );
        if( paContextUnique.get() == nullptr ) {
            //FIXME 初期化失敗時の処理
            return;
        }

        auto &  paContext = *paContextUnique;

        pa_context_set_state_callback(
            &paContext
            , paContextStateCallback
            , nullptr
        );

        paContextDisconnector.reset(
            connect(
                paContext
            )
        );
        if( paContextDisconnector.get() == nullptr ) {
            //FIXME 初期化失敗時の処理
            return;
        }
    }

    void finalizeAudioPlayer(
    )
    {
        auto    paContextUnique = std::move( ::paContextUnique );
        auto    paContextDisconnector = std::move( ::paContextDisconnector );
    }

    void pause(
        AudioPlayer &   _audioPlayer
        , Bool          _paused
    )
    {
        auto &  paStream = *( _audioPlayer.implUnique->paStreamUnique );

        const auto  PAUSED = _paused ? 1 : 0;

        PAOperationUnique   paOperationUnique(
            pa_stream_cork(
                &paStream
                , PAUSED
                , nullptr
                , nullptr
            )
        );
        if( paOperationUnique.get() == nullptr ) {
            return;
        }

        auto &  paOperation = *paOperationUnique;

        dp::wait(
            paOperation
        );
    }

    Bool initializeAudioPlayerImpl(
        AudioPlayer &           _audioPlayer
        , const SpeakerKey &    _KEY
        , AudioFormat           _audioFormat
        , UInt                  _sampleRate
        , UInt                  _channels
    )
    {
        pa_sample_format_t  sampleFormat;
        if( toSampleFormat(
            sampleFormat
            , _audioFormat
        ) == false ) {
            return false;
        }

        auto &  impl = *( _audioPlayer.implUnique );

        auto    paContextPtr = getPAContext();
        if( paContextPtr == nullptr ) {
            return false;
        }
        auto &  paContext = *paContextPtr;

        auto &  paStreamUnique = impl.paStreamUnique;
        paStreamUnique.reset(
            newPAStream(
                paContext
                , sampleFormat
                , _sampleRate
                , _channels
            )
        );
        if( paStreamUnique.get() == nullptr ) {
            return false;
        }

        auto &  paStream = *paStreamUnique;

        pa_stream_set_state_callback(
            &paStream
            , paStreamStateCallback
            , &_audioPlayer
        );

        auto &  paStreamDisconnector = impl.paStreamDisconnector;
        paStreamDisconnector.reset(
            connectPlayback(
                paStream
                , paContext
                , _KEY.index
            )
        );
        if( paStreamDisconnector.get() == nullptr ) {
            return false;
        }

        return true;
    }

    void AudioPlayerImpl::ExitThread::operator()(
        AudioPlayerImpl *   _impl
    ) const
    {
        PAOperationUnique   paOperationUnique(
            pa_stream_flush(
                _impl->paStreamUnique.get()
                , nullptr
                , nullptr
            )
        );

        dp::PALock  lock;

        _impl->ended = true;

        dp::paNotify();
    }
}
