#ifndef DP_OPENGL_GL10_H
#define DP_OPENGL_GL10_H

#include "dp/opengl/common.h"
#include "dp/opengl/types.h"
#include "dp/opengl/constants.h"

#define GL10_FUNCTIONS  \
    GL_FUNCTION( GLenum, glGetError, () )   \
\
    GL_FUNCTION( void, glBegin, ( GLenum ) )    \
    GL_FUNCTION( void, glEnd, () )  \
\
    GL_FUNCTION( void, glEdgeFlag, ( GLboolean ) )  \
    GL_FUNCTION( void, glEdgeFlagv, ( const GLboolean * ) ) \
\
    GL_FUNCTION( void, glVertex2s, ( GLshort, GLshort ) )   \
    GL_FUNCTION( void, glVertex2i, ( GLint, GLint ) )   \
    GL_FUNCTION( void, glVertex2f, ( GLfloat, GLfloat ) )   \
    GL_FUNCTION( void, glVertex2d, ( GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertex3s, ( GLshort, GLshort, GLshort ) )  \
    GL_FUNCTION( void, glVertex3i, ( GLint, GLint, GLint ) )    \
    GL_FUNCTION( void, glVertex3f, ( GLfloat, GLfloat, GLfloat ) )  \
    GL_FUNCTION( void, glVertex3d, ( GLdouble, GLdouble, GLdouble ) )   \
    GL_FUNCTION( void, glVertex4s, ( GLshort, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertex4i, ( GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glVertex4f, ( GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertex4d, ( GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertex2sv, ( const GLshort * ) )   \
    GL_FUNCTION( void, glVertex2iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glVertex2fv, ( const GLfloat * ) )   \
    GL_FUNCTION( void, glVertex2dv, ( const GLdouble * ) )  \
    GL_FUNCTION( void, glVertex3sv, ( const GLshort * ) )   \
    GL_FUNCTION( void, glVertex3iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glVertex3fv, ( const GLfloat * ) )   \
    GL_FUNCTION( void, glVertex3dv, ( const GLdouble * ) )  \
    GL_FUNCTION( void, glVertex4sv, ( const GLshort * ) )   \
    GL_FUNCTION( void, glVertex4iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glVertex4fv, ( const GLfloat * ) )   \
    GL_FUNCTION( void, glVertex4dv, ( const GLdouble * ) )  \
\
    GL_FUNCTION( void, glTexCoord1s, ( GLshort ) )  \
    GL_FUNCTION( void, glTexCoord1i, ( GLint ) )    \
    GL_FUNCTION( void, glTexCoord1f, ( GLfloat ) )  \
    GL_FUNCTION( void, glTexCoord1d, ( GLdouble ) ) \
    GL_FUNCTION( void, glTexCoord2s, ( GLshort, GLshort ) ) \
    GL_FUNCTION( void, glTexCoord2i, ( GLint, GLint ) ) \
    GL_FUNCTION( void, glTexCoord2f, ( GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glTexCoord2d, ( GLdouble, GLdouble ) )   \
    GL_FUNCTION( void, glTexCoord3s, ( GLshort, GLshort, GLshort ) )    \
    GL_FUNCTION( void, glTexCoord3i, ( GLint, GLint, GLint ) )  \
    GL_FUNCTION( void, glTexCoord3f, ( GLfloat, GLfloat, GLfloat ) )    \
    GL_FUNCTION( void, glTexCoord3d, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glTexCoord4s, ( GLshort, GLshort, GLshort, GLshort ) )   \
    GL_FUNCTION( void, glTexCoord4i, ( GLint, GLint, GLint, GLint ) )   \
    GL_FUNCTION( void, glTexCoord4f, ( GLfloat, GLfloat, GLfloat, GLfloat ) )   \
    GL_FUNCTION( void, glTexCoord4d, ( GLdouble, GLdouble, GLdouble, GLdouble ) )   \
    GL_FUNCTION( void, glTexCoord1sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glTexCoord1iv, ( const GLint * ) )   \
    GL_FUNCTION( void, glTexCoord1fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord1dv, ( const GLdouble * ) )    \
    GL_FUNCTION( void, glTexCoord2sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glTexCoord2iv, ( const GLint * ) )   \
    GL_FUNCTION( void, glTexCoord2fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord2dv, ( const GLdouble * ) )    \
    GL_FUNCTION( void, glTexCoord3sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glTexCoord3iv, ( const GLint * ) )   \
    GL_FUNCTION( void, glTexCoord3fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord3dv, ( const GLdouble * ) )    \
    GL_FUNCTION( void, glTexCoord4sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glTexCoord4iv, ( const GLint * ) )   \
    GL_FUNCTION( void, glTexCoord4fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord4dv, ( const GLdouble * ) )    \
\
    GL_FUNCTION( void, glNormal3b, ( GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glNormal3s, ( GLshort, GLshort, GLshort ) )  \
    GL_FUNCTION( void, glNormal3i, ( GLint, GLint, GLint ) )    \
    GL_FUNCTION( void, glNormal3f, ( GLfloat, GLfloat, GLfloat ) )  \
    GL_FUNCTION( void, glNormal3d, ( GLdouble, GLdouble, GLdouble ) )   \
    GL_FUNCTION( void, glNormal3bv, ( const GLbyte * ) )    \
    GL_FUNCTION( void, glNormal3sv, ( const GLshort * ) )   \
    GL_FUNCTION( void, glNormal3iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glNormal3fv, ( const GLfloat * ) )   \
    GL_FUNCTION( void, glNormal3dv, ( const GLdouble * ) )  \
\
    GL_FUNCTION( void, glColor3b, ( GLbyte, GLbyte, GLbyte ) )  \
    GL_FUNCTION( void, glColor3s, ( GLshort, GLshort, GLshort ) )   \
    GL_FUNCTION( void, glColor3i, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glColor3f, ( GLfloat, GLfloat, GLfloat ) )   \
    GL_FUNCTION( void, glColor3d, ( GLdouble, GLdouble, GLdouble ) )    \
    GL_FUNCTION( void, glColor3ub, ( GLubyte, GLubyte, GLubyte ) )  \
    GL_FUNCTION( void, glColor3us, ( GLushort, GLushort, GLushort ) )   \
    GL_FUNCTION( void, glColor3ui, ( GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glColor4b, ( GLbyte, GLbyte, GLbyte, GLbyte ) )  \
    GL_FUNCTION( void, glColor4s, ( GLshort, GLshort, GLshort, GLshort ) )  \
    GL_FUNCTION( void, glColor4i, ( GLint, GLint, GLint, GLint ) )  \
    GL_FUNCTION( void, glColor4f, ( GLfloat, GLfloat, GLfloat, GLfloat ) )  \
    GL_FUNCTION( void, glColor4d, ( GLdouble, GLdouble, GLdouble, GLdouble ) )  \
    GL_FUNCTION( void, glColor4ub, ( GLubyte, GLubyte, GLubyte, GLubyte ) ) \
    GL_FUNCTION( void, glColor4us, ( GLushort, GLushort, GLushort, GLushort ) ) \
    GL_FUNCTION( void, glColor4ui, ( GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glColor3bv, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glColor3sv, ( const GLshort * ) )    \
    GL_FUNCTION( void, glColor3iv, ( const GLint * ) )  \
    GL_FUNCTION( void, glColor3fv, ( const GLfloat * ) )    \
    GL_FUNCTION( void, glColor3dv, ( const GLdouble * ) )   \
    GL_FUNCTION( void, glColor3ubv, ( const GLubyte * ) )   \
    GL_FUNCTION( void, glColor3usv, ( const GLushort * ) )  \
    GL_FUNCTION( void, glColor3uiv, ( const GLuint * ) )    \
    GL_FUNCTION( void, glColor4bv, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glColor4sv, ( const GLshort * ) )    \
    GL_FUNCTION( void, glColor4iv, ( const GLint * ) )  \
    GL_FUNCTION( void, glColor4fv, ( const GLfloat * ) )    \
    GL_FUNCTION( void, glColor4dv, ( const GLdouble * ) )   \
    GL_FUNCTION( void, glColor4ubv, ( const GLubyte * ) )   \
    GL_FUNCTION( void, glColor4usv, ( const GLushort * ) )  \
    GL_FUNCTION( void, glColor4uiv, ( const GLuint * ) )    \
\
    GL_FUNCTION( void, glIndexs, ( GLshort ) )  \
    GL_FUNCTION( void, glIndexi, ( GLint ) )    \
    GL_FUNCTION( void, glIndexf, ( GLfloat ) )  \
    GL_FUNCTION( void, glIndexd, ( GLdouble ) ) \
    GL_FUNCTION( void, glIndexsv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glIndexiv, ( const GLint * ) )   \
    GL_FUNCTION( void, glIndexfv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glIndexdv, ( const GLdouble * ) )    \
\
    GL_FUNCTION( void, glRects, ( GLshort, GLshort, GLshort, GLshort ) )    \
    GL_FUNCTION( void, glRecti, ( GLint, GLint, GLint, GLint ) )    \
    GL_FUNCTION( void, glRectf, ( GLfloat, GLfloat, GLfloat, GLfloat ) )    \
    GL_FUNCTION( void, glRectd, ( GLdouble, GLdouble, GLdouble, GLdouble ) )    \
    GL_FUNCTION( void, glRectsv, ( const GLshort *, const GLshort * ) ) \
    GL_FUNCTION( void, glRectiv, ( const GLint *, const GLint * ) ) \
    GL_FUNCTION( void, glRectfv, ( const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glRectdv, ( const GLdouble *, const GLdouble * ) )   \
\
    GL_FUNCTION( void, glDepthRange, ( GLclampd, GLclampd ) )   \
    GL_FUNCTION( void, glViewport, ( GLint, GLint, GLsizei, GLsizei ) ) \
\
    GL_FUNCTION( void, glMatrixMode, ( GLenum ) )   \
\
    GL_FUNCTION( void, glLoadMatrixf, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glLoadMatrixd, ( const GLdouble * ) )    \
\
    GL_FUNCTION( void, glMultMatrixf, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glMultMatrixd, ( const GLdouble * ) )    \
\
    GL_FUNCTION( void, glLoadIdentity, () ) \
\
    GL_FUNCTION( void, glRotatef, ( GLfloat, GLfloat, GLfloat, GLfloat ) )  \
    GL_FUNCTION( void, glRotated, ( GLdouble, GLdouble, GLdouble, GLdouble ) )  \
\
    GL_FUNCTION( void, glTranslatef, ( GLfloat, GLfloat, GLfloat ) )    \
    GL_FUNCTION( void, glTranslated, ( GLdouble, GLdouble, GLdouble ) ) \
\
    GL_FUNCTION( void, glScalef, ( GLfloat, GLfloat, GLfloat ) )    \
    GL_FUNCTION( void, glScaled, ( GLdouble, GLdouble, GLdouble ) ) \
\
    GL_FUNCTION( void, glFrustum, ( GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble ) )  \
    GL_FUNCTION( void, glOrtho, ( GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble ) )    \
\
    GL_FUNCTION( void, glPushMatrix, () )   \
    GL_FUNCTION( void, glPopMatrix, () )    \
\
    GL_FUNCTION( void, glEnable, ( GLenum ) )   \
    GL_FUNCTION( void, glDisable, ( GLenum ) )  \
\
    GL_FUNCTION( void, glTexGeni, ( GLenum, GLenum, GLint ) )   \
    GL_FUNCTION( void, glTexGenf, ( GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glTexGend, ( GLenum, GLenum, GLdouble ) )    \
    GL_FUNCTION( void, glTexGeniv, ( GLenum, GLenum, const GLint * ) )  \
    GL_FUNCTION( void, glTexGenfv, ( GLenum, GLenum, const GLfloat * ) )    \
    GL_FUNCTION( void, glTexGendv, ( GLenum, GLenum, const GLdouble * ) )   \
\
    GL_FUNCTION( void, glClipPlane, ( GLenum, const GLdouble * ) )  \
\
    GL_FUNCTION( void, glRasterPos2s, ( GLshort, GLshort ) )    \
    GL_FUNCTION( void, glRasterPos2i, ( GLint, GLint ) )    \
    GL_FUNCTION( void, glRasterPos2f, ( GLfloat, GLfloat ) )    \
    GL_FUNCTION( void, glRasterPos2d, ( GLdouble, GLdouble ) )  \
    GL_FUNCTION( void, glRasterPos2sv, ( const GLshort * ) )    \
    GL_FUNCTION( void, glRasterPos2iv, ( const GLint * ) )  \
    GL_FUNCTION( void, glRasterPos2fv, ( const GLfloat * ) )    \
    GL_FUNCTION( void, glRasterPos2dv, ( const GLdouble * ) )   \
    GL_FUNCTION( void, glRasterPos3s, ( GLshort, GLshort, GLshort ) )   \
    GL_FUNCTION( void, glRasterPos3i, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glRasterPos3f, ( GLfloat, GLfloat, GLfloat ) )   \
    GL_FUNCTION( void, glRasterPos3d, ( GLdouble, GLdouble, GLdouble ) )    \
    GL_FUNCTION( void, glRasterPos3sv, ( const GLshort * ) )    \
    GL_FUNCTION( void, glRasterPos3iv, ( const GLint * ) )  \
    GL_FUNCTION( void, glRasterPos3fv, ( const GLfloat * ) )    \
    GL_FUNCTION( void, glRasterPos3dv, ( const GLdouble * ) )   \
    GL_FUNCTION( void, glRasterPos4s, ( GLshort, GLshort, GLshort, GLshort ) )  \
    GL_FUNCTION( void, glRasterPos4i, ( GLint, GLint, GLint, GLint ) )  \
    GL_FUNCTION( void, glRasterPos4f, ( GLfloat, GLfloat, GLfloat, GLfloat ) )  \
    GL_FUNCTION( void, glRasterPos4d, ( GLdouble, GLdouble, GLdouble, GLdouble ) )  \
    GL_FUNCTION( void, glRasterPos4sv, ( const GLshort * ) )    \
    GL_FUNCTION( void, glRasterPos4iv, ( const GLint * ) )  \
    GL_FUNCTION( void, glRasterPos4fv, ( const GLfloat * ) )    \
    GL_FUNCTION( void, glRasterPos4dv, ( const GLdouble * ) )   \
\
    GL_FUNCTION( void, glFrontFace, ( GLenum ) )    \
\
    GL_FUNCTION( void, glMateriali, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glMaterialf, ( GLenum, GLenum, GLfloat ) )   \
    GL_FUNCTION( void, glMaterialiv, ( GLenum, GLenum, const GLint * ) )    \
    GL_FUNCTION( void, glMaterialfv, ( GLenum, GLenum, const GLfloat * ) )  \
\
    GL_FUNCTION( void, glLighti, ( GLenum, GLenum, GLint ) )    \
    GL_FUNCTION( void, glLightf, ( GLenum, GLenum, GLfloat ) )  \
    GL_FUNCTION( void, glLightiv, ( GLenum, GLenum, const GLint * ) )   \
    GL_FUNCTION( void, glLightfv, ( GLenum, GLenum, const GLfloat * ) ) \
\
    GL_FUNCTION( void, glLightModeli, ( GLenum, GLint ) )   \
    GL_FUNCTION( void, glLightModelf, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glLightModeliv, ( GLenum, const GLint * ) )  \
    GL_FUNCTION( void, glLightModelfv, ( GLenum, const GLfloat * ) )    \
\
    GL_FUNCTION( void, glColorMaterial, ( GLenum, GLenum ) )    \
\
    GL_FUNCTION( void, glShadeModel, ( GLenum ) )   \
\
    GL_FUNCTION( void, glPointSize, ( GLfloat ) )   \
\
    GL_FUNCTION( void, glLineWidth, ( GLfloat ) )   \
    GL_FUNCTION( void, glLineStipple, ( GLint, GLushort ) ) \
\
    GL_FUNCTION( void, glCullFace, ( GLenum ) ) \
    GL_FUNCTION( void, glPolygonStipple, ( const GLubyte * ) )  \
    GL_FUNCTION( void, glPolygonMode, ( GLenum, GLenum ) )  \
\
    GL_FUNCTION( void, glPixelStorei, ( GLenum, GLint ) )   \
    GL_FUNCTION( void, glPixelStoref, ( GLenum, GLfloat ) ) \
\
    GL_FUNCTION( void, glPixelTransferi, ( GLenum, GLint ) )    \
    GL_FUNCTION( void, glPixelTransferf, ( GLenum, GLfloat ) )  \
\
    GL_FUNCTION( void, glPixelMapuiv, ( GLenum, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glPixelMapusv, ( GLenum, GLsizei, const GLushort * ) )   \
    GL_FUNCTION( void, glPixelMapfv, ( GLenum, GLsizei, const GLfloat * ) ) \
\
    GL_FUNCTION( void, glDrawPixels, ( GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
\
    GL_FUNCTION( void, glPixelZoom, ( GLfloat, GLfloat ) )  \
\
    GL_FUNCTION( void, glBitmap, ( GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte * ) )    \
\
    GL_FUNCTION( void, glTexImage1D, ( GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTexImage2D, ( GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) )    \
\
    GL_FUNCTION( void, glTexParameteri, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glTexParameterf, ( GLenum, GLenum, GLfloat ) )   \
    GL_FUNCTION( void, glTexParameteriv, ( GLenum, GLenum, const GLint * ) )    \
    GL_FUNCTION( void, glTexParameterfv, ( GLenum, GLenum, const GLfloat * ) )  \
\
    GL_FUNCTION( void, glTexEnvi, ( GLenum, GLenum, GLint ) )   \
    GL_FUNCTION( void, glTexEnvf, ( GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glTexEnviv, ( GLenum, GLenum, const GLint * ) )  \
    GL_FUNCTION( void, glTexEnvfv, ( GLenum, GLenum, const GLfloat * ) )    \
\
    GL_FUNCTION( void, glFogi, ( GLenum, GLint ) )  \
    GL_FUNCTION( void, glFogf, ( GLenum, GLfloat ) )    \
    GL_FUNCTION( void, glFogiv, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glFogfv, ( GLenum, const GLfloat * ) )   \
\
    GL_FUNCTION( void, glScissor, ( GLint, GLint, GLsizei, GLsizei ) )  \
\
    GL_FUNCTION( void, glAlphaFunc, ( GLenum, GLclampf ) )  \
\
    GL_FUNCTION( void, glStencilFunc, ( GLenum, GLint, GLuint ) )   \
    GL_FUNCTION( void, glStencilOp, ( GLenum, GLenum, GLenum ) )    \
\
    GL_FUNCTION( void, glDepthFunc, ( GLenum ) )    \
\
    GL_FUNCTION( void, glBlendFunc, ( GLenum, GLenum ) )    \
\
    GL_FUNCTION( void, glLogicOp, ( GLenum ) )  \
\
    GL_FUNCTION( void, glDrawBuffer, ( GLenum ) )   \
\
    GL_FUNCTION( void, glIndexMask, ( GLuint ) )    \
    GL_FUNCTION( void, glColorMask, ( GLboolean, GLboolean, GLboolean, GLboolean ) )    \
    GL_FUNCTION( void, glDepthMask, ( GLboolean ) ) \
    GL_FUNCTION( void, glStencilMask, ( GLuint ) )  \
\
    GL_FUNCTION( void, glClear, ( GLbitfield ) )    \
    GL_FUNCTION( void, glClearColor, ( GLclampf, GLclampf, GLclampf, GLclampf ) )   \
    GL_FUNCTION( void, glClearIndex, ( GLfloat ) )  \
    GL_FUNCTION( void, glClearDepth, ( GLclampd ) ) \
    GL_FUNCTION( void, glClearStencil, ( GLint ) )  \
    GL_FUNCTION( void, glClearAccum, ( GLfloat, GLfloat, GLfloat, GLfloat ) )   \
\
    GL_FUNCTION( void, glAccum, ( GLenum, GLfloat ) )   \
\
    GL_FUNCTION( void, glReadPixels, ( GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glReadBuffer, ( GLenum ) )   \
\
    GL_FUNCTION( void, glCopyPixels, ( GLint, GLint, GLsizei, GLsizei, GLenum ) )   \
\
    GL_FUNCTION( void, glMap1f, ( GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat * ) )   \
    GL_FUNCTION( void, glMap1d, ( GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble * ) )    \
    GL_FUNCTION( void, glMap2f, ( GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat * ) )   \
    GL_FUNCTION( void, glMap2d, ( GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble * ) )  \
\
    GL_FUNCTION( void, glEvalCoord1f, ( GLfloat ) ) \
    GL_FUNCTION( void, glEvalCoord1d, ( GLdouble ) )    \
    GL_FUNCTION( void, glEvalCoord2f, ( GLfloat, GLfloat ) )    \
    GL_FUNCTION( void, glEvalCoord2d, ( GLdouble, GLdouble ) )  \
    GL_FUNCTION( void, glEvalCoord1fv, ( const GLfloat * ) )    \
    GL_FUNCTION( void, glEvalCoord1dv, ( const GLdouble * ) )   \
    GL_FUNCTION( void, glEvalCoord2fv, ( const GLfloat * ) )    \
    GL_FUNCTION( void, glEvalCoord2dv, ( const GLdouble * ) )   \
\
    GL_FUNCTION( void, glMapGrid1f, ( GLint, GLfloat, GLfloat ) )   \
    GL_FUNCTION( void, glMapGrid1d, ( GLint, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glMapGrid2f, ( GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat ) )  \
    GL_FUNCTION( void, glMapGrid2d, ( GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble ) )  \
\
    GL_FUNCTION( void, glEvalMesh1, ( GLenum, GLint, GLint ) )  \
    GL_FUNCTION( void, glEvalMesh2, ( GLenum, GLint, GLint, GLint, GLint ) )    \
\
    GL_FUNCTION( void, glEvalPoint1, ( GLint ) )    \
    GL_FUNCTION( void, glEvalPoint2, ( GLint, GLint ) ) \
\
    GL_FUNCTION( void, glInitNames, () )    \
    GL_FUNCTION( void, glPopName, () )  \
    GL_FUNCTION( void, glPushName, ( GLuint ) ) \
    GL_FUNCTION( void, glLoadName, ( GLuint ) ) \
\
    GL_FUNCTION( GLint, glRenderMode, ( GLenum ) )  \
    GL_FUNCTION( void, glSelectBuffer, ( GLsizei, GLuint * ) )  \
\
    GL_FUNCTION( void, glFeedbackBuffer, ( GLsizei, GLenum, GLfloat * ) )   \
    GL_FUNCTION( void, glPassThrough, ( GLfloat ) ) \
\
    GL_FUNCTION( void, glNewList, ( GLuint, GLenum ) )  \
    GL_FUNCTION( void, glEndList, () )  \
    GL_FUNCTION( void, glCallList, ( GLuint ) ) \
    GL_FUNCTION( void, glCallLists, ( GLsizei, GLenum, const GLvoid * ) )   \
    GL_FUNCTION( void, glListBase, ( GLuint ) ) \
    GL_FUNCTION( GLuint, glGenLists, ( GLsizei ) )  \
    GL_FUNCTION( GLboolean, glIsList, ( GLuint ) )  \
    GL_FUNCTION( void, glDeleteLists, ( GLuint, GLsizei ) ) \
\
    GL_FUNCTION( void, glFlush, () )    \
    GL_FUNCTION( void, glFinish, () )   \
\
    GL_FUNCTION( void, glHint, ( GLenum, GLenum ) ) \
\
    GL_FUNCTION( void, glGetBooleanv, ( GLenum, GLboolean * ) ) \
    GL_FUNCTION( void, glGetIntegerv, ( GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetFloatv, ( GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetDoublev, ( GLenum, GLdouble * ) )   \
\
    GL_FUNCTION( GLboolean, glIsEnabled, ( GLenum ) )   \
\
    GL_FUNCTION( void, glGetClipPlane, ( GLenum, GLdouble * ) ) \
    GL_FUNCTION( void, glGetLightiv, ( GLenum, GLenum, GLint * ) )  \
    GL_FUNCTION( void, glGetLightfv, ( GLenum, GLenum, GLfloat * ) )    \
    GL_FUNCTION( void, glGetMaterialiv, ( GLenum, GLenum, GLint * ) )   \
    GL_FUNCTION( void, glGetMaterialfv, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetTexEnviv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetTexEnvfv, ( GLenum, GLenum, GLfloat * ) )   \
    GL_FUNCTION( void, glGetTexGeniv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetTexGenfv, ( GLenum, GLenum, GLfloat * ) )   \
    GL_FUNCTION( void, glGetTexParameteriv, ( GLenum, GLenum, GLint * ) )   \
    GL_FUNCTION( void, glGetTexParameterfv, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetTexLevelParameteriv, ( GLenum, GLint, GLenum, GLint * ) )   \
    GL_FUNCTION( void, glGetTexLevelParameterfv, ( GLenum, GLint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetPixelMapuiv, ( GLenum, GLuint * ) ) \
    GL_FUNCTION( void, glGetPixelMapusv, ( GLenum, GLushort * ) )   \
    GL_FUNCTION( void, glGetPixelMapfv, ( GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetMapiv, ( GLenum, GLenum, GLint * ) )    \
    GL_FUNCTION( void, glGetMapfv, ( GLenum, GLenum, GLfloat * ) )  \
    GL_FUNCTION( void, glGetMapdv, ( GLenum, GLenum, GLdouble * ) ) \
    GL_FUNCTION( void, glGetTexImage, ( GLenum, GLint, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGetPolygonStipple, ( GLubyte * ) ) \
    GL_FUNCTION( const GLubyte *, glGetString, ( GLenum ) ) \
\
    GL_FUNCTION( void, glPushAttrib, ( GLbitfield ) )   \
    GL_FUNCTION( void, glPopAttrib, () )    \

namespace dp {
#define GL_FUNCTION GL_EXTERN_FUNCTION_POINTER
    GL10_FUNCTIONS
#undef  GL_FUNCTION
}

#endif  // DP_OPENGL_GL10_H
