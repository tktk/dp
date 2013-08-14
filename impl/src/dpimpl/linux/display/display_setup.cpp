#include "dpimpl/linux/display/display_setup.h"
#include "dpimpl/linux/util/export.h"

DPCONSTRUCTOR void constructor(
)
{
    dp::initializeDisplay();
}

DPDESTRUCTOR void destructor(
)
{
    dp::finalizeDisplay();
}
