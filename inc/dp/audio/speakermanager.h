#ifndef DP_AUDIO_SPEAKERMANAGER_H
#define DP_AUDIO_SPEAKERMANAGER_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/audio/speakerkey.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

#include <functional>
#include <memory>

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

    typedef std::shared_ptr< SpeakerManager > SpeakerManagerShared;

    typedef std::weak_ptr< SpeakerManager > SpeakerManagerWeak;

    typedef Unique< SpeakerManagerInfo >::type SpeakerManagerInfoUnique;

    typedef std::shared_ptr< SpeakerManagerInfo > SpeakerManagerInfoShared;

    typedef std::weak_ptr< SpeakerManagerInfo > SpeakerManagerInfoWeak;
}

#endif  // DP_AUDIO_SPEAKERMANAGER_H
