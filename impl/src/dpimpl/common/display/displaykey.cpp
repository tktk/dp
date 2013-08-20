#include "dpimpl/util/export.h"
#include "dp/display/displaykey.h"

#include "dpimpl/common/display/displaykey.h"

namespace dp {
    void free(
        DisplayKey &    _key
    )
    {
        delete &_key;
    }
}
