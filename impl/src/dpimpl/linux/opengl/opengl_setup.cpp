#include "dpimpl/linux/opengl/opengl_setup.h"
#include "dpimpl/linux/util/export.h"

DPCONSTRUCTOR void constructor(
)
{
    dp::initializeOpenGL();
}

DPDESTRUCTOR void destructor(
)
{
    dp::finalizeOpenGL();
}
