#ifndef DP_AUDIO_AUDIOPLAYER_H
#define DP_AUDIO_AUDIOPLAYER_H

#include "dp/audio/speakerkey.h"
#include "dp/audio/audioformat.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <mutex>
#include <functional>
#include <memory>

namespace dp {
    struct AudioPlayer;

    struct AudioPlayerInfo;

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

    DPEXPORT void free(
        AudioPlayer &
    );

    DPEXPORT const AudioPlayerInfo & getInfo(
        const AudioPlayer &
    );

    DPEXPORT AudioPlayerInfo & getInfoMutable(
        AudioPlayer &
    );

    DPEXPORT std::mutex & getMutexForStartEventHandler(
        AudioPlayer &
    );

    DPEXPORT std::mutex & getMutexForEndEventHandler(
        AudioPlayer &
    );

    DPEXPORT std::mutex & getMutexForPlayEventHandler(
        AudioPlayer &
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

    DPEXPORT void free(
        AudioPlayerInfo &
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

    typedef std::shared_ptr< AudioPlayer > AudioPlayerShared;

    typedef std::weak_ptr< AudioPlayer > AudioPlayerWeak;

    typedef Unique< AudioPlayerInfo >::type AudioPlayerInfoUnique;

    typedef std::shared_ptr< AudioPlayerInfo > AudioPlayerInfoShared;

    typedef std::weak_ptr< AudioPlayerInfo > AudioPlayerInfoWeak;
}

#endif  // DP_AUDIO_AUDIOPLAYER_H
