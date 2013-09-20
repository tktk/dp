#ifndef DPIMPL_LINUX_AUDIO_AUDIO_SETUP_H
#define DPIMPL_LINUX_AUDIO_AUDIO_SETUP_H

#include "dpimpl/linux/audio/pulseaudio.h"

namespace dp {
    inline void initializeAudio(
    )
    {
        initializePulseAudio();
    }

    inline void finalizeAudio(
    )
    {
        finalizePulseAudio();
    }
}

#endif  // DPIMPL_LINUX_AUDIO_AUDIO_SETUP_H
