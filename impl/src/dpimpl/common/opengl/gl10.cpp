#include "dpimpl/util/export.h"
#include "dp/opengl/gl10.h"

#include "dpimpl/common/opengl/common.h"

namespace dp {
#define GL_FUNCTION GL_DECLARE_FUNCTION_POINTER
    GL10_FUNCTIONS
#undef  GL_FUNCTION
}
