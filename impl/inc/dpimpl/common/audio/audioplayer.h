#ifndef DPIMPL_COMMON_AUDIO_AUDIOPLAYER_H
#define DPIMPL_COMMON_AUDIO_AUDIOPLAYER_H

#if defined LINUX   // OS
#include "dpimpl/linux/audio/audioplayer.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/audio/audioplayer.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#include "dp/audio/speakerkey.h"
#include "dp/audio/audioformat.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"

#include <mutex>

namespace dp {
    void callPlayEventHandler(
        AudioPlayer &
        , void *
        , ULong
    );

    void callEndEventHandler(
        AudioPlayer &
    );

    struct AudioPlayerImpl;

    Bool initializeAudioPlayerImpl(
        AudioPlayer &
        , const SpeakerKey &
        , AudioFormat
        , UInt
        , UInt
    );

    void free(
        AudioPlayerImpl &
    );

    typedef Unique< AudioPlayerImpl >::type AudioPlayerImplUnique;

    struct AudioPlayer
    {
        AudioPlayerInfoUnique   infoUnique;
        std::mutex              mutexForPlayEventHandler;
        std::mutex              mutexForEndEventHandler;

        AudioPlayerImplUnique   implUnique;
    };
}

#endif  // DPIMPL_COMMON_AUDIO_AUDIOPLAYER_H
