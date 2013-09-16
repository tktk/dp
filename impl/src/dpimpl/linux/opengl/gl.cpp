#include "dpimpl/common/opengl/gl.h"
#include "dp/opengl/gl.h"
#include "dp/common/primitives.h"

#include "dpimpl/linux/opengl/glx.h"

namespace dp {
    GLProc glGetProcAddress(
        const StringChar *  _NAME
    )
    {
        return glXGetProcAddress( reinterpret_cast< const UByte * >( _NAME ) );
    }
}
