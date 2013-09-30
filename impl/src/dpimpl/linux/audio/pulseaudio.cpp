#include "dpimpl/linux/audio/pulseaudio.h"
#include "dp/common/primitives.h"

#include <pulse/thread-mainloop.h>
#include <pulse/mainloop-api.h>
#include <pulse/context.h>
#include <pulse/operation.h>
#include <pulse/stream.h>
#include <pulse/introspect.h>
#include <memory>

namespace {
    struct FreePAMainloop
    {
        void operator()(
            pa_threaded_mainloop *  _mainloop
        ) const
        {
            pa_threaded_mainloop_stop( _mainloop );

            pa_threaded_mainloop_free( _mainloop );
        }
    };

    typedef std::unique_ptr<
        pa_threaded_mainloop
        , FreePAMainloop
    > PAMainloopUnique;

    pa_threaded_mainloop * newPAMainloop(
    )
    {
        PAMainloopUnique    mainloopUnique( pa_threaded_mainloop_new() );
        if( mainloopUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  mainloop = *mainloopUnique;

        pa_threaded_mainloop_start( &mainloop );

        return mainloopUnique.release();
    }

    struct FreePAMainloopApi
    {
        void operator()(
            pa_mainloop_api *   _mainloopApi
        ) const
        {
            _mainloopApi->quit(
                _mainloopApi
                , 0
            );
        }
    };

    typedef std::unique_ptr<
        pa_mainloop_api
        , FreePAMainloopApi
    > PAMainloopApiUnique;

    pa_mainloop_api * newPAMainloopApi(
        pa_threaded_mainloop &  _mainloop
    )
    {
        return pa_threaded_mainloop_get_api( &_mainloop );
    }

    PAMainloopUnique    mainloopUnique;
    PAMainloopApiUnique mainloopApiUnique;

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
        mainloopUnique.reset( newPAMainloop() );
        if( mainloopUnique.get() == nullptr ) {
            //FIXME 初期化失敗時の処理
            return;
        }

        auto &  mainloop = *mainloopUnique;

        mainloopApiUnique.reset(
            newPAMainloopApi(
                mainloop
            )
        );
        if( mainloopApiUnique.get() == nullptr ) {
            //FIXME 初期化失敗時の処理
            return;
        }
    }

    void finalizePulseAudio(
    )
    {
        auto    mainloopUnique = std::move( ::mainloopUnique );
        auto    mainloopApiUnique = std::move( ::mainloopApiUnique );
    }

    PALock::PALock(
    )
    {
        auto &  mainloop = *mainloopUnique;

        pa_threaded_mainloop_lock( &mainloop );
    }

    PALock::~PALock(
    )
    {
        auto &  mainloop = *mainloopUnique;

        pa_threaded_mainloop_unlock( &mainloop );
    }

    void paWait(
    )
    {
        auto &  mainloop = *mainloopUnique;

        pa_threaded_mainloop_wait( &mainloop );
    }

    void paNotify(
    )
    {
        auto &  mainloop = *mainloopUnique;

        pa_threaded_mainloop_signal(
            &mainloop
            , 0
        );
    }

    void FreePAContext::operator()(
        pa_context *    _paContext
    ) const
    {
        PALock  lock;

        pa_context_unref( _paContext );
    }

    pa_context * newPAContext(
    )
    {
        auto &  mainloopApi = *mainloopApiUnique;

        PALock  lock;

        return pa_context_new(
            &mainloopApi
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

    void FreePAOperation::operator()(
        pa_operation *  _paOperation
    ) const
    {
        pa_operation_unref( _paOperation );
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

    void FreePAStream::operator()(
        pa_stream * _paStream
    ) const
    {
        pa_stream_unref( _paStream );
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

    void DissconnectPAStream::operator()(
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
            , PA_STREAM_NOFLAGS
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
