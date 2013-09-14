#ifndef DP_OPENGL_GL12_H
#define DP_OPENGL_GL12_H

#include "dp/opengl/common.h"
#include "dp/opengl/types.h"
#include "dp/opengl/constants.h"

#define GL12_FUNCTIONS  \
    GL_FUNCTION( void, glDrawRangeElements, ( GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid * ) )   \
\
    GL_FUNCTION( void, glColorTable, ( GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid * ) )  \
    GL_FUNCTION( void, glColorTableParameteriv, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glColorTableParameterfv, ( GLenum, GLenum, const GLfloat * ) )   \
    GL_FUNCTION( void, glCopyColorTable, ( GLenum, GLenum, GLint, GLint, GLsizei ) )    \
    GL_FUNCTION( void, glColorSubTable, ( GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) )  \
    GL_FUNCTION( void, glCopyColorSubTable, ( GLenum, GLsizei, GLint, GLint, GLsizei ) )    \
    GL_FUNCTION( void, glConvolutionFilter1D, ( GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glConvolutionFilter2D, ( GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) )    \
    GL_FUNCTION( void, glConvolutionParameteri, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glConvolutionParameterf, ( GLenum, GLenum, GLfloat ) )   \
    GL_FUNCTION( void, glConvolutionParameteriv, ( GLenum, GLenum, const GLint * ) )    \
    GL_FUNCTION( void, glConvolutionParameterfv, ( GLenum, GLenum, const GLfloat * ) )  \
    GL_FUNCTION( void, glSeparableFilter2D, ( GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid * ) )  \
    GL_FUNCTION( void, glCopyConvolutionFilter1D, ( GLenum, GLenum, GLint, GLint, GLsizei ) )   \
    GL_FUNCTION( void, glCopyConvolutionFilter2D, ( GLenum, GLenum, GLint, GLint, GLsizei, GLsizei ) )  \
    GL_FUNCTION( void, glHistogram, ( GLenum, GLsizei, GLenum, GLboolean ) )    \
    GL_FUNCTION( void, glMinmax, ( GLenum, GLenum, GLboolean ) )    \
\
    GL_FUNCTION( void, glTexImage3D, ( GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) )   \
    GL_FUNCTION( void, glTexSubImage3D, ( GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glCopyTexSubImage3D, ( GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei ) )    \
\
    GL_FUNCTION( void, glBlendColor, ( GLclampf, GLclampf, GLclampf, GLclampf ) )   \
    GL_FUNCTION( void, glBlendEquation, ( GLenum ) )    \
\
    GL_FUNCTION( void, glGetColorTable, ( GLenum, GLenum, GLenum, GLvoid * ) )  \
    GL_FUNCTION( void, glGetColorTableParameteriv, ( GLenum, GLenum, GLint * ) )    \
    GL_FUNCTION( void, glGetColorTableParameterfv, ( GLenum, GLenum, GLfloat * ) )  \
    GL_FUNCTION( void, glGetConvolutionFilter, ( GLenum, GLenum, GLenum, GLvoid * ) )   \
    GL_FUNCTION( void, glGetSeparableFilter, ( GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid * ) ) \
    GL_FUNCTION( void, glGetConvolutionParameteriv, ( GLenum, GLenum, GLint * ) )   \
    GL_FUNCTION( void, glGetConvolutionParameterfv, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetHistogram, ( GLenum, GLboolean, GLenum, GLenum, GLvoid * ) )    \
    GL_FUNCTION( void, glResetHistogram, ( GLenum ) )   \
    GL_FUNCTION( void, glGetHistogramParameteriv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetHistogramParameterfv, ( GLenum, GLenum, GLfloat * ) )   \
    GL_FUNCTION( void, glGetMinmax, ( GLenum, GLboolean, GLenum, GLenum, GLvoid * ) )   \
    GL_FUNCTION( void, glResetMinmax, ( GLenum ) )  \
    GL_FUNCTION( void, glGetMinmaxParameteriv, ( GLenum, GLenum, GLint * ) )    \
    GL_FUNCTION( void, glGetMinmaxParameterfv, ( GLenum, GLenum, GLfloat * ) )  \

namespace dp {
#define GL_FUNCTION GL_EXTERN_FUNCTION_POINTER
    GL12_FUNCTIONS
#undef  GL_FUNCTION
}

#endif  // DP_OPENGL_GL12_H
