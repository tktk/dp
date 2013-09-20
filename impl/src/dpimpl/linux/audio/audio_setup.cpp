#include "dpimpl/linux/audio/audio_setup.h"
#include "dpimpl/linux/util/export.h"

DPCONSTRUCTOR void constructor(
)
{
    dp::initializeAudio();
}

DPDESTRUCTOR void destructor(
)
{
    dp::finalizeAudio();
}
