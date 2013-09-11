#include "dpimpl/util/export.h"
#include "dp/opengl/common.h"

#include "dp/opengl/gl10.h"
#include "dpimpl/common/opengl/common.h"
#include "dp/common/primitives.h"

#include <map>

namespace {
#define GL_FUNCTION_POINTER_TO_NAME( _returnType, _name, _args )    \
    { &( dp::toGLProc( dp::_name ) ), #_name }, \

    const std::map< const dp::GLProc *, const dp::StringChar * >    FUNCTION_POINTER_TO_NAME = {
#define GL_FUNCTION GL_FUNCTION_POINTER_TO_NAME
        GL10_FUNCTIONS
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
    void loadGLProc(
        GLProc &    _proc
    )
    {
        if( _proc != nullptr ) {
            return;
        }

        const auto  NAME = getName(
            _proc
        );
        if( NAME != nullptr ) {
            _proc = glGetProcAddress( NAME );

            return;
        }
    }
}
