#include "dpimpl/util/export.h"
#include "dp/opengl/glcontext.h"

#include "dp/window/window.h"

namespace dp {
    GLContext * newGLContext(
        const GLContextInfo &
    )
    {
        //TODO
        return nullptr;
    }

    GLContext * newGLContext(
        const GLContextInfo &
        , GLContext &
    )
    {
        //TODO
        return nullptr;
    }

    void glMakeCurrent(
        Window &
        , GLContext &
    )
    {
        //TODO
    }

    void glMakeCurrent(
    )
    {
        //TODO
    }

    void swapBuffers(
        GLContext &
    )
    {
        //TODO
    }
}
