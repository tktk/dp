#ifndef DPIMPL_COMMON_AUDIO_AUDIOPLAYERINFO_H
#define DPIMPL_COMMON_AUDIO_AUDIOPLAYERINFO_H

#include "dp/audio/audioplayer.h"

namespace dp {
    struct AudioPlayerInfo
    {
        AudioPlayerStartEventHandler    startEventHandler;
        AudioPlayerEndEventHandler      endEventHandler;
        AudioPlayerPlayEventHandler     playEventHandler;
    };
}

#endif  // DPIMPL_COMMON_AUDIO_AUDIOPLAYERINFO_H
