#ifndef DP_OPENGL_FUNCTIONS_H
#define DP_OPENGL_FUNCTIONS_H

#include "dp/opengl/types.h"
#include "dp/util/import.h"

#define GL_FUNCTIONS    \
    //TODO

#if defined LINUX   //OS
#   define DPSTDCALL
#elif defined WINDOWS   // OS
#   define DPSTDCALL __stdcall
#else   // OS
#   error 未対応のOS
#endif  // OS

#define GL_EXTERN_FUNCTION_POINTER( _returnType, _name, _args ) \
    DPEXPORT extern _returnType ( DPSTDCALL * _name )_args; \

namespace dp {
#define GL_FUNCTION GL_EXTERN_FUNCTION_POINTER
    GL_FUNCTIONS
#undef  GL_FUNCTION
}

#endif  // DP_OPENGL_FUNCTIONS_H
