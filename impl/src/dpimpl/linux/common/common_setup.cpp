#include "dpimpl/linux/common/common_setup.h"
#include "dpimpl/linux/util/export.h"

DPCONSTRUCTOR void constructor(
)
{
    dp::initializeCommon();
}
