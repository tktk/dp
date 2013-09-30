#include "dpimpl/linux/xlib/xlib_setup.h"
#include "dpimpl/linux/util/export.h"

DPCONSTRUCTOR void constructor(
)
{
    dp::initializeXlib_();
}

DPDESTRUCTOR void destructor(
)
{
    dp::finalizeXlib_();
}
