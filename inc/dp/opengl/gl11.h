#ifndef DP_OPENGL_GL11_H
#define DP_OPENGL_GL11_H

#include "dp/opengl/common.h"
#include "dp/opengl/types.h"
#include "dp/opengl/constants.h"

#define GL11_FUNCTIONS  \
    GL_FUNCTION( void, glIndexub, ( GLubyte ) ) \
    GL_FUNCTION( void, glIndexubv, ( const GLubyte * ) )    \
\
    GL_FUNCTION( void, glEdgeFlagPointer, ( GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glTexCoordPointer, ( GLint, GLenum, GLsizei, const GLvoid * ) )  \
    GL_FUNCTION( void, glColorPointer, ( GLint, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glIndexPointer, ( GLenum, GLsizei, const GLvoid * ) )    \
    GL_FUNCTION( void, glNormalPointer, ( GLenum, GLsizei, const GLvoid * ) )   \
    GL_FUNCTION( void, glVertexPointer, ( GLint, GLenum, GLsizei, const GLvoid * ) )    \
\
    GL_FUNCTION( void, glEnableClientState, ( GLenum ) )    \
    GL_FUNCTION( void, glDisableClientState, ( GLenum ) )   \
\
    GL_FUNCTION( void, glArrayElement, ( GLint ) )  \
    GL_FUNCTION( void, glDrawArrays, ( GLenum, GLint, GLsizei ) )   \
    GL_FUNCTION( void, glDrawElements, ( GLenum, GLsizei, GLenum, const GLvoid * ) )    \
    GL_FUNCTION( void, glInterleavedArrays, ( GLenum, GLsizei, const GLvoid * ) )   \
\
    GL_FUNCTION( void, glPolygonOffset, ( GLfloat, GLfloat ) )  \
\
    GL_FUNCTION( void, glCopyTexImage1D, ( GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint ) )  \
    GL_FUNCTION( void, glCopyTexImage2D, ( GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint ) ) \
    GL_FUNCTION( void, glTexSubImage1D, ( GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTexSubImage2D, ( GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glCopyTexSubImage1D, ( GLenum, GLint, GLint, GLint, GLint, GLsizei ) )   \
    GL_FUNCTION( void, glCopyTexSubImage2D, ( GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei ) )   \
\
    GL_FUNCTION( void, glBindTexture, ( GLenum, GLuint ) )  \
    GL_FUNCTION( void, glDeleteTextures, ( GLsizei, const GLuint * ) )  \
    GL_FUNCTION( void, glGenTextures, ( GLsizei, GLuint * ) )   \
    GL_FUNCTION( GLboolean, glAreTexturesResident, ( GLsizei, const GLuint *, GLboolean * ) )   \
    GL_FUNCTION( void, glPrioritizeTextures, ( GLsizei, const GLuint *, const GLclampf * ) )    \
\
    GL_FUNCTION( GLboolean, glIsTexture, ( GLuint ) )   \
\
    GL_FUNCTION( void, glGetPointerv, ( GLenum, GLvoid ** ) )   \
\
    GL_FUNCTION( void, glPushClientAttrib, ( GLbitfield ) ) \
    GL_FUNCTION( void, glPopClientAttrib, () )  \

namespace dp {
#define GL_FUNCTION GL_EXTERN_FUNCTION_POINTER
    GL11_FUNCTIONS
#undef  GL_FUNCTION
}

#endif  // DP_OPENGL_GL11_H
