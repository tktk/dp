#include "dpimpl/util/export.h"
#include "dp/input/gamepadkey.h"

#include "dpimpl/common/input/gamepadkey.h"

namespace dp {
    void free(
        GamePadKey &    _key
    )
    {
        delete &_key;
    }
}
