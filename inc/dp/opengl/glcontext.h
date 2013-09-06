#ifndef DP_OPENGL_GLCONTEXT_H
#define DP_OPENGL_GLCONTEXT_H

#include "dp/window/window.h"
#include "dp/common/memory.h"
#include "dp/util/import.h"

#include <memory>

namespace dp {
    struct GLContext;

    struct GLContextInfo;

    DPEXPORT GLContext * newGLContext(
        const GLContextInfo &
    );

    DPEXPORT GLContext * newGLContext(
        const GLContextInfo &
        , GLContext &
    );

    DPEXPORT void free(
        GLContext &
    );

    DPEXPORT void glMakeCurrent(
        Window &
        , GLContext &
    );

    DPEXPORT void glMakeCurrent(
    );

    DPEXPORT void swapBuffers(
        GLContext &
    );

    DPEXPORT GLContextInfo * newGLContextInfo(
    );

    DPEXPORT GLContextInfo * clone(
        const GLContextInfo &
    );

    DPEXPORT void free(
        GLContextInfo &
    );

    DPEXPORT Bool getVSync(
        const GLContextInfo &
    );

    DPEXPORT void setVSync(
        GLContextInfo &
        , Bool
    );

    DPEXPORT Bool getDoubleBuffer(
        const GLContextInfo &
    );

    DPEXPORT void setDoubleBuffer(
        GLContextInfo &
        , Bool
    );

    DPEXPORT Bool isExistsAuxBuffers(
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

    DPEXPORT Bool isExistsRedBits(
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

    DPEXPORT Bool isExistsGreenBits(
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

    DPEXPORT Bool isExistsBlueBits(
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

    DPEXPORT Bool isExistsAlphaBits(
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

    DPEXPORT Bool isExistsDepthBits(
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

    DPEXPORT Bool isExistsStencilBits(
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

    DPEXPORT Bool isExistsAccumRedBits(
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

    DPEXPORT Bool isExistsAccumGreenBits(
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

    DPEXPORT Bool isExistsAccumBlueBits(
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

    DPEXPORT Bool isExistsAccumAlphaBits(
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

    typedef std::shared_ptr< GLContext > GLContextShared;

    typedef std::weak_ptr< GLContext > GLContextWeak;

    typedef Unique< GLContextInfo >::type GLContextInfoUnique;

    typedef std::shared_ptr< GLContextInfo > GLContextInfoShared;

    typedef std::weak_ptr< GLContextInfo > GLContextInfoWeak;
}

#endif  // DP_OPENGL_GLCONTEXT_H
