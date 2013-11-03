#ifndef DPIMPL_LINUX_AUDIO_PULSEAUDIO_H
#define DPIMPL_LINUX_AUDIO_PULSEAUDIO_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"

#include <pulse/context.h>
#include <pulse/stream.h>
#include <memory>

namespace dp {
    void initializePulseAudio(
    );

    void finalizePulseAudio(
    );

    struct PALock
    {
        PALock(
        );

        ~PALock(
        );
    };

    void paWait(
    );

    void paNotify(
    );

    typedef Unique< pa_context >::type PAContextUnique;

    pa_context * newPAContext(
    );

    struct DisconnectPAContext
    {
        void operator()(
            pa_context *
        ) const;
    };

    typedef std::unique_ptr<
        pa_context
        , DisconnectPAContext
    > PAContextDisconnector;

    pa_context * connect(
        pa_context &
    );

    void wait(
        pa_operation &
    );

    typedef Unique< pa_operation >::type PAOperationUnique;

    typedef Unique< pa_stream >::type PAStreamUnique;

    pa_stream * newPAStream(
        pa_context &
        , pa_sample_format_t
        , UInt
        , UByte
    );

    struct DisconnectPAStream
    {
        void operator()(
            pa_stream *
        ) const;
    };

    typedef std::unique_ptr<
        pa_stream
        , DisconnectPAStream
    > PAStreamDisconnector;

    pa_stream * connectPlayback(
        pa_stream &
        , pa_context &
        , UInt
    );

    Bool write(
        pa_stream &
        , void *
        , size_t
    );
}

#endif  // DPIMPL_LINUX_AUDIO_PULSEAUDIO_H
