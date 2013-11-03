#include "dpimpl/util/export.h"
#include "dp/input/gamepadkey.h"

#include "dpimpl/common/input/gamepadkey.h"

template<>
void free(
    const dp::GamePadKey &  _KEY
)
{
    delete &_KEY;
}
