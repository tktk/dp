#ifndef DP_AUDIO_SPEAKERMANAGER_H
#define DP_AUDIO_SPEAKERMANAGER_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/audio/speakerkey.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

#include <functional>

DPSTRUCT( dp, SpeakerManager )

DPSTRUCT( dp, SpeakerManagerInfo )

namespace dp {
    typedef std::function<
        void(
            SpeakerManager &
            , SpeakerKeyUnique &&
            , Bool
        )
    > SpeakerManagerConnectEventHandler;

    DPEXPORT SpeakerManager * newSpeakerManager(
        const SpeakerManagerInfo &
    );

    DPEXPORT SpeakerManagerInfo * newSpeakerManagerInfo(
    );

    DPEXPORT SpeakerManagerInfo * clone(
        const SpeakerManagerInfo &
    );

    DPEXPORT const SpeakerManagerConnectEventHandler & getConnectEventHandler(
        const SpeakerManagerInfo &
    );

    DPEXPORT void setConnectEventHandler(
        SpeakerManagerInfo &
        , const SpeakerManagerConnectEventHandler &
    );

    typedef Unique< SpeakerManager >::type SpeakerManagerUnique;

    typedef Shared< SpeakerManager >::type SpeakerManagerShared;

    typedef Weak< SpeakerManager >::type SpeakerManagerWeak;

    typedef Unique< SpeakerManagerInfo >::type SpeakerManagerInfoUnique;

    typedef Shared< SpeakerManagerInfo >::type SpeakerManagerInfoShared;

    typedef Weak< SpeakerManagerInfo >::type SpeakerManagerInfoWeak;
}

#endif  // DP_AUDIO_SPEAKERMANAGER_H
