#include "dp/util/export.h"
#include "dp/display/displaymodekey.h"

#include "dpimpl/common/display/displaymodekey.h"

template<>
void dpFree(
    const dp::DisplayModeKey &  _KEY
)
{
    delete &_KEY;
}
