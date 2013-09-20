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
            pa_context *    _context
        ) const
        {
            pa_context_unref( _context );
        }
    };

    typedef std::unique_ptr<
        pa_context
        , FreePAContext
    > PAContextUnique;

    pa_context * newPAContext(
    );
}

#endif  // DPIMPL_LINUX_AUDIO_PULSEAUDIO_H
