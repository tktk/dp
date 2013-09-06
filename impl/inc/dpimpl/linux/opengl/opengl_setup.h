#ifndef DPIMPL_LINUX_OPENGL_OPENGL_SETUP_H
#define DPIMPL_LINUX_OPENGL_OPENGL_SETUP_H

#include "dpimpl/linux/opengl/glcontext.h"

namespace dp {
    inline void initializeOpenGL(
    )
    {
        initializeGLContext();
    }

    inline void finalizeOpenGL(
    )
    {
        finalizeGLContext();
    }
}

#endif  // DPIMPL_LINUX_OPENGL_OPENGL_SETUP_H
