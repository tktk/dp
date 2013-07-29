#include "dpimpl/linux/common/common.h"
#include "dpimpl/linux/util/export.h"

DPCONSTRUCTOR void constructor(
)
{
    dp::initializeCommon();
}

DPDESTRUCTOR void destructor(
)
{
    dp::finalizeCommon();
}
