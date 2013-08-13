#include "dpimpl/util/export.h"
#include "dp/display/displaymodekey.h"

#include "dpimpl/common/display/displaymodekey.h"

namespace dp {
    void displayModeKeyDelete(
        DisplayModeKey &    _modeKey
    )
    {
        delete &_modeKey;
    }
}
