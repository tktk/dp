#ifndef DPIMPL_LINUX_OPENGL_GLCONTEXT_H
#define DPIMPL_LINUX_OPENGL_GLCONTEXT_H

#include "dpimpl/linux/opengl/glx.h"

#include <memory>
#include <type_traits>

namespace dp {
    void initializeGLContext(
    );

    void finalizeGLContext(
    );

    struct GLContext
    {
    private:
        struct FreeGLXContext
        {
            void operator()(
                GLXContext
            ) const;
        };

        typedef std::unique_ptr<
            std::remove_pointer< GLXContext >::type
            , FreeGLXContext
        > GLXContextUnique;

    public:
        GLXContextUnique    glxContextUnique;
    };
}

#endif  // DPIMPL_LINUX_OPENGL_GLCONTEXT_H
