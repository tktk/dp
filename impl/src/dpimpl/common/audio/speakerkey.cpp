#include "dpimpl/util/export.h"
#include "dp/audio/speakerkey.h"

#include "dpimpl/common/audio/speakerkey.h"

namespace dp {
    void free(
        SpeakerKey &    _key
    )
    {
        delete &_key;
    }
}
