#ifndef DPIMPL_COMMON_OPENGL_COMMON_H
#define DPIMPL_COMMON_OPENGL_COMMON_H

#include "dp/opengl/common.h"
#include "dp/common/primitives.h"

#define GL_DECLARE_FUNCTION_POINTER( _returnType, _name, _args )    \
    _returnType ( DPSTDCALL * _name )_args = nullptr;   \

namespace dp {
    GLProc glGetProcAddress(
        const StringChar *
    );
}

#endif  // DPIMPL_COMMON_OPENGL_COMMON_H
