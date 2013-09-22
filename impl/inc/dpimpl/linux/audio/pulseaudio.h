#ifndef DPIMPL_LINUX_AUDIO_PULSEAUDIO_H
#define DPIMPL_LINUX_AUDIO_PULSEAUDIO_H

#include <pulse/context.h>
#include <memory>

namespace dp {
    void initializePulseAudio(
    );

    void finalizePulseAudio(
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
        pa_context &    _paContext
    );
}

#endif  // DPIMPL_LINUX_AUDIO_PULSEAUDIO_H
