#include "dp/util/export.h"
#include "dp/audio/speakerkey.h"

#include "dpimpl/common/audio/speakerkey.h"

template<>
void dpFree(
    const dp::SpeakerKey &  _KEY
)
{
    delete &_KEY;
}
