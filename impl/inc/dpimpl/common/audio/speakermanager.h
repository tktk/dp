#ifndef DPIMPL_COMMON_AUDIO_SPEAKERMANAGER_H
#define DPIMPL_COMMON_AUDIO_SPEAKERMANAGER_H

#if defined LINUX   // OS
#include "dpimpl/linux/audio/speakermanager.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/audio/speakermanager.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#include "dp/audio/speakermanager.h"
#include "dp/audio/speakerkey.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"

namespace dp {
    void callConnectEventHandler(
        SpeakerManager &
        , SpeakerKeyUnique &&
        , Bool
    );

    struct SpeakerManagerImpl;

    Bool initializeSpeakerManagerImpl(
        SpeakerManager &
    );

    void free(
        SpeakerManagerImpl &
    );

    typedef Unique< SpeakerManagerImpl >::type SpeakerManagerImplUnique;

    struct SpeakerManager
    {
        SpeakerManagerInfoUnique    infoUnique;
        SpeakerManagerImplUnique    implUnique;
    };
}

#endif  // DPIMPL_COMMON_AUDIO_SPEAKERMANAGER_H
