#ifndef DP_OPENGL_TYPES_H
#define DP_OPENGL_TYPES_H

#include "dp/common/primitives.h"

#include <cstddef>

namespace dp {
    typedef UInt GLenum;
    typedef UByte GLboolean;
    typedef void GLvoid;

    typedef Byte GLbyte;
    typedef Short GLshort;
    typedef Int GLint;

    typedef UByte GLubyte;
    typedef UShort GLushort;
    typedef UInt GLuint;

    typedef Float GLfloat;
    typedef Float GLclampf;
    typedef Double GLdouble;
    typedef Double GLclampd;

    typedef StringChar GLchar;
    typedef UInt GLbitfield;
    typedef Int GLsizei;

    typedef ptrdiff_t GLintptr;
    typedef ptrdiff_t GLsizeiptr;

    typedef Long GLint64;
    typedef ULong GLuint64;

    typedef struct __GLsync * GLsync;
}

#endif  // DP_OPENGL_TYPES_H
