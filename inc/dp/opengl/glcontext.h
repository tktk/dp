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

    DPEXPORT void setAuxBuffers(
        const GLContextInfo &
        , Int
    );

    DPEXPORT Int getAuxBuffers(
        const GLContextInfo &
    );

    DPEXPORT Bool isExistsAuxBuffers(
        const GLContextInfo &
    );

    DPEXPORT void clearAuxBuffers(
        GLContextInfo &
    );

    DPEXPORT void setRedBits(
        const GLContextInfo &
        , Int
    );

    DPEXPORT Int getRedBits(
        const GLContextInfo &
    );

    DPEXPORT Bool isExistsRedBits(
        const GLContextInfo &
    );

    DPEXPORT void clearRedBits(
        GLContextInfo &
    );

    DPEXPORT void setGreenBits(
        const GLContextInfo &
        , Int
    );

    DPEXPORT Int getGreenBits(
        const GLContextInfo &
    );

    DPEXPORT Bool isExistsGreenBits(
        const GLContextInfo &
    );

    DPEXPORT void clearGreenBits(
        GLContextInfo &
    );

    DPEXPORT void setBlueBits(
        const GLContextInfo &
        , Int
    );

    DPEXPORT Int getBlueBits(
        const GLContextInfo &
    );

    DPEXPORT Bool isExistsBlueBits(
        const GLContextInfo &
    );

    DPEXPORT void clearBlueBits(
        GLContextInfo &
    );

    DPEXPORT void setAlphaBits(
        const GLContextInfo &
        , Int
    );

    DPEXPORT Int getAlphaBits(
        const GLContextInfo &
    );

    DPEXPORT Bool isExistsAlphaBits(
        const GLContextInfo &
    );

    DPEXPORT void clearAlphaBits(
        GLContextInfo &
    );

    DPEXPORT void setDepthBits(
        const GLContextInfo &
        , Int
    );

    DPEXPORT Int getDepthBits(
        const GLContextInfo &
    );

    DPEXPORT Bool isExistsDepthBits(
        const GLContextInfo &
    );

    DPEXPORT void clearDepthBits(
        GLContextInfo &
    );

    DPEXPORT void setStencilBits(
        const GLContextInfo &
        , Int
    );

    DPEXPORT Int getStencilBits(
        const GLContextInfo &
    );

    DPEXPORT Bool isExistsStencilBits(
        const GLContextInfo &
    );

    DPEXPORT void clearStencilBits(
        GLContextInfo &
    );

    DPEXPORT void setAccumRedBits(
        const GLContextInfo &
        , Int
    );

    DPEXPORT Int getAccumRedBits(
        const GLContextInfo &
    );

    DPEXPORT Bool isExistsAccumRedBits(
        const GLContextInfo &
    );

    DPEXPORT void clearAccumRedBits(
        GLContextInfo &
    );

    DPEXPORT void setAccumGreenBits(
        const GLContextInfo &
        , Int
    );

    DPEXPORT Int getAccumGreenBits(
        const GLContextInfo &
    );

    DPEXPORT Bool isExistsAccumGreenBits(
        const GLContextInfo &
    );

    DPEXPORT void clearAccumGreenBits(
        GLContextInfo &
    );

    DPEXPORT void setAccumBlueBits(
        const GLContextInfo &
        , Int
    );

    DPEXPORT Int getAccumBlueBits(
        const GLContextInfo &
    );

    DPEXPORT Bool isExistsAccumBlueBits(
        const GLContextInfo &
    );

    DPEXPORT void clearAccumBlueBits(
        GLContextInfo &
    );

    DPEXPORT void setAccumAlphaBits(
        const GLContextInfo &
        , Int
    );

    DPEXPORT Int getAccumAlphaBits(
        const GLContextInfo &
    );

    DPEXPORT Bool isExistsAccumAlphaBits(
        const GLContextInfo &
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
