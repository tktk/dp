#ifndef DPIMPL_COMMON_OPENGL_GLCONTEXTINFO_H
#define DPIMPL_COMMON_OPENGL_GLCONTEXTINFO_H

#include "dp/common/primitives.h"

namespace dp {
    struct GLContextInfo
    {
        Bool    doubleBuffer;
        Bool    existsAuxBuffers;
        Int     auxBuffers;
        Bool    existsRedBits;
        Int     redBits;
        Bool    existsGreenBits;
        Int     greenBits;
        Bool    existsBlueBits;
        Int     blueBits;
        Bool    existsAlphaBits;
        Int     alphaBits;
        Bool    existsDepthBits;
        Int     depthBits;
        Bool    existsStencilBits;
        Int     stencilBits;
        Bool    existsAccumRedBits;
        Int     accumRedBits;
        Bool    existsAccumGreenBits;
        Int     accumGreenBits;
        Bool    existsAccumBlueBits;
        Int     accumBlueBits;
        Bool    existsAccumAlphaBits;
        Int     accumAlphaBits;
    };
}

#endif  // DPIMPL_COMMON_OPENGL_GLCONTEXTINFO_H
