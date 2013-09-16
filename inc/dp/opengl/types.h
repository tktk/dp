#ifndef DP_OPENGL_TYPES_H
#define DP_OPENGL_TYPES_H

#include "dp/common/primitives.h"

#include <cstddef>
#include <cinttypes>

namespace dp {
    // GL_VERSION_1_0
    typedef unsigned int GLenum;
    typedef float GLfloat;
    typedef int GLint;
    typedef int GLsizei;
    typedef void GLvoid;
    typedef unsigned int GLbitfield;
    typedef double GLdouble;
    typedef unsigned int GLuint;
    typedef unsigned char GLboolean;
    typedef unsigned char GLubyte;

    // GL_VERSION_1_1
    typedef float GLclampf;
    typedef double GLclampd;

    // GL_VERSION_1_5
    typedef ptrdiff_t GLsizeiptr;
    typedef ptrdiff_t GLintptr;

    // GL_VERSION_2_0
    typedef char GLchar;
    typedef short GLshort;
    typedef signed char GLbyte;
    typedef unsigned short GLushort;

    // GL_VERSION_3_0
    typedef unsigned short GLhalf;

    // GL_VERSION_3_2
    typedef struct __GLsync *GLsync;
    typedef uint64_t GLuint64;
    typedef int64_t GLint64;

    // GL_ARB_bindless_texture
    typedef uint64_t GLuint64EXT;

    // GL_ARB_half_float_pixel
    typedef unsigned short GLhalfARB;

    // GL_ARB_shader_objects
    typedef unsigned int GLhandleARB;   //FIXME __APPLE__の場合void *
    typedef char GLcharARB;

    // GL_ARB_vertex_buffer_object
    typedef ptrdiff_t GLsizeiptrARB;
    typedef ptrdiff_t GLintptrARB;

    // GL_OES_fixed_point
    typedef GLint GLfixed;

    // GL_NV_gpu_shader5
    typedef int64_t GLint64EXT;

    // GL_NV_half_float
    typedef unsigned short GLhalfNV;

    // GL_NV_vdpau_interop
    typedef GLintptr GLvdpauSurfaceNV;
}

#endif  // DP_OPENGL_TYPES_H
