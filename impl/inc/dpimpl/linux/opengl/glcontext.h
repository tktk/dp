#ifndef DPIMPL_LINUX_OPENGL_GLCONTEXT_H
#define DPIMPL_LINUX_OPENGL_GLCONTEXT_H

#include "dpimpl/linux/opengl/glx.h"
#include "dp/common/memory.h"

#include <type_traits>

namespace dp {
    void initializeGLContext(
    );

    void finalizeGLContext(
    );

    typedef std::remove_pointer< GLXContext >::type GLXContextEntity;

    struct GLContext
    {
        Unique< GLXContextEntity >::type    glxContextUnique;
    };
}

#endif  // DPIMPL_LINUX_OPENGL_GLCONTEXT_H
