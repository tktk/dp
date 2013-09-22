#ifndef DPIMPL_LINUX_AUDIO_SPEAKERMANAGER_H
#define DPIMPL_LINUX_AUDIO_SPEAKERMANAGER_H

#include "dpimpl/linux/audio/pulseaudio.h"

namespace dp {
    struct SpeakerManagerImpl
    {
        PAContextUnique         paContextUnique;
        PAContextDisconnector   paContextDisconnector;
    };
}

#endif  // DPIMPL_LINUX_AUDIO_SPEAKERMANAGER_H
