#ifndef DPIMPL_LINUX_AUDIO_AUDIO_SETUP_H
#define DPIMPL_LINUX_AUDIO_AUDIO_SETUP_H

#include "dpimpl/linux/audio/pulseaudio.h"
#include "dpimpl/linux/audio/audioplayer.h"

namespace dp {
    inline void initializeAudio(
    )
    {
        initializePulseAudio();
        initializeAudioPlayer();
    }

    inline void finalizeAudio(
    )
    {
        finalizeAudioPlayer();
        finalizePulseAudio();
    }
}

#endif  // DPIMPL_LINUX_AUDIO_AUDIO_SETUP_H
