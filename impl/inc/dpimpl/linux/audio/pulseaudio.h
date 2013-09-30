#ifndef DPIMPL_LINUX_AUDIO_PULSEAUDIO_H
#define DPIMPL_LINUX_AUDIO_PULSEAUDIO_H

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

    struct FreePAContext
    {
        void operator()(
            pa_context *
        ) const;
    };

    typedef std::unique_ptr<
        pa_context
        , FreePAContext
    > PAContextUnique;

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

    struct FreePAOperation
    {
        void operator()(
            pa_operation *
        ) const;
    };

    void wait(
        pa_operation &
    );

    typedef std::unique_ptr<
        pa_operation
        , FreePAOperation
    > PAOperationUnique;

    struct FreePAStream
    {
        void operator()(
            pa_stream *
        ) const;
    };

    typedef std::unique_ptr<
        pa_stream
        , FreePAStream
    > PAStreamUnique;

    pa_stream * newPAStream(
        pa_context &
        , pa_sample_format_t
        , UInt
        , UByte
    );

    struct DissconnectPAStream
    {
        void operator()(
            pa_stream *
        ) const;
    };

    typedef std::unique_ptr<
        pa_stream
        , DissconnectPAStream
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
