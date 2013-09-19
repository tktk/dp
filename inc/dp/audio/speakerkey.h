#ifndef DP_AUDIO_SPEAKERKEY_H
#define DP_AUDIO_SPEAKERKEY_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <memory>

namespace dp {
    struct SpeakerKey;

    DPEXPORT SpeakerKey * clone(
        const SpeakerKey &
    );

    DPEXPORT void free(
        SpeakerKey &
    );

    DPEXPORT Bool equals(
        const SpeakerKey &
        , const SpeakerKey &
    );

    DPEXPORT Bool less(
        const SpeakerKey &
        , const SpeakerKey &
    );

    typedef Unique< SpeakerKey >::type SpeakerKeyUnique;

    typedef std::shared_ptr< SpeakerKey > SpeakerKeyShared;

    typedef std::weak_ptr< SpeakerKey > SpeakerKeyWeak;
}

#endif  // DP_AUDIO_SPEAKERKEY_H
