#include "dpimpl/util/export.h"
#include "dp/opengl/common.h"

#include "dpimpl/common/opengl/common.h"
#include "dp/opengl/gl10.h"
#include "dp/opengl/gl11.h"
#include "dp/opengl/gl12.h"
#include "dp/common/primitives.h"

#include <map>

#define GL_FUNCTIONS    \
    GL10_FUNCTIONS  \
    GL11_FUNCTIONS  \
    GL12_FUNCTIONS  \

namespace {
#define GL_FUNCTION_POINTER_TO_NAME( _returnType, _name, _args )    \
    { &( dp::toGLProc( dp::_name ) ), #_name }, \

    const std::map< const dp::GLProc *, const dp::StringChar * >    FUNCTION_POINTER_TO_NAME = {
#define GL_FUNCTION GL_FUNCTION_POINTER_TO_NAME
        GL_FUNCTIONS
#undef  GL_FUNCTION
    };

    const dp::StringChar * getName(
        const dp::GLProc &  _PROC
    )
    {
        auto    it = FUNCTION_POINTER_TO_NAME.find( &_PROC );
        if( it == FUNCTION_POINTER_TO_NAME.end() ) {
            return nullptr;
        }

        return it->second;
    }
}

namespace dp {
#define GL_DECLARE_FUNCTION_POINTER( _returnType, _name, _args )    \
    _returnType ( DPSTDCALL * _name )_args = nullptr;   \

#define GL_FUNCTION GL_DECLARE_FUNCTION_POINTER
        GL_FUNCTIONS
#undef  GL_FUNCTION

    Bool loadGLProc(
        GLProc &    _proc
    )
    {
        if( _proc != nullptr ) {
            return true;
        }

        const auto  NAME = getName(
            _proc
        );
        if( NAME == nullptr ) {
            return false;
        }

        _proc = glGetProcAddress( NAME );

        return _proc != nullptr;
    }
}
