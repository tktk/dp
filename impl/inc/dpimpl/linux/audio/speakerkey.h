#ifndef DPIMPL_LINUX_AUDIO_SPEAKERKEY_H
#define DPIMPL_LINUX_AUDIO_SPEAKERKEY_H

#include "dp/audio/speakerkey.h"
#include "dp/common/primitives.h"

namespace dp {
    struct SpeakerKey
    {
        UInt    index;
    };

    SpeakerKey * newSpeakerKey(
        UInt
    );
}

#endif  // DPIMPL_LINUX_AUDIO_SPEAKERKEY_H
