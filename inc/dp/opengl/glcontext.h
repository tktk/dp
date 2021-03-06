﻿#ifndef DP_OPENGL_GLCONTEXT_H
#define DP_OPENGL_GLCONTEXT_H

#include "dp/window/window.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

DPSTRUCT( dp, GLContext )

DPSTRUCT( dp, GLContextInfo )

namespace dp {
    DPEXPORT GLContext * newGLContext(
        const GLContextInfo &
    );

    DPEXPORT GLContext * newGLContext(
        const GLContextInfo &
        , GLContext &
    );

    DPEXPORT void glMakeCurrent(
        Window &
        , GLContext &
        , Bool
    );

    DPEXPORT void glMakeCurrent(
    );

    DPEXPORT void glSwapBuffers(
        Window &
    );

    DPEXPORT GLContextInfo * newGLContextInfo(
    );

    DPEXPORT GLContextInfo * clone(
        const GLContextInfo &
    );

    DPEXPORT Bool getDoubleBuffer(
        const GLContextInfo &
    );

    DPEXPORT void setDoubleBuffer(
        GLContextInfo &
        , Bool
    );

    DPEXPORT Bool existsAuxBuffers(
        const GLContextInfo &
    );

    DPEXPORT Int getAuxBuffers(
        const GLContextInfo &
    );

    DPEXPORT void setAuxBuffers(
        GLContextInfo &
        , Int
    );

    DPEXPORT void clearAuxBuffers(
        GLContextInfo &
    );

    DPEXPORT Bool existsRedBits(
        const GLContextInfo &
    );

    DPEXPORT Int getRedBits(
        const GLContextInfo &
    );

    DPEXPORT void setRedBits(
        GLContextInfo &
        , Int
    );

    DPEXPORT void clearRedBits(
        GLContextInfo &
    );

    DPEXPORT Bool existsGreenBits(
        const GLContextInfo &
    );

    DPEXPORT Int getGreenBits(
        const GLContextInfo &
    );

    DPEXPORT void setGreenBits(
        GLContextInfo &
        , Int
    );

    DPEXPORT void clearGreenBits(
        GLContextInfo &
    );

    DPEXPORT Bool existsBlueBits(
        const GLContextInfo &
    );

    DPEXPORT Int getBlueBits(
        const GLContextInfo &
    );

    DPEXPORT void setBlueBits(
        GLContextInfo &
        , Int
    );

    DPEXPORT void clearBlueBits(
        GLContextInfo &
    );

    DPEXPORT Bool existsAlphaBits(
        const GLContextInfo &
    );

    DPEXPORT Int getAlphaBits(
        const GLContextInfo &
    );

    DPEXPORT void setAlphaBits(
        GLContextInfo &
        , Int
    );

    DPEXPORT void clearAlphaBits(
        GLContextInfo &
    );

    DPEXPORT Bool existsDepthBits(
        const GLContextInfo &
    );

    DPEXPORT Int getDepthBits(
        const GLContextInfo &
    );

    DPEXPORT void setDepthBits(
        GLContextInfo &
        , Int
    );

    DPEXPORT void clearDepthBits(
        GLContextInfo &
    );

    DPEXPORT Bool existsStencilBits(
        const GLContextInfo &
    );

    DPEXPORT Int getStencilBits(
        const GLContextInfo &
    );

    DPEXPORT void setStencilBits(
        GLContextInfo &
        , Int
    );

    DPEXPORT void clearStencilBits(
        GLContextInfo &
    );

    DPEXPORT Bool existsAccumRedBits(
        const GLContextInfo &
    );

    DPEXPORT Int getAccumRedBits(
        const GLContextInfo &
    );

    DPEXPORT void setAccumRedBits(
        GLContextInfo &
        , Int
    );

    DPEXPORT void clearAccumRedBits(
        GLContextInfo &
    );

    DPEXPORT Bool existsAccumGreenBits(
        const GLContextInfo &
    );

    DPEXPORT Int getAccumGreenBits(
        const GLContextInfo &
    );

    DPEXPORT void setAccumGreenBits(
        GLContextInfo &
        , Int
    );

    DPEXPORT void clearAccumGreenBits(
        GLContextInfo &
    );

    DPEXPORT Bool existsAccumBlueBits(
        const GLContextInfo &
    );

    DPEXPORT Int getAccumBlueBits(
        const GLContextInfo &
    );

    DPEXPORT void setAccumBlueBits(
        GLContextInfo &
        , Int
    );

    DPEXPORT void clearAccumBlueBits(
        GLContextInfo &
    );

    DPEXPORT Bool existsAccumAlphaBits(
        const GLContextInfo &
    );

    DPEXPORT Int getAccumAlphaBits(
        const GLContextInfo &
    );

    DPEXPORT void setAccumAlphaBits(
        GLContextInfo &
        , Int
    );

    DPEXPORT void clearAccumAlphaBits(
        GLContextInfo &
    );

    typedef Unique< GLContext >::type GLContextUnique;

    typedef Shared< GLContext >::type GLContextShared;

    typedef Weak< GLContext >::type GLContextWeak;

    typedef Unique< GLContextInfo >::type GLContextInfoUnique;

    typedef Shared< GLContextInfo >::type GLContextInfoShared;

    typedef Weak< GLContextInfo >::type GLContextInfoWeak;
}

#endif  // DP_OPENGL_GLCONTEXT_H
