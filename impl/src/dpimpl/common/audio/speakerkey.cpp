#include "dpimpl/util/export.h"
#include "dp/audio/speakerkey.h"

#include "dpimpl/common/audio/speakerkey.h"

template<>
void free(
    const dp::SpeakerKey &  _KEY
)
{
    delete &_KEY;
}
