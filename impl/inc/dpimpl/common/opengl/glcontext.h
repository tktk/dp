#ifndef DPIMPL_COMMON_OPENGL_GLCONTEXT_H
#define DPIMPL_COMMON_OPENGL_GLCONTEXT_H

#if defined LINUX   // OS
#include "dpimpl/linux/opengl/glcontext.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/opengl/glcontext.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#endif  // DPIMPL_COMMON_OPENGL_GLCONTEXT_H
