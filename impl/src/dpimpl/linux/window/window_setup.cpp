#include "dpimpl/linux/window/window_setup.h"
#include "dpimpl/linux/util/export.h"

DPCONSTRUCTOR void constructor(
)
{
    dp::initializeWindow_();
}
