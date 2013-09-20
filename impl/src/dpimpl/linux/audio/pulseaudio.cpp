#include "dpimpl/linux/audio/pulseaudio.h"

#include <pulse/thread-mainloop.h>
#include <pulse/mainloop-api.h>
#include <pulse/context.h>
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

    pa_context * newPAContext(
    )
    {
        auto &  mainloopApi = *mainloopApiUnique;

        return pa_context_new(
            &mainloopApi
            , nullptr
        );
    }
}
