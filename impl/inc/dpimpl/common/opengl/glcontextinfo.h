#ifndef DPIMPL_COMMON_OPENGL_GLCONTEXTINFO_H
#define DPIMPL_COMMON_OPENGL_GLCONTEXTINFO_H

#include "dp/common/primitives.h"

namespace dp {
    struct GLContextInfo
    {
        Bool    doubleBuffer;
        Bool    existsAuxBuffers_;
        Int     auxBuffers;
        Bool    existsRedBits_;
        Int     redBits;
        Bool    existsGreenBits_;
        Int     greenBits;
        Bool    existsBlueBits_;
        Int     blueBits;
        Bool    existsAlphaBits_;
        Int     alphaBits;
        Bool    existsDepthBits_;
        Int     depthBits;
        Bool    existsStencilBits_;
        Int     stencilBits;
        Bool    existsAccumRedBits_;
        Int     accumRedBits;
        Bool    existsAccumGreenBits_;
        Int     accumGreenBits;
        Bool    existsAccumBlueBits_;
        Int     accumBlueBits;
        Bool    existsAccumAlphaBits_;
        Int     accumAlphaBits;
    };
}

#endif  // DPIMPL_COMMON_OPENGL_GLCONTEXTINFO_H
