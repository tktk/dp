#include "dpimpl/linux/audio/pulseaudio.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"

#include <pulse/thread-mainloop.h>
#include <pulse/mainloop-api.h>
#include <pulse/context.h>
#include <pulse/operation.h>
#include <pulse/stream.h>
#include <pulse/introspect.h>
#include <utility>

template<>
void free(
    const pa_threaded_mainloop &    _MAINLOOP
)
{
    auto &  mainloop = const_cast< pa_threaded_mainloop & >( _MAINLOOP );

    pa_threaded_mainloop_stop( &mainloop );

    pa_threaded_mainloop_free( &mainloop );
}

template<>
void free(
    const pa_mainloop_api & _API
)
{
    auto &  api = const_cast< pa_mainloop_api & >( _API );

    api.quit(
        &api
        , 0
    );
}

template<>
void free(
    const pa_context &  _CONTEXT
)
{
    dp::PALock  lock;

    pa_context_unref( const_cast< pa_context * >( &_CONTEXT ) );
}

template<>
void free(
    const pa_operation &    _OPERATION
)
{
    pa_operation_unref( const_cast< pa_operation * >( &_OPERATION ) );
}

template<>
void free(
    const pa_stream &   _STREAM
)
{
    pa_stream_unref( const_cast< pa_stream * >( &_STREAM ) );
}

namespace {
    typedef dp::Unique< pa_threaded_mainloop >::type PAMainloopUnique;

    pa_threaded_mainloop * newPAMainloop(
    )
    {
        PAMainloopUnique    paMainloopUnique( pa_threaded_mainloop_new() );
        if( paMainloopUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  paMainloop = *paMainloopUnique;

        pa_threaded_mainloop_start( &paMainloop );

        return paMainloopUnique.release();
    }

    typedef dp::Unique< pa_mainloop_api >::type PAMainloopApiUnique;

    pa_mainloop_api * newPAMainloopApi(
        pa_threaded_mainloop &  _paMainloop
    )
    {
        return pa_threaded_mainloop_get_api( &_paMainloop );
    }

    PAMainloopUnique    paMainloopUnique;
    PAMainloopApiUnique paMainloopApiUnique;

    dp::Bool connect(
        pa_context &    _paContext
    )
    {
        dp::PALock  lock;

        return pa_context_connect(
            &_paContext
            , nullptr
            , PA_CONTEXT_NOFAIL
            , nullptr
        ) == 0;
    }

    void disconnect(
        pa_context &    _paContext
    )
    {
        dp::PALock  lock;

        pa_context_disconnect( &_paContext );
    }

    void getSinkNameCallback(
        pa_context *            _paContext
        , const pa_sink_info *  _INFO
        , dp::Int
        , void *                _name
    )
    {
        if( _INFO == nullptr ) {
            return;
        }

        auto &  name = *static_cast< dp::String * >( _name );

        name.assign( _INFO->name );
    }

    void paOperationStateCallback(
        pa_operation *  _paOperation
        , void *
    )
    {
        dp::paNotify();
    }

    dp::Bool getSinkName(
        dp::String &    _name
        , pa_context &  _paContext
        , dp::UInt      _index
    )
    {
        dp::PAOperationUnique   paOperationUnique(
            pa_context_get_sink_info_by_index(
                &_paContext
                , _index
                , getSinkNameCallback
                , &_name
            )
        );
        if( paOperationUnique.get() == nullptr ) {
            return false;
        }

        auto &  paOperation = *paOperationUnique;

        dp::wait(
            paOperation
        );

        return true;
    }
}

namespace dp {
    void initializePulseAudio(
    )
    {
        paMainloopUnique.reset( newPAMainloop() );
        if( paMainloopUnique.get() == nullptr ) {
            //FIXME 初期化失敗時の処理
            return;
        }

        auto &  paMainloop = *paMainloopUnique;

        paMainloopApiUnique.reset(
            newPAMainloopApi(
                paMainloop
            )
        );
        if( paMainloopApiUnique.get() == nullptr ) {
            //FIXME 初期化失敗時の処理
            return;
        }
    }

    void finalizePulseAudio(
    )
    {
        auto    paMainloopUnique = std::move( ::paMainloopUnique );
        auto    paMainloopApiUnique = std::move( ::paMainloopApiUnique );
    }

    PALock::PALock(
    )
    {
        auto &  paMainloop = *paMainloopUnique;

        pa_threaded_mainloop_lock( &paMainloop );
    }

    PALock::~PALock(
    )
    {
        auto &  paMainloop = *paMainloopUnique;

        pa_threaded_mainloop_unlock( &paMainloop );
    }

    void paWait(
    )
    {
        auto &  paMainloop = *paMainloopUnique;

        pa_threaded_mainloop_wait( &paMainloop );
    }

    void paNotify(
    )
    {
        auto &  paMainloop = *paMainloopUnique;

        pa_threaded_mainloop_signal(
            &paMainloop
            , 0
        );
    }

    pa_context * newPAContext(
    )
    {
        auto &  paMainloopApi = *paMainloopApiUnique;

        PALock  lock;

        return pa_context_new(
            &paMainloopApi
            , nullptr
        );
    }

    void DisconnectPAContext::operator()(
        pa_context *    _paContext
    ) const
    {
        ::disconnect(
            *_paContext
        );
    }

    pa_context * connect(
        pa_context &    _paContext
    )
    {
        if( ::connect(
            _paContext
        ) == false ) {
            return nullptr;
        }

        return &_paContext;
    }

    void wait(
        pa_operation &  _paOperation
    )
    {
        pa_operation_set_state_callback(
            &_paOperation
            , paOperationStateCallback
            , nullptr
        );

        dp::PALock  lock;

        while( pa_operation_get_state( &_paOperation ) == PA_OPERATION_RUNNING ) {
            dp::paWait();
        }
    }

    pa_stream * newPAStream(
        pa_context &            _paContext
        , pa_sample_format_t    _sampleFormat
        , UInt                  _sampleRate
        , UByte                 _channels
    )
    {
        pa_sample_spec  sampleSpec;
        sampleSpec.format = _sampleFormat;
        sampleSpec.rate = _sampleRate;
        sampleSpec.channels = _channels;

        return pa_stream_new(
            &_paContext
            , ""    //FIXME
            , &sampleSpec
            , nullptr
        );
    }

    void DisconnectPAStream::operator()(
        pa_stream * _paStream
    ) const
    {
        pa_stream_disconnect( _paStream );
    }

    pa_stream * connectPlayback(
        pa_stream &     _paStream
        , pa_context &  _paContext
        , UInt          _index
    )
    {
        String  name;
        if( getSinkName(
            name
            , _paContext
            , _index
        ) == false ) {
            return nullptr;
        }

        auto    paStream = &_paStream;

        if( pa_stream_connect_playback(
            paStream
            , name.c_str()
            , nullptr
            , PA_STREAM_START_CORKED
            , nullptr
            , nullptr
        ) != 0 ) {
            return nullptr;
        }

        return paStream;
    }

    Bool write(
        pa_stream & _paStream
        , void *    _data
        , size_t    _size
    )
    {
        PALock  lock;

        return pa_stream_write(
            &_paStream
            , _data
            , _size
            , nullptr
            , 0
            , PA_SEEK_RELATIVE
        ) == 0;
    }
}
