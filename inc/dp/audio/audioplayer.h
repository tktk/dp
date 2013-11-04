#ifndef DP_AUDIO_AUDIOPLAYER_H
#define DP_AUDIO_AUDIOPLAYER_H

#include "dp/audio/speakerkey.h"
#include "dp/audio/audioformat.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

#include <functional>

DPSTRUCT( dp, AudioPlayer )

DPSTRUCT( dp, AudioPlayerInfo )

namespace dp {
    typedef std::function<
        void(
            AudioPlayer &
        )
    > AudioPlayerStartEventHandler;

    typedef std::function<
        void(
            AudioPlayer &
        )
    > AudioPlayerEndEventHandler;

    typedef std::function<
        ULong(
            AudioPlayer &
            , void *
            , ULong
        )
    > AudioPlayerPlayEventHandler;

    DPEXPORT AudioPlayer * newAudioPlayer(
        const SpeakerKey &
        , const AudioPlayerInfo &
        , AudioFormat
        , UInt
        , UInt
    );

    DPEXPORT void pause(
        AudioPlayer &
        , Bool
    );

    DPEXPORT AudioPlayerInfo * newAudioPlayerInfo(
    );

    DPEXPORT AudioPlayerInfo * clone(
        const AudioPlayerInfo &
    );

    DPEXPORT const AudioPlayerStartEventHandler & getStartEventHandler(
        const AudioPlayerInfo &
    );

    DPEXPORT void setStartEventHandler(
        AudioPlayerInfo &
        , const AudioPlayerStartEventHandler &
    );

    DPEXPORT const AudioPlayerEndEventHandler & getEndEventHandler(
        const AudioPlayerInfo &
    );

    DPEXPORT void setEndEventHandler(
        AudioPlayerInfo &
        , const AudioPlayerEndEventHandler &
    );

    DPEXPORT const AudioPlayerPlayEventHandler & getPlayEventHandler(
        const AudioPlayerInfo &
    );

    DPEXPORT void setPlayEventHandler(
        AudioPlayerInfo &
        , const AudioPlayerPlayEventHandler &
    );

    typedef Unique< AudioPlayer >::type AudioPlayerUnique;

    typedef Shared< AudioPlayer >::type AudioPlayerShared;

    typedef Weak< AudioPlayer >::type AudioPlayerWeak;

    typedef Unique< AudioPlayerInfo >::type AudioPlayerInfoUnique;

    typedef Shared< AudioPlayerInfo >::type AudioPlayerInfoShared;

    typedef Weak< AudioPlayerInfo >::type AudioPlayerInfoWeak;
}

#endif  // DP_AUDIO_AUDIOPLAYER_H
