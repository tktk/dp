#ifndef DP_OPENGL_FUNCTIONS_H
#define DP_OPENGL_FUNCTIONS_H

#include "dp/opengl/types.h"
#include "dp/util/import.h"

#define GL_FUNCTIONS \
    /* GL_VERSION_1_0 */ \
    GL_FUNCTION( GLenum, glGetError, () ) \
    GL_FUNCTION( void, glBegin, ( GLenum ) ) \
    GL_FUNCTION( void, glEnd, () ) \
    GL_FUNCTION( void, glEdgeFlag, ( GLboolean ) ) \
    GL_FUNCTION( void, glEdgeFlagv, ( const GLboolean * ) ) \
    GL_FUNCTION( void, glVertex2s, ( GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertex2i, ( GLint, GLint ) ) \
    GL_FUNCTION( void, glVertex2f, ( GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertex2d, ( GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertex3s, ( GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertex3i, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glVertex3f, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertex3d, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertex4s, ( GLshort, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertex4i, ( GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glVertex4f, ( GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertex4d, ( GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertex2sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glVertex2iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glVertex2fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glVertex2dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glVertex3sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glVertex3iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glVertex3fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glVertex3dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glVertex4sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glVertex4iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glVertex4fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glVertex4dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glTexCoord1s, ( GLshort ) ) \
    GL_FUNCTION( void, glTexCoord1i, ( GLint ) ) \
    GL_FUNCTION( void, glTexCoord1f, ( GLfloat ) ) \
    GL_FUNCTION( void, glTexCoord1d, ( GLdouble ) ) \
    GL_FUNCTION( void, glTexCoord2s, ( GLshort, GLshort ) ) \
    GL_FUNCTION( void, glTexCoord2i, ( GLint, GLint ) ) \
    GL_FUNCTION( void, glTexCoord2f, ( GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glTexCoord2d, ( GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glTexCoord3s, ( GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glTexCoord3i, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glTexCoord3f, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glTexCoord3d, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glTexCoord4s, ( GLshort, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glTexCoord4i, ( GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glTexCoord4f, ( GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glTexCoord4d, ( GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glTexCoord1sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glTexCoord1iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glTexCoord1fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord1dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glTexCoord2sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glTexCoord2iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glTexCoord2fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord2dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glTexCoord3sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glTexCoord3iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glTexCoord3fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord3dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glTexCoord4sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glTexCoord4iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glTexCoord4fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord4dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glNormal3b, ( GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glNormal3s, ( GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glNormal3i, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glNormal3f, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glNormal3d, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glNormal3bv, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glNormal3sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glNormal3iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glNormal3fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glNormal3dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glColor3b, ( GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glColor3s, ( GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glColor3i, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glColor3f, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glColor3d, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glColor3ub, ( GLubyte, GLubyte, GLubyte ) ) \
    GL_FUNCTION( void, glColor3us, ( GLushort, GLushort, GLushort ) ) \
    GL_FUNCTION( void, glColor3ui, ( GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glColor4b, ( GLbyte, GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glColor4s, ( GLshort, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glColor4i, ( GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glColor4f, ( GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glColor4d, ( GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glColor4ub, ( GLubyte, GLubyte, GLubyte, GLubyte ) ) \
    GL_FUNCTION( void, glColor4us, ( GLushort, GLushort, GLushort, GLushort ) ) \
    GL_FUNCTION( void, glColor4ui, ( GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glColor3bv, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glColor3sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glColor3iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glColor3fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glColor3dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glColor3ubv, ( const GLubyte * ) ) \
    GL_FUNCTION( void, glColor3usv, ( const GLushort * ) ) \
    GL_FUNCTION( void, glColor3uiv, ( const GLuint * ) ) \
    GL_FUNCTION( void, glColor4bv, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glColor4sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glColor4iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glColor4fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glColor4dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glColor4ubv, ( const GLubyte * ) ) \
    GL_FUNCTION( void, glColor4usv, ( const GLushort * ) ) \
    GL_FUNCTION( void, glColor4uiv, ( const GLuint * ) ) \
    GL_FUNCTION( void, glIndexs, ( GLshort ) ) \
    GL_FUNCTION( void, glIndexi, ( GLint ) ) \
    GL_FUNCTION( void, glIndexf, ( GLfloat ) ) \
    GL_FUNCTION( void, glIndexd, ( GLdouble ) ) \
    GL_FUNCTION( void, glIndexsv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glIndexiv, ( const GLint * ) ) \
    GL_FUNCTION( void, glIndexfv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glIndexdv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glRects, ( GLshort, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glRecti, ( GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glRectf, ( GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glRectd, ( GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glRectsv, ( const GLshort *, const GLshort * ) ) \
    GL_FUNCTION( void, glRectiv, ( const GLint *, const GLint * ) ) \
    GL_FUNCTION( void, glRectfv, ( const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glRectdv, ( const GLdouble *, const GLdouble * ) ) \
    GL_FUNCTION( void, glDepthRange, ( GLclampd, GLclampd ) ) \
    GL_FUNCTION( void, glViewport, ( GLint, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glMatrixMode, ( GLenum ) ) \
    GL_FUNCTION( void, glLoadMatrixf, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glLoadMatrixd, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glMultMatrixf, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glMultMatrixd, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glLoadIdentity, () ) \
    GL_FUNCTION( void, glRotatef, ( GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glRotated, ( GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glTranslatef, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glTranslated, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glScalef, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glScaled, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glFrustum, ( GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glOrtho, ( GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glPushMatrix, () ) \
    GL_FUNCTION( void, glPopMatrix, () ) \
    GL_FUNCTION( void, glEnable, ( GLenum ) ) \
    GL_FUNCTION( void, glDisable, ( GLenum ) ) \
    GL_FUNCTION( void, glTexGeni, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glTexGenf, ( GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glTexGend, ( GLenum, GLenum, GLdouble ) ) \
    GL_FUNCTION( void, glTexGeniv, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glTexGenfv, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glTexGendv, ( GLenum, GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glClipPlane, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glRasterPos2s, ( GLshort, GLshort ) ) \
    GL_FUNCTION( void, glRasterPos2i, ( GLint, GLint ) ) \
    GL_FUNCTION( void, glRasterPos2f, ( GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glRasterPos2d, ( GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glRasterPos2sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glRasterPos2iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glRasterPos2fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glRasterPos2dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glRasterPos3s, ( GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glRasterPos3i, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glRasterPos3f, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glRasterPos3d, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glRasterPos3sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glRasterPos3iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glRasterPos3fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glRasterPos3dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glRasterPos4s, ( GLshort, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glRasterPos4i, ( GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glRasterPos4f, ( GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glRasterPos4d, ( GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glRasterPos4sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glRasterPos4iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glRasterPos4fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glRasterPos4dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glFrontFace, ( GLenum ) ) \
    GL_FUNCTION( void, glMateriali, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glMaterialf, ( GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glMaterialiv, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glMaterialfv, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glLighti, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glLightf, ( GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glLightiv, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glLightfv, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glLightModeli, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glLightModelf, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glLightModeliv, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glLightModelfv, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glColorMaterial, ( GLenum, GLenum ) ) \
    GL_FUNCTION( void, glShadeModel, ( GLenum ) ) \
    GL_FUNCTION( void, glPointSize, ( GLfloat ) ) \
    GL_FUNCTION( void, glLineWidth, ( GLfloat ) ) \
    GL_FUNCTION( void, glLineStipple, ( GLint, GLushort ) ) \
    GL_FUNCTION( void, glCullFace, ( GLenum ) ) \
    GL_FUNCTION( void, glPolygonStipple, ( const GLubyte * ) ) \
    GL_FUNCTION( void, glPolygonMode, ( GLenum, GLenum ) ) \
    GL_FUNCTION( void, glPixelStorei, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glPixelStoref, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glPixelTransferi, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glPixelTransferf, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glPixelMapuiv, ( GLenum, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glPixelMapusv, ( GLenum, GLsizei, const GLushort * ) ) \
    GL_FUNCTION( void, glPixelMapfv, ( GLenum, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glDrawPixels, ( GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glPixelZoom, ( GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glBitmap, ( GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte * ) ) \
    GL_FUNCTION( void, glTexImage1D, ( GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTexImage2D, ( GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTexParameteri, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glTexParameterf, ( GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glTexParameteriv, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glTexParameterfv, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glTexEnvi, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glTexEnvf, ( GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glTexEnviv, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glTexEnvfv, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glFogi, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glFogf, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glFogiv, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glFogfv, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glScissor, ( GLint, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glAlphaFunc, ( GLenum, GLclampf ) ) \
    GL_FUNCTION( void, glStencilFunc, ( GLenum, GLint, GLuint ) ) \
    GL_FUNCTION( void, glStencilOp, ( GLenum, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glDepthFunc, ( GLenum ) ) \
    GL_FUNCTION( void, glBlendFunc, ( GLenum, GLenum ) ) \
    GL_FUNCTION( void, glLogicOp, ( GLenum ) ) \
    GL_FUNCTION( void, glDrawBuffer, ( GLenum ) ) \
    GL_FUNCTION( void, glIndexMask, ( GLuint ) ) \
    GL_FUNCTION( void, glColorMask, ( GLboolean, GLboolean, GLboolean, GLboolean ) ) \
    GL_FUNCTION( void, glDepthMask, ( GLboolean ) ) \
    GL_FUNCTION( void, glStencilMask, ( GLuint ) ) \
    GL_FUNCTION( void, glClear, ( GLbitfield ) ) \
    GL_FUNCTION( void, glClearColor, ( GLclampf, GLclampf, GLclampf, GLclampf ) ) \
    GL_FUNCTION( void, glClearIndex, ( GLfloat ) ) \
    GL_FUNCTION( void, glClearDepth, ( GLclampd ) ) \
    GL_FUNCTION( void, glClearStencil, ( GLint ) ) \
    GL_FUNCTION( void, glClearAccum, ( GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glAccum, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glReadPixels, ( GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glReadBuffer, ( GLenum ) ) \
    GL_FUNCTION( void, glCopyPixels, ( GLint, GLint, GLsizei, GLsizei, GLenum ) ) \
    GL_FUNCTION( void, glMap1f, ( GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat * ) ) \
    GL_FUNCTION( void, glMap1d, ( GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble * ) ) \
    GL_FUNCTION( void, glMap2f, ( GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat * ) ) \
    GL_FUNCTION( void, glMap2d, ( GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble * ) ) \
    GL_FUNCTION( void, glEvalCoord1f, ( GLfloat ) ) \
    GL_FUNCTION( void, glEvalCoord1d, ( GLdouble ) ) \
    GL_FUNCTION( void, glEvalCoord2f, ( GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glEvalCoord2d, ( GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glEvalCoord1fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glEvalCoord1dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glEvalCoord2fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glEvalCoord2dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glMapGrid1f, ( GLint, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glMapGrid1d, ( GLint, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glMapGrid2f, ( GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glMapGrid2d, ( GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glEvalMesh1, ( GLenum, GLint, GLint ) ) \
    GL_FUNCTION( void, glEvalMesh2, ( GLenum, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glEvalPoint1, ( GLint ) ) \
    GL_FUNCTION( void, glEvalPoint2, ( GLint, GLint ) ) \
    GL_FUNCTION( void, glInitNames, () ) \
    GL_FUNCTION( void, glPopName, () ) \
    GL_FUNCTION( void, glPushName, ( GLuint ) ) \
    GL_FUNCTION( void, glLoadName, ( GLuint ) ) \
    GL_FUNCTION( GLint, glRenderMode, ( GLenum ) ) \
    GL_FUNCTION( void, glSelectBuffer, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glFeedbackBuffer, ( GLsizei, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glPassThrough, ( GLfloat ) ) \
    GL_FUNCTION( void, glNewList, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glEndList, () ) \
    GL_FUNCTION( void, glCallList, ( GLuint ) ) \
    GL_FUNCTION( void, glCallLists, ( GLsizei, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glListBase, ( GLuint ) ) \
    GL_FUNCTION( GLuint, glGenLists, ( GLsizei ) ) \
    GL_FUNCTION( GLboolean, glIsList, ( GLuint ) ) \
    GL_FUNCTION( void, glDeleteLists, ( GLuint, GLsizei ) ) \
    GL_FUNCTION( void, glFlush, () ) \
    GL_FUNCTION( void, glFinish, () ) \
    GL_FUNCTION( void, glHint, ( GLenum, GLenum ) ) \
    GL_FUNCTION( void, glGetBooleanv, ( GLenum, GLboolean * ) ) \
    GL_FUNCTION( void, glGetIntegerv, ( GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetFloatv, ( GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetDoublev, ( GLenum, GLdouble * ) ) \
    GL_FUNCTION( GLboolean, glIsEnabled, ( GLenum ) ) \
    GL_FUNCTION( void, glGetClipPlane, ( GLenum, GLdouble * ) ) \
    GL_FUNCTION( void, glGetLightiv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetLightfv, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetMaterialiv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetMaterialfv, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetTexEnviv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetTexEnvfv, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetTexGeniv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetTexGenfv, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetTexParameteriv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetTexParameterfv, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetTexLevelParameteriv, ( GLenum, GLint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetTexLevelParameterfv, ( GLenum, GLint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetPixelMapuiv, ( GLenum, GLuint * ) ) \
    GL_FUNCTION( void, glGetPixelMapusv, ( GLenum, GLushort * ) ) \
    GL_FUNCTION( void, glGetPixelMapfv, ( GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetMapiv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetMapfv, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetMapdv, ( GLenum, GLenum, GLdouble * ) ) \
    GL_FUNCTION( void, glGetTexImage, ( GLenum, GLint, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGetPolygonStipple, ( GLubyte * ) ) \
    GL_FUNCTION( const GLubyte *, glGetString, ( GLenum ) ) \
    GL_FUNCTION( void, glPushAttrib, ( GLbitfield ) ) \
    GL_FUNCTION( void, glPopAttrib, () ) \
    \
    /* GL_VERSION_1_1 */ \
    GL_FUNCTION( void, glIndexub, ( GLubyte ) ) \
    GL_FUNCTION( void, glIndexubv, ( const GLubyte * ) ) \
    GL_FUNCTION( void, glEdgeFlagPointer, ( GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glTexCoordPointer, ( GLint, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glColorPointer, ( GLint, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glIndexPointer, ( GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glNormalPointer, ( GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glVertexPointer, ( GLint, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glEnableClientState, ( GLenum ) ) \
    GL_FUNCTION( void, glDisableClientState, ( GLenum ) ) \
    GL_FUNCTION( void, glArrayElement, ( GLint ) ) \
    GL_FUNCTION( void, glDrawArrays, ( GLenum, GLint, GLsizei ) ) \
    GL_FUNCTION( void, glDrawElements, ( GLenum, GLsizei, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glInterleavedArrays, ( GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glPolygonOffset, ( GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glCopyTexImage1D, ( GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint ) ) \
    GL_FUNCTION( void, glCopyTexImage2D, ( GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint ) ) \
    GL_FUNCTION( void, glTexSubImage1D, ( GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTexSubImage2D, ( GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glCopyTexSubImage1D, ( GLenum, GLint, GLint, GLint, GLint, GLsizei ) ) \
    GL_FUNCTION( void, glCopyTexSubImage2D, ( GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glBindTexture, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDeleteTextures, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenTextures, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( GLboolean, glAreTexturesResident, ( GLsizei, const GLuint *, GLboolean * ) ) \
    GL_FUNCTION( void, glPrioritizeTextures, ( GLsizei, const GLuint *, const GLclampf * ) ) \
    GL_FUNCTION( GLboolean, glIsTexture, ( GLuint ) ) \
    GL_FUNCTION( void, glGetPointerv, ( GLenum, GLvoid ** ) ) \
    GL_FUNCTION( void, glPushClientAttrib, ( GLbitfield ) ) \
    GL_FUNCTION( void, glPopClientAttrib, () ) \
    \
    /* GL_VERSION_1_2 */ \
    GL_FUNCTION( void, glDrawRangeElements, ( GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTexImage3D, ( GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTexSubImage3D, ( GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glCopyTexSubImage3D, ( GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei ) ) \
    \
    /* GL_VERSION_1_3 */ \
    GL_FUNCTION( void, glActiveTexture, ( GLenum ) ) \
    GL_FUNCTION( void, glSampleCoverage, ( GLfloat, GLboolean ) ) \
    GL_FUNCTION( void, glCompressedTexImage3D, ( GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTexImage2D, ( GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTexImage1D, ( GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTexSubImage3D, ( GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTexSubImage2D, ( GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTexSubImage1D, ( GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glGetCompressedTexImage, ( GLenum, GLint, GLvoid * ) ) \
    GL_FUNCTION( void, glClientActiveTexture, ( GLenum ) ) \
    GL_FUNCTION( void, glMultiTexCoord1d, ( GLenum, GLdouble ) ) \
    GL_FUNCTION( void, glMultiTexCoord1dv, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glMultiTexCoord1f, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glMultiTexCoord1fv, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMultiTexCoord1i, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glMultiTexCoord1iv, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glMultiTexCoord1s, ( GLenum, GLshort ) ) \
    GL_FUNCTION( void, glMultiTexCoord1sv, ( GLenum, const GLshort * ) ) \
    GL_FUNCTION( void, glMultiTexCoord2d, ( GLenum, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glMultiTexCoord2dv, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glMultiTexCoord2f, ( GLenum, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glMultiTexCoord2fv, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMultiTexCoord2i, ( GLenum, GLint, GLint ) ) \
    GL_FUNCTION( void, glMultiTexCoord2iv, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glMultiTexCoord2s, ( GLenum, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glMultiTexCoord2sv, ( GLenum, const GLshort * ) ) \
    GL_FUNCTION( void, glMultiTexCoord3d, ( GLenum, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glMultiTexCoord3dv, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glMultiTexCoord3f, ( GLenum, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glMultiTexCoord3fv, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMultiTexCoord3i, ( GLenum, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glMultiTexCoord3iv, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glMultiTexCoord3s, ( GLenum, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glMultiTexCoord3sv, ( GLenum, const GLshort * ) ) \
    GL_FUNCTION( void, glMultiTexCoord4d, ( GLenum, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glMultiTexCoord4dv, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glMultiTexCoord4f, ( GLenum, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glMultiTexCoord4fv, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMultiTexCoord4i, ( GLenum, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glMultiTexCoord4iv, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glMultiTexCoord4s, ( GLenum, GLshort, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glMultiTexCoord4sv, ( GLenum, const GLshort * ) ) \
    GL_FUNCTION( void, glLoadTransposeMatrixf, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glLoadTransposeMatrixd, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glMultTransposeMatrixf, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glMultTransposeMatrixd, ( const GLdouble * ) ) \
    \
    /* GL_VERSION_1_4 */ \
    GL_FUNCTION( void, glBlendFuncSeparate, ( GLenum, GLenum, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glMultiDrawArrays, ( GLenum, const GLint *, const GLsizei *, GLsizei ) ) \
    GL_FUNCTION( void, glMultiDrawElements, ( GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei ) ) \
    GL_FUNCTION( void, glPointParameterf, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glPointParameterfv, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glPointParameteri, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glPointParameteriv, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glFogCoordf, ( GLfloat ) ) \
    GL_FUNCTION( void, glFogCoordfv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glFogCoordd, ( GLdouble ) ) \
    GL_FUNCTION( void, glFogCoorddv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glFogCoordPointer, ( GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glSecondaryColor3b, ( GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glSecondaryColor3bv, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glSecondaryColor3d, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glSecondaryColor3dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glSecondaryColor3f, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glSecondaryColor3fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glSecondaryColor3i, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glSecondaryColor3iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glSecondaryColor3s, ( GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glSecondaryColor3sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glSecondaryColor3ub, ( GLubyte, GLubyte, GLubyte ) ) \
    GL_FUNCTION( void, glSecondaryColor3ubv, ( const GLubyte * ) ) \
    GL_FUNCTION( void, glSecondaryColor3ui, ( GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glSecondaryColor3uiv, ( const GLuint * ) ) \
    GL_FUNCTION( void, glSecondaryColor3us, ( GLushort, GLushort, GLushort ) ) \
    GL_FUNCTION( void, glSecondaryColor3usv, ( const GLushort * ) ) \
    GL_FUNCTION( void, glSecondaryColorPointer, ( GLint, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glWindowPos2d, ( GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glWindowPos2dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glWindowPos2f, ( GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glWindowPos2fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glWindowPos2i, ( GLint, GLint ) ) \
    GL_FUNCTION( void, glWindowPos2iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glWindowPos2s, ( GLshort, GLshort ) ) \
    GL_FUNCTION( void, glWindowPos2sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glWindowPos3d, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glWindowPos3dv, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glWindowPos3f, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glWindowPos3fv, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glWindowPos3i, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glWindowPos3iv, ( const GLint * ) ) \
    GL_FUNCTION( void, glWindowPos3s, ( GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glWindowPos3sv, ( const GLshort * ) ) \
    GL_FUNCTION( void, glBlendColor, ( GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glBlendEquation, ( GLenum ) ) \
    \
    /* GL_VERSION_1_5 */ \
    GL_FUNCTION( void, glGenQueries, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glDeleteQueries, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsQuery, ( GLuint ) ) \
    GL_FUNCTION( void, glBeginQuery, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glEndQuery, ( GLenum ) ) \
    GL_FUNCTION( void, glGetQueryiv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetQueryObjectiv, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetQueryObjectuiv, ( GLuint, GLenum, GLuint * ) ) \
    GL_FUNCTION( void, glBindBuffer, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDeleteBuffers, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenBuffers, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsBuffer, ( GLuint ) ) \
    GL_FUNCTION( void, glBufferData, ( GLenum, GLsizeiptr, const GLvoid *, GLenum ) ) \
    GL_FUNCTION( void, glBufferSubData, ( GLenum, GLintptr, GLsizeiptr, const GLvoid * ) ) \
    GL_FUNCTION( void, glGetBufferSubData, ( GLenum, GLintptr, GLsizeiptr, GLvoid * ) ) \
    GL_FUNCTION( void *, glMapBuffer, ( GLenum, GLenum ) ) \
    GL_FUNCTION( GLboolean, glUnmapBuffer, ( GLenum ) ) \
    GL_FUNCTION( void, glGetBufferParameteriv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetBufferPointerv, ( GLenum, GLenum, GLvoid ** ) ) \
    \
    /* GL_VERSION_2_0 */ \
    GL_FUNCTION( void, glBlendEquationSeparate, ( GLenum, GLenum ) ) \
    GL_FUNCTION( void, glDrawBuffers, ( GLsizei, const GLenum * ) ) \
    GL_FUNCTION( void, glStencilOpSeparate, ( GLenum, GLenum, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glStencilFuncSeparate, ( GLenum, GLenum, GLint, GLuint ) ) \
    GL_FUNCTION( void, glStencilMaskSeparate, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glAttachShader, ( GLuint, GLuint ) ) \
    GL_FUNCTION( void, glBindAttribLocation, ( GLuint, GLuint, const GLchar * ) ) \
    GL_FUNCTION( void, glCompileShader, ( GLuint ) ) \
    GL_FUNCTION( GLuint, glCreateProgram, ( ) ) \
    GL_FUNCTION( GLuint, glCreateShader, ( GLenum ) ) \
    GL_FUNCTION( void, glDeleteProgram, ( GLuint ) ) \
    GL_FUNCTION( void, glDeleteShader, ( GLuint ) ) \
    GL_FUNCTION( void, glDetachShader, ( GLuint, GLuint ) ) \
    GL_FUNCTION( void, glDisableVertexAttribArray, ( GLuint ) ) \
    GL_FUNCTION( void, glEnableVertexAttribArray, ( GLuint ) ) \
    GL_FUNCTION( void, glGetActiveAttrib, ( GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar * ) ) \
    GL_FUNCTION( void, glGetActiveUniform, ( GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar * ) ) \
    GL_FUNCTION( void, glGetAttachedShaders, ( GLuint, GLsizei, GLsizei *, GLuint * ) ) \
    GL_FUNCTION( GLint, glGetAttribLocation, ( GLuint, const GLchar * ) ) \
    GL_FUNCTION( void, glGetProgramiv, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetProgramInfoLog, ( GLuint, GLsizei, GLsizei *, GLchar * ) ) \
    GL_FUNCTION( void, glGetShaderiv, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetShaderInfoLog, ( GLuint, GLsizei, GLsizei *, GLchar * ) ) \
    GL_FUNCTION( void, glGetShaderSource, ( GLuint, GLsizei, GLsizei *, GLchar * ) ) \
    GL_FUNCTION( GLint, glGetUniformLocation, ( GLuint, const GLchar * ) ) \
    GL_FUNCTION( void, glGetUniformfv, ( GLuint, GLint, GLfloat * ) ) \
    GL_FUNCTION( void, glGetUniformiv, ( GLuint, GLint, GLint * ) ) \
    GL_FUNCTION( void, glGetVertexAttribdv, ( GLuint, GLenum, GLdouble * ) ) \
    GL_FUNCTION( void, glGetVertexAttribfv, ( GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetVertexAttribiv, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetVertexAttribPointerv, ( GLuint, GLenum, GLvoid ** ) ) \
    GL_FUNCTION( GLboolean, glIsProgram, ( GLuint ) ) \
    GL_FUNCTION( GLboolean, glIsShader, ( GLuint ) ) \
    GL_FUNCTION( void, glLinkProgram, ( GLuint ) ) \
    GL_FUNCTION( void, glShaderSource, ( GLuint, GLsizei, const GLchar *const*, const GLint * ) ) \
    GL_FUNCTION( void, glUseProgram, ( GLuint ) ) \
    GL_FUNCTION( void, glUniform1f, ( GLint, GLfloat ) ) \
    GL_FUNCTION( void, glUniform2f, ( GLint, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glUniform3f, ( GLint, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glUniform4f, ( GLint, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glUniform1i, ( GLint, GLint ) ) \
    GL_FUNCTION( void, glUniform2i, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glUniform3i, ( GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glUniform4i, ( GLint, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glUniform1fv, ( GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniform2fv, ( GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniform3fv, ( GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniform4fv, ( GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniform1iv, ( GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glUniform2iv, ( GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glUniform3iv, ( GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glUniform4iv, ( GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glUniformMatrix2fv, ( GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniformMatrix3fv, ( GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniformMatrix4fv, ( GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glValidateProgram, ( GLuint ) ) \
    GL_FUNCTION( void, glVertexAttrib1d, ( GLuint, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttrib1dv, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttrib1f, ( GLuint, GLfloat ) ) \
    GL_FUNCTION( void, glVertexAttrib1fv, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttrib1s, ( GLuint, GLshort ) ) \
    GL_FUNCTION( void, glVertexAttrib1sv, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib2d, ( GLuint, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttrib2dv, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttrib2f, ( GLuint, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertexAttrib2fv, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttrib2s, ( GLuint, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertexAttrib2sv, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib3d, ( GLuint, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttrib3dv, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttrib3f, ( GLuint, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertexAttrib3fv, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttrib3s, ( GLuint, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertexAttrib3sv, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib4Nbv, ( GLuint, const GLbyte * ) ) \
    GL_FUNCTION( void, glVertexAttrib4Niv, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glVertexAttrib4Nsv, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib4Nub, ( GLuint, GLubyte, GLubyte, GLubyte, GLubyte ) ) \
    GL_FUNCTION( void, glVertexAttrib4Nubv, ( GLuint, const GLubyte * ) ) \
    GL_FUNCTION( void, glVertexAttrib4Nuiv, ( GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttrib4Nusv, ( GLuint, const GLushort * ) ) \
    GL_FUNCTION( void, glVertexAttrib4bv, ( GLuint, const GLbyte * ) ) \
    GL_FUNCTION( void, glVertexAttrib4d, ( GLuint, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttrib4dv, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttrib4f, ( GLuint, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertexAttrib4fv, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttrib4iv, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glVertexAttrib4s, ( GLuint, GLshort, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertexAttrib4sv, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib4ubv, ( GLuint, const GLubyte * ) ) \
    GL_FUNCTION( void, glVertexAttrib4uiv, ( GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttrib4usv, ( GLuint, const GLushort * ) ) \
    GL_FUNCTION( void, glVertexAttribPointer, ( GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid * ) ) \
    \
    /* GL_VERSION_2_1 */ \
    GL_FUNCTION( void, glUniformMatrix2x3fv, ( GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniformMatrix3x2fv, ( GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniformMatrix2x4fv, ( GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniformMatrix4x2fv, ( GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniformMatrix3x4fv, ( GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniformMatrix4x3fv, ( GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    \
    /* GL_VERSION_3_0 */ \
    GL_FUNCTION( void, glColorMaski, ( GLuint, GLboolean, GLboolean, GLboolean, GLboolean ) ) \
    GL_FUNCTION( void, glGetBooleani_v, ( GLenum, GLuint, GLboolean * ) ) \
    GL_FUNCTION( void, glGetIntegeri_v, ( GLenum, GLuint, GLint * ) ) \
    GL_FUNCTION( void, glEnablei, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDisablei, ( GLenum, GLuint ) ) \
    GL_FUNCTION( GLboolean, glIsEnabledi, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glBeginTransformFeedback, ( GLenum ) ) \
    GL_FUNCTION( void, glEndTransformFeedback, ( ) ) \
    GL_FUNCTION( void, glBindBufferRange, ( GLenum, GLuint, GLuint, GLintptr, GLsizeiptr ) ) \
    GL_FUNCTION( void, glBindBufferBase, ( GLenum, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glTransformFeedbackVaryings, ( GLuint, GLsizei, const GLchar *const*, GLenum ) ) \
    GL_FUNCTION( void, glGetTransformFeedbackVarying, ( GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar * ) ) \
    GL_FUNCTION( void, glClampColor, ( GLenum, GLenum ) ) \
    GL_FUNCTION( void, glBeginConditionalRender, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glEndConditionalRender, ( ) ) \
    GL_FUNCTION( void, glVertexAttribIPointer, ( GLuint, GLint, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glGetVertexAttribIiv, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetVertexAttribIuiv, ( GLuint, GLenum, GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttribI1i, ( GLuint, GLint ) ) \
    GL_FUNCTION( void, glVertexAttribI2i, ( GLuint, GLint, GLint ) ) \
    GL_FUNCTION( void, glVertexAttribI3i, ( GLuint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glVertexAttribI4i, ( GLuint, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glVertexAttribI1ui, ( GLuint, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribI2ui, ( GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribI3ui, ( GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribI4ui, ( GLuint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribI1iv, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glVertexAttribI2iv, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glVertexAttribI3iv, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glVertexAttribI4iv, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glVertexAttribI1uiv, ( GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttribI2uiv, ( GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttribI3uiv, ( GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttribI4uiv, ( GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttribI4bv, ( GLuint, const GLbyte * ) ) \
    GL_FUNCTION( void, glVertexAttribI4sv, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttribI4ubv, ( GLuint, const GLubyte * ) ) \
    GL_FUNCTION( void, glVertexAttribI4usv, ( GLuint, const GLushort * ) ) \
    GL_FUNCTION( void, glGetUniformuiv, ( GLuint, GLint, GLuint * ) ) \
    GL_FUNCTION( void, glBindFragDataLocation, ( GLuint, GLuint, const GLchar * ) ) \
    GL_FUNCTION( GLint, glGetFragDataLocation, ( GLuint, const GLchar * ) ) \
    GL_FUNCTION( void, glUniform1ui, ( GLint, GLuint ) ) \
    GL_FUNCTION( void, glUniform2ui, ( GLint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glUniform3ui, ( GLint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glUniform4ui, ( GLint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glUniform1uiv, ( GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glUniform2uiv, ( GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glUniform3uiv, ( GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glUniform4uiv, ( GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glTexParameterIiv, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glTexParameterIuiv, ( GLenum, GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glGetTexParameterIiv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetTexParameterIuiv, ( GLenum, GLenum, GLuint * ) ) \
    GL_FUNCTION( void, glClearBufferiv, ( GLenum, GLint, const GLint * ) ) \
    GL_FUNCTION( void, glClearBufferuiv, ( GLenum, GLint, const GLuint * ) ) \
    GL_FUNCTION( void, glClearBufferfv, ( GLenum, GLint, const GLfloat * ) ) \
    GL_FUNCTION( void, glClearBufferfi, ( GLenum, GLint, GLfloat, GLint ) ) \
    GL_FUNCTION( const GLubyte *, glGetStringi, ( GLenum, GLuint ) ) \
    GL_FUNCTION( GLboolean, glIsRenderbuffer, ( GLuint ) ) \
    GL_FUNCTION( void, glBindRenderbuffer, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDeleteRenderbuffers, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenRenderbuffers, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glRenderbufferStorage, ( GLenum, GLenum, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glGetRenderbufferParameteriv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( GLboolean, glIsFramebuffer, ( GLuint ) ) \
    GL_FUNCTION( void, glBindFramebuffer, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDeleteFramebuffers, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenFramebuffers, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( GLenum, glCheckFramebufferStatus, ( GLenum ) ) \
    GL_FUNCTION( void, glFramebufferTexture1D, ( GLenum, GLenum, GLenum, GLuint, GLint ) ) \
    GL_FUNCTION( void, glFramebufferTexture2D, ( GLenum, GLenum, GLenum, GLuint, GLint ) ) \
    GL_FUNCTION( void, glFramebufferTexture3D, ( GLenum, GLenum, GLenum, GLuint, GLint, GLint ) ) \
    GL_FUNCTION( void, glFramebufferRenderbuffer, ( GLenum, GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glGetFramebufferAttachmentParameteriv, ( GLenum, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGenerateMipmap, ( GLenum ) ) \
    GL_FUNCTION( void, glBlitFramebuffer, ( GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum ) ) \
    GL_FUNCTION( void, glRenderbufferStorageMultisample, ( GLenum, GLsizei, GLenum, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glFramebufferTextureLayer, ( GLenum, GLenum, GLuint, GLint, GLint ) ) \
    GL_FUNCTION( void *, glMapBufferRange, ( GLenum, GLintptr, GLsizeiptr, GLbitfield ) ) \
    GL_FUNCTION( void, glFlushMappedBufferRange, ( GLenum, GLintptr, GLsizeiptr ) ) \
    GL_FUNCTION( void, glBindVertexArray, ( GLuint ) ) \
    GL_FUNCTION( void, glDeleteVertexArrays, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenVertexArrays, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsVertexArray, ( GLuint ) ) \
    \
    /* GL_VERSION_3_1 */ \
    GL_FUNCTION( void, glDrawArraysInstanced, ( GLenum, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glDrawElementsInstanced, ( GLenum, GLsizei, GLenum, const GLvoid *, GLsizei ) ) \
    GL_FUNCTION( void, glTexBuffer, ( GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glPrimitiveRestartIndex, ( GLuint ) ) \
    GL_FUNCTION( void, glCopyBufferSubData, ( GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr ) ) \
    GL_FUNCTION( void, glGetUniformIndices, ( GLuint, GLsizei, const GLchar *const*, GLuint * ) ) \
    GL_FUNCTION( void, glGetActiveUniformsiv, ( GLuint, GLsizei, const GLuint *, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetActiveUniformName, ( GLuint, GLuint, GLsizei, GLsizei *, GLchar * ) ) \
    GL_FUNCTION( GLuint, glGetUniformBlockIndex, ( GLuint, const GLchar * ) ) \
    GL_FUNCTION( void, glGetActiveUniformBlockiv, ( GLuint, GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetActiveUniformBlockName, ( GLuint, GLuint, GLsizei, GLsizei *, GLchar * ) ) \
    GL_FUNCTION( void, glUniformBlockBinding, ( GLuint, GLuint, GLuint ) ) \
    \
    /* GL_VERSION_3_2 */ \
    GL_FUNCTION( void, glDrawElementsBaseVertex, ( GLenum, GLsizei, GLenum, const GLvoid *, GLint ) ) \
    GL_FUNCTION( void, glDrawRangeElementsBaseVertex, ( GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *, GLint ) ) \
    GL_FUNCTION( void, glDrawElementsInstancedBaseVertex, ( GLenum, GLsizei, GLenum, const GLvoid *, GLsizei, GLint ) ) \
    GL_FUNCTION( void, glMultiDrawElementsBaseVertex, ( GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glProvokingVertex, ( GLenum ) ) \
    GL_FUNCTION( GLsync, glFenceSync, ( GLenum, GLbitfield ) ) \
    GL_FUNCTION( GLboolean, glIsSync, ( GLsync ) ) \
    GL_FUNCTION( void, glDeleteSync, ( GLsync ) ) \
    GL_FUNCTION( GLenum, glClientWaitSync, ( GLsync, GLbitfield, GLuint64 ) ) \
    GL_FUNCTION( void, glWaitSync, ( GLsync, GLbitfield, GLuint64 ) ) \
    GL_FUNCTION( void, glGetInteger64v, ( GLenum, GLint64 * ) ) \
    GL_FUNCTION( void, glGetSynciv, ( GLsync, GLenum, GLsizei, GLsizei *, GLint * ) ) \
    GL_FUNCTION( void, glGetInteger64i_v, ( GLenum, GLuint, GLint64 * ) ) \
    GL_FUNCTION( void, glGetBufferParameteri64v, ( GLenum, GLenum, GLint64 * ) ) \
    GL_FUNCTION( void, glFramebufferTexture, ( GLenum, GLenum, GLuint, GLint ) ) \
    GL_FUNCTION( void, glTexImage2DMultisample, ( GLenum, GLsizei, GLint, GLsizei, GLsizei, GLboolean ) ) \
    GL_FUNCTION( void, glTexImage3DMultisample, ( GLenum, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean ) ) \
    GL_FUNCTION( void, glGetMultisamplefv, ( GLenum, GLuint, GLfloat * ) ) \
    GL_FUNCTION( void, glSampleMaski, ( GLuint, GLbitfield ) ) \
    \
    /* GL_VERSION_3_3 */ \
    GL_FUNCTION( void, glBindFragDataLocationIndexed, ( GLuint, GLuint, GLuint, const GLchar * ) ) \
    GL_FUNCTION( GLint, glGetFragDataIndex, ( GLuint, const GLchar * ) ) \
    GL_FUNCTION( void, glGenSamplers, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glDeleteSamplers, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsSampler, ( GLuint ) ) \
    GL_FUNCTION( void, glBindSampler, ( GLuint, GLuint ) ) \
    GL_FUNCTION( void, glSamplerParameteri, ( GLuint, GLenum, GLint ) ) \
    GL_FUNCTION( void, glSamplerParameteriv, ( GLuint, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glSamplerParameterf, ( GLuint, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glSamplerParameterfv, ( GLuint, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glSamplerParameterIiv, ( GLuint, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glSamplerParameterIuiv, ( GLuint, GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glGetSamplerParameteriv, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetSamplerParameterIiv, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetSamplerParameterfv, ( GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetSamplerParameterIuiv, ( GLuint, GLenum, GLuint * ) ) \
    GL_FUNCTION( void, glQueryCounter, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glGetQueryObjecti64v, ( GLuint, GLenum, GLint64 * ) ) \
    GL_FUNCTION( void, glGetQueryObjectui64v, ( GLuint, GLenum, GLuint64 * ) ) \
    GL_FUNCTION( void, glVertexAttribDivisor, ( GLuint, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribP1ui, ( GLuint, GLenum, GLboolean, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribP1uiv, ( GLuint, GLenum, GLboolean, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttribP2ui, ( GLuint, GLenum, GLboolean, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribP2uiv, ( GLuint, GLenum, GLboolean, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttribP3ui, ( GLuint, GLenum, GLboolean, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribP3uiv, ( GLuint, GLenum, GLboolean, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttribP4ui, ( GLuint, GLenum, GLboolean, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribP4uiv, ( GLuint, GLenum, GLboolean, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexP2ui, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glVertexP2uiv, ( GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexP3ui, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glVertexP3uiv, ( GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexP4ui, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glVertexP4uiv, ( GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glTexCoordP1ui, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glTexCoordP1uiv, ( GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glTexCoordP2ui, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glTexCoordP2uiv, ( GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glTexCoordP3ui, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glTexCoordP3uiv, ( GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glTexCoordP4ui, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glTexCoordP4uiv, ( GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glMultiTexCoordP1ui, ( GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glMultiTexCoordP1uiv, ( GLenum, GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glMultiTexCoordP2ui, ( GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glMultiTexCoordP2uiv, ( GLenum, GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glMultiTexCoordP3ui, ( GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glMultiTexCoordP3uiv, ( GLenum, GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glMultiTexCoordP4ui, ( GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glMultiTexCoordP4uiv, ( GLenum, GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glNormalP3ui, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glNormalP3uiv, ( GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glColorP3ui, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glColorP3uiv, ( GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glColorP4ui, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glColorP4uiv, ( GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glSecondaryColorP3ui, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glSecondaryColorP3uiv, ( GLenum, const GLuint * ) ) \
    \
    /* GL_VERSION_4_0 */ \
    GL_FUNCTION( void, glMinSampleShading, ( GLfloat ) ) \
    GL_FUNCTION( void, glBlendEquationi, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glBlendEquationSeparatei, ( GLuint, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glBlendFunci, ( GLuint, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glBlendFuncSeparatei, ( GLuint, GLenum, GLenum, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glDrawArraysIndirect, ( GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glDrawElementsIndirect, ( GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glUniform1d, ( GLint, GLdouble ) ) \
    GL_FUNCTION( void, glUniform2d, ( GLint, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glUniform3d, ( GLint, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glUniform4d, ( GLint, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glUniform1dv, ( GLint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glUniform2dv, ( GLint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glUniform3dv, ( GLint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glUniform4dv, ( GLint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glUniformMatrix2dv, ( GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glUniformMatrix3dv, ( GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glUniformMatrix4dv, ( GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glUniformMatrix2x3dv, ( GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glUniformMatrix2x4dv, ( GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glUniformMatrix3x2dv, ( GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glUniformMatrix3x4dv, ( GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glUniformMatrix4x2dv, ( GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glUniformMatrix4x3dv, ( GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glGetUniformdv, ( GLuint, GLint, GLdouble * ) ) \
    GL_FUNCTION( GLint, glGetSubroutineUniformLocation, ( GLuint, GLenum, const GLchar * ) ) \
    GL_FUNCTION( GLuint, glGetSubroutineIndex, ( GLuint, GLenum, const GLchar * ) ) \
    GL_FUNCTION( void, glGetActiveSubroutineUniformiv, ( GLuint, GLenum, GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetActiveSubroutineUniformName, ( GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar * ) ) \
    GL_FUNCTION( void, glGetActiveSubroutineName, ( GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar * ) ) \
    GL_FUNCTION( void, glUniformSubroutinesuiv, ( GLenum, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGetUniformSubroutineuiv, ( GLenum, GLint, GLuint * ) ) \
    GL_FUNCTION( void, glGetProgramStageiv, ( GLuint, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glPatchParameteri, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glPatchParameterfv, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glBindTransformFeedback, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDeleteTransformFeedbacks, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenTransformFeedbacks, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsTransformFeedback, ( GLuint ) ) \
    GL_FUNCTION( void, glPauseTransformFeedback, ( ) ) \
    GL_FUNCTION( void, glResumeTransformFeedback, ( ) ) \
    GL_FUNCTION( void, glDrawTransformFeedback, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDrawTransformFeedbackStream, ( GLenum, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glBeginQueryIndexed, ( GLenum, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glEndQueryIndexed, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glGetQueryIndexediv, ( GLenum, GLuint, GLenum, GLint * ) ) \
    \
    /* GL_VERSION_4_1 */ \
    GL_FUNCTION( void, glReleaseShaderCompiler, ( ) ) \
    GL_FUNCTION( void, glShaderBinary, ( GLsizei, const GLuint *, GLenum, const GLvoid *, GLsizei ) ) \
    GL_FUNCTION( void, glGetShaderPrecisionFormat, ( GLenum, GLenum, GLint *, GLint * ) ) \
    GL_FUNCTION( void, glDepthRangef, ( GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glClearDepthf, ( GLfloat ) ) \
    GL_FUNCTION( void, glGetProgramBinary, ( GLuint, GLsizei, GLsizei *, GLenum *, GLvoid * ) ) \
    GL_FUNCTION( void, glProgramBinary, ( GLuint, GLenum, const GLvoid *, GLsizei ) ) \
    GL_FUNCTION( void, glProgramParameteri, ( GLuint, GLenum, GLint ) ) \
    GL_FUNCTION( void, glUseProgramStages, ( GLuint, GLbitfield, GLuint ) ) \
    GL_FUNCTION( void, glActiveShaderProgram, ( GLuint, GLuint ) ) \
    GL_FUNCTION( GLuint, glCreateShaderProgramv, ( GLenum, GLsizei, const GLchar *const* ) ) \
    GL_FUNCTION( void, glBindProgramPipeline, ( GLuint ) ) \
    GL_FUNCTION( void, glDeleteProgramPipelines, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenProgramPipelines, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsProgramPipeline, ( GLuint ) ) \
    GL_FUNCTION( void, glGetProgramPipelineiv, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glProgramUniform1i, ( GLuint, GLint, GLint ) ) \
    GL_FUNCTION( void, glProgramUniform1iv, ( GLuint, GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glProgramUniform1f, ( GLuint, GLint, GLfloat ) ) \
    GL_FUNCTION( void, glProgramUniform1fv, ( GLuint, GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniform1d, ( GLuint, GLint, GLdouble ) ) \
    GL_FUNCTION( void, glProgramUniform1dv, ( GLuint, GLint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniform1ui, ( GLuint, GLint, GLuint ) ) \
    GL_FUNCTION( void, glProgramUniform1uiv, ( GLuint, GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glProgramUniform2i, ( GLuint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glProgramUniform2iv, ( GLuint, GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glProgramUniform2f, ( GLuint, GLint, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glProgramUniform2fv, ( GLuint, GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniform2d, ( GLuint, GLint, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glProgramUniform2dv, ( GLuint, GLint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniform2ui, ( GLuint, GLint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glProgramUniform2uiv, ( GLuint, GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glProgramUniform3i, ( GLuint, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glProgramUniform3iv, ( GLuint, GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glProgramUniform3f, ( GLuint, GLint, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glProgramUniform3fv, ( GLuint, GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniform3d, ( GLuint, GLint, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glProgramUniform3dv, ( GLuint, GLint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniform3ui, ( GLuint, GLint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glProgramUniform3uiv, ( GLuint, GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glProgramUniform4i, ( GLuint, GLint, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glProgramUniform4iv, ( GLuint, GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glProgramUniform4f, ( GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glProgramUniform4fv, ( GLuint, GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniform4d, ( GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glProgramUniform4dv, ( GLuint, GLint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniform4ui, ( GLuint, GLint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glProgramUniform4uiv, ( GLuint, GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix2fv, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix3fv, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix4fv, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix2dv, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix3dv, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix4dv, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix2x3fv, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix3x2fv, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix2x4fv, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix4x2fv, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix3x4fv, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix4x3fv, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix2x3dv, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix3x2dv, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix2x4dv, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix4x2dv, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix3x4dv, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix4x3dv, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glValidateProgramPipeline, ( GLuint ) ) \
    GL_FUNCTION( void, glGetProgramPipelineInfoLog, ( GLuint, GLsizei, GLsizei *, GLchar * ) ) \
    GL_FUNCTION( void, glVertexAttribL1d, ( GLuint, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttribL2d, ( GLuint, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttribL3d, ( GLuint, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttribL4d, ( GLuint, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttribL1dv, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttribL2dv, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttribL3dv, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttribL4dv, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttribLPointer, ( GLuint, GLint, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glGetVertexAttribLdv, ( GLuint, GLenum, GLdouble * ) ) \
    GL_FUNCTION( void, glViewportArrayv, ( GLuint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glViewportIndexedf, ( GLuint, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glViewportIndexedfv, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glScissorArrayv, ( GLuint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glScissorIndexed, ( GLuint, GLint, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glScissorIndexedv, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glDepthRangeArrayv, ( GLuint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glDepthRangeIndexed, ( GLuint, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glGetFloati_v, ( GLenum, GLuint, GLfloat * ) ) \
    GL_FUNCTION( void, glGetDoublei_v, ( GLenum, GLuint, GLdouble * ) ) \
    \
    /* GL_VERSION_4_2 */ \
    GL_FUNCTION( void, glDrawArraysInstancedBaseInstance, ( GLenum, GLint, GLsizei, GLsizei, GLuint ) ) \
    GL_FUNCTION( void, glDrawElementsInstancedBaseInstance, ( GLenum, GLsizei, GLenum, const void *, GLsizei, GLuint ) ) \
    GL_FUNCTION( void, glDrawElementsInstancedBaseVertexBaseInstance, ( GLenum, GLsizei, GLenum, const void *, GLsizei, GLint, GLuint ) ) \
    GL_FUNCTION( void, glGetInternalformativ, ( GLenum, GLenum, GLenum, GLsizei, GLint * ) ) \
    GL_FUNCTION( void, glGetActiveAtomicCounterBufferiv, ( GLuint, GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glBindImageTexture, ( GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glMemoryBarrier, ( GLbitfield ) ) \
    GL_FUNCTION( void, glTexStorage1D, ( GLenum, GLsizei, GLenum, GLsizei ) ) \
    GL_FUNCTION( void, glTexStorage2D, ( GLenum, GLsizei, GLenum, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glTexStorage3D, ( GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glDrawTransformFeedbackInstanced, ( GLenum, GLuint, GLsizei ) ) \
    GL_FUNCTION( void, glDrawTransformFeedbackStreamInstanced, ( GLenum, GLuint, GLuint, GLsizei ) ) \
    \
    /* GL_VERSION_4_3 */ \
    GL_FUNCTION( void, glClearBufferData, ( GLenum, GLenum, GLenum, GLenum, const void * ) ) \
    GL_FUNCTION( void, glClearBufferSubData, ( GLenum, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void * ) ) \
    GL_FUNCTION( void, glDispatchCompute, ( GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glDispatchComputeIndirect, ( GLintptr ) ) \
    GL_FUNCTION( void, glCopyImageSubData, ( GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glFramebufferParameteri, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glGetFramebufferParameteriv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetInternalformati64v, ( GLenum, GLenum, GLenum, GLsizei, GLint64 * ) ) \
    GL_FUNCTION( void, glInvalidateTexSubImage, ( GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glInvalidateTexImage, ( GLuint, GLint ) ) \
    GL_FUNCTION( void, glInvalidateBufferSubData, ( GLuint, GLintptr, GLsizeiptr ) ) \
    GL_FUNCTION( void, glInvalidateBufferData, ( GLuint ) ) \
    GL_FUNCTION( void, glInvalidateFramebuffer, ( GLenum, GLsizei, const GLenum * ) ) \
    GL_FUNCTION( void, glInvalidateSubFramebuffer, ( GLenum, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glMultiDrawArraysIndirect, ( GLenum, const void *, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glMultiDrawElementsIndirect, ( GLenum, GLenum, const void *, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glGetProgramInterfaceiv, ( GLuint, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( GLuint, glGetProgramResourceIndex, ( GLuint, GLenum, const GLchar * ) ) \
    GL_FUNCTION( void, glGetProgramResourceName, ( GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar * ) ) \
    GL_FUNCTION( void, glGetProgramResourceiv, ( GLuint, GLenum, GLuint, GLsizei, const GLenum *, GLsizei, GLsizei *, GLint * ) ) \
    GL_FUNCTION( GLint, glGetProgramResourceLocation, ( GLuint, GLenum, const GLchar * ) ) \
    GL_FUNCTION( GLint, glGetProgramResourceLocationIndex, ( GLuint, GLenum, const GLchar * ) ) \
    GL_FUNCTION( void, glShaderStorageBlockBinding, ( GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glTexBufferRange, ( GLenum, GLenum, GLuint, GLintptr, GLsizeiptr ) ) \
    GL_FUNCTION( void, glTexStorage2DMultisample, ( GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean ) ) \
    GL_FUNCTION( void, glTexStorage3DMultisample, ( GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean ) ) \
    GL_FUNCTION( void, glTextureView, ( GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glBindVertexBuffer, ( GLuint, GLuint, GLintptr, GLsizei ) ) \
    GL_FUNCTION( void, glVertexAttribFormat, ( GLuint, GLint, GLenum, GLboolean, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribIFormat, ( GLuint, GLint, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribLFormat, ( GLuint, GLint, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribBinding, ( GLuint, GLuint ) ) \
    GL_FUNCTION( void, glVertexBindingDivisor, ( GLuint, GLuint ) ) \
    GL_FUNCTION( void, glDebugMessageControl, ( GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean ) ) \
    GL_FUNCTION( void, glDebugMessageInsert, ( GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar * ) ) \
    GL_FUNCTION( void, glDebugMessageCallback, ( GLDEBUGPROC, const void * ) ) \
    GL_FUNCTION( GLuint, glGetDebugMessageLog, ( GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar * ) ) \
    GL_FUNCTION( void, glPushDebugGroup, ( GLenum, GLuint, GLsizei, const GLchar * ) ) \
    GL_FUNCTION( void, glPopDebugGroup, ( ) ) \
    GL_FUNCTION( void, glObjectLabel, ( GLenum, GLuint, GLsizei, const GLchar * ) ) \
    GL_FUNCTION( void, glGetObjectLabel, ( GLenum, GLuint, GLsizei, GLsizei *, GLchar * ) ) \
    GL_FUNCTION( void, glObjectPtrLabel, ( const void *, GLsizei, const GLchar * ) ) \
    GL_FUNCTION( void, glGetObjectPtrLabel, ( const void *, GLsizei, GLsizei *, GLchar * ) ) \
    \
    /* GL_VERSION_4_4 */ \
    GL_FUNCTION( void, glBufferStorage, ( GLenum, GLsizeiptr, const void *, GLbitfield ) ) \
    GL_FUNCTION( void, glClearTexImage, ( GLuint, GLint, GLenum, GLenum, const void * ) ) \
    GL_FUNCTION( void, glClearTexSubImage, ( GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void * ) ) \
    GL_FUNCTION( void, glBindBuffersBase, ( GLenum, GLuint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glBindBuffersRange, ( GLenum, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizeiptr * ) ) \
    GL_FUNCTION( void, glBindTextures, ( GLuint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glBindSamplers, ( GLuint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glBindImageTextures, ( GLuint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glBindVertexBuffers, ( GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei * ) ) \
    \
    /* GL_ARB_ES2_compatibility */ \
    \
    /* GL_ARB_ES3_compatibility */ \
    \
    /* GL_ARB_arrays_of_arrays */ \
    \
    /* GL_ARB_base_instance */ \
    \
    /* GL_ARB_bindless_texture */ \
    GL_FUNCTION( GLuint64, glGetTextureHandleARB, ( GLuint ) ) \
    GL_FUNCTION( GLuint64, glGetTextureSamplerHandleARB, ( GLuint, GLuint ) ) \
    GL_FUNCTION( void, glMakeTextureHandleResidentARB, ( GLuint64 ) ) \
    GL_FUNCTION( void, glMakeTextureHandleNonResidentARB, ( GLuint64 ) ) \
    GL_FUNCTION( GLuint64, glGetImageHandleARB, ( GLuint, GLint, GLboolean, GLint, GLenum ) ) \
    GL_FUNCTION( void, glMakeImageHandleResidentARB, ( GLuint64, GLenum ) ) \
    GL_FUNCTION( void, glMakeImageHandleNonResidentARB, ( GLuint64 ) ) \
    GL_FUNCTION( void, glUniformHandleui64ARB, ( GLint, GLuint64 ) ) \
    GL_FUNCTION( void, glUniformHandleui64vARB, ( GLint, GLsizei, const GLuint64 * ) ) \
    GL_FUNCTION( void, glProgramUniformHandleui64ARB, ( GLuint, GLint, GLuint64 ) ) \
    GL_FUNCTION( void, glProgramUniformHandleui64vARB, ( GLuint, GLint, GLsizei, const GLuint64 * ) ) \
    GL_FUNCTION( GLboolean, glIsTextureHandleResidentARB, ( GLuint64 ) ) \
    GL_FUNCTION( GLboolean, glIsImageHandleResidentARB, ( GLuint64 ) ) \
    GL_FUNCTION( void, glVertexAttribL1ui64ARB, ( GLuint, GLuint64EXT ) ) \
    GL_FUNCTION( void, glVertexAttribL1ui64vARB, ( GLuint, const GLuint64EXT * ) ) \
    GL_FUNCTION( void, glGetVertexAttribLui64vARB, ( GLuint, GLenum, GLuint64EXT * ) ) \
    \
    /* GL_ARB_blend_func_extended */ \
    \
    /* GL_ARB_buffer_storage */ \
    \
    /* GL_ARB_cl_event */ \
    GL_FUNCTION( GLsync, glCreateSyncFromCLeventARB, ( struct _cl_context *, struct _cl_event *, GLbitfield ) ) \
    \
    /* GL_ARB_clear_buffer_object */ \
    \
    /* GL_ARB_clear_texture */ \
    \
    /* GL_ARB_color_buffer_float */ \
    GL_FUNCTION( void, glClampColorARB, ( GLenum, GLenum ) ) \
    \
    /* GL_ARB_compatibility */ \
    \
    /* GL_ARB_compressed_texture_pixel_storage */ \
    \
    /* GL_ARB_compute_shader */ \
    \
    /* GL_ARB_compute_variable_group_size */ \
    GL_FUNCTION( void, glDispatchComputeGroupSizeARB, ( GLuint, GLuint, GLuint, GLuint, GLuint, GLuint ) ) \
    \
    /* GL_ARB_conservative_depth */ \
    \
    /* GL_ARB_copy_buffer */ \
    \
    /* GL_ARB_copy_image */ \
    \
    /* GL_ARB_debug_output */ \
    GL_FUNCTION( void, glDebugMessageControlARB, ( GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean ) ) \
    GL_FUNCTION( void, glDebugMessageInsertARB, ( GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar * ) ) \
    GL_FUNCTION( void, glDebugMessageCallbackARB, ( GLDEBUGPROCARB, const void * ) ) \
    GL_FUNCTION( GLuint, glGetDebugMessageLogARB, ( GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar * ) ) \
    \
    /* GL_ARB_depth_buffer_float */ \
    \
    /* GL_ARB_depth_clamp */ \
    \
    /* GL_ARB_depth_texture */ \
    \
    /* GL_ARB_draw_buffers */ \
    GL_FUNCTION( void, glDrawBuffersARB, ( GLsizei, const GLenum * ) ) \
    \
    /* GL_ARB_draw_buffers_blend */ \
    GL_FUNCTION( void, glBlendEquationiARB, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glBlendEquationSeparateiARB, ( GLuint, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glBlendFunciARB, ( GLuint, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glBlendFuncSeparateiARB, ( GLuint, GLenum, GLenum, GLenum, GLenum ) ) \
    \
    /* GL_ARB_draw_elements_base_vertex */ \
    \
    /* GL_ARB_draw_indirect */ \
    \
    /* GL_ARB_draw_instanced */ \
    GL_FUNCTION( void, glDrawArraysInstancedARB, ( GLenum, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glDrawElementsInstancedARB, ( GLenum, GLsizei, GLenum, const GLvoid *, GLsizei ) ) \
    \
    /* GL_ARB_enhanced_layouts */ \
    \
    /* GL_ARB_explicit_attrib_location */ \
    \
    /* GL_ARB_explicit_uniform_location */ \
    \
    /* GL_ARB_fragment_coord_conventions */ \
    \
    /* GL_ARB_fragment_layer_viewport */ \
    \
    /* GL_ARB_fragment_program */ \
    GL_FUNCTION( void, glProgramStringARB, ( GLenum, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glBindProgramARB, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDeleteProgramsARB, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenProgramsARB, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glProgramEnvParameter4dARB, ( GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glProgramEnvParameter4dvARB, ( GLenum, GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramEnvParameter4fARB, ( GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glProgramEnvParameter4fvARB, ( GLenum, GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramLocalParameter4dARB, ( GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glProgramLocalParameter4dvARB, ( GLenum, GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramLocalParameter4fARB, ( GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glProgramLocalParameter4fvARB, ( GLenum, GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glGetProgramEnvParameterdvARB, ( GLenum, GLuint, GLdouble * ) ) \
    GL_FUNCTION( void, glGetProgramEnvParameterfvARB, ( GLenum, GLuint, GLfloat * ) ) \
    GL_FUNCTION( void, glGetProgramLocalParameterdvARB, ( GLenum, GLuint, GLdouble * ) ) \
    GL_FUNCTION( void, glGetProgramLocalParameterfvARB, ( GLenum, GLuint, GLfloat * ) ) \
    GL_FUNCTION( void, glGetProgramivARB, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetProgramStringARB, ( GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( GLboolean, glIsProgramARB, ( GLuint ) ) \
    \
    /* GL_ARB_fragment_program_shadow */ \
    \
    /* GL_ARB_fragment_shader */ \
    \
    /* GL_ARB_framebuffer_no_attachments */ \
    \
    /* GL_ARB_framebuffer_object */ \
    \
    /* GL_ARB_framebuffer_sRGB */ \
    \
    /* GL_ARB_geometry_shader4 */ \
    GL_FUNCTION( void, glProgramParameteriARB, ( GLuint, GLenum, GLint ) ) \
    GL_FUNCTION( void, glFramebufferTextureARB, ( GLenum, GLenum, GLuint, GLint ) ) \
    GL_FUNCTION( void, glFramebufferTextureLayerARB, ( GLenum, GLenum, GLuint, GLint, GLint ) ) \
    GL_FUNCTION( void, glFramebufferTextureFaceARB, ( GLenum, GLenum, GLuint, GLint, GLenum ) ) \
    \
    /* GL_ARB_get_program_binary */ \
    \
    /* GL_ARB_gpu_shader5 */ \
    \
    /* GL_ARB_gpu_shader_fp64 */ \
    \
    /* GL_ARB_half_float_pixel */ \
    \
    /* GL_ARB_half_float_vertex */ \
    \
    /* GL_ARB_imaging */ \
    GL_FUNCTION( void, glColorTable, ( GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glColorTableParameterfv, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glColorTableParameteriv, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glCopyColorTable, ( GLenum, GLenum, GLint, GLint, GLsizei ) ) \
    GL_FUNCTION( void, glGetColorTable, ( GLenum, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGetColorTableParameterfv, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetColorTableParameteriv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glColorSubTable, ( GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glCopyColorSubTable, ( GLenum, GLsizei, GLint, GLint, GLsizei ) ) \
    GL_FUNCTION( void, glConvolutionFilter1D, ( GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glConvolutionFilter2D, ( GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glConvolutionParameterf, ( GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glConvolutionParameterfv, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glConvolutionParameteri, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glConvolutionParameteriv, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glCopyConvolutionFilter1D, ( GLenum, GLenum, GLint, GLint, GLsizei ) ) \
    GL_FUNCTION( void, glCopyConvolutionFilter2D, ( GLenum, GLenum, GLint, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glGetConvolutionFilter, ( GLenum, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGetConvolutionParameterfv, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetConvolutionParameteriv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetSeparableFilter, ( GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid * ) ) \
    GL_FUNCTION( void, glSeparableFilter2D, ( GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid * ) ) \
    GL_FUNCTION( void, glGetHistogram, ( GLenum, GLboolean, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGetHistogramParameterfv, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetHistogramParameteriv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetMinmax, ( GLenum, GLboolean, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGetMinmaxParameterfv, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetMinmaxParameteriv, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glHistogram, ( GLenum, GLsizei, GLenum, GLboolean ) ) \
    GL_FUNCTION( void, glMinmax, ( GLenum, GLenum, GLboolean ) ) \
    GL_FUNCTION( void, glResetHistogram, ( GLenum ) ) \
    GL_FUNCTION( void, glResetMinmax, ( GLenum ) ) \
    \
    /* GL_ARB_indirect_parameters */ \
    GL_FUNCTION( void, glMultiDrawArraysIndirectCountARB, ( GLenum, GLintptr, GLintptr, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glMultiDrawElementsIndirectCountARB, ( GLenum, GLenum, GLintptr, GLintptr, GLsizei, GLsizei ) ) \
    \
    /* GL_ARB_instanced_arrays */ \
    GL_FUNCTION( void, glVertexAttribDivisorARB, ( GLuint, GLuint ) ) \
    \
    /* GL_ARB_internalformat_query */ \
    \
    /* GL_ARB_internalformat_query2 */ \
    \
    /* GL_ARB_invalidate_subdata */ \
    \
    /* GL_ARB_map_buffer_alignment */ \
    \
    /* GL_ARB_map_buffer_range */ \
    \
    /* GL_ARB_matrix_palette */ \
    GL_FUNCTION( void, glCurrentPaletteMatrixARB, ( GLint ) ) \
    GL_FUNCTION( void, glMatrixIndexubvARB, ( GLint, const GLubyte * ) ) \
    GL_FUNCTION( void, glMatrixIndexusvARB, ( GLint, const GLushort * ) ) \
    GL_FUNCTION( void, glMatrixIndexuivARB, ( GLint, const GLuint * ) ) \
    GL_FUNCTION( void, glMatrixIndexPointerARB, ( GLint, GLenum, GLsizei, const GLvoid * ) ) \
    \
    /* GL_ARB_multi_bind */ \
    \
    /* GL_ARB_multi_draw_indirect */ \
    \
    /* GL_ARB_multisample */ \
    GL_FUNCTION( void, glSampleCoverageARB, ( GLfloat, GLboolean ) ) \
    \
    /* GL_ARB_multitexture */ \
    GL_FUNCTION( void, glActiveTextureARB, ( GLenum ) ) \
    GL_FUNCTION( void, glClientActiveTextureARB, ( GLenum ) ) \
    GL_FUNCTION( void, glMultiTexCoord1dARB, ( GLenum, GLdouble ) ) \
    GL_FUNCTION( void, glMultiTexCoord1dvARB, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glMultiTexCoord1fARB, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glMultiTexCoord1fvARB, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMultiTexCoord1iARB, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glMultiTexCoord1ivARB, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glMultiTexCoord1sARB, ( GLenum, GLshort ) ) \
    GL_FUNCTION( void, glMultiTexCoord1svARB, ( GLenum, const GLshort * ) ) \
    GL_FUNCTION( void, glMultiTexCoord2dARB, ( GLenum, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glMultiTexCoord2dvARB, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glMultiTexCoord2fARB, ( GLenum, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glMultiTexCoord2fvARB, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMultiTexCoord2iARB, ( GLenum, GLint, GLint ) ) \
    GL_FUNCTION( void, glMultiTexCoord2ivARB, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glMultiTexCoord2sARB, ( GLenum, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glMultiTexCoord2svARB, ( GLenum, const GLshort * ) ) \
    GL_FUNCTION( void, glMultiTexCoord3dARB, ( GLenum, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glMultiTexCoord3dvARB, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glMultiTexCoord3fARB, ( GLenum, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glMultiTexCoord3fvARB, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMultiTexCoord3iARB, ( GLenum, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glMultiTexCoord3ivARB, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glMultiTexCoord3sARB, ( GLenum, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glMultiTexCoord3svARB, ( GLenum, const GLshort * ) ) \
    GL_FUNCTION( void, glMultiTexCoord4dARB, ( GLenum, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glMultiTexCoord4dvARB, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glMultiTexCoord4fARB, ( GLenum, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glMultiTexCoord4fvARB, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMultiTexCoord4iARB, ( GLenum, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glMultiTexCoord4ivARB, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glMultiTexCoord4sARB, ( GLenum, GLshort, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glMultiTexCoord4svARB, ( GLenum, const GLshort * ) ) \
    \
    /* GL_ARB_occlusion_query */ \
    GL_FUNCTION( void, glGenQueriesARB, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glDeleteQueriesARB, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsQueryARB, ( GLuint ) ) \
    GL_FUNCTION( void, glBeginQueryARB, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glEndQueryARB, ( GLenum ) ) \
    GL_FUNCTION( void, glGetQueryivARB, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetQueryObjectivARB, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetQueryObjectuivARB, ( GLuint, GLenum, GLuint * ) ) \
    \
    /* GL_ARB_occlusion_query2 */ \
    \
    /* GL_ARB_pixel_buffer_object */ \
    \
    /* GL_ARB_point_parameters */ \
    GL_FUNCTION( void, glPointParameterfARB, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glPointParameterfvARB, ( GLenum, const GLfloat * ) ) \
    \
    /* GL_ARB_point_sprite */ \
    \
    /* GL_ARB_program_interface_query */ \
    \
    /* GL_ARB_provoking_vertex */ \
    \
    /* GL_ARB_query_buffer_object */ \
    \
    /* GL_ARB_robust_buffer_access_behavior */ \
    \
    /* GL_ARB_robustness */ \
    GL_FUNCTION( GLenum, glGetGraphicsResetStatusARB, ( ) ) \
    GL_FUNCTION( void, glGetnTexImageARB, ( GLenum, GLint, GLenum, GLenum, GLsizei, GLvoid * ) ) \
    GL_FUNCTION( void, glReadnPixelsARB, ( GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, GLvoid * ) ) \
    GL_FUNCTION( void, glGetnCompressedTexImageARB, ( GLenum, GLint, GLsizei, GLvoid * ) ) \
    GL_FUNCTION( void, glGetnUniformfvARB, ( GLuint, GLint, GLsizei, GLfloat * ) ) \
    GL_FUNCTION( void, glGetnUniformivARB, ( GLuint, GLint, GLsizei, GLint * ) ) \
    GL_FUNCTION( void, glGetnUniformuivARB, ( GLuint, GLint, GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glGetnUniformdvARB, ( GLuint, GLint, GLsizei, GLdouble * ) ) \
    GL_FUNCTION( void, glGetnMapdvARB, ( GLenum, GLenum, GLsizei, GLdouble * ) ) \
    GL_FUNCTION( void, glGetnMapfvARB, ( GLenum, GLenum, GLsizei, GLfloat * ) ) \
    GL_FUNCTION( void, glGetnMapivARB, ( GLenum, GLenum, GLsizei, GLint * ) ) \
    GL_FUNCTION( void, glGetnPixelMapfvARB, ( GLenum, GLsizei, GLfloat * ) ) \
    GL_FUNCTION( void, glGetnPixelMapuivARB, ( GLenum, GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glGetnPixelMapusvARB, ( GLenum, GLsizei, GLushort * ) ) \
    GL_FUNCTION( void, glGetnPolygonStippleARB, ( GLsizei, GLubyte * ) ) \
    GL_FUNCTION( void, glGetnColorTableARB, ( GLenum, GLenum, GLenum, GLsizei, GLvoid * ) ) \
    GL_FUNCTION( void, glGetnConvolutionFilterARB, ( GLenum, GLenum, GLenum, GLsizei, GLvoid * ) ) \
    GL_FUNCTION( void, glGetnSeparableFilterARB, ( GLenum, GLenum, GLenum, GLsizei, GLvoid *, GLsizei, GLvoid *, GLvoid * ) ) \
    GL_FUNCTION( void, glGetnHistogramARB, ( GLenum, GLboolean, GLenum, GLenum, GLsizei, GLvoid * ) ) \
    GL_FUNCTION( void, glGetnMinmaxARB, ( GLenum, GLboolean, GLenum, GLenum, GLsizei, GLvoid * ) ) \
    \
    /* GL_ARB_robustness_isolation */ \
    \
    /* GL_ARB_sample_shading */ \
    GL_FUNCTION( void, glMinSampleShadingARB, ( GLfloat ) ) \
    \
    /* GL_ARB_sampler_objects */ \
    \
    /* GL_ARB_seamless_cube_map */ \
    \
    /* GL_ARB_seamless_cubemap_per_texture */ \
    \
    /* GL_ARB_separate_shader_objects */ \
    \
    /* GL_ARB_shader_atomic_counters */ \
    \
    /* GL_ARB_shader_bit_encoding */ \
    \
    /* GL_ARB_shader_draw_parameters */ \
    \
    /* GL_ARB_shader_group_vote */ \
    \
    /* GL_ARB_shader_image_load_store */ \
    \
    /* GL_ARB_shader_image_size */ \
    \
    /* GL_ARB_shader_objects */ \
    GL_FUNCTION( void, glDeleteObjectARB, ( GLhandleARB ) ) \
    GL_FUNCTION( GLhandleARB, glGetHandleARB, ( GLenum ) ) \
    GL_FUNCTION( void, glDetachObjectARB, ( GLhandleARB, GLhandleARB ) ) \
    GL_FUNCTION( GLhandleARB, glCreateShaderObjectARB, ( GLenum ) ) \
    GL_FUNCTION( void, glShaderSourceARB, ( GLhandleARB, GLsizei, const GLcharARB **, const GLint * ) ) \
    GL_FUNCTION( void, glCompileShaderARB, ( GLhandleARB ) ) \
    GL_FUNCTION( GLhandleARB, glCreateProgramObjectARB, ( ) ) \
    GL_FUNCTION( void, glAttachObjectARB, ( GLhandleARB, GLhandleARB ) ) \
    GL_FUNCTION( void, glLinkProgramARB, ( GLhandleARB ) ) \
    GL_FUNCTION( void, glUseProgramObjectARB, ( GLhandleARB ) ) \
    GL_FUNCTION( void, glValidateProgramARB, ( GLhandleARB ) ) \
    GL_FUNCTION( void, glUniform1fARB, ( GLint, GLfloat ) ) \
    GL_FUNCTION( void, glUniform2fARB, ( GLint, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glUniform3fARB, ( GLint, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glUniform4fARB, ( GLint, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glUniform1iARB, ( GLint, GLint ) ) \
    GL_FUNCTION( void, glUniform2iARB, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glUniform3iARB, ( GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glUniform4iARB, ( GLint, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glUniform1fvARB, ( GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniform2fvARB, ( GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniform3fvARB, ( GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniform4fvARB, ( GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniform1ivARB, ( GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glUniform2ivARB, ( GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glUniform3ivARB, ( GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glUniform4ivARB, ( GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glUniformMatrix2fvARB, ( GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniformMatrix3fvARB, ( GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glUniformMatrix4fvARB, ( GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glGetObjectParameterfvARB, ( GLhandleARB, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetObjectParameterivARB, ( GLhandleARB, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetInfoLogARB, ( GLhandleARB, GLsizei, GLsizei *, GLcharARB * ) ) \
    GL_FUNCTION( void, glGetAttachedObjectsARB, ( GLhandleARB, GLsizei, GLsizei *, GLhandleARB * ) ) \
    GL_FUNCTION( GLint, glGetUniformLocationARB, ( GLhandleARB, const GLcharARB * ) ) \
    GL_FUNCTION( void, glGetActiveUniformARB, ( GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB * ) ) \
    GL_FUNCTION( void, glGetUniformfvARB, ( GLhandleARB, GLint, GLfloat * ) ) \
    GL_FUNCTION( void, glGetUniformivARB, ( GLhandleARB, GLint, GLint * ) ) \
    GL_FUNCTION( void, glGetShaderSourceARB, ( GLhandleARB, GLsizei, GLsizei *, GLcharARB * ) ) \
    \
    /* GL_ARB_shader_precision */ \
    \
    /* GL_ARB_shader_stencil_export */ \
    \
    /* GL_ARB_shader_storage_buffer_object */ \
    \
    /* GL_ARB_shader_subroutine */ \
    \
    /* GL_ARB_shader_texture_lod */ \
    \
    /* GL_ARB_shading_language_100 */ \
    \
    /* GL_ARB_shading_language_420pack */ \
    \
    /* GL_ARB_shading_language_include */ \
    GL_FUNCTION( void, glNamedStringARB, ( GLenum, GLint, const GLchar *, GLint, const GLchar * ) ) \
    GL_FUNCTION( void, glDeleteNamedStringARB, ( GLint, const GLchar * ) ) \
    GL_FUNCTION( void, glCompileShaderIncludeARB, ( GLuint, GLsizei, const GLchar *const*, const GLint * ) ) \
    GL_FUNCTION( GLboolean, glIsNamedStringARB, ( GLint, const GLchar * ) ) \
    GL_FUNCTION( void, glGetNamedStringARB, ( GLint, const GLchar *, GLsizei, GLint *, GLchar * ) ) \
    GL_FUNCTION( void, glGetNamedStringivARB, ( GLint, const GLchar *, GLenum, GLint * ) ) \
    \
    /* GL_ARB_shading_language_packing */ \
    \
    /* GL_ARB_shadow */ \
    \
    /* GL_ARB_shadow_ambient */ \
    \
    /* GL_ARB_sparse_texture */ \
    GL_FUNCTION( void, glTexPageCommitmentARB, ( GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean ) ) \
    \
    /* GL_ARB_stencil_texturing */ \
    \
    /* GL_ARB_sync */ \
    \
    /* GL_ARB_tessellation_shader */ \
    \
    /* GL_ARB_texture_border_clamp */ \
    \
    /* GL_ARB_texture_buffer_object */ \
    GL_FUNCTION( void, glTexBufferARB, ( GLenum, GLenum, GLuint ) ) \
    \
    /* GL_ARB_texture_buffer_object_rgb32 */ \
    \
    /* GL_ARB_texture_buffer_range */ \
    \
    /* GL_ARB_texture_compression */ \
    GL_FUNCTION( void, glCompressedTexImage3DARB, ( GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTexImage2DARB, ( GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTexImage1DARB, ( GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTexSubImage3DARB, ( GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTexSubImage2DARB, ( GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTexSubImage1DARB, ( GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glGetCompressedTexImageARB, ( GLenum, GLint, GLvoid * ) ) \
    \
    /* GL_ARB_texture_compression_bptc */ \
    \
    /* GL_ARB_texture_compression_rgtc */ \
    \
    /* GL_ARB_texture_cube_map */ \
    \
    /* GL_ARB_texture_cube_map_array */ \
    \
    /* GL_ARB_texture_env_add */ \
    \
    /* GL_ARB_texture_env_combine */ \
    \
    /* GL_ARB_texture_env_crossbar */ \
    \
    /* GL_ARB_texture_env_dot3 */ \
    \
    /* GL_ARB_texture_float */ \
    \
    /* GL_ARB_texture_gather */ \
    \
    /* GL_ARB_texture_mirror_clamp_to_edge */ \
    \
    /* GL_ARB_texture_mirrored_repeat */ \
    \
    /* GL_ARB_texture_multisample */ \
    \
    /* GL_ARB_texture_non_power_of_two */ \
    \
    /* GL_ARB_texture_query_levels */ \
    \
    /* GL_ARB_texture_query_lod */ \
    \
    /* GL_ARB_texture_rectangle */ \
    \
    /* GL_ARB_texture_rg */ \
    \
    /* GL_ARB_texture_rgb10_a2ui */ \
    \
    /* GL_ARB_texture_stencil8 */ \
    \
    /* GL_ARB_texture_storage */ \
    \
    /* GL_ARB_texture_storage_multisample */ \
    \
    /* GL_ARB_texture_swizzle */ \
    \
    /* GL_ARB_texture_view */ \
    \
    /* GL_ARB_timer_query */ \
    \
    /* GL_ARB_transform_feedback2 */ \
    \
    /* GL_ARB_transform_feedback3 */ \
    \
    /* GL_ARB_transform_feedback_instanced */ \
    \
    /* GL_ARB_transpose_matrix */ \
    GL_FUNCTION( void, glLoadTransposeMatrixfARB, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glLoadTransposeMatrixdARB, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glMultTransposeMatrixfARB, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glMultTransposeMatrixdARB, ( const GLdouble * ) ) \
    \
    /* GL_ARB_uniform_buffer_object */ \
    \
    /* GL_ARB_vertex_array_bgra */ \
    \
    /* GL_ARB_vertex_array_object */ \
    \
    /* GL_ARB_vertex_attrib_64bit */ \
    \
    /* GL_ARB_vertex_attrib_binding */ \
    \
    /* GL_ARB_vertex_blend */ \
    GL_FUNCTION( void, glWeightbvARB, ( GLint, const GLbyte * ) ) \
    GL_FUNCTION( void, glWeightsvARB, ( GLint, const GLshort * ) ) \
    GL_FUNCTION( void, glWeightivARB, ( GLint, const GLint * ) ) \
    GL_FUNCTION( void, glWeightfvARB, ( GLint, const GLfloat * ) ) \
    GL_FUNCTION( void, glWeightdvARB, ( GLint, const GLdouble * ) ) \
    GL_FUNCTION( void, glWeightubvARB, ( GLint, const GLubyte * ) ) \
    GL_FUNCTION( void, glWeightusvARB, ( GLint, const GLushort * ) ) \
    GL_FUNCTION( void, glWeightuivARB, ( GLint, const GLuint * ) ) \
    GL_FUNCTION( void, glWeightPointerARB, ( GLint, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glVertexBlendARB, ( GLint ) ) \
    \
    /* GL_ARB_vertex_buffer_object */ \
    GL_FUNCTION( void, glBindBufferARB, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDeleteBuffersARB, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenBuffersARB, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsBufferARB, ( GLuint ) ) \
    GL_FUNCTION( void, glBufferDataARB, ( GLenum, GLsizeiptrARB, const GLvoid *, GLenum ) ) \
    GL_FUNCTION( void, glBufferSubDataARB, ( GLenum, GLintptrARB, GLsizeiptrARB, const GLvoid * ) ) \
    GL_FUNCTION( void, glGetBufferSubDataARB, ( GLenum, GLintptrARB, GLsizeiptrARB, GLvoid * ) ) \
    GL_FUNCTION( void *, glMapBufferARB, ( GLenum, GLenum ) ) \
    GL_FUNCTION( GLboolean, glUnmapBufferARB, ( GLenum ) ) \
    GL_FUNCTION( void, glGetBufferParameterivARB, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetBufferPointervARB, ( GLenum, GLenum, GLvoid ** ) ) \
    \
    /* GL_ARB_vertex_program */ \
    GL_FUNCTION( void, glVertexAttrib1dARB, ( GLuint, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttrib1dvARB, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttrib1fARB, ( GLuint, GLfloat ) ) \
    GL_FUNCTION( void, glVertexAttrib1fvARB, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttrib1sARB, ( GLuint, GLshort ) ) \
    GL_FUNCTION( void, glVertexAttrib1svARB, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib2dARB, ( GLuint, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttrib2dvARB, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttrib2fARB, ( GLuint, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertexAttrib2fvARB, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttrib2sARB, ( GLuint, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertexAttrib2svARB, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib3dARB, ( GLuint, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttrib3dvARB, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttrib3fARB, ( GLuint, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertexAttrib3fvARB, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttrib3sARB, ( GLuint, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertexAttrib3svARB, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib4NbvARB, ( GLuint, const GLbyte * ) ) \
    GL_FUNCTION( void, glVertexAttrib4NivARB, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glVertexAttrib4NsvARB, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib4NubARB, ( GLuint, GLubyte, GLubyte, GLubyte, GLubyte ) ) \
    GL_FUNCTION( void, glVertexAttrib4NubvARB, ( GLuint, const GLubyte * ) ) \
    GL_FUNCTION( void, glVertexAttrib4NuivARB, ( GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttrib4NusvARB, ( GLuint, const GLushort * ) ) \
    GL_FUNCTION( void, glVertexAttrib4bvARB, ( GLuint, const GLbyte * ) ) \
    GL_FUNCTION( void, glVertexAttrib4dARB, ( GLuint, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttrib4dvARB, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttrib4fARB, ( GLuint, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertexAttrib4fvARB, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttrib4ivARB, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glVertexAttrib4sARB, ( GLuint, GLshort, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertexAttrib4svARB, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib4ubvARB, ( GLuint, const GLubyte * ) ) \
    GL_FUNCTION( void, glVertexAttrib4uivARB, ( GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttrib4usvARB, ( GLuint, const GLushort * ) ) \
    GL_FUNCTION( void, glVertexAttribPointerARB, ( GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glEnableVertexAttribArrayARB, ( GLuint ) ) \
    GL_FUNCTION( void, glDisableVertexAttribArrayARB, ( GLuint ) ) \
    GL_FUNCTION( void, glGetVertexAttribdvARB, ( GLuint, GLenum, GLdouble * ) ) \
    GL_FUNCTION( void, glGetVertexAttribfvARB, ( GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetVertexAttribivARB, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetVertexAttribPointervARB, ( GLuint, GLenum, GLvoid ** ) ) \
    \
    /* GL_ARB_vertex_shader */ \
    GL_FUNCTION( void, glBindAttribLocationARB, ( GLhandleARB, GLuint, const GLcharARB * ) ) \
    GL_FUNCTION( void, glGetActiveAttribARB, ( GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB * ) ) \
    GL_FUNCTION( GLint, glGetAttribLocationARB, ( GLhandleARB, const GLcharARB * ) ) \
    \
    /* GL_ARB_vertex_type_10f_11f_11f_rev */ \
    \
    /* GL_ARB_vertex_type_2_10_10_10_rev */ \
    \
    /* GL_ARB_viewport_array */ \
    \
    /* GL_ARB_window_pos */ \
    GL_FUNCTION( void, glWindowPos2dARB, ( GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glWindowPos2dvARB, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glWindowPos2fARB, ( GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glWindowPos2fvARB, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glWindowPos2iARB, ( GLint, GLint ) ) \
    GL_FUNCTION( void, glWindowPos2ivARB, ( const GLint * ) ) \
    GL_FUNCTION( void, glWindowPos2sARB, ( GLshort, GLshort ) ) \
    GL_FUNCTION( void, glWindowPos2svARB, ( const GLshort * ) ) \
    GL_FUNCTION( void, glWindowPos3dARB, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glWindowPos3dvARB, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glWindowPos3fARB, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glWindowPos3fvARB, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glWindowPos3iARB, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glWindowPos3ivARB, ( const GLint * ) ) \
    GL_FUNCTION( void, glWindowPos3sARB, ( GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glWindowPos3svARB, ( const GLshort * ) ) \
    \
    /* GL_KHR_debug */ \
    \
    /* GL_KHR_texture_compression_astc_ldr */ \
    \
    /* GL_OES_byte_coordinates */ \
    GL_FUNCTION( void, glMultiTexCoord1bOES, ( GLenum, GLbyte ) ) \
    GL_FUNCTION( void, glMultiTexCoord1bvOES, ( GLenum, const GLbyte * ) ) \
    GL_FUNCTION( void, glMultiTexCoord2bOES, ( GLenum, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glMultiTexCoord2bvOES, ( GLenum, const GLbyte * ) ) \
    GL_FUNCTION( void, glMultiTexCoord3bOES, ( GLenum, GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glMultiTexCoord3bvOES, ( GLenum, const GLbyte * ) ) \
    GL_FUNCTION( void, glMultiTexCoord4bOES, ( GLenum, GLbyte, GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glMultiTexCoord4bvOES, ( GLenum, const GLbyte * ) ) \
    GL_FUNCTION( void, glTexCoord1bOES, ( GLbyte ) ) \
    GL_FUNCTION( void, glTexCoord1bvOES, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glTexCoord2bOES, ( GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glTexCoord2bvOES, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glTexCoord3bOES, ( GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glTexCoord3bvOES, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glTexCoord4bOES, ( GLbyte, GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glTexCoord4bvOES, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glVertex2bOES, ( GLbyte ) ) \
    GL_FUNCTION( void, glVertex2bvOES, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glVertex3bOES, ( GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glVertex3bvOES, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glVertex4bOES, ( GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glVertex4bvOES, ( const GLbyte * ) ) \
    \
    /* GL_OES_compressed_paletted_texture */ \
    \
    /* GL_OES_fixed_point */ \
    GL_FUNCTION( void, glAlphaFuncxOES, ( GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glClearColorxOES, ( GLfixed, GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glClearDepthxOES, ( GLfixed ) ) \
    GL_FUNCTION( void, glClipPlanexOES, ( GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glColor4xOES, ( GLfixed, GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glDepthRangexOES, ( GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glFogxOES, ( GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glFogxvOES, ( GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glFrustumxOES, ( GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glGetClipPlanexOES, ( GLenum, GLfixed * ) ) \
    GL_FUNCTION( void, glGetFixedvOES, ( GLenum, GLfixed * ) ) \
    GL_FUNCTION( void, glGetTexEnvxvOES, ( GLenum, GLenum, GLfixed * ) ) \
    GL_FUNCTION( void, glGetTexParameterxvOES, ( GLenum, GLenum, GLfixed * ) ) \
    GL_FUNCTION( void, glLightModelxOES, ( GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glLightModelxvOES, ( GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glLightxOES, ( GLenum, GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glLightxvOES, ( GLenum, GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glLineWidthxOES, ( GLfixed ) ) \
    GL_FUNCTION( void, glLoadMatrixxOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glMaterialxOES, ( GLenum, GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glMaterialxvOES, ( GLenum, GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glMultMatrixxOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glMultiTexCoord4xOES, ( GLenum, GLfixed, GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glNormal3xOES, ( GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glOrthoxOES, ( GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glPointParameterxvOES, ( GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glPointSizexOES, ( GLfixed ) ) \
    GL_FUNCTION( void, glPolygonOffsetxOES, ( GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glRotatexOES, ( GLfixed, GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glSampleCoverageOES, ( GLfixed, GLboolean ) ) \
    GL_FUNCTION( void, glScalexOES, ( GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glTexEnvxOES, ( GLenum, GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glTexEnvxvOES, ( GLenum, GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glTexParameterxOES, ( GLenum, GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glTexParameterxvOES, ( GLenum, GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glTranslatexOES, ( GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glAccumxOES, ( GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glBitmapxOES, ( GLsizei, GLsizei, GLfixed, GLfixed, GLfixed, GLfixed, const GLubyte * ) ) \
    GL_FUNCTION( void, glBlendColorxOES, ( GLfixed, GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glClearAccumxOES, ( GLfixed, GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glColor3xOES, ( GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glColor3xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glColor4xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glConvolutionParameterxOES, ( GLenum, GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glConvolutionParameterxvOES, ( GLenum, GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glEvalCoord1xOES, ( GLfixed ) ) \
    GL_FUNCTION( void, glEvalCoord1xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glEvalCoord2xOES, ( GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glEvalCoord2xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glFeedbackBufferxOES, ( GLsizei, GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glGetConvolutionParameterxvOES, ( GLenum, GLenum, GLfixed * ) ) \
    GL_FUNCTION( void, glGetHistogramParameterxvOES, ( GLenum, GLenum, GLfixed * ) ) \
    GL_FUNCTION( void, glGetLightxOES, ( GLenum, GLenum, GLfixed * ) ) \
    GL_FUNCTION( void, glGetMapxvOES, ( GLenum, GLenum, GLfixed * ) ) \
    GL_FUNCTION( void, glGetMaterialxOES, ( GLenum, GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glGetPixelMapxv, ( GLenum, GLint, GLfixed * ) ) \
    GL_FUNCTION( void, glGetTexGenxvOES, ( GLenum, GLenum, GLfixed * ) ) \
    GL_FUNCTION( void, glGetTexLevelParameterxvOES, ( GLenum, GLint, GLenum, GLfixed * ) ) \
    GL_FUNCTION( void, glIndexxOES, ( GLfixed ) ) \
    GL_FUNCTION( void, glIndexxvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glLoadTransposeMatrixxOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glMap1xOES, ( GLenum, GLfixed, GLfixed, GLint, GLint, GLfixed ) ) \
    GL_FUNCTION( void, glMap2xOES, ( GLenum, GLfixed, GLfixed, GLint, GLint, GLfixed, GLfixed, GLint, GLint, GLfixed ) ) \
    GL_FUNCTION( void, glMapGrid1xOES, ( GLint, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glMapGrid2xOES, ( GLint, GLfixed, GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glMultTransposeMatrixxOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glMultiTexCoord1xOES, ( GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glMultiTexCoord1xvOES, ( GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glMultiTexCoord2xOES, ( GLenum, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glMultiTexCoord2xvOES, ( GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glMultiTexCoord3xOES, ( GLenum, GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glMultiTexCoord3xvOES, ( GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glMultiTexCoord4xvOES, ( GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glNormal3xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glPassThroughxOES, ( GLfixed ) ) \
    GL_FUNCTION( void, glPixelMapx, ( GLenum, GLint, const GLfixed * ) ) \
    GL_FUNCTION( void, glPixelStorex, ( GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glPixelTransferxOES, ( GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glPixelZoomxOES, ( GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glPrioritizeTexturesxOES, ( GLsizei, const GLuint *, const GLfixed * ) ) \
    GL_FUNCTION( void, glRasterPos2xOES, ( GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glRasterPos2xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glRasterPos3xOES, ( GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glRasterPos3xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glRasterPos4xOES, ( GLfixed, GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glRasterPos4xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glRectxOES, ( GLfixed, GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glRectxvOES, ( const GLfixed *, const GLfixed * ) ) \
    GL_FUNCTION( void, glTexCoord1xOES, ( GLfixed ) ) \
    GL_FUNCTION( void, glTexCoord1xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glTexCoord2xOES, ( GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glTexCoord2xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glTexCoord3xOES, ( GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glTexCoord3xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glTexCoord4xOES, ( GLfixed, GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glTexCoord4xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glTexGenxOES, ( GLenum, GLenum, GLfixed ) ) \
    GL_FUNCTION( void, glTexGenxvOES, ( GLenum, GLenum, const GLfixed * ) ) \
    GL_FUNCTION( void, glVertex2xOES, ( GLfixed ) ) \
    GL_FUNCTION( void, glVertex2xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glVertex3xOES, ( GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glVertex3xvOES, ( const GLfixed * ) ) \
    GL_FUNCTION( void, glVertex4xOES, ( GLfixed, GLfixed, GLfixed ) ) \
    GL_FUNCTION( void, glVertex4xvOES, ( const GLfixed * ) ) \
    \
    /* GL_OES_query_matrix */ \
    GL_FUNCTION( GLbitfield, glQueryMatrixxOES, ( GLfixed *, GLint * ) ) \
    \
    /* GL_OES_read_format */ \
    \
    /* GL_OES_single_precision */ \
    GL_FUNCTION( void, glClearDepthfOES, ( GLclampf ) ) \
    GL_FUNCTION( void, glClipPlanefOES, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glDepthRangefOES, ( GLclampf, GLclampf ) ) \
    GL_FUNCTION( void, glFrustumfOES, ( GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glGetClipPlanefOES, ( GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glOrthofOES, ( GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    \
    /* GL_3DFX_multisample */ \
    \
    /* GL_3DFX_tbuffer */ \
    GL_FUNCTION( void, glTbufferMask3DFX, ( GLuint ) ) \
    \
    /* GL_3DFX_texture_compression_FXT1 */ \
    \
    /* GL_AMD_blend_minmax_factor */ \
    \
    /* GL_AMD_conservative_depth */ \
    \
    /* GL_AMD_debug_output */ \
    GL_FUNCTION( void, glDebugMessageEnableAMD, ( GLenum, GLenum, GLsizei, const GLuint *, GLboolean ) ) \
    GL_FUNCTION( void, glDebugMessageInsertAMD, ( GLenum, GLenum, GLuint, GLsizei, const GLchar * ) ) \
    GL_FUNCTION( void, glDebugMessageCallbackAMD, ( GLDEBUGPROCAMD, void * ) ) \
    GL_FUNCTION( GLuint, glGetDebugMessageLogAMD, ( GLuint, GLsizei, GLenum *, GLuint *, GLuint *, GLsizei *, GLchar * ) ) \
    \
    /* GL_AMD_depth_clamp_separate */ \
    \
    /* GL_AMD_draw_buffers_blend */ \
    GL_FUNCTION( void, glBlendFuncIndexedAMD, ( GLuint, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glBlendFuncSeparateIndexedAMD, ( GLuint, GLenum, GLenum, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glBlendEquationIndexedAMD, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glBlendEquationSeparateIndexedAMD, ( GLuint, GLenum, GLenum ) ) \
    \
    /* GL_AMD_interleaved_elements */ \
    GL_FUNCTION( void, glVertexAttribParameteriAMD, ( GLuint, GLenum, GLint ) ) \
    \
    /* GL_AMD_multi_draw_indirect */ \
    GL_FUNCTION( void, glMultiDrawArraysIndirectAMD, ( GLenum, const GLvoid *, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glMultiDrawElementsIndirectAMD, ( GLenum, GLenum, const GLvoid *, GLsizei, GLsizei ) ) \
    \
    /* GL_AMD_name_gen_delete */ \
    GL_FUNCTION( void, glGenNamesAMD, ( GLenum, GLuint, GLuint * ) ) \
    GL_FUNCTION( void, glDeleteNamesAMD, ( GLenum, GLuint, const GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsNameAMD, ( GLenum, GLuint ) ) \
    \
    /* GL_AMD_performance_monitor */ \
    GL_FUNCTION( void, glGetPerfMonitorGroupsAMD, ( GLint *, GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glGetPerfMonitorCountersAMD, ( GLuint, GLint *, GLint *, GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glGetPerfMonitorGroupStringAMD, ( GLuint, GLsizei, GLsizei *, GLchar * ) ) \
    GL_FUNCTION( void, glGetPerfMonitorCounterStringAMD, ( GLuint, GLuint, GLsizei, GLsizei *, GLchar * ) ) \
    GL_FUNCTION( void, glGetPerfMonitorCounterInfoAMD, ( GLuint, GLuint, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGenPerfMonitorsAMD, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glDeletePerfMonitorsAMD, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glSelectPerfMonitorCountersAMD, ( GLuint, GLboolean, GLuint, GLint, GLuint * ) ) \
    GL_FUNCTION( void, glBeginPerfMonitorAMD, ( GLuint ) ) \
    GL_FUNCTION( void, glEndPerfMonitorAMD, ( GLuint ) ) \
    GL_FUNCTION( void, glGetPerfMonitorCounterDataAMD, ( GLuint, GLenum, GLsizei, GLuint *, GLint * ) ) \
    \
    /* GL_AMD_pinned_memory */ \
    \
    /* GL_AMD_query_buffer_object */ \
    \
    /* GL_AMD_sample_positions */ \
    GL_FUNCTION( void, glSetMultisamplefvAMD, ( GLenum, GLuint, const GLfloat * ) ) \
    \
    /* GL_AMD_seamless_cubemap_per_texture */ \
    \
    /* GL_AMD_shader_atomic_counter_ops */ \
    \
    /* GL_AMD_shader_stencil_export */ \
    \
    /* GL_AMD_shader_trinary_minmax */ \
    \
    /* GL_AMD_sparse_texture */ \
    GL_FUNCTION( void, glTexStorageSparseAMD, ( GLenum, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLbitfield ) ) \
    GL_FUNCTION( void, glTextureStorageSparseAMD, ( GLuint, GLenum, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLbitfield ) ) \
    \
    /* GL_AMD_stencil_operation_extended */ \
    GL_FUNCTION( void, glStencilOpValueAMD, ( GLenum, GLuint ) ) \
    \
    /* GL_AMD_texture_texture4 */ \
    \
    /* GL_AMD_transform_feedback3_lines_triangles */ \
    \
    /* GL_AMD_vertex_shader_layer */ \
    \
    /* GL_AMD_vertex_shader_tessellator */ \
    GL_FUNCTION( void, glTessellationFactorAMD, ( GLfloat ) ) \
    GL_FUNCTION( void, glTessellationModeAMD, ( GLenum ) ) \
    \
    /* GL_AMD_vertex_shader_viewport_index */ \
    \
    /* GL_APPLE_aux_depth_stencil */ \
    \
    /* GL_APPLE_client_storage */ \
    \
    /* GL_APPLE_element_array */ \
    GL_FUNCTION( void, glElementPointerAPPLE, ( GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glDrawElementArrayAPPLE, ( GLenum, GLint, GLsizei ) ) \
    GL_FUNCTION( void, glDrawRangeElementArrayAPPLE, ( GLenum, GLuint, GLuint, GLint, GLsizei ) ) \
    GL_FUNCTION( void, glMultiDrawElementArrayAPPLE, ( GLenum, const GLint *, const GLsizei *, GLsizei ) ) \
    GL_FUNCTION( void, glMultiDrawRangeElementArrayAPPLE, ( GLenum, GLuint, GLuint, const GLint *, const GLsizei *, GLsizei ) ) \
    \
    /* GL_APPLE_fence */ \
    GL_FUNCTION( void, glGenFencesAPPLE, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glDeleteFencesAPPLE, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glSetFenceAPPLE, ( GLuint ) ) \
    GL_FUNCTION( GLboolean, glIsFenceAPPLE, ( GLuint ) ) \
    GL_FUNCTION( GLboolean, glTestFenceAPPLE, ( GLuint ) ) \
    GL_FUNCTION( void, glFinishFenceAPPLE, ( GLuint ) ) \
    GL_FUNCTION( GLboolean, glTestObjectAPPLE, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glFinishObjectAPPLE, ( GLenum, GLint ) ) \
    \
    /* GL_APPLE_float_pixels */ \
    \
    /* GL_APPLE_flush_buffer_range */ \
    GL_FUNCTION( void, glBufferParameteriAPPLE, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glFlushMappedBufferRangeAPPLE, ( GLenum, GLintptr, GLsizeiptr ) ) \
    \
    /* GL_APPLE_object_purgeable */ \
    GL_FUNCTION( GLenum, glObjectPurgeableAPPLE, ( GLenum, GLuint, GLenum ) ) \
    GL_FUNCTION( GLenum, glObjectUnpurgeableAPPLE, ( GLenum, GLuint, GLenum ) ) \
    GL_FUNCTION( void, glGetObjectParameterivAPPLE, ( GLenum, GLuint, GLenum, GLint * ) ) \
    \
    /* GL_APPLE_rgb_422 */ \
    \
    /* GL_APPLE_row_bytes */ \
    \
    /* GL_APPLE_specular_vector */ \
    \
    /* GL_APPLE_texture_range */ \
    GL_FUNCTION( void, glTextureRangeAPPLE, ( GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glGetTexParameterPointervAPPLE, ( GLenum, GLenum, GLvoid ** ) ) \
    \
    /* GL_APPLE_transform_hint */ \
    \
    /* GL_APPLE_vertex_array_object */ \
    GL_FUNCTION( void, glBindVertexArrayAPPLE, ( GLuint ) ) \
    GL_FUNCTION( void, glDeleteVertexArraysAPPLE, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenVertexArraysAPPLE, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsVertexArrayAPPLE, ( GLuint ) ) \
    \
    /* GL_APPLE_vertex_array_range */ \
    GL_FUNCTION( void, glVertexArrayRangeAPPLE, ( GLsizei, GLvoid * ) ) \
    GL_FUNCTION( void, glFlushVertexArrayRangeAPPLE, ( GLsizei, GLvoid * ) ) \
    GL_FUNCTION( void, glVertexArrayParameteriAPPLE, ( GLenum, GLint ) ) \
    \
    /* GL_APPLE_vertex_program_evaluators */ \
    GL_FUNCTION( void, glEnableVertexAttribAPPLE, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glDisableVertexAttribAPPLE, ( GLuint, GLenum ) ) \
    GL_FUNCTION( GLboolean, glIsVertexAttribEnabledAPPLE, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glMapVertexAttrib1dAPPLE, ( GLuint, GLuint, GLdouble, GLdouble, GLint, GLint, const GLdouble * ) ) \
    GL_FUNCTION( void, glMapVertexAttrib1fAPPLE, ( GLuint, GLuint, GLfloat, GLfloat, GLint, GLint, const GLfloat * ) ) \
    GL_FUNCTION( void, glMapVertexAttrib2dAPPLE, ( GLuint, GLuint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble * ) ) \
    GL_FUNCTION( void, glMapVertexAttrib2fAPPLE, ( GLuint, GLuint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat * ) ) \
    \
    /* GL_APPLE_ycbcr_422 */ \
    \
    /* GL_ATI_draw_buffers */ \
    GL_FUNCTION( void, glDrawBuffersATI, ( GLsizei, const GLenum * ) ) \
    \
    /* GL_ATI_element_array */ \
    GL_FUNCTION( void, glElementPointerATI, ( GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glDrawElementArrayATI, ( GLenum, GLsizei ) ) \
    GL_FUNCTION( void, glDrawRangeElementArrayATI, ( GLenum, GLuint, GLuint, GLsizei ) ) \
    \
    /* GL_ATI_envmap_bumpmap */ \
    GL_FUNCTION( void, glTexBumpParameterivATI, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glTexBumpParameterfvATI, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glGetTexBumpParameterivATI, ( GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetTexBumpParameterfvATI, ( GLenum, GLfloat * ) ) \
    \
    /* GL_ATI_fragment_shader */ \
    GL_FUNCTION( GLuint, glGenFragmentShadersATI, ( GLuint ) ) \
    GL_FUNCTION( void, glBindFragmentShaderATI, ( GLuint ) ) \
    GL_FUNCTION( void, glDeleteFragmentShaderATI, ( GLuint ) ) \
    GL_FUNCTION( void, glBeginFragmentShaderATI, ( ) ) \
    GL_FUNCTION( void, glEndFragmentShaderATI, ( ) ) \
    GL_FUNCTION( void, glPassTexCoordATI, ( GLuint, GLuint, GLenum ) ) \
    GL_FUNCTION( void, glSampleMapATI, ( GLuint, GLuint, GLenum ) ) \
    GL_FUNCTION( void, glColorFragmentOp1ATI, ( GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glColorFragmentOp2ATI, ( GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glColorFragmentOp3ATI, ( GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glAlphaFragmentOp1ATI, ( GLenum, GLuint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glAlphaFragmentOp2ATI, ( GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glAlphaFragmentOp3ATI, ( GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glSetFragmentShaderConstantATI, ( GLuint, const GLfloat * ) ) \
    \
    /* GL_ATI_map_object_buffer */ \
    GL_FUNCTION( void *, glMapObjectBufferATI, ( GLuint ) ) \
    GL_FUNCTION( void, glUnmapObjectBufferATI, ( GLuint ) ) \
    \
    /* GL_ATI_meminfo */ \
    \
    /* GL_ATI_pixel_format_float */ \
    \
    /* GL_ATI_pn_triangles */ \
    GL_FUNCTION( void, glPNTrianglesiATI, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glPNTrianglesfATI, ( GLenum, GLfloat ) ) \
    \
    /* GL_ATI_separate_stencil */ \
    GL_FUNCTION( void, glStencilOpSeparateATI, ( GLenum, GLenum, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glStencilFuncSeparateATI, ( GLenum, GLenum, GLint, GLuint ) ) \
    \
    /* GL_ATI_text_fragment_shader */ \
    \
    /* GL_ATI_texture_env_combine3 */ \
    \
    /* GL_ATI_texture_float */ \
    \
    /* GL_ATI_texture_mirror_once */ \
    \
    /* GL_ATI_vertex_array_object */ \
    GL_FUNCTION( GLuint, glNewObjectBufferATI, ( GLsizei, const GLvoid *, GLenum ) ) \
    GL_FUNCTION( GLboolean, glIsObjectBufferATI, ( GLuint ) ) \
    GL_FUNCTION( void, glUpdateObjectBufferATI, ( GLuint, GLuint, GLsizei, const GLvoid *, GLenum ) ) \
    GL_FUNCTION( void, glGetObjectBufferfvATI, ( GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetObjectBufferivATI, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glFreeObjectBufferATI, ( GLuint ) ) \
    GL_FUNCTION( void, glArrayObjectATI, ( GLenum, GLint, GLenum, GLsizei, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glGetArrayObjectfvATI, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetArrayObjectivATI, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glVariantArrayObjectATI, ( GLuint, GLenum, GLsizei, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glGetVariantArrayObjectfvATI, ( GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetVariantArrayObjectivATI, ( GLuint, GLenum, GLint * ) ) \
    \
    /* GL_ATI_vertex_attrib_array_object */ \
    GL_FUNCTION( void, glVertexAttribArrayObjectATI, ( GLuint, GLint, GLenum, GLboolean, GLsizei, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glGetVertexAttribArrayObjectfvATI, ( GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetVertexAttribArrayObjectivATI, ( GLuint, GLenum, GLint * ) ) \
    \
    /* GL_ATI_vertex_streams */ \
    GL_FUNCTION( void, glVertexStream1sATI, ( GLenum, GLshort ) ) \
    GL_FUNCTION( void, glVertexStream1svATI, ( GLenum, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexStream1iATI, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glVertexStream1ivATI, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glVertexStream1fATI, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glVertexStream1fvATI, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexStream1dATI, ( GLenum, GLdouble ) ) \
    GL_FUNCTION( void, glVertexStream1dvATI, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexStream2sATI, ( GLenum, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertexStream2svATI, ( GLenum, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexStream2iATI, ( GLenum, GLint, GLint ) ) \
    GL_FUNCTION( void, glVertexStream2ivATI, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glVertexStream2fATI, ( GLenum, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertexStream2fvATI, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexStream2dATI, ( GLenum, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexStream2dvATI, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexStream3sATI, ( GLenum, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertexStream3svATI, ( GLenum, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexStream3iATI, ( GLenum, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glVertexStream3ivATI, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glVertexStream3fATI, ( GLenum, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertexStream3fvATI, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexStream3dATI, ( GLenum, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexStream3dvATI, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexStream4sATI, ( GLenum, GLshort, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertexStream4svATI, ( GLenum, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexStream4iATI, ( GLenum, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glVertexStream4ivATI, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glVertexStream4fATI, ( GLenum, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertexStream4fvATI, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexStream4dATI, ( GLenum, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexStream4dvATI, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glNormalStream3bATI, ( GLenum, GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glNormalStream3bvATI, ( GLenum, const GLbyte * ) ) \
    GL_FUNCTION( void, glNormalStream3sATI, ( GLenum, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glNormalStream3svATI, ( GLenum, const GLshort * ) ) \
    GL_FUNCTION( void, glNormalStream3iATI, ( GLenum, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glNormalStream3ivATI, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glNormalStream3fATI, ( GLenum, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glNormalStream3fvATI, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glNormalStream3dATI, ( GLenum, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glNormalStream3dvATI, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glClientActiveVertexStreamATI, ( GLenum ) ) \
    GL_FUNCTION( void, glVertexBlendEnviATI, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glVertexBlendEnvfATI, ( GLenum, GLfloat ) ) \
    \
    /* GL_EXT_422_pixels */ \
    \
    /* GL_EXT_abgr */ \
    \
    /* GL_EXT_bgra */ \
    \
    /* GL_EXT_bindable_uniform */ \
    GL_FUNCTION( void, glUniformBufferEXT, ( GLuint, GLint, GLuint ) ) \
    GL_FUNCTION( GLint, glGetUniformBufferSizeEXT, ( GLuint, GLint ) ) \
    GL_FUNCTION( GLintptr, glGetUniformOffsetEXT, ( GLuint, GLint ) ) \
    \
    /* GL_EXT_blend_color */ \
    GL_FUNCTION( void, glBlendColorEXT, ( GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    \
    /* GL_EXT_blend_equation_separate */ \
    GL_FUNCTION( void, glBlendEquationSeparateEXT, ( GLenum, GLenum ) ) \
    \
    /* GL_EXT_blend_func_separate */ \
    GL_FUNCTION( void, glBlendFuncSeparateEXT, ( GLenum, GLenum, GLenum, GLenum ) ) \
    \
    /* GL_EXT_blend_logic_op */ \
    \
    /* GL_EXT_blend_minmax */ \
    GL_FUNCTION( void, glBlendEquationEXT, ( GLenum ) ) \
    \
    /* GL_EXT_blend_subtract */ \
    \
    /* GL_EXT_clip_volume_hint */ \
    \
    /* GL_EXT_cmyka */ \
    \
    /* GL_EXT_color_subtable */ \
    GL_FUNCTION( void, glColorSubTableEXT, ( GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glCopyColorSubTableEXT, ( GLenum, GLsizei, GLint, GLint, GLsizei ) ) \
    \
    /* GL_EXT_compiled_vertex_array */ \
    GL_FUNCTION( void, glLockArraysEXT, ( GLint, GLsizei ) ) \
    GL_FUNCTION( void, glUnlockArraysEXT, ( ) ) \
    \
    /* GL_EXT_convolution */ \
    GL_FUNCTION( void, glConvolutionFilter1DEXT, ( GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glConvolutionFilter2DEXT, ( GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glConvolutionParameterfEXT, ( GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glConvolutionParameterfvEXT, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glConvolutionParameteriEXT, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glConvolutionParameterivEXT, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glCopyConvolutionFilter1DEXT, ( GLenum, GLenum, GLint, GLint, GLsizei ) ) \
    GL_FUNCTION( void, glCopyConvolutionFilter2DEXT, ( GLenum, GLenum, GLint, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glGetConvolutionFilterEXT, ( GLenum, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGetConvolutionParameterfvEXT, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetConvolutionParameterivEXT, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetSeparableFilterEXT, ( GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid * ) ) \
    GL_FUNCTION( void, glSeparableFilter2DEXT, ( GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid * ) ) \
    \
    /* GL_EXT_coordinate_frame */ \
    GL_FUNCTION( void, glTangent3bEXT, ( GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glTangent3bvEXT, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glTangent3dEXT, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glTangent3dvEXT, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glTangent3fEXT, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glTangent3fvEXT, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glTangent3iEXT, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glTangent3ivEXT, ( const GLint * ) ) \
    GL_FUNCTION( void, glTangent3sEXT, ( GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glTangent3svEXT, ( const GLshort * ) ) \
    GL_FUNCTION( void, glBinormal3bEXT, ( GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glBinormal3bvEXT, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glBinormal3dEXT, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glBinormal3dvEXT, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glBinormal3fEXT, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glBinormal3fvEXT, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glBinormal3iEXT, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glBinormal3ivEXT, ( const GLint * ) ) \
    GL_FUNCTION( void, glBinormal3sEXT, ( GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glBinormal3svEXT, ( const GLshort * ) ) \
    GL_FUNCTION( void, glTangentPointerEXT, ( GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glBinormalPointerEXT, ( GLenum, GLsizei, const GLvoid * ) ) \
    \
    /* GL_EXT_copy_texture */ \
    GL_FUNCTION( void, glCopyTexImage1DEXT, ( GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint ) ) \
    GL_FUNCTION( void, glCopyTexImage2DEXT, ( GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint ) ) \
    GL_FUNCTION( void, glCopyTexSubImage1DEXT, ( GLenum, GLint, GLint, GLint, GLint, GLsizei ) ) \
    GL_FUNCTION( void, glCopyTexSubImage2DEXT, ( GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glCopyTexSubImage3DEXT, ( GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei ) ) \
    \
    /* GL_EXT_cull_vertex */ \
    GL_FUNCTION( void, glCullParameterdvEXT, ( GLenum, GLdouble * ) ) \
    GL_FUNCTION( void, glCullParameterfvEXT, ( GLenum, GLfloat * ) ) \
    \
    /* GL_EXT_depth_bounds_test */ \
    GL_FUNCTION( void, glDepthBoundsEXT, ( GLclampd, GLclampd ) ) \
    \
    /* GL_EXT_direct_state_access */ \
    GL_FUNCTION( void, glMatrixLoadfEXT, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMatrixLoaddEXT, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glMatrixMultfEXT, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMatrixMultdEXT, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glMatrixLoadIdentityEXT, ( GLenum ) ) \
    GL_FUNCTION( void, glMatrixRotatefEXT, ( GLenum, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glMatrixRotatedEXT, ( GLenum, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glMatrixScalefEXT, ( GLenum, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glMatrixScaledEXT, ( GLenum, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glMatrixTranslatefEXT, ( GLenum, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glMatrixTranslatedEXT, ( GLenum, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glMatrixFrustumEXT, ( GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glMatrixOrthoEXT, ( GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glMatrixPopEXT, ( GLenum ) ) \
    GL_FUNCTION( void, glMatrixPushEXT, ( GLenum ) ) \
    GL_FUNCTION( void, glClientAttribDefaultEXT, ( GLbitfield ) ) \
    GL_FUNCTION( void, glPushClientAttribDefaultEXT, ( GLbitfield ) ) \
    GL_FUNCTION( void, glTextureParameterfEXT, ( GLuint, GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glTextureParameterfvEXT, ( GLuint, GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glTextureParameteriEXT, ( GLuint, GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glTextureParameterivEXT, ( GLuint, GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glTextureImage1DEXT, ( GLuint, GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTextureImage2DEXT, ( GLuint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTextureSubImage1DEXT, ( GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTextureSubImage2DEXT, ( GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glCopyTextureImage1DEXT, ( GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint ) ) \
    GL_FUNCTION( void, glCopyTextureImage2DEXT, ( GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint ) ) \
    GL_FUNCTION( void, glCopyTextureSubImage1DEXT, ( GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei ) ) \
    GL_FUNCTION( void, glCopyTextureSubImage2DEXT, ( GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glGetTextureImageEXT, ( GLuint, GLenum, GLint, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGetTextureParameterfvEXT, ( GLuint, GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetTextureParameterivEXT, ( GLuint, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetTextureLevelParameterfvEXT, ( GLuint, GLenum, GLint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetTextureLevelParameterivEXT, ( GLuint, GLenum, GLint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glTextureImage3DEXT, ( GLuint, GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTextureSubImage3DEXT, ( GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glCopyTextureSubImage3DEXT, ( GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glBindMultiTextureEXT, ( GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glMultiTexCoordPointerEXT, ( GLenum, GLint, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glMultiTexEnvfEXT, ( GLenum, GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glMultiTexEnvfvEXT, ( GLenum, GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMultiTexEnviEXT, ( GLenum, GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glMultiTexEnvivEXT, ( GLenum, GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glMultiTexGendEXT, ( GLenum, GLenum, GLenum, GLdouble ) ) \
    GL_FUNCTION( void, glMultiTexGendvEXT, ( GLenum, GLenum, GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glMultiTexGenfEXT, ( GLenum, GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glMultiTexGenfvEXT, ( GLenum, GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMultiTexGeniEXT, ( GLenum, GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glMultiTexGenivEXT, ( GLenum, GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glGetMultiTexEnvfvEXT, ( GLenum, GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetMultiTexEnvivEXT, ( GLenum, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetMultiTexGendvEXT, ( GLenum, GLenum, GLenum, GLdouble * ) ) \
    GL_FUNCTION( void, glGetMultiTexGenfvEXT, ( GLenum, GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetMultiTexGenivEXT, ( GLenum, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glMultiTexParameteriEXT, ( GLenum, GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glMultiTexParameterivEXT, ( GLenum, GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glMultiTexParameterfEXT, ( GLenum, GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glMultiTexParameterfvEXT, ( GLenum, GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMultiTexImage1DEXT, ( GLenum, GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glMultiTexImage2DEXT, ( GLenum, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glMultiTexSubImage1DEXT, ( GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glMultiTexSubImage2DEXT, ( GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glCopyMultiTexImage1DEXT, ( GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint ) ) \
    GL_FUNCTION( void, glCopyMultiTexImage2DEXT, ( GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint ) ) \
    GL_FUNCTION( void, glCopyMultiTexSubImage1DEXT, ( GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei ) ) \
    GL_FUNCTION( void, glCopyMultiTexSubImage2DEXT, ( GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glGetMultiTexImageEXT, ( GLenum, GLenum, GLint, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGetMultiTexParameterfvEXT, ( GLenum, GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetMultiTexParameterivEXT, ( GLenum, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetMultiTexLevelParameterfvEXT, ( GLenum, GLenum, GLint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetMultiTexLevelParameterivEXT, ( GLenum, GLenum, GLint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glMultiTexImage3DEXT, ( GLenum, GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glMultiTexSubImage3DEXT, ( GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glCopyMultiTexSubImage3DEXT, ( GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glEnableClientStateIndexedEXT, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDisableClientStateIndexedEXT, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glGetFloatIndexedvEXT, ( GLenum, GLuint, GLfloat * ) ) \
    GL_FUNCTION( void, glGetDoubleIndexedvEXT, ( GLenum, GLuint, GLdouble * ) ) \
    GL_FUNCTION( void, glGetPointerIndexedvEXT, ( GLenum, GLuint, GLvoid ** ) ) \
    GL_FUNCTION( void, glEnableIndexedEXT, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDisableIndexedEXT, ( GLenum, GLuint ) ) \
    GL_FUNCTION( GLboolean, glIsEnabledIndexedEXT, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glGetIntegerIndexedvEXT, ( GLenum, GLuint, GLint * ) ) \
    GL_FUNCTION( void, glGetBooleanIndexedvEXT, ( GLenum, GLuint, GLboolean * ) ) \
    GL_FUNCTION( void, glCompressedTextureImage3DEXT, ( GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTextureImage2DEXT, ( GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTextureImage1DEXT, ( GLuint, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTextureSubImage3DEXT, ( GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTextureSubImage2DEXT, ( GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedTextureSubImage1DEXT, ( GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glGetCompressedTextureImageEXT, ( GLuint, GLenum, GLint, GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedMultiTexImage3DEXT, ( GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedMultiTexImage2DEXT, ( GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedMultiTexImage1DEXT, ( GLenum, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedMultiTexSubImage3DEXT, ( GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedMultiTexSubImage2DEXT, ( GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glCompressedMultiTexSubImage1DEXT, ( GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glGetCompressedMultiTexImageEXT, ( GLenum, GLenum, GLint, GLvoid * ) ) \
    GL_FUNCTION( void, glMatrixLoadTransposefEXT, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMatrixLoadTransposedEXT, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glMatrixMultTransposefEXT, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glMatrixMultTransposedEXT, ( GLenum, const GLdouble * ) ) \
    GL_FUNCTION( void, glNamedBufferDataEXT, ( GLuint, GLsizeiptr, const GLvoid *, GLenum ) ) \
    GL_FUNCTION( void, glNamedBufferSubDataEXT, ( GLuint, GLintptr, GLsizeiptr, const GLvoid * ) ) \
    GL_FUNCTION( void *, glMapNamedBufferEXT, ( GLuint, GLenum ) ) \
    GL_FUNCTION( GLboolean, glUnmapNamedBufferEXT, ( GLuint ) ) \
    GL_FUNCTION( void, glGetNamedBufferParameterivEXT, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetNamedBufferPointervEXT, ( GLuint, GLenum, GLvoid ** ) ) \
    GL_FUNCTION( void, glGetNamedBufferSubDataEXT, ( GLuint, GLintptr, GLsizeiptr, GLvoid * ) ) \
    GL_FUNCTION( void, glProgramUniform1fEXT, ( GLuint, GLint, GLfloat ) ) \
    GL_FUNCTION( void, glProgramUniform2fEXT, ( GLuint, GLint, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glProgramUniform3fEXT, ( GLuint, GLint, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glProgramUniform4fEXT, ( GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glProgramUniform1iEXT, ( GLuint, GLint, GLint ) ) \
    GL_FUNCTION( void, glProgramUniform2iEXT, ( GLuint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glProgramUniform3iEXT, ( GLuint, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glProgramUniform4iEXT, ( GLuint, GLint, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glProgramUniform1fvEXT, ( GLuint, GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniform2fvEXT, ( GLuint, GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniform3fvEXT, ( GLuint, GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniform4fvEXT, ( GLuint, GLint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniform1ivEXT, ( GLuint, GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glProgramUniform2ivEXT, ( GLuint, GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glProgramUniform3ivEXT, ( GLuint, GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glProgramUniform4ivEXT, ( GLuint, GLint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix2fvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix3fvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix4fvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix2x3fvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix3x2fvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix2x4fvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix4x2fvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix3x4fvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix4x3fvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLfloat * ) ) \
    GL_FUNCTION( void, glTextureBufferEXT, ( GLuint, GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glMultiTexBufferEXT, ( GLenum, GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glTextureParameterIivEXT, ( GLuint, GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glTextureParameterIuivEXT, ( GLuint, GLenum, GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glGetTextureParameterIivEXT, ( GLuint, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetTextureParameterIuivEXT, ( GLuint, GLenum, GLenum, GLuint * ) ) \
    GL_FUNCTION( void, glMultiTexParameterIivEXT, ( GLenum, GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glMultiTexParameterIuivEXT, ( GLenum, GLenum, GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glGetMultiTexParameterIivEXT, ( GLenum, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetMultiTexParameterIuivEXT, ( GLenum, GLenum, GLenum, GLuint * ) ) \
    GL_FUNCTION( void, glProgramUniform1uiEXT, ( GLuint, GLint, GLuint ) ) \
    GL_FUNCTION( void, glProgramUniform2uiEXT, ( GLuint, GLint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glProgramUniform3uiEXT, ( GLuint, GLint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glProgramUniform4uiEXT, ( GLuint, GLint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glProgramUniform1uivEXT, ( GLuint, GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glProgramUniform2uivEXT, ( GLuint, GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glProgramUniform3uivEXT, ( GLuint, GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glProgramUniform4uivEXT, ( GLuint, GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glNamedProgramLocalParameters4fvEXT, ( GLuint, GLenum, GLuint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glNamedProgramLocalParameterI4iEXT, ( GLuint, GLenum, GLuint, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glNamedProgramLocalParameterI4ivEXT, ( GLuint, GLenum, GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glNamedProgramLocalParametersI4ivEXT, ( GLuint, GLenum, GLuint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glNamedProgramLocalParameterI4uiEXT, ( GLuint, GLenum, GLuint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glNamedProgramLocalParameterI4uivEXT, ( GLuint, GLenum, GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glNamedProgramLocalParametersI4uivEXT, ( GLuint, GLenum, GLuint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGetNamedProgramLocalParameterIivEXT, ( GLuint, GLenum, GLuint, GLint * ) ) \
    GL_FUNCTION( void, glGetNamedProgramLocalParameterIuivEXT, ( GLuint, GLenum, GLuint, GLuint * ) ) \
    GL_FUNCTION( void, glEnableClientStateiEXT, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDisableClientStateiEXT, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glGetFloati_vEXT, ( GLenum, GLuint, GLfloat * ) ) \
    GL_FUNCTION( void, glGetDoublei_vEXT, ( GLenum, GLuint, GLdouble * ) ) \
    GL_FUNCTION( void, glGetPointeri_vEXT, ( GLenum, GLuint, GLvoid ** ) ) \
    GL_FUNCTION( void, glNamedProgramStringEXT, ( GLuint, GLenum, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glNamedProgramLocalParameter4dEXT, ( GLuint, GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glNamedProgramLocalParameter4dvEXT, ( GLuint, GLenum, GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glNamedProgramLocalParameter4fEXT, ( GLuint, GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glNamedProgramLocalParameter4fvEXT, ( GLuint, GLenum, GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glGetNamedProgramLocalParameterdvEXT, ( GLuint, GLenum, GLuint, GLdouble * ) ) \
    GL_FUNCTION( void, glGetNamedProgramLocalParameterfvEXT, ( GLuint, GLenum, GLuint, GLfloat * ) ) \
    GL_FUNCTION( void, glGetNamedProgramivEXT, ( GLuint, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetNamedProgramStringEXT, ( GLuint, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glNamedRenderbufferStorageEXT, ( GLuint, GLenum, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glGetNamedRenderbufferParameterivEXT, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glNamedRenderbufferStorageMultisampleEXT, ( GLuint, GLsizei, GLenum, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glNamedRenderbufferStorageMultisampleCoverageEXT, ( GLuint, GLsizei, GLsizei, GLenum, GLsizei, GLsizei ) ) \
    GL_FUNCTION( GLenum, glCheckNamedFramebufferStatusEXT, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glNamedFramebufferTexture1DEXT, ( GLuint, GLenum, GLenum, GLuint, GLint ) ) \
    GL_FUNCTION( void, glNamedFramebufferTexture2DEXT, ( GLuint, GLenum, GLenum, GLuint, GLint ) ) \
    GL_FUNCTION( void, glNamedFramebufferTexture3DEXT, ( GLuint, GLenum, GLenum, GLuint, GLint, GLint ) ) \
    GL_FUNCTION( void, glNamedFramebufferRenderbufferEXT, ( GLuint, GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glGetNamedFramebufferAttachmentParameterivEXT, ( GLuint, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGenerateTextureMipmapEXT, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glGenerateMultiTexMipmapEXT, ( GLenum, GLenum ) ) \
    GL_FUNCTION( void, glFramebufferDrawBufferEXT, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glFramebufferDrawBuffersEXT, ( GLuint, GLsizei, const GLenum * ) ) \
    GL_FUNCTION( void, glFramebufferReadBufferEXT, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glGetFramebufferParameterivEXT, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glNamedCopyBufferSubDataEXT, ( GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr ) ) \
    GL_FUNCTION( void, glNamedFramebufferTextureEXT, ( GLuint, GLenum, GLuint, GLint ) ) \
    GL_FUNCTION( void, glNamedFramebufferTextureLayerEXT, ( GLuint, GLenum, GLuint, GLint, GLint ) ) \
    GL_FUNCTION( void, glNamedFramebufferTextureFaceEXT, ( GLuint, GLenum, GLuint, GLint, GLenum ) ) \
    GL_FUNCTION( void, glTextureRenderbufferEXT, ( GLuint, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glMultiTexRenderbufferEXT, ( GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glVertexArrayVertexOffsetEXT, ( GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr ) ) \
    GL_FUNCTION( void, glVertexArrayColorOffsetEXT, ( GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr ) ) \
    GL_FUNCTION( void, glVertexArrayEdgeFlagOffsetEXT, ( GLuint, GLuint, GLsizei, GLintptr ) ) \
    GL_FUNCTION( void, glVertexArrayIndexOffsetEXT, ( GLuint, GLuint, GLenum, GLsizei, GLintptr ) ) \
    GL_FUNCTION( void, glVertexArrayNormalOffsetEXT, ( GLuint, GLuint, GLenum, GLsizei, GLintptr ) ) \
    GL_FUNCTION( void, glVertexArrayTexCoordOffsetEXT, ( GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr ) ) \
    GL_FUNCTION( void, glVertexArrayMultiTexCoordOffsetEXT, ( GLuint, GLuint, GLenum, GLint, GLenum, GLsizei, GLintptr ) ) \
    GL_FUNCTION( void, glVertexArrayFogCoordOffsetEXT, ( GLuint, GLuint, GLenum, GLsizei, GLintptr ) ) \
    GL_FUNCTION( void, glVertexArraySecondaryColorOffsetEXT, ( GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr ) ) \
    GL_FUNCTION( void, glVertexArrayVertexAttribOffsetEXT, ( GLuint, GLuint, GLuint, GLint, GLenum, GLboolean, GLsizei, GLintptr ) ) \
    GL_FUNCTION( void, glVertexArrayVertexAttribIOffsetEXT, ( GLuint, GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr ) ) \
    GL_FUNCTION( void, glEnableVertexArrayEXT, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glDisableVertexArrayEXT, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glEnableVertexArrayAttribEXT, ( GLuint, GLuint ) ) \
    GL_FUNCTION( void, glDisableVertexArrayAttribEXT, ( GLuint, GLuint ) ) \
    GL_FUNCTION( void, glGetVertexArrayIntegervEXT, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetVertexArrayPointervEXT, ( GLuint, GLenum, GLvoid ** ) ) \
    GL_FUNCTION( void, glGetVertexArrayIntegeri_vEXT, ( GLuint, GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetVertexArrayPointeri_vEXT, ( GLuint, GLuint, GLenum, GLvoid ** ) ) \
    GL_FUNCTION( void *, glMapNamedBufferRangeEXT, ( GLuint, GLintptr, GLsizeiptr, GLbitfield ) ) \
    GL_FUNCTION( void, glFlushMappedNamedBufferRangeEXT, ( GLuint, GLintptr, GLsizeiptr ) ) \
    GL_FUNCTION( void, glNamedBufferStorageEXT, ( GLuint, GLsizeiptr, const void *, GLbitfield ) ) \
    GL_FUNCTION( void, glClearNamedBufferDataEXT, ( GLuint, GLenum, GLenum, GLenum, const void * ) ) \
    GL_FUNCTION( void, glClearNamedBufferSubDataEXT, ( GLuint, GLenum, GLenum, GLenum, GLsizeiptr, GLsizeiptr, const void * ) ) \
    GL_FUNCTION( void, glNamedFramebufferParameteriEXT, ( GLuint, GLenum, GLint ) ) \
    GL_FUNCTION( void, glGetNamedFramebufferParameterivEXT, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glProgramUniform1dEXT, ( GLuint, GLint, GLdouble ) ) \
    GL_FUNCTION( void, glProgramUniform2dEXT, ( GLuint, GLint, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glProgramUniform3dEXT, ( GLuint, GLint, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glProgramUniform4dEXT, ( GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glProgramUniform1dvEXT, ( GLuint, GLint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniform2dvEXT, ( GLuint, GLint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniform3dvEXT, ( GLuint, GLint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniform4dvEXT, ( GLuint, GLint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix2dvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix3dvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix4dvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix2x3dvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix2x4dvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix3x2dvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix3x4dvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix4x2dvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramUniformMatrix4x3dvEXT, ( GLuint, GLint, GLsizei, GLboolean, const GLdouble * ) ) \
    GL_FUNCTION( void, glTextureBufferRangeEXT, ( GLuint, GLenum, GLenum, GLuint, GLintptr, GLsizeiptr ) ) \
    GL_FUNCTION( void, glTextureStorage1DEXT, ( GLuint, GLenum, GLsizei, GLenum, GLsizei ) ) \
    GL_FUNCTION( void, glTextureStorage2DEXT, ( GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glTextureStorage3DEXT, ( GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glTextureStorage2DMultisampleEXT, ( GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean ) ) \
    GL_FUNCTION( void, glTextureStorage3DMultisampleEXT, ( GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean ) ) \
    GL_FUNCTION( void, glVertexArrayBindVertexBufferEXT, ( GLuint, GLuint, GLuint, GLintptr, GLsizei ) ) \
    GL_FUNCTION( void, glVertexArrayVertexAttribFormatEXT, ( GLuint, GLuint, GLint, GLenum, GLboolean, GLuint ) ) \
    GL_FUNCTION( void, glVertexArrayVertexAttribIFormatEXT, ( GLuint, GLuint, GLint, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glVertexArrayVertexAttribLFormatEXT, ( GLuint, GLuint, GLint, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glVertexArrayVertexAttribBindingEXT, ( GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glVertexArrayVertexBindingDivisorEXT, ( GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glVertexArrayVertexAttribLOffsetEXT, ( GLuint, GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr ) ) \
    GL_FUNCTION( void, glTexturePageCommitmentEXT, ( GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean ) ) \
    GL_FUNCTION( void, glVertexArrayVertexAttribDivisorEXT, ( GLuint, GLuint, GLuint ) ) \
    \
    /* GL_EXT_draw_buffers2 */ \
    GL_FUNCTION( void, glColorMaskIndexedEXT, ( GLuint, GLboolean, GLboolean, GLboolean, GLboolean ) ) \
    \
    /* GL_EXT_draw_instanced */ \
    GL_FUNCTION( void, glDrawArraysInstancedEXT, ( GLenum, GLint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glDrawElementsInstancedEXT, ( GLenum, GLsizei, GLenum, const GLvoid *, GLsizei ) ) \
    \
    /* GL_EXT_draw_range_elements */ \
    GL_FUNCTION( void, glDrawRangeElementsEXT, ( GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid * ) ) \
    \
    /* GL_EXT_fog_coord */ \
    GL_FUNCTION( void, glFogCoordfEXT, ( GLfloat ) ) \
    GL_FUNCTION( void, glFogCoordfvEXT, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glFogCoorddEXT, ( GLdouble ) ) \
    GL_FUNCTION( void, glFogCoorddvEXT, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glFogCoordPointerEXT, ( GLenum, GLsizei, const GLvoid * ) ) \
    \
    /* GL_EXT_framebuffer_blit */ \
    GL_FUNCTION( void, glBlitFramebufferEXT, ( GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum ) ) \
    \
    /* GL_EXT_framebuffer_multisample */ \
    GL_FUNCTION( void, glRenderbufferStorageMultisampleEXT, ( GLenum, GLsizei, GLenum, GLsizei, GLsizei ) ) \
    \
    /* GL_EXT_framebuffer_multisample_blit_scaled */ \
    \
    /* GL_EXT_framebuffer_object */ \
    GL_FUNCTION( GLboolean, glIsRenderbufferEXT, ( GLuint ) ) \
    GL_FUNCTION( void, glBindRenderbufferEXT, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDeleteRenderbuffersEXT, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenRenderbuffersEXT, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glRenderbufferStorageEXT, ( GLenum, GLenum, GLsizei, GLsizei ) ) \
    GL_FUNCTION( void, glGetRenderbufferParameterivEXT, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( GLboolean, glIsFramebufferEXT, ( GLuint ) ) \
    GL_FUNCTION( void, glBindFramebufferEXT, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDeleteFramebuffersEXT, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenFramebuffersEXT, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( GLenum, glCheckFramebufferStatusEXT, ( GLenum ) ) \
    GL_FUNCTION( void, glFramebufferTexture1DEXT, ( GLenum, GLenum, GLenum, GLuint, GLint ) ) \
    GL_FUNCTION( void, glFramebufferTexture2DEXT, ( GLenum, GLenum, GLenum, GLuint, GLint ) ) \
    GL_FUNCTION( void, glFramebufferTexture3DEXT, ( GLenum, GLenum, GLenum, GLuint, GLint, GLint ) ) \
    GL_FUNCTION( void, glFramebufferRenderbufferEXT, ( GLenum, GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glGetFramebufferAttachmentParameterivEXT, ( GLenum, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGenerateMipmapEXT, ( GLenum ) ) \
    \
    /* GL_EXT_framebuffer_sRGB */ \
    \
    /* GL_EXT_geometry_shader4 */ \
    GL_FUNCTION( void, glProgramParameteriEXT, ( GLuint, GLenum, GLint ) ) \
    \
    /* GL_EXT_gpu_program_parameters */ \
    GL_FUNCTION( void, glProgramEnvParameters4fvEXT, ( GLenum, GLuint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramLocalParameters4fvEXT, ( GLenum, GLuint, GLsizei, const GLfloat * ) ) \
    \
    /* GL_EXT_gpu_shader4 */ \
    GL_FUNCTION( void, glGetUniformuivEXT, ( GLuint, GLint, GLuint * ) ) \
    GL_FUNCTION( void, glBindFragDataLocationEXT, ( GLuint, GLuint, const GLchar * ) ) \
    GL_FUNCTION( GLint, glGetFragDataLocationEXT, ( GLuint, const GLchar * ) ) \
    GL_FUNCTION( void, glUniform1uiEXT, ( GLint, GLuint ) ) \
    GL_FUNCTION( void, glUniform2uiEXT, ( GLint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glUniform3uiEXT, ( GLint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glUniform4uiEXT, ( GLint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glUniform1uivEXT, ( GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glUniform2uivEXT, ( GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glUniform3uivEXT, ( GLint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glUniform4uivEXT, ( GLint, GLsizei, const GLuint * ) ) \
    \
    /* GL_EXT_histogram */ \
    GL_FUNCTION( void, glGetHistogramEXT, ( GLenum, GLboolean, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGetHistogramParameterfvEXT, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetHistogramParameterivEXT, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetMinmaxEXT, ( GLenum, GLboolean, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGetMinmaxParameterfvEXT, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetMinmaxParameterivEXT, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glHistogramEXT, ( GLenum, GLsizei, GLenum, GLboolean ) ) \
    GL_FUNCTION( void, glMinmaxEXT, ( GLenum, GLenum, GLboolean ) ) \
    GL_FUNCTION( void, glResetHistogramEXT, ( GLenum ) ) \
    GL_FUNCTION( void, glResetMinmaxEXT, ( GLenum ) ) \
    \
    /* GL_EXT_index_array_formats */ \
    \
    /* GL_EXT_index_func */ \
    GL_FUNCTION( void, glIndexFuncEXT, ( GLenum, GLclampf ) ) \
    \
    /* GL_EXT_index_material */ \
    GL_FUNCTION( void, glIndexMaterialEXT, ( GLenum, GLenum ) ) \
    \
    /* GL_EXT_index_texture */ \
    \
    /* GL_EXT_light_texture */ \
    GL_FUNCTION( void, glApplyTextureEXT, ( GLenum ) ) \
    GL_FUNCTION( void, glTextureLightEXT, ( GLenum ) ) \
    GL_FUNCTION( void, glTextureMaterialEXT, ( GLenum, GLenum ) ) \
    \
    /* GL_EXT_misc_attribute */ \
    \
    /* GL_EXT_multi_draw_arrays */ \
    GL_FUNCTION( void, glMultiDrawArraysEXT, ( GLenum, const GLint *, const GLsizei *, GLsizei ) ) \
    GL_FUNCTION( void, glMultiDrawElementsEXT, ( GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei ) ) \
    \
    /* GL_EXT_multisample */ \
    GL_FUNCTION( void, glSampleMaskEXT, ( GLclampf, GLboolean ) ) \
    GL_FUNCTION( void, glSamplePatternEXT, ( GLenum ) ) \
    \
    /* GL_EXT_packed_depth_stencil */ \
    \
    /* GL_EXT_packed_float */ \
    \
    /* GL_EXT_packed_pixels */ \
    \
    /* GL_EXT_paletted_texture */ \
    GL_FUNCTION( void, glColorTableEXT, ( GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glGetColorTableEXT, ( GLenum, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGetColorTableParameterivEXT, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetColorTableParameterfvEXT, ( GLenum, GLenum, GLfloat * ) ) \
    \
    /* GL_EXT_pixel_buffer_object */ \
    \
    /* GL_EXT_pixel_transform */ \
    GL_FUNCTION( void, glPixelTransformParameteriEXT, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glPixelTransformParameterfEXT, ( GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glPixelTransformParameterivEXT, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glPixelTransformParameterfvEXT, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glGetPixelTransformParameterivEXT, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetPixelTransformParameterfvEXT, ( GLenum, GLenum, GLfloat * ) ) \
    \
    /* GL_EXT_pixel_transform_color_table */ \
    \
    /* GL_EXT_point_parameters */ \
    GL_FUNCTION( void, glPointParameterfEXT, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glPointParameterfvEXT, ( GLenum, const GLfloat * ) ) \
    \
    /* GL_EXT_polygon_offset */ \
    GL_FUNCTION( void, glPolygonOffsetEXT, ( GLfloat, GLfloat ) ) \
    \
    /* GL_EXT_provoking_vertex */ \
    GL_FUNCTION( void, glProvokingVertexEXT, ( GLenum ) ) \
    \
    /* GL_EXT_rescale_normal */ \
    \
    /* GL_EXT_secondary_color */ \
    GL_FUNCTION( void, glSecondaryColor3bEXT, ( GLbyte, GLbyte, GLbyte ) ) \
    GL_FUNCTION( void, glSecondaryColor3bvEXT, ( const GLbyte * ) ) \
    GL_FUNCTION( void, glSecondaryColor3dEXT, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glSecondaryColor3dvEXT, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glSecondaryColor3fEXT, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glSecondaryColor3fvEXT, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glSecondaryColor3iEXT, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glSecondaryColor3ivEXT, ( const GLint * ) ) \
    GL_FUNCTION( void, glSecondaryColor3sEXT, ( GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glSecondaryColor3svEXT, ( const GLshort * ) ) \
    GL_FUNCTION( void, glSecondaryColor3ubEXT, ( GLubyte, GLubyte, GLubyte ) ) \
    GL_FUNCTION( void, glSecondaryColor3ubvEXT, ( const GLubyte * ) ) \
    GL_FUNCTION( void, glSecondaryColor3uiEXT, ( GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glSecondaryColor3uivEXT, ( const GLuint * ) ) \
    GL_FUNCTION( void, glSecondaryColor3usEXT, ( GLushort, GLushort, GLushort ) ) \
    GL_FUNCTION( void, glSecondaryColor3usvEXT, ( const GLushort * ) ) \
    GL_FUNCTION( void, glSecondaryColorPointerEXT, ( GLint, GLenum, GLsizei, const GLvoid * ) ) \
    \
    /* GL_EXT_separate_shader_objects */ \
    GL_FUNCTION( void, glUseShaderProgramEXT, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glActiveProgramEXT, ( GLuint ) ) \
    GL_FUNCTION( GLuint, glCreateShaderProgramEXT, ( GLenum, const GLchar * ) ) \
    \
    /* GL_EXT_separate_specular_color */ \
    \
    /* GL_EXT_shader_image_load_store */ \
    GL_FUNCTION( void, glBindImageTextureEXT, ( GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLint ) ) \
    GL_FUNCTION( void, glMemoryBarrierEXT, ( GLbitfield ) ) \
    \
    /* GL_EXT_shadow_funcs */ \
    \
    /* GL_EXT_shared_texture_palette */ \
    \
    /* GL_EXT_stencil_clear_tag */ \
    GL_FUNCTION( void, glStencilClearTagEXT, ( GLsizei, GLuint ) ) \
    \
    /* GL_EXT_stencil_two_side */ \
    GL_FUNCTION( void, glActiveStencilFaceEXT, ( GLenum ) ) \
    \
    /* GL_EXT_stencil_wrap */ \
    \
    /* GL_EXT_subtexture */ \
    GL_FUNCTION( void, glTexSubImage1DEXT, ( GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTexSubImage2DEXT, ( GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    \
    /* GL_EXT_texture */ \
    \
    /* GL_EXT_texture3D */ \
    GL_FUNCTION( void, glTexImage3DEXT, ( GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTexSubImage3DEXT, ( GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    \
    /* GL_EXT_texture_array */ \
    \
    /* GL_EXT_texture_buffer_object */ \
    GL_FUNCTION( void, glTexBufferEXT, ( GLenum, GLenum, GLuint ) ) \
    \
    /* GL_EXT_texture_compression_latc */ \
    \
    /* GL_EXT_texture_compression_rgtc */ \
    \
    /* GL_EXT_texture_compression_s3tc */ \
    \
    /* GL_EXT_texture_cube_map */ \
    \
    /* GL_EXT_texture_env_add */ \
    \
    /* GL_EXT_texture_env_combine */ \
    \
    /* GL_EXT_texture_env_dot3 */ \
    \
    /* GL_EXT_texture_filter_anisotropic */ \
    \
    /* GL_EXT_texture_integer */ \
    GL_FUNCTION( void, glTexParameterIivEXT, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glTexParameterIuivEXT, ( GLenum, GLenum, const GLuint * ) ) \
    GL_FUNCTION( void, glGetTexParameterIivEXT, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetTexParameterIuivEXT, ( GLenum, GLenum, GLuint * ) ) \
    GL_FUNCTION( void, glClearColorIiEXT, ( GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glClearColorIuiEXT, ( GLuint, GLuint, GLuint, GLuint ) ) \
    \
    /* GL_EXT_texture_lod_bias */ \
    \
    /* GL_EXT_texture_mirror_clamp */ \
    \
    /* GL_EXT_texture_object */ \
    GL_FUNCTION( GLboolean, glAreTexturesResidentEXT, ( GLsizei, const GLuint *, GLboolean * ) ) \
    GL_FUNCTION( void, glBindTextureEXT, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDeleteTexturesEXT, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenTexturesEXT, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsTextureEXT, ( GLuint ) ) \
    GL_FUNCTION( void, glPrioritizeTexturesEXT, ( GLsizei, const GLuint *, const GLclampf * ) ) \
    \
    /* GL_EXT_texture_perturb_normal */ \
    GL_FUNCTION( void, glTextureNormalEXT, ( GLenum ) ) \
    \
    /* GL_EXT_texture_sRGB */ \
    \
    /* GL_EXT_texture_sRGB_decode */ \
    \
    /* GL_EXT_texture_shared_exponent */ \
    \
    /* GL_EXT_texture_snorm */ \
    \
    /* GL_EXT_texture_swizzle */ \
    \
    /* GL_EXT_timer_query */ \
    GL_FUNCTION( void, glGetQueryObjecti64vEXT, ( GLuint, GLenum, GLint64 * ) ) \
    GL_FUNCTION( void, glGetQueryObjectui64vEXT, ( GLuint, GLenum, GLuint64 * ) ) \
    \
    /* GL_EXT_transform_feedback */ \
    GL_FUNCTION( void, glBeginTransformFeedbackEXT, ( GLenum ) ) \
    GL_FUNCTION( void, glEndTransformFeedbackEXT, ( ) ) \
    GL_FUNCTION( void, glBindBufferRangeEXT, ( GLenum, GLuint, GLuint, GLintptr, GLsizeiptr ) ) \
    GL_FUNCTION( void, glBindBufferOffsetEXT, ( GLenum, GLuint, GLuint, GLintptr ) ) \
    GL_FUNCTION( void, glBindBufferBaseEXT, ( GLenum, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glTransformFeedbackVaryingsEXT, ( GLuint, GLsizei, const GLchar *const*, GLenum ) ) \
    GL_FUNCTION( void, glGetTransformFeedbackVaryingEXT, ( GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar * ) ) \
    \
    /* GL_EXT_vertex_array */ \
    GL_FUNCTION( void, glArrayElementEXT, ( GLint ) ) \
    GL_FUNCTION( void, glColorPointerEXT, ( GLint, GLenum, GLsizei, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glDrawArraysEXT, ( GLenum, GLint, GLsizei ) ) \
    GL_FUNCTION( void, glEdgeFlagPointerEXT, ( GLsizei, GLsizei, const GLboolean * ) ) \
    GL_FUNCTION( void, glGetPointervEXT, ( GLenum, GLvoid ** ) ) \
    GL_FUNCTION( void, glIndexPointerEXT, ( GLenum, GLsizei, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glNormalPointerEXT, ( GLenum, GLsizei, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glTexCoordPointerEXT, ( GLint, GLenum, GLsizei, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glVertexPointerEXT, ( GLint, GLenum, GLsizei, GLsizei, const GLvoid * ) ) \
    \
    /* GL_EXT_vertex_array_bgra */ \
    \
    /* GL_EXT_vertex_attrib_64bit */ \
    GL_FUNCTION( void, glVertexAttribL1dEXT, ( GLuint, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttribL2dEXT, ( GLuint, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttribL3dEXT, ( GLuint, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttribL4dEXT, ( GLuint, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttribL1dvEXT, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttribL2dvEXT, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttribL3dvEXT, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttribL4dvEXT, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttribLPointerEXT, ( GLuint, GLint, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glGetVertexAttribLdvEXT, ( GLuint, GLenum, GLdouble * ) ) \
    \
    /* GL_EXT_vertex_shader */ \
    GL_FUNCTION( void, glBeginVertexShaderEXT, ( ) ) \
    GL_FUNCTION( void, glEndVertexShaderEXT, ( ) ) \
    GL_FUNCTION( void, glBindVertexShaderEXT, ( GLuint ) ) \
    GL_FUNCTION( GLuint, glGenVertexShadersEXT, ( GLuint ) ) \
    GL_FUNCTION( void, glDeleteVertexShaderEXT, ( GLuint ) ) \
    GL_FUNCTION( void, glShaderOp1EXT, ( GLenum, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glShaderOp2EXT, ( GLenum, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glShaderOp3EXT, ( GLenum, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glSwizzleEXT, ( GLuint, GLuint, GLenum, GLenum, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glWriteMaskEXT, ( GLuint, GLuint, GLenum, GLenum, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glInsertComponentEXT, ( GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glExtractComponentEXT, ( GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( GLuint, glGenSymbolsEXT, ( GLenum, GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glSetInvariantEXT, ( GLuint, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glSetLocalConstantEXT, ( GLuint, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glVariantbvEXT, ( GLuint, const GLbyte * ) ) \
    GL_FUNCTION( void, glVariantsvEXT, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVariantivEXT, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glVariantfvEXT, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glVariantdvEXT, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVariantubvEXT, ( GLuint, const GLubyte * ) ) \
    GL_FUNCTION( void, glVariantusvEXT, ( GLuint, const GLushort * ) ) \
    GL_FUNCTION( void, glVariantuivEXT, ( GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glVariantPointerEXT, ( GLuint, GLenum, GLuint, const GLvoid * ) ) \
    GL_FUNCTION( void, glEnableVariantClientStateEXT, ( GLuint ) ) \
    GL_FUNCTION( void, glDisableVariantClientStateEXT, ( GLuint ) ) \
    GL_FUNCTION( GLuint, glBindLightParameterEXT, ( GLenum, GLenum ) ) \
    GL_FUNCTION( GLuint, glBindMaterialParameterEXT, ( GLenum, GLenum ) ) \
    GL_FUNCTION( GLuint, glBindTexGenParameterEXT, ( GLenum, GLenum, GLenum ) ) \
    GL_FUNCTION( GLuint, glBindTextureUnitParameterEXT, ( GLenum, GLenum ) ) \
    GL_FUNCTION( GLuint, glBindParameterEXT, ( GLenum ) ) \
    GL_FUNCTION( GLboolean, glIsVariantEnabledEXT, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glGetVariantBooleanvEXT, ( GLuint, GLenum, GLboolean * ) ) \
    GL_FUNCTION( void, glGetVariantIntegervEXT, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetVariantFloatvEXT, ( GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetVariantPointervEXT, ( GLuint, GLenum, GLvoid ** ) ) \
    GL_FUNCTION( void, glGetInvariantBooleanvEXT, ( GLuint, GLenum, GLboolean * ) ) \
    GL_FUNCTION( void, glGetInvariantIntegervEXT, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetInvariantFloatvEXT, ( GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetLocalConstantBooleanvEXT, ( GLuint, GLenum, GLboolean * ) ) \
    GL_FUNCTION( void, glGetLocalConstantIntegervEXT, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetLocalConstantFloatvEXT, ( GLuint, GLenum, GLfloat * ) ) \
    \
    /* GL_EXT_vertex_weighting */ \
    GL_FUNCTION( void, glVertexWeightfEXT, ( GLfloat ) ) \
    GL_FUNCTION( void, glVertexWeightfvEXT, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexWeightPointerEXT, ( GLint, GLenum, GLsizei, const GLvoid * ) ) \
    \
    /* GL_EXT_x11_sync_object */ \
    GL_FUNCTION( GLsync, glImportSyncEXT, ( GLenum, GLintptr, GLbitfield ) ) \
    \
    /* GL_GREMEDY_frame_terminator */ \
    GL_FUNCTION( void, glFrameTerminatorGREMEDY, ( ) ) \
    \
    /* GL_GREMEDY_string_marker */ \
    GL_FUNCTION( void, glStringMarkerGREMEDY, ( GLsizei, const GLvoid * ) ) \
    \
    /* GL_HP_convolution_border_modes */ \
    \
    /* GL_HP_image_transform */ \
    GL_FUNCTION( void, glImageTransformParameteriHP, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glImageTransformParameterfHP, ( GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glImageTransformParameterivHP, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glImageTransformParameterfvHP, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glGetImageTransformParameterivHP, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetImageTransformParameterfvHP, ( GLenum, GLenum, GLfloat * ) ) \
    \
    /* GL_HP_occlusion_test */ \
    \
    /* GL_HP_texture_lighting */ \
    \
    /* GL_IBM_cull_vertex */ \
    \
    /* GL_IBM_multimode_draw_arrays */ \
    GL_FUNCTION( void, glMultiModeDrawArraysIBM, ( const GLenum *, const GLint *, const GLsizei *, GLsizei, GLint ) ) \
    GL_FUNCTION( void, glMultiModeDrawElementsIBM, ( const GLenum *, const GLsizei *, GLenum, const GLvoid *const*, GLsizei, GLint ) ) \
    \
    /* GL_IBM_rasterpos_clip */ \
    \
    /* GL_IBM_static_data */ \
    GL_FUNCTION( void, glFlushStaticDataIBM, ( GLenum ) ) \
    \
    /* GL_IBM_texture_mirrored_repeat */ \
    \
    /* GL_IBM_vertex_array_lists */ \
    GL_FUNCTION( void, glColorPointerListIBM, ( GLint, GLenum, GLint, const GLvoid **, GLint ) ) \
    GL_FUNCTION( void, glSecondaryColorPointerListIBM, ( GLint, GLenum, GLint, const GLvoid **, GLint ) ) \
    GL_FUNCTION( void, glEdgeFlagPointerListIBM, ( GLint, const GLboolean **, GLint ) ) \
    GL_FUNCTION( void, glFogCoordPointerListIBM, ( GLenum, GLint, const GLvoid **, GLint ) ) \
    GL_FUNCTION( void, glIndexPointerListIBM, ( GLenum, GLint, const GLvoid **, GLint ) ) \
    GL_FUNCTION( void, glNormalPointerListIBM, ( GLenum, GLint, const GLvoid **, GLint ) ) \
    GL_FUNCTION( void, glTexCoordPointerListIBM, ( GLint, GLenum, GLint, const GLvoid **, GLint ) ) \
    GL_FUNCTION( void, glVertexPointerListIBM, ( GLint, GLenum, GLint, const GLvoid **, GLint ) ) \
    \
    /* GL_INGR_blend_func_separate */ \
    GL_FUNCTION( void, glBlendFuncSeparateINGR, ( GLenum, GLenum, GLenum, GLenum ) ) \
    \
    /* GL_INGR_color_clamp */ \
    \
    /* GL_INGR_interlace_read */ \
    \
    /* GL_INTEL_map_texture */ \
    GL_FUNCTION( void, glSyncTextureINTEL, ( GLuint ) ) \
    GL_FUNCTION( void, glUnmapTexture2DINTEL, ( GLuint, GLint ) ) \
    GL_FUNCTION( void *, glMapTexture2DINTEL, ( GLuint, GLint, GLbitfield, const GLint *, const GLenum * ) ) \
    \
    /* GL_INTEL_parallel_arrays */ \
    GL_FUNCTION( void, glVertexPointervINTEL, ( GLint, GLenum, const GLvoid ** ) ) \
    GL_FUNCTION( void, glNormalPointervINTEL, ( GLenum, const GLvoid ** ) ) \
    GL_FUNCTION( void, glColorPointervINTEL, ( GLint, GLenum, const GLvoid ** ) ) \
    GL_FUNCTION( void, glTexCoordPointervINTEL, ( GLint, GLenum, const GLvoid ** ) ) \
    \
    /* GL_MESAX_texture_stack */ \
    \
    /* GL_MESA_pack_invert */ \
    \
    /* GL_MESA_resize_buffers */ \
    GL_FUNCTION( void, glResizeBuffersMESA, ( ) ) \
    \
    /* GL_MESA_window_pos */ \
    GL_FUNCTION( void, glWindowPos2dMESA, ( GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glWindowPos2dvMESA, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glWindowPos2fMESA, ( GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glWindowPos2fvMESA, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glWindowPos2iMESA, ( GLint, GLint ) ) \
    GL_FUNCTION( void, glWindowPos2ivMESA, ( const GLint * ) ) \
    GL_FUNCTION( void, glWindowPos2sMESA, ( GLshort, GLshort ) ) \
    GL_FUNCTION( void, glWindowPos2svMESA, ( const GLshort * ) ) \
    GL_FUNCTION( void, glWindowPos3dMESA, ( GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glWindowPos3dvMESA, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glWindowPos3fMESA, ( GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glWindowPos3fvMESA, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glWindowPos3iMESA, ( GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glWindowPos3ivMESA, ( const GLint * ) ) \
    GL_FUNCTION( void, glWindowPos3sMESA, ( GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glWindowPos3svMESA, ( const GLshort * ) ) \
    GL_FUNCTION( void, glWindowPos4dMESA, ( GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glWindowPos4dvMESA, ( const GLdouble * ) ) \
    GL_FUNCTION( void, glWindowPos4fMESA, ( GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glWindowPos4fvMESA, ( const GLfloat * ) ) \
    GL_FUNCTION( void, glWindowPos4iMESA, ( GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glWindowPos4ivMESA, ( const GLint * ) ) \
    GL_FUNCTION( void, glWindowPos4sMESA, ( GLshort, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glWindowPos4svMESA, ( const GLshort * ) ) \
    \
    /* GL_MESA_ycbcr_texture */ \
    \
    /* GL_NVX_conditional_render */ \
    GL_FUNCTION( void, glBeginConditionalRenderNVX, ( GLuint ) ) \
    GL_FUNCTION( void, glEndConditionalRenderNVX, ( ) ) \
    \
    /* GL_NV_bindless_multi_draw_indirect */ \
    GL_FUNCTION( void, glMultiDrawArraysIndirectBindlessNV, ( GLenum, const GLvoid *, GLsizei, GLsizei, GLint ) ) \
    GL_FUNCTION( void, glMultiDrawElementsIndirectBindlessNV, ( GLenum, GLenum, const GLvoid *, GLsizei, GLsizei, GLint ) ) \
    \
    /* GL_NV_bindless_texture */ \
    GL_FUNCTION( GLuint64, glGetTextureHandleNV, ( GLuint ) ) \
    GL_FUNCTION( GLuint64, glGetTextureSamplerHandleNV, ( GLuint, GLuint ) ) \
    GL_FUNCTION( void, glMakeTextureHandleResidentNV, ( GLuint64 ) ) \
    GL_FUNCTION( void, glMakeTextureHandleNonResidentNV, ( GLuint64 ) ) \
    GL_FUNCTION( GLuint64, glGetImageHandleNV, ( GLuint, GLint, GLboolean, GLint, GLenum ) ) \
    GL_FUNCTION( void, glMakeImageHandleResidentNV, ( GLuint64, GLenum ) ) \
    GL_FUNCTION( void, glMakeImageHandleNonResidentNV, ( GLuint64 ) ) \
    GL_FUNCTION( void, glUniformHandleui64NV, ( GLint, GLuint64 ) ) \
    GL_FUNCTION( void, glUniformHandleui64vNV, ( GLint, GLsizei, const GLuint64 * ) ) \
    GL_FUNCTION( void, glProgramUniformHandleui64NV, ( GLuint, GLint, GLuint64 ) ) \
    GL_FUNCTION( void, glProgramUniformHandleui64vNV, ( GLuint, GLint, GLsizei, const GLuint64 * ) ) \
    GL_FUNCTION( GLboolean, glIsTextureHandleResidentNV, ( GLuint64 ) ) \
    GL_FUNCTION( GLboolean, glIsImageHandleResidentNV, ( GLuint64 ) ) \
    \
    /* GL_NV_blend_equation_advanced */ \
    GL_FUNCTION( void, glBlendParameteriNV, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glBlendBarrierNV, ( ) ) \
    \
    /* GL_NV_blend_equation_advanced_coherent */ \
    \
    /* GL_NV_blend_square */ \
    \
    /* GL_NV_compute_program5 */ \
    \
    /* GL_NV_conditional_render */ \
    GL_FUNCTION( void, glBeginConditionalRenderNV, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glEndConditionalRenderNV, ( ) ) \
    \
    /* GL_NV_copy_depth_to_color */ \
    \
    /* GL_NV_copy_image */ \
    GL_FUNCTION( void, glCopyImageSubDataNV, ( GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei ) ) \
    \
    /* GL_NV_deep_texture3D */ \
    \
    /* GL_NV_depth_buffer_float */ \
    GL_FUNCTION( void, glDepthRangedNV, ( GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glClearDepthdNV, ( GLdouble ) ) \
    GL_FUNCTION( void, glDepthBoundsdNV, ( GLdouble, GLdouble ) ) \
    \
    /* GL_NV_depth_clamp */ \
    \
    /* GL_NV_draw_texture */ \
    GL_FUNCTION( void, glDrawTextureNV, ( GLuint, GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    \
    /* GL_NV_evaluators */ \
    GL_FUNCTION( void, glMapControlPointsNV, ( GLenum, GLuint, GLenum, GLsizei, GLsizei, GLint, GLint, GLboolean, const GLvoid * ) ) \
    GL_FUNCTION( void, glMapParameterivNV, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glMapParameterfvNV, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glGetMapControlPointsNV, ( GLenum, GLuint, GLenum, GLsizei, GLsizei, GLboolean, GLvoid * ) ) \
    GL_FUNCTION( void, glGetMapParameterivNV, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetMapParameterfvNV, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetMapAttribParameterivNV, ( GLenum, GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetMapAttribParameterfvNV, ( GLenum, GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glEvalMapsNV, ( GLenum, GLenum ) ) \
    \
    /* GL_NV_explicit_multisample */ \
    GL_FUNCTION( void, glGetMultisamplefvNV, ( GLenum, GLuint, GLfloat * ) ) \
    GL_FUNCTION( void, glSampleMaskIndexedNV, ( GLuint, GLbitfield ) ) \
    GL_FUNCTION( void, glTexRenderbufferNV, ( GLenum, GLuint ) ) \
    \
    /* GL_NV_fence */ \
    GL_FUNCTION( void, glDeleteFencesNV, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenFencesNV, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsFenceNV, ( GLuint ) ) \
    GL_FUNCTION( GLboolean, glTestFenceNV, ( GLuint ) ) \
    GL_FUNCTION( void, glGetFenceivNV, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glFinishFenceNV, ( GLuint ) ) \
    GL_FUNCTION( void, glSetFenceNV, ( GLuint, GLenum ) ) \
    \
    /* GL_NV_float_buffer */ \
    \
    /* GL_NV_fog_distance */ \
    \
    /* GL_NV_fragment_program */ \
    GL_FUNCTION( void, glProgramNamedParameter4fNV, ( GLuint, GLsizei, const GLubyte *, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glProgramNamedParameter4fvNV, ( GLuint, GLsizei, const GLubyte *, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramNamedParameter4dNV, ( GLuint, GLsizei, const GLubyte *, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glProgramNamedParameter4dvNV, ( GLuint, GLsizei, const GLubyte *, const GLdouble * ) ) \
    GL_FUNCTION( void, glGetProgramNamedParameterfvNV, ( GLuint, GLsizei, const GLubyte *, GLfloat * ) ) \
    GL_FUNCTION( void, glGetProgramNamedParameterdvNV, ( GLuint, GLsizei, const GLubyte *, GLdouble * ) ) \
    \
    /* GL_NV_fragment_program2 */ \
    \
    /* GL_NV_fragment_program4 */ \
    \
    /* GL_NV_fragment_program_option */ \
    \
    /* GL_NV_framebuffer_multisample_coverage */ \
    GL_FUNCTION( void, glRenderbufferStorageMultisampleCoverageNV, ( GLenum, GLsizei, GLsizei, GLenum, GLsizei, GLsizei ) ) \
    \
    /* GL_NV_geometry_program4 */ \
    GL_FUNCTION( void, glProgramVertexLimitNV, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glFramebufferTextureEXT, ( GLenum, GLenum, GLuint, GLint ) ) \
    GL_FUNCTION( void, glFramebufferTextureLayerEXT, ( GLenum, GLenum, GLuint, GLint, GLint ) ) \
    GL_FUNCTION( void, glFramebufferTextureFaceEXT, ( GLenum, GLenum, GLuint, GLint, GLenum ) ) \
    \
    /* GL_NV_geometry_shader4 */ \
    \
    /* GL_NV_gpu_program4 */ \
    GL_FUNCTION( void, glProgramLocalParameterI4iNV, ( GLenum, GLuint, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glProgramLocalParameterI4ivNV, ( GLenum, GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glProgramLocalParametersI4ivNV, ( GLenum, GLuint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glProgramLocalParameterI4uiNV, ( GLenum, GLuint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glProgramLocalParameterI4uivNV, ( GLenum, GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glProgramLocalParametersI4uivNV, ( GLenum, GLuint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glProgramEnvParameterI4iNV, ( GLenum, GLuint, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glProgramEnvParameterI4ivNV, ( GLenum, GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glProgramEnvParametersI4ivNV, ( GLenum, GLuint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glProgramEnvParameterI4uiNV, ( GLenum, GLuint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glProgramEnvParameterI4uivNV, ( GLenum, GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glProgramEnvParametersI4uivNV, ( GLenum, GLuint, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGetProgramLocalParameterIivNV, ( GLenum, GLuint, GLint * ) ) \
    GL_FUNCTION( void, glGetProgramLocalParameterIuivNV, ( GLenum, GLuint, GLuint * ) ) \
    GL_FUNCTION( void, glGetProgramEnvParameterIivNV, ( GLenum, GLuint, GLint * ) ) \
    GL_FUNCTION( void, glGetProgramEnvParameterIuivNV, ( GLenum, GLuint, GLuint * ) ) \
    \
    /* GL_NV_gpu_program5 */ \
    GL_FUNCTION( void, glProgramSubroutineParametersuivNV, ( GLenum, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGetProgramSubroutineParameteruivNV, ( GLenum, GLuint, GLuint * ) ) \
    \
    /* GL_NV_gpu_program5_mem_extended */ \
    \
    /* GL_NV_gpu_shader5 */ \
    GL_FUNCTION( void, glUniform1i64NV, ( GLint, GLint64EXT ) ) \
    GL_FUNCTION( void, glUniform2i64NV, ( GLint, GLint64EXT, GLint64EXT ) ) \
    GL_FUNCTION( void, glUniform3i64NV, ( GLint, GLint64EXT, GLint64EXT, GLint64EXT ) ) \
    GL_FUNCTION( void, glUniform4i64NV, ( GLint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT ) ) \
    GL_FUNCTION( void, glUniform1i64vNV, ( GLint, GLsizei, const GLint64EXT * ) ) \
    GL_FUNCTION( void, glUniform2i64vNV, ( GLint, GLsizei, const GLint64EXT * ) ) \
    GL_FUNCTION( void, glUniform3i64vNV, ( GLint, GLsizei, const GLint64EXT * ) ) \
    GL_FUNCTION( void, glUniform4i64vNV, ( GLint, GLsizei, const GLint64EXT * ) ) \
    GL_FUNCTION( void, glUniform1ui64NV, ( GLint, GLuint64EXT ) ) \
    GL_FUNCTION( void, glUniform2ui64NV, ( GLint, GLuint64EXT, GLuint64EXT ) ) \
    GL_FUNCTION( void, glUniform3ui64NV, ( GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT ) ) \
    GL_FUNCTION( void, glUniform4ui64NV, ( GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT ) ) \
    GL_FUNCTION( void, glUniform1ui64vNV, ( GLint, GLsizei, const GLuint64EXT * ) ) \
    GL_FUNCTION( void, glUniform2ui64vNV, ( GLint, GLsizei, const GLuint64EXT * ) ) \
    GL_FUNCTION( void, glUniform3ui64vNV, ( GLint, GLsizei, const GLuint64EXT * ) ) \
    GL_FUNCTION( void, glUniform4ui64vNV, ( GLint, GLsizei, const GLuint64EXT * ) ) \
    GL_FUNCTION( void, glGetUniformi64vNV, ( GLuint, GLint, GLint64EXT * ) ) \
    GL_FUNCTION( void, glProgramUniform1i64NV, ( GLuint, GLint, GLint64EXT ) ) \
    GL_FUNCTION( void, glProgramUniform2i64NV, ( GLuint, GLint, GLint64EXT, GLint64EXT ) ) \
    GL_FUNCTION( void, glProgramUniform3i64NV, ( GLuint, GLint, GLint64EXT, GLint64EXT, GLint64EXT ) ) \
    GL_FUNCTION( void, glProgramUniform4i64NV, ( GLuint, GLint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT ) ) \
    GL_FUNCTION( void, glProgramUniform1i64vNV, ( GLuint, GLint, GLsizei, const GLint64EXT * ) ) \
    GL_FUNCTION( void, glProgramUniform2i64vNV, ( GLuint, GLint, GLsizei, const GLint64EXT * ) ) \
    GL_FUNCTION( void, glProgramUniform3i64vNV, ( GLuint, GLint, GLsizei, const GLint64EXT * ) ) \
    GL_FUNCTION( void, glProgramUniform4i64vNV, ( GLuint, GLint, GLsizei, const GLint64EXT * ) ) \
    GL_FUNCTION( void, glProgramUniform1ui64NV, ( GLuint, GLint, GLuint64EXT ) ) \
    GL_FUNCTION( void, glProgramUniform2ui64NV, ( GLuint, GLint, GLuint64EXT, GLuint64EXT ) ) \
    GL_FUNCTION( void, glProgramUniform3ui64NV, ( GLuint, GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT ) ) \
    GL_FUNCTION( void, glProgramUniform4ui64NV, ( GLuint, GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT ) ) \
    GL_FUNCTION( void, glProgramUniform1ui64vNV, ( GLuint, GLint, GLsizei, const GLuint64EXT * ) ) \
    GL_FUNCTION( void, glProgramUniform2ui64vNV, ( GLuint, GLint, GLsizei, const GLuint64EXT * ) ) \
    GL_FUNCTION( void, glProgramUniform3ui64vNV, ( GLuint, GLint, GLsizei, const GLuint64EXT * ) ) \
    GL_FUNCTION( void, glProgramUniform4ui64vNV, ( GLuint, GLint, GLsizei, const GLuint64EXT * ) ) \
    \
    /* GL_NV_half_float */ \
    GL_FUNCTION( void, glVertex2hNV, ( GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glVertex2hvNV, ( const GLhalfNV * ) ) \
    GL_FUNCTION( void, glVertex3hNV, ( GLhalfNV, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glVertex3hvNV, ( const GLhalfNV * ) ) \
    GL_FUNCTION( void, glVertex4hNV, ( GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glVertex4hvNV, ( const GLhalfNV * ) ) \
    GL_FUNCTION( void, glNormal3hNV, ( GLhalfNV, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glNormal3hvNV, ( const GLhalfNV * ) ) \
    GL_FUNCTION( void, glColor3hNV, ( GLhalfNV, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glColor3hvNV, ( const GLhalfNV * ) ) \
    GL_FUNCTION( void, glColor4hNV, ( GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glColor4hvNV, ( const GLhalfNV * ) ) \
    GL_FUNCTION( void, glTexCoord1hNV, ( GLhalfNV ) ) \
    GL_FUNCTION( void, glTexCoord1hvNV, ( const GLhalfNV * ) ) \
    GL_FUNCTION( void, glTexCoord2hNV, ( GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glTexCoord2hvNV, ( const GLhalfNV * ) ) \
    GL_FUNCTION( void, glTexCoord3hNV, ( GLhalfNV, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glTexCoord3hvNV, ( const GLhalfNV * ) ) \
    GL_FUNCTION( void, glTexCoord4hNV, ( GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glTexCoord4hvNV, ( const GLhalfNV * ) ) \
    GL_FUNCTION( void, glMultiTexCoord1hNV, ( GLenum, GLhalfNV ) ) \
    GL_FUNCTION( void, glMultiTexCoord1hvNV, ( GLenum, const GLhalfNV * ) ) \
    GL_FUNCTION( void, glMultiTexCoord2hNV, ( GLenum, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glMultiTexCoord2hvNV, ( GLenum, const GLhalfNV * ) ) \
    GL_FUNCTION( void, glMultiTexCoord3hNV, ( GLenum, GLhalfNV, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glMultiTexCoord3hvNV, ( GLenum, const GLhalfNV * ) ) \
    GL_FUNCTION( void, glMultiTexCoord4hNV, ( GLenum, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glMultiTexCoord4hvNV, ( GLenum, const GLhalfNV * ) ) \
    GL_FUNCTION( void, glFogCoordhNV, ( GLhalfNV ) ) \
    GL_FUNCTION( void, glFogCoordhvNV, ( const GLhalfNV * ) ) \
    GL_FUNCTION( void, glSecondaryColor3hNV, ( GLhalfNV, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glSecondaryColor3hvNV, ( const GLhalfNV * ) ) \
    GL_FUNCTION( void, glVertexWeighthNV, ( GLhalfNV ) ) \
    GL_FUNCTION( void, glVertexWeighthvNV, ( const GLhalfNV * ) ) \
    GL_FUNCTION( void, glVertexAttrib1hNV, ( GLuint, GLhalfNV ) ) \
    GL_FUNCTION( void, glVertexAttrib1hvNV, ( GLuint, const GLhalfNV * ) ) \
    GL_FUNCTION( void, glVertexAttrib2hNV, ( GLuint, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glVertexAttrib2hvNV, ( GLuint, const GLhalfNV * ) ) \
    GL_FUNCTION( void, glVertexAttrib3hNV, ( GLuint, GLhalfNV, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glVertexAttrib3hvNV, ( GLuint, const GLhalfNV * ) ) \
    GL_FUNCTION( void, glVertexAttrib4hNV, ( GLuint, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV ) ) \
    GL_FUNCTION( void, glVertexAttrib4hvNV, ( GLuint, const GLhalfNV * ) ) \
    GL_FUNCTION( void, glVertexAttribs1hvNV, ( GLuint, GLsizei, const GLhalfNV * ) ) \
    GL_FUNCTION( void, glVertexAttribs2hvNV, ( GLuint, GLsizei, const GLhalfNV * ) ) \
    GL_FUNCTION( void, glVertexAttribs3hvNV, ( GLuint, GLsizei, const GLhalfNV * ) ) \
    GL_FUNCTION( void, glVertexAttribs4hvNV, ( GLuint, GLsizei, const GLhalfNV * ) ) \
    \
    /* GL_NV_light_max_exponent */ \
    \
    /* GL_NV_multisample_coverage */ \
    \
    /* GL_NV_multisample_filter_hint */ \
    \
    /* GL_NV_occlusion_query */ \
    GL_FUNCTION( void, glGenOcclusionQueriesNV, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glDeleteOcclusionQueriesNV, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsOcclusionQueryNV, ( GLuint ) ) \
    GL_FUNCTION( void, glBeginOcclusionQueryNV, ( GLuint ) ) \
    GL_FUNCTION( void, glEndOcclusionQueryNV, ( ) ) \
    GL_FUNCTION( void, glGetOcclusionQueryivNV, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetOcclusionQueryuivNV, ( GLuint, GLenum, GLuint * ) ) \
    \
    /* GL_NV_packed_depth_stencil */ \
    \
    /* GL_NV_parameter_buffer_object */ \
    GL_FUNCTION( void, glProgramBufferParametersfvNV, ( GLenum, GLuint, GLuint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramBufferParametersIivNV, ( GLenum, GLuint, GLuint, GLsizei, const GLint * ) ) \
    GL_FUNCTION( void, glProgramBufferParametersIuivNV, ( GLenum, GLuint, GLuint, GLsizei, const GLuint * ) ) \
    \
    /* GL_NV_parameter_buffer_object2 */ \
    \
    /* GL_NV_path_rendering */ \
    GL_FUNCTION( GLuint, glGenPathsNV, ( GLsizei ) ) \
    GL_FUNCTION( void, glDeletePathsNV, ( GLuint, GLsizei ) ) \
    GL_FUNCTION( GLboolean, glIsPathNV, ( GLuint ) ) \
    GL_FUNCTION( void, glPathCommandsNV, ( GLuint, GLsizei, const GLubyte *, GLsizei, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glPathCoordsNV, ( GLuint, GLsizei, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glPathSubCommandsNV, ( GLuint, GLsizei, GLsizei, GLsizei, const GLubyte *, GLsizei, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glPathSubCoordsNV, ( GLuint, GLsizei, GLsizei, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glPathStringNV, ( GLuint, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glPathGlyphsNV, ( GLuint, GLenum, const GLvoid *, GLbitfield, GLsizei, GLenum, const GLvoid *, GLenum, GLuint, GLfloat ) ) \
    GL_FUNCTION( void, glPathGlyphRangeNV, ( GLuint, GLenum, const GLvoid *, GLbitfield, GLuint, GLsizei, GLenum, GLuint, GLfloat ) ) \
    GL_FUNCTION( void, glWeightPathsNV, ( GLuint, GLsizei, const GLuint *, const GLfloat * ) ) \
    GL_FUNCTION( void, glCopyPathNV, ( GLuint, GLuint ) ) \
    GL_FUNCTION( void, glInterpolatePathsNV, ( GLuint, GLuint, GLuint, GLfloat ) ) \
    GL_FUNCTION( void, glTransformPathNV, ( GLuint, GLuint, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glPathParameterivNV, ( GLuint, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glPathParameteriNV, ( GLuint, GLenum, GLint ) ) \
    GL_FUNCTION( void, glPathParameterfvNV, ( GLuint, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glPathParameterfNV, ( GLuint, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glPathDashArrayNV, ( GLuint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glPathStencilFuncNV, ( GLenum, GLint, GLuint ) ) \
    GL_FUNCTION( void, glPathStencilDepthOffsetNV, ( GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glStencilFillPathNV, ( GLuint, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glStencilStrokePathNV, ( GLuint, GLint, GLuint ) ) \
    GL_FUNCTION( void, glStencilFillPathInstancedNV, ( GLsizei, GLenum, const GLvoid *, GLuint, GLenum, GLuint, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glStencilStrokePathInstancedNV, ( GLsizei, GLenum, const GLvoid *, GLuint, GLint, GLuint, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glPathCoverDepthFuncNV, ( GLenum ) ) \
    GL_FUNCTION( void, glPathColorGenNV, ( GLenum, GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glPathTexGenNV, ( GLenum, GLenum, GLint, const GLfloat * ) ) \
    GL_FUNCTION( void, glPathFogGenNV, ( GLenum ) ) \
    GL_FUNCTION( void, glCoverFillPathNV, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glCoverStrokePathNV, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glCoverFillPathInstancedNV, ( GLsizei, GLenum, const GLvoid *, GLuint, GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glCoverStrokePathInstancedNV, ( GLsizei, GLenum, const GLvoid *, GLuint, GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glGetPathParameterivNV, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetPathParameterfvNV, ( GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetPathCommandsNV, ( GLuint, GLubyte * ) ) \
    GL_FUNCTION( void, glGetPathCoordsNV, ( GLuint, GLfloat * ) ) \
    GL_FUNCTION( void, glGetPathDashArrayNV, ( GLuint, GLfloat * ) ) \
    GL_FUNCTION( void, glGetPathMetricsNV, ( GLbitfield, GLsizei, GLenum, const GLvoid *, GLuint, GLsizei, GLfloat * ) ) \
    GL_FUNCTION( void, glGetPathMetricRangeNV, ( GLbitfield, GLuint, GLsizei, GLsizei, GLfloat * ) ) \
    GL_FUNCTION( void, glGetPathSpacingNV, ( GLenum, GLsizei, GLenum, const GLvoid *, GLuint, GLfloat, GLfloat, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetPathColorGenivNV, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetPathColorGenfvNV, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetPathTexGenivNV, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetPathTexGenfvNV, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( GLboolean, glIsPointInFillPathNV, ( GLuint, GLuint, GLfloat, GLfloat ) ) \
    GL_FUNCTION( GLboolean, glIsPointInStrokePathNV, ( GLuint, GLfloat, GLfloat ) ) \
    GL_FUNCTION( GLfloat, glGetPathLengthNV, ( GLuint, GLsizei, GLsizei ) ) \
    GL_FUNCTION( GLboolean, glPointAlongPathNV, ( GLuint, GLsizei, GLsizei, GLfloat, GLfloat *, GLfloat *, GLfloat *, GLfloat * ) ) \
    \
    /* GL_NV_pixel_data_range */ \
    GL_FUNCTION( void, glPixelDataRangeNV, ( GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glFlushPixelDataRangeNV, ( GLenum ) ) \
    \
    /* GL_NV_point_sprite */ \
    GL_FUNCTION( void, glPointParameteriNV, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glPointParameterivNV, ( GLenum, const GLint * ) ) \
    \
    /* GL_NV_present_video */ \
    GL_FUNCTION( void, glPresentFrameKeyedNV, ( GLuint, GLuint64EXT, GLuint, GLuint, GLenum, GLenum, GLuint, GLuint, GLenum, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glPresentFrameDualFillNV, ( GLuint, GLuint64EXT, GLuint, GLuint, GLenum, GLenum, GLuint, GLenum, GLuint, GLenum, GLuint, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glGetVideoivNV, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetVideouivNV, ( GLuint, GLenum, GLuint * ) ) \
    GL_FUNCTION( void, glGetVideoi64vNV, ( GLuint, GLenum, GLint64EXT * ) ) \
    GL_FUNCTION( void, glGetVideoui64vNV, ( GLuint, GLenum, GLuint64EXT * ) ) \
    \
    /* GL_NV_primitive_restart */ \
    GL_FUNCTION( void, glPrimitiveRestartNV, ( ) ) \
    GL_FUNCTION( void, glPrimitiveRestartIndexNV, ( GLuint ) ) \
    \
    /* GL_NV_register_combiners */ \
    GL_FUNCTION( void, glCombinerParameterfvNV, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glCombinerParameterfNV, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glCombinerParameterivNV, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glCombinerParameteriNV, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glCombinerInputNV, ( GLenum, GLenum, GLenum, GLenum, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glCombinerOutputNV, ( GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLboolean, GLboolean, GLboolean ) ) \
    GL_FUNCTION( void, glFinalCombinerInputNV, ( GLenum, GLenum, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glGetCombinerInputParameterfvNV, ( GLenum, GLenum, GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetCombinerInputParameterivNV, ( GLenum, GLenum, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetCombinerOutputParameterfvNV, ( GLenum, GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetCombinerOutputParameterivNV, ( GLenum, GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetFinalCombinerInputParameterfvNV, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetFinalCombinerInputParameterivNV, ( GLenum, GLenum, GLint * ) ) \
    \
    /* GL_NV_register_combiners2 */ \
    GL_FUNCTION( void, glCombinerStageParameterfvNV, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glGetCombinerStageParameterfvNV, ( GLenum, GLenum, GLfloat * ) ) \
    \
    /* GL_NV_shader_atomic_counters */ \
    \
    /* GL_NV_shader_atomic_float */ \
    \
    /* GL_NV_shader_buffer_load */ \
    GL_FUNCTION( void, glMakeBufferResidentNV, ( GLenum, GLenum ) ) \
    GL_FUNCTION( void, glMakeBufferNonResidentNV, ( GLenum ) ) \
    GL_FUNCTION( GLboolean, glIsBufferResidentNV, ( GLenum ) ) \
    GL_FUNCTION( void, glMakeNamedBufferResidentNV, ( GLuint, GLenum ) ) \
    GL_FUNCTION( void, glMakeNamedBufferNonResidentNV, ( GLuint ) ) \
    GL_FUNCTION( GLboolean, glIsNamedBufferResidentNV, ( GLuint ) ) \
    GL_FUNCTION( void, glGetBufferParameterui64vNV, ( GLenum, GLenum, GLuint64EXT * ) ) \
    GL_FUNCTION( void, glGetNamedBufferParameterui64vNV, ( GLuint, GLenum, GLuint64EXT * ) ) \
    GL_FUNCTION( void, glGetIntegerui64vNV, ( GLenum, GLuint64EXT * ) ) \
    GL_FUNCTION( void, glUniformui64NV, ( GLint, GLuint64EXT ) ) \
    GL_FUNCTION( void, glUniformui64vNV, ( GLint, GLsizei, const GLuint64EXT * ) ) \
    GL_FUNCTION( void, glGetUniformui64vNV, ( GLuint, GLint, GLuint64EXT * ) ) \
    GL_FUNCTION( void, glProgramUniformui64NV, ( GLuint, GLint, GLuint64EXT ) ) \
    GL_FUNCTION( void, glProgramUniformui64vNV, ( GLuint, GLint, GLsizei, const GLuint64EXT * ) ) \
    \
    /* GL_NV_shader_buffer_store */ \
    \
    /* GL_NV_shader_storage_buffer_object */ \
    \
    /* GL_NV_tessellation_program5 */ \
    \
    /* GL_NV_texgen_emboss */ \
    \
    /* GL_NV_texgen_reflection */ \
    \
    /* GL_NV_texture_barrier */ \
    GL_FUNCTION( void, glTextureBarrierNV, ( ) ) \
    \
    /* GL_NV_texture_compression_vtc */ \
    \
    /* GL_NV_texture_env_combine4 */ \
    \
    /* GL_NV_texture_expand_normal */ \
    \
    /* GL_NV_texture_multisample */ \
    GL_FUNCTION( void, glTexImage2DMultisampleCoverageNV, ( GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLboolean ) ) \
    GL_FUNCTION( void, glTexImage3DMultisampleCoverageNV, ( GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean ) ) \
    GL_FUNCTION( void, glTextureImage2DMultisampleNV, ( GLuint, GLenum, GLsizei, GLint, GLsizei, GLsizei, GLboolean ) ) \
    GL_FUNCTION( void, glTextureImage3DMultisampleNV, ( GLuint, GLenum, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean ) ) \
    GL_FUNCTION( void, glTextureImage2DMultisampleCoverageNV, ( GLuint, GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLboolean ) ) \
    GL_FUNCTION( void, glTextureImage3DMultisampleCoverageNV, ( GLuint, GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean ) ) \
    \
    /* GL_NV_texture_rectangle */ \
    \
    /* GL_NV_texture_shader */ \
    \
    /* GL_NV_texture_shader2 */ \
    \
    /* GL_NV_texture_shader3 */ \
    \
    /* GL_NV_transform_feedback */ \
    GL_FUNCTION( void, glBeginTransformFeedbackNV, ( GLenum ) ) \
    GL_FUNCTION( void, glEndTransformFeedbackNV, ( ) ) \
    GL_FUNCTION( void, glTransformFeedbackAttribsNV, ( GLuint, const GLint *, GLenum ) ) \
    GL_FUNCTION( void, glBindBufferRangeNV, ( GLenum, GLuint, GLuint, GLintptr, GLsizeiptr ) ) \
    GL_FUNCTION( void, glBindBufferOffsetNV, ( GLenum, GLuint, GLuint, GLintptr ) ) \
    GL_FUNCTION( void, glBindBufferBaseNV, ( GLenum, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glTransformFeedbackVaryingsNV, ( GLuint, GLsizei, const GLint *, GLenum ) ) \
    GL_FUNCTION( void, glActiveVaryingNV, ( GLuint, const GLchar * ) ) \
    GL_FUNCTION( GLint, glGetVaryingLocationNV, ( GLuint, const GLchar * ) ) \
    GL_FUNCTION( void, glGetActiveVaryingNV, ( GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar * ) ) \
    GL_FUNCTION( void, glGetTransformFeedbackVaryingNV, ( GLuint, GLuint, GLint * ) ) \
    GL_FUNCTION( void, glTransformFeedbackStreamAttribsNV, ( GLsizei, const GLint *, GLsizei, const GLint *, GLenum ) ) \
    \
    /* GL_NV_transform_feedback2 */ \
    GL_FUNCTION( void, glBindTransformFeedbackNV, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDeleteTransformFeedbacksNV, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glGenTransformFeedbacksNV, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( GLboolean, glIsTransformFeedbackNV, ( GLuint ) ) \
    GL_FUNCTION( void, glPauseTransformFeedbackNV, ( ) ) \
    GL_FUNCTION( void, glResumeTransformFeedbackNV, ( ) ) \
    GL_FUNCTION( void, glDrawTransformFeedbackNV, ( GLenum, GLuint ) ) \
    \
    /* GL_NV_vdpau_interop */ \
    GL_FUNCTION( void, glVDPAUInitNV, ( const GLvoid *, const GLvoid * ) ) \
    GL_FUNCTION( void, glVDPAUFiniNV, ( ) ) \
    GL_FUNCTION( GLvdpauSurfaceNV, glVDPAURegisterVideoSurfaceNV, ( const GLvoid *, GLenum, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( GLvdpauSurfaceNV, glVDPAURegisterOutputSurfaceNV, ( const GLvoid *, GLenum, GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glVDPAUIsSurfaceNV, ( GLvdpauSurfaceNV ) ) \
    GL_FUNCTION( void, glVDPAUUnregisterSurfaceNV, ( GLvdpauSurfaceNV ) ) \
    GL_FUNCTION( void, glVDPAUGetSurfaceivNV, ( GLvdpauSurfaceNV, GLenum, GLsizei, GLsizei *, GLint * ) ) \
    GL_FUNCTION( void, glVDPAUSurfaceAccessNV, ( GLvdpauSurfaceNV, GLenum ) ) \
    GL_FUNCTION( void, glVDPAUMapSurfacesNV, ( GLsizei, const GLvdpauSurfaceNV * ) ) \
    GL_FUNCTION( void, glVDPAUUnmapSurfacesNV, ( GLsizei, const GLvdpauSurfaceNV * ) ) \
    \
    /* GL_NV_vertex_array_range */ \
    GL_FUNCTION( void, glFlushVertexArrayRangeNV, ( ) ) \
    GL_FUNCTION( void, glVertexArrayRangeNV, ( GLsizei, const GLvoid * ) ) \
    \
    /* GL_NV_vertex_array_range2 */ \
    \
    /* GL_NV_vertex_attrib_integer_64bit */ \
    GL_FUNCTION( void, glVertexAttribL1i64NV, ( GLuint, GLint64EXT ) ) \
    GL_FUNCTION( void, glVertexAttribL2i64NV, ( GLuint, GLint64EXT, GLint64EXT ) ) \
    GL_FUNCTION( void, glVertexAttribL3i64NV, ( GLuint, GLint64EXT, GLint64EXT, GLint64EXT ) ) \
    GL_FUNCTION( void, glVertexAttribL4i64NV, ( GLuint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT ) ) \
    GL_FUNCTION( void, glVertexAttribL1i64vNV, ( GLuint, const GLint64EXT * ) ) \
    GL_FUNCTION( void, glVertexAttribL2i64vNV, ( GLuint, const GLint64EXT * ) ) \
    GL_FUNCTION( void, glVertexAttribL3i64vNV, ( GLuint, const GLint64EXT * ) ) \
    GL_FUNCTION( void, glVertexAttribL4i64vNV, ( GLuint, const GLint64EXT * ) ) \
    GL_FUNCTION( void, glVertexAttribL1ui64NV, ( GLuint, GLuint64EXT ) ) \
    GL_FUNCTION( void, glVertexAttribL2ui64NV, ( GLuint, GLuint64EXT, GLuint64EXT ) ) \
    GL_FUNCTION( void, glVertexAttribL3ui64NV, ( GLuint, GLuint64EXT, GLuint64EXT, GLuint64EXT ) ) \
    GL_FUNCTION( void, glVertexAttribL4ui64NV, ( GLuint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT ) ) \
    GL_FUNCTION( void, glVertexAttribL1ui64vNV, ( GLuint, const GLuint64EXT * ) ) \
    GL_FUNCTION( void, glVertexAttribL2ui64vNV, ( GLuint, const GLuint64EXT * ) ) \
    GL_FUNCTION( void, glVertexAttribL3ui64vNV, ( GLuint, const GLuint64EXT * ) ) \
    GL_FUNCTION( void, glVertexAttribL4ui64vNV, ( GLuint, const GLuint64EXT * ) ) \
    GL_FUNCTION( void, glGetVertexAttribLi64vNV, ( GLuint, GLenum, GLint64EXT * ) ) \
    GL_FUNCTION( void, glGetVertexAttribLui64vNV, ( GLuint, GLenum, GLuint64EXT * ) ) \
    GL_FUNCTION( void, glVertexAttribLFormatNV, ( GLuint, GLint, GLenum, GLsizei ) ) \
    \
    /* GL_NV_vertex_buffer_unified_memory */ \
    GL_FUNCTION( void, glBufferAddressRangeNV, ( GLenum, GLuint, GLuint64EXT, GLsizeiptr ) ) \
    GL_FUNCTION( void, glVertexFormatNV, ( GLint, GLenum, GLsizei ) ) \
    GL_FUNCTION( void, glNormalFormatNV, ( GLenum, GLsizei ) ) \
    GL_FUNCTION( void, glColorFormatNV, ( GLint, GLenum, GLsizei ) ) \
    GL_FUNCTION( void, glIndexFormatNV, ( GLenum, GLsizei ) ) \
    GL_FUNCTION( void, glTexCoordFormatNV, ( GLint, GLenum, GLsizei ) ) \
    GL_FUNCTION( void, glEdgeFlagFormatNV, ( GLsizei ) ) \
    GL_FUNCTION( void, glSecondaryColorFormatNV, ( GLint, GLenum, GLsizei ) ) \
    GL_FUNCTION( void, glFogCoordFormatNV, ( GLenum, GLsizei ) ) \
    GL_FUNCTION( void, glVertexAttribFormatNV, ( GLuint, GLint, GLenum, GLboolean, GLsizei ) ) \
    GL_FUNCTION( void, glVertexAttribIFormatNV, ( GLuint, GLint, GLenum, GLsizei ) ) \
    GL_FUNCTION( void, glGetIntegerui64i_vNV, ( GLenum, GLuint, GLuint64EXT * ) ) \
    \
    /* GL_NV_vertex_program */ \
    GL_FUNCTION( GLboolean, glAreProgramsResidentNV, ( GLsizei, const GLuint *, GLboolean * ) ) \
    GL_FUNCTION( void, glBindProgramNV, ( GLenum, GLuint ) ) \
    GL_FUNCTION( void, glDeleteProgramsNV, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glExecuteProgramNV, ( GLenum, GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glGenProgramsNV, ( GLsizei, GLuint * ) ) \
    GL_FUNCTION( void, glGetProgramParameterdvNV, ( GLenum, GLuint, GLenum, GLdouble * ) ) \
    GL_FUNCTION( void, glGetProgramParameterfvNV, ( GLenum, GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetProgramivNV, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetProgramStringNV, ( GLuint, GLenum, GLubyte * ) ) \
    GL_FUNCTION( void, glGetTrackMatrixivNV, ( GLenum, GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetVertexAttribdvNV, ( GLuint, GLenum, GLdouble * ) ) \
    GL_FUNCTION( void, glGetVertexAttribfvNV, ( GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetVertexAttribivNV, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetVertexAttribPointervNV, ( GLuint, GLenum, GLvoid ** ) ) \
    GL_FUNCTION( GLboolean, glIsProgramNV, ( GLuint ) ) \
    GL_FUNCTION( void, glLoadProgramNV, ( GLenum, GLuint, GLsizei, const GLubyte * ) ) \
    GL_FUNCTION( void, glProgramParameter4dNV, ( GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glProgramParameter4dvNV, ( GLenum, GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramParameter4fNV, ( GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glProgramParameter4fvNV, ( GLenum, GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glProgramParameters4dvNV, ( GLenum, GLuint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glProgramParameters4fvNV, ( GLenum, GLuint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glRequestResidentProgramsNV, ( GLsizei, const GLuint * ) ) \
    GL_FUNCTION( void, glTrackMatrixNV, ( GLenum, GLuint, GLenum, GLenum ) ) \
    GL_FUNCTION( void, glVertexAttribPointerNV, ( GLuint, GLint, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glVertexAttrib1dNV, ( GLuint, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttrib1dvNV, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttrib1fNV, ( GLuint, GLfloat ) ) \
    GL_FUNCTION( void, glVertexAttrib1fvNV, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttrib1sNV, ( GLuint, GLshort ) ) \
    GL_FUNCTION( void, glVertexAttrib1svNV, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib2dNV, ( GLuint, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttrib2dvNV, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttrib2fNV, ( GLuint, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertexAttrib2fvNV, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttrib2sNV, ( GLuint, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertexAttrib2svNV, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib3dNV, ( GLuint, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttrib3dvNV, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttrib3fNV, ( GLuint, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertexAttrib3fvNV, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttrib3sNV, ( GLuint, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertexAttrib3svNV, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib4dNV, ( GLuint, GLdouble, GLdouble, GLdouble, GLdouble ) ) \
    GL_FUNCTION( void, glVertexAttrib4dvNV, ( GLuint, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttrib4fNV, ( GLuint, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glVertexAttrib4fvNV, ( GLuint, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttrib4sNV, ( GLuint, GLshort, GLshort, GLshort, GLshort ) ) \
    GL_FUNCTION( void, glVertexAttrib4svNV, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttrib4ubNV, ( GLuint, GLubyte, GLubyte, GLubyte, GLubyte ) ) \
    GL_FUNCTION( void, glVertexAttrib4ubvNV, ( GLuint, const GLubyte * ) ) \
    GL_FUNCTION( void, glVertexAttribs1dvNV, ( GLuint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttribs1fvNV, ( GLuint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttribs1svNV, ( GLuint, GLsizei, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttribs2dvNV, ( GLuint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttribs2fvNV, ( GLuint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttribs2svNV, ( GLuint, GLsizei, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttribs3dvNV, ( GLuint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttribs3fvNV, ( GLuint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttribs3svNV, ( GLuint, GLsizei, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttribs4dvNV, ( GLuint, GLsizei, const GLdouble * ) ) \
    GL_FUNCTION( void, glVertexAttribs4fvNV, ( GLuint, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glVertexAttribs4svNV, ( GLuint, GLsizei, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttribs4ubvNV, ( GLuint, GLsizei, const GLubyte * ) ) \
    \
    /* GL_NV_vertex_program1_1 */ \
    \
    /* GL_NV_vertex_program2 */ \
    \
    /* GL_NV_vertex_program2_option */ \
    \
    /* GL_NV_vertex_program3 */ \
    \
    /* GL_NV_vertex_program4 */ \
    GL_FUNCTION( void, glVertexAttribI1iEXT, ( GLuint, GLint ) ) \
    GL_FUNCTION( void, glVertexAttribI2iEXT, ( GLuint, GLint, GLint ) ) \
    GL_FUNCTION( void, glVertexAttribI3iEXT, ( GLuint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glVertexAttribI4iEXT, ( GLuint, GLint, GLint, GLint, GLint ) ) \
    GL_FUNCTION( void, glVertexAttribI1uiEXT, ( GLuint, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribI2uiEXT, ( GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribI3uiEXT, ( GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribI4uiEXT, ( GLuint, GLuint, GLuint, GLuint, GLuint ) ) \
    GL_FUNCTION( void, glVertexAttribI1ivEXT, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glVertexAttribI2ivEXT, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glVertexAttribI3ivEXT, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glVertexAttribI4ivEXT, ( GLuint, const GLint * ) ) \
    GL_FUNCTION( void, glVertexAttribI1uivEXT, ( GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttribI2uivEXT, ( GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttribI3uivEXT, ( GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttribI4uivEXT, ( GLuint, const GLuint * ) ) \
    GL_FUNCTION( void, glVertexAttribI4bvEXT, ( GLuint, const GLbyte * ) ) \
    GL_FUNCTION( void, glVertexAttribI4svEXT, ( GLuint, const GLshort * ) ) \
    GL_FUNCTION( void, glVertexAttribI4ubvEXT, ( GLuint, const GLubyte * ) ) \
    GL_FUNCTION( void, glVertexAttribI4usvEXT, ( GLuint, const GLushort * ) ) \
    GL_FUNCTION( void, glVertexAttribIPointerEXT, ( GLuint, GLint, GLenum, GLsizei, const GLvoid * ) ) \
    GL_FUNCTION( void, glGetVertexAttribIivEXT, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetVertexAttribIuivEXT, ( GLuint, GLenum, GLuint * ) ) \
    \
    /* GL_NV_video_capture */ \
    GL_FUNCTION( void, glBeginVideoCaptureNV, ( GLuint ) ) \
    GL_FUNCTION( void, glBindVideoCaptureStreamBufferNV, ( GLuint, GLuint, GLenum, GLintptrARB ) ) \
    GL_FUNCTION( void, glBindVideoCaptureStreamTextureNV, ( GLuint, GLuint, GLenum, GLenum, GLuint ) ) \
    GL_FUNCTION( void, glEndVideoCaptureNV, ( GLuint ) ) \
    GL_FUNCTION( void, glGetVideoCaptureivNV, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetVideoCaptureStreamivNV, ( GLuint, GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetVideoCaptureStreamfvNV, ( GLuint, GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetVideoCaptureStreamdvNV, ( GLuint, GLuint, GLenum, GLdouble * ) ) \
    GL_FUNCTION( GLenum, glVideoCaptureNV, ( GLuint, GLuint *, GLuint64EXT * ) ) \
    GL_FUNCTION( void, glVideoCaptureStreamParameterivNV, ( GLuint, GLuint, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glVideoCaptureStreamParameterfvNV, ( GLuint, GLuint, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glVideoCaptureStreamParameterdvNV, ( GLuint, GLuint, GLenum, const GLdouble * ) ) \
    \
    /* GL_OML_interlace */ \
    \
    /* GL_OML_resample */ \
    \
    /* GL_OML_subsample */ \
    \
    /* GL_PGI_misc_hints */ \
    GL_FUNCTION( void, glHintPGI, ( GLenum, GLint ) ) \
    \
    /* GL_PGI_vertex_hints */ \
    \
    /* GL_REND_screen_coordinates */ \
    \
    /* GL_S3_s3tc */ \
    \
    /* GL_SGIS_detail_texture */ \
    GL_FUNCTION( void, glDetailTexFuncSGIS, ( GLenum, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glGetDetailTexFuncSGIS, ( GLenum, GLfloat * ) ) \
    \
    /* GL_SGIS_fog_function */ \
    GL_FUNCTION( void, glFogFuncSGIS, ( GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glGetFogFuncSGIS, ( GLfloat * ) ) \
    \
    /* GL_SGIS_generate_mipmap */ \
    \
    /* GL_SGIS_multisample */ \
    GL_FUNCTION( void, glSampleMaskSGIS, ( GLclampf, GLboolean ) ) \
    GL_FUNCTION( void, glSamplePatternSGIS, ( GLenum ) ) \
    \
    /* GL_SGIS_pixel_texture */ \
    GL_FUNCTION( void, glPixelTexGenParameteriSGIS, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glPixelTexGenParameterivSGIS, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glPixelTexGenParameterfSGIS, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glPixelTexGenParameterfvSGIS, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glGetPixelTexGenParameterivSGIS, ( GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetPixelTexGenParameterfvSGIS, ( GLenum, GLfloat * ) ) \
    \
    /* GL_SGIS_point_line_texgen */ \
    \
    /* GL_SGIS_point_parameters */ \
    GL_FUNCTION( void, glPointParameterfSGIS, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glPointParameterfvSGIS, ( GLenum, const GLfloat * ) ) \
    \
    /* GL_SGIS_sharpen_texture */ \
    GL_FUNCTION( void, glSharpenTexFuncSGIS, ( GLenum, GLsizei, const GLfloat * ) ) \
    GL_FUNCTION( void, glGetSharpenTexFuncSGIS, ( GLenum, GLfloat * ) ) \
    \
    /* GL_SGIS_texture4D */ \
    GL_FUNCTION( void, glTexImage4DSGIS, ( GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glTexSubImage4DSGIS, ( GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    \
    /* GL_SGIS_texture_border_clamp */ \
    \
    /* GL_SGIS_texture_color_mask */ \
    GL_FUNCTION( void, glTextureColorMaskSGIS, ( GLboolean, GLboolean, GLboolean, GLboolean ) ) \
    \
    /* GL_SGIS_texture_edge_clamp */ \
    \
    /* GL_SGIS_texture_filter4 */ \
    GL_FUNCTION( void, glGetTexFilterFuncSGIS, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glTexFilterFuncSGIS, ( GLenum, GLenum, GLsizei, const GLfloat * ) ) \
    \
    /* GL_SGIS_texture_lod */ \
    \
    /* GL_SGIS_texture_select */ \
    \
    /* GL_SGIX_async */ \
    GL_FUNCTION( void, glAsyncMarkerSGIX, ( GLuint ) ) \
    GL_FUNCTION( GLint, glFinishAsyncSGIX, ( GLuint * ) ) \
    GL_FUNCTION( GLint, glPollAsyncSGIX, ( GLuint * ) ) \
    GL_FUNCTION( GLuint, glGenAsyncMarkersSGIX, ( GLsizei ) ) \
    GL_FUNCTION( void, glDeleteAsyncMarkersSGIX, ( GLuint, GLsizei ) ) \
    GL_FUNCTION( GLboolean, glIsAsyncMarkerSGIX, ( GLuint ) ) \
    \
    /* GL_SGIX_async_histogram */ \
    \
    /* GL_SGIX_async_pixel */ \
    \
    /* GL_SGIX_blend_alpha_minmax */ \
    \
    /* GL_SGIX_calligraphic_fragment */ \
    \
    /* GL_SGIX_clipmap */ \
    \
    /* GL_SGIX_convolution_accuracy */ \
    \
    /* GL_SGIX_depth_pass_instrument */ \
    \
    /* GL_SGIX_depth_texture */ \
    \
    /* GL_SGIX_flush_raster */ \
    GL_FUNCTION( void, glFlushRasterSGIX, ( ) ) \
    \
    /* GL_SGIX_fog_offset */ \
    \
    /* GL_SGIX_fragment_lighting */ \
    GL_FUNCTION( void, glFragmentColorMaterialSGIX, ( GLenum, GLenum ) ) \
    GL_FUNCTION( void, glFragmentLightfSGIX, ( GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glFragmentLightfvSGIX, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glFragmentLightiSGIX, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glFragmentLightivSGIX, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glFragmentLightModelfSGIX, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glFragmentLightModelfvSGIX, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glFragmentLightModeliSGIX, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glFragmentLightModelivSGIX, ( GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glFragmentMaterialfSGIX, ( GLenum, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glFragmentMaterialfvSGIX, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glFragmentMaterialiSGIX, ( GLenum, GLenum, GLint ) ) \
    GL_FUNCTION( void, glFragmentMaterialivSGIX, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glGetFragmentLightfvSGIX, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetFragmentLightivSGIX, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glGetFragmentMaterialfvSGIX, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetFragmentMaterialivSGIX, ( GLenum, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glLightEnviSGIX, ( GLenum, GLint ) ) \
    \
    /* GL_SGIX_framezoom */ \
    GL_FUNCTION( void, glFrameZoomSGIX, ( GLint ) ) \
    \
    /* GL_SGIX_igloo_interface */ \
    GL_FUNCTION( void, glIglooInterfaceSGIX, ( GLenum, const GLvoid * ) ) \
    \
    /* GL_SGIX_instruments */ \
    GL_FUNCTION( GLint, glGetInstrumentsSGIX, ( ) ) \
    GL_FUNCTION( void, glInstrumentsBufferSGIX, ( GLsizei, GLint * ) ) \
    GL_FUNCTION( GLint, glPollInstrumentsSGIX, ( GLint * ) ) \
    GL_FUNCTION( void, glReadInstrumentsSGIX, ( GLint ) ) \
    GL_FUNCTION( void, glStartInstrumentsSGIX, ( ) ) \
    GL_FUNCTION( void, glStopInstrumentsSGIX, ( GLint ) ) \
    \
    /* GL_SGIX_interlace */ \
    \
    /* GL_SGIX_ir_instrument1 */ \
    \
    /* GL_SGIX_list_priority */ \
    GL_FUNCTION( void, glGetListParameterfvSGIX, ( GLuint, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetListParameterivSGIX, ( GLuint, GLenum, GLint * ) ) \
    GL_FUNCTION( void, glListParameterfSGIX, ( GLuint, GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glListParameterfvSGIX, ( GLuint, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glListParameteriSGIX, ( GLuint, GLenum, GLint ) ) \
    GL_FUNCTION( void, glListParameterivSGIX, ( GLuint, GLenum, const GLint * ) ) \
    \
    /* GL_SGIX_pixel_texture */ \
    GL_FUNCTION( void, glPixelTexGenSGIX, ( GLenum ) ) \
    \
    /* GL_SGIX_pixel_tiles */ \
    \
    /* GL_SGIX_polynomial_ffd */ \
    GL_FUNCTION( void, glDeformationMap3dSGIX, ( GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble * ) ) \
    GL_FUNCTION( void, glDeformationMap3fSGIX, ( GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat * ) ) \
    GL_FUNCTION( void, glDeformSGIX, ( GLbitfield ) ) \
    GL_FUNCTION( void, glLoadIdentityDeformationMapSGIX, ( GLbitfield ) ) \
    \
    /* GL_SGIX_reference_plane */ \
    GL_FUNCTION( void, glReferencePlaneSGIX, ( const GLdouble * ) ) \
    \
    /* GL_SGIX_resample */ \
    \
    /* GL_SGIX_scalebias_hint */ \
    \
    /* GL_SGIX_shadow */ \
    \
    /* GL_SGIX_shadow_ambient */ \
    \
    /* GL_SGIX_sprite */ \
    GL_FUNCTION( void, glSpriteParameterfSGIX, ( GLenum, GLfloat ) ) \
    GL_FUNCTION( void, glSpriteParameterfvSGIX, ( GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glSpriteParameteriSGIX, ( GLenum, GLint ) ) \
    GL_FUNCTION( void, glSpriteParameterivSGIX, ( GLenum, const GLint * ) ) \
    \
    /* GL_SGIX_subsample */ \
    \
    /* GL_SGIX_tag_sample_buffer */ \
    GL_FUNCTION( void, glTagSampleBufferSGIX, ( ) ) \
    \
    /* GL_SGIX_texture_add_env */ \
    \
    /* GL_SGIX_texture_coordinate_clamp */ \
    \
    /* GL_SGIX_texture_lod_bias */ \
    \
    /* GL_SGIX_texture_multi_buffer */ \
    \
    /* GL_SGIX_texture_scale_bias */ \
    \
    /* GL_SGIX_vertex_preclip */ \
    \
    /* GL_SGIX_ycrcb */ \
    \
    /* GL_SGIX_ycrcb_subsample */ \
    \
    /* GL_SGIX_ycrcba */ \
    \
    /* GL_SGI_color_matrix */ \
    \
    /* GL_SGI_color_table */ \
    GL_FUNCTION( void, glColorTableSGI, ( GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid * ) ) \
    GL_FUNCTION( void, glColorTableParameterfvSGI, ( GLenum, GLenum, const GLfloat * ) ) \
    GL_FUNCTION( void, glColorTableParameterivSGI, ( GLenum, GLenum, const GLint * ) ) \
    GL_FUNCTION( void, glCopyColorTableSGI, ( GLenum, GLenum, GLint, GLint, GLsizei ) ) \
    GL_FUNCTION( void, glGetColorTableSGI, ( GLenum, GLenum, GLenum, GLvoid * ) ) \
    GL_FUNCTION( void, glGetColorTableParameterfvSGI, ( GLenum, GLenum, GLfloat * ) ) \
    GL_FUNCTION( void, glGetColorTableParameterivSGI, ( GLenum, GLenum, GLint * ) ) \
    \
    /* GL_SGI_texture_color_table */ \
    \
    /* GL_SUNX_constant_data */ \
    GL_FUNCTION( void, glFinishTextureSUNX, ( ) ) \
    \
    /* GL_SUN_convolution_border_modes */ \
    \
    /* GL_SUN_global_alpha */ \
    GL_FUNCTION( void, glGlobalAlphaFactorbSUN, ( GLbyte ) ) \
    GL_FUNCTION( void, glGlobalAlphaFactorsSUN, ( GLshort ) ) \
    GL_FUNCTION( void, glGlobalAlphaFactoriSUN, ( GLint ) ) \
    GL_FUNCTION( void, glGlobalAlphaFactorfSUN, ( GLfloat ) ) \
    GL_FUNCTION( void, glGlobalAlphaFactordSUN, ( GLdouble ) ) \
    GL_FUNCTION( void, glGlobalAlphaFactorubSUN, ( GLubyte ) ) \
    GL_FUNCTION( void, glGlobalAlphaFactorusSUN, ( GLushort ) ) \
    GL_FUNCTION( void, glGlobalAlphaFactoruiSUN, ( GLuint ) ) \
    \
    /* GL_SUN_mesh_array */ \
    GL_FUNCTION( void, glDrawMeshArraysSUN, ( GLenum, GLint, GLsizei, GLsizei ) ) \
    \
    /* GL_SUN_slice_accum */ \
    \
    /* GL_SUN_triangle_list */ \
    GL_FUNCTION( void, glReplacementCodeuiSUN, ( GLuint ) ) \
    GL_FUNCTION( void, glReplacementCodeusSUN, ( GLushort ) ) \
    GL_FUNCTION( void, glReplacementCodeubSUN, ( GLubyte ) ) \
    GL_FUNCTION( void, glReplacementCodeuivSUN, ( const GLuint * ) ) \
    GL_FUNCTION( void, glReplacementCodeusvSUN, ( const GLushort * ) ) \
    GL_FUNCTION( void, glReplacementCodeubvSUN, ( const GLubyte * ) ) \
    GL_FUNCTION( void, glReplacementCodePointerSUN, ( GLenum, GLsizei, const GLvoid ** ) ) \
    \
    /* GL_SUN_vertex */ \
    GL_FUNCTION( void, glColor4ubVertex2fSUN, ( GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glColor4ubVertex2fvSUN, ( const GLubyte *, const GLfloat * ) ) \
    GL_FUNCTION( void, glColor4ubVertex3fSUN, ( GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glColor4ubVertex3fvSUN, ( const GLubyte *, const GLfloat * ) ) \
    GL_FUNCTION( void, glColor3fVertex3fSUN, ( GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glColor3fVertex3fvSUN, ( const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glNormal3fVertex3fSUN, ( GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glNormal3fVertex3fvSUN, ( const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glColor4fNormal3fVertex3fSUN, ( GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glColor4fNormal3fVertex3fvSUN, ( const GLfloat *, const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord2fVertex3fSUN, ( GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glTexCoord2fVertex3fvSUN, ( const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord4fVertex4fSUN, ( GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glTexCoord4fVertex4fvSUN, ( const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord2fColor4ubVertex3fSUN, ( GLfloat, GLfloat, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glTexCoord2fColor4ubVertex3fvSUN, ( const GLfloat *, const GLubyte *, const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord2fColor3fVertex3fSUN, ( GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glTexCoord2fColor3fVertex3fvSUN, ( const GLfloat *, const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord2fNormal3fVertex3fSUN, ( GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glTexCoord2fNormal3fVertex3fvSUN, ( const GLfloat *, const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord2fColor4fNormal3fVertex3fSUN, ( GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glTexCoord2fColor4fNormal3fVertex3fvSUN, ( const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glTexCoord4fColor4fNormal3fVertex4fSUN, ( GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glTexCoord4fColor4fNormal3fVertex4fvSUN, ( const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glReplacementCodeuiVertex3fSUN, ( GLuint, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glReplacementCodeuiVertex3fvSUN, ( const GLuint *, const GLfloat * ) ) \
    GL_FUNCTION( void, glReplacementCodeuiColor4ubVertex3fSUN, ( GLuint, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glReplacementCodeuiColor4ubVertex3fvSUN, ( const GLuint *, const GLubyte *, const GLfloat * ) ) \
    GL_FUNCTION( void, glReplacementCodeuiColor3fVertex3fSUN, ( GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glReplacementCodeuiColor3fVertex3fvSUN, ( const GLuint *, const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glReplacementCodeuiNormal3fVertex3fSUN, ( GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glReplacementCodeuiNormal3fVertex3fvSUN, ( const GLuint *, const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glReplacementCodeuiColor4fNormal3fVertex3fSUN, ( GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glReplacementCodeuiColor4fNormal3fVertex3fvSUN, ( const GLuint *, const GLfloat *, const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glReplacementCodeuiTexCoord2fVertex3fSUN, ( GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glReplacementCodeuiTexCoord2fVertex3fvSUN, ( const GLuint *, const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN, ( GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN, ( const GLuint *, const GLfloat *, const GLfloat *, const GLfloat * ) ) \
    GL_FUNCTION( void, glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN, ( GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat ) ) \
    GL_FUNCTION( void, glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN, ( const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat * ) ) \
    \
    /* GL_WIN_phong_shading */ \
    \
    /* GL_WIN_specular_fog */ \

namespace dp {
    typedef void ( * GLDEBUGPROC )(
        GLenum
        , GLenum
        , GLuint
        , GLenum
        , GLsizei
        , const GLchar *
        , const void *
    );
    typedef void ( * GLDEBUGPROCARB )(
        GLenum
        , GLenum
        , GLuint
        , GLenum
        , GLsizei
        , const GLchar *
        , const void *
    );
    typedef void ( * GLDEBUGPROCAMD )(
        GLuint
        , GLenum
        , GLenum
        , GLsizei
        , const GLchar *
        , void *
    );

#if defined LINUX   // OS
#   define DPSTDCALL
#elif defined WINDOWS   // OS
#   define DPSTDCALL __stdcall
#else   // OS
#   error 未対応のOS
#endif  // OS

#define GL_EXTERN_FUNCTION_POINTER( _returnType, _name, _args ) \
    DPEXPORT extern _returnType ( DPSTDCALL * _name )_args; \

#define GL_FUNCTION GL_EXTERN_FUNCTION_POINTER
    GL_FUNCTIONS
#undef  GL_FUNCTION
}

#endif  // DP_OPENGL_FUNCTIONS_H
