﻿#include "dpimpl/util/export.h"
#include "dp/opengl/glcontext.h"

namespace dp {
    void free(
        GLContext & _glContext
    )
    {
        delete &_glContext;
    }
}