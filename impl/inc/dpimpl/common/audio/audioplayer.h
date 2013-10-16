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

namespace dp {
    void callStartEventHandler(
        AudioPlayer &
    );

    void callEndEventHandler(
        AudioPlayer &
    );

    ULong callPlayEventHandler(
        AudioPlayer &
        , void *
        , ULong
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
        AudioPlayerImplUnique   implUnique;
    };
}

#endif  // DPIMPL_COMMON_AUDIO_AUDIOPLAYER_H
