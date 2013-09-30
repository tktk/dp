#ifndef DPIMPL_LINUX_AUDIO_AUDIOPLAYER_H
#define DPIMPL_LINUX_AUDIO_AUDIOPLAYER_H

#include "dpimpl/linux/audio/pulseaudio.h"
#include "dp/common/primitives.h"
#include "dp/common/thread.h"

#include <memory>
#include <thread>

namespace dp {
    void initializeAudioPlayer(
    );

    void finalizeAudioPlayer(
    );

    struct AudioPlayerImpl
    {
    private:
        struct ExitThread
        {
            void operator()(
                AudioPlayerImpl *
            ) const;
        };

        typedef std::unique_ptr<
            AudioPlayerImpl
            , ExitThread
        > ThreadExiter;

    public:
        PAStreamUnique          paStreamUnique;
        PAStreamDisconnector    paStreamDisconnector;

        Bool    ended;

        std::thread     thread;
        ThreadJoiner    threadJoiner;
        ThreadExiter    threadExiter;
    };
}

#endif  // DPIMPL_LINUX_AUDIO_AUDIOPLAYER_H
