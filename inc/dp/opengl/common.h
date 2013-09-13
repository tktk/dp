#ifndef DP_OPENGL_COMMON_H
#define DP_OPENGL_COMMON_H

#include "dp/common/primitives.h"
#include "dp/util/import.h"

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
    typedef void( * GLProc )();

    template< typename T >
    GLProc & toGLProc(
        T & _proc
    )
    {
        return reinterpret_cast< GLProc & >( _proc );
    }

    template< typename T >
    GLProc * toGLProcPtr(
        T & _proc
    )
    {
        return &toGLProc< T >( _proc );
    }

    DPEXPORT Bool loadGLProc(
        GLProc &
    );

    inline Bool loadGLProc(
        GLProc *    _proc
    )
    {
        return loadGLProc( *_proc );
    }

    template< typename T >
    Bool loadGLProc(
        T & _proc
    )
    {
        return loadGLProc( toGLProc( _proc ) );
    }
}

#endif  // DP_OPENGL_COMMON_H
