#ifndef DP_OPENGL_GL_H
#define DP_OPENGL_GL_H

#include "dp/opengl/types.h"
#include "dp/opengl/constants.h"
#include "dp/opengl/functions.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

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

    template< typename T >
    Bool loadGLProcs(
        const T &   _PROCS
    )
    {
        auto    result = true;

        for( auto & proc : _PROCS ) {
            if( loadGLProc( proc ) == false ) {
                result = false;
            }
        }

        return result;
    }
}

#endif  // DP_OPENGL_GL_H
