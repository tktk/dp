#include "dpimpl/util/export.h"
#include "dp/opengl/glcontext.h"

#include "dpimpl/common/opengl/glcontext.h"

template<>
void free(
    const dp::GLContext &   _GL_CONTEXT
)
{
    delete &_GL_CONTEXT;
}
