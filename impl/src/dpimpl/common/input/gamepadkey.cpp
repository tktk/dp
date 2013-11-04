#include "dp/util/export.h"
#include "dp/input/gamepadkey.h"

#include "dpimpl/common/input/gamepadkey.h"

template<>
void dpFree(
    const dp::GamePadKey &  _KEY
)
{
    delete &_KEY;
}
