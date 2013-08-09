#ifndef DPIMPL_COMMON_DISPLAY_DISPLAYKEY_H
#define DPIMPL_COMMON_DISPLAY_DISPLAYKEY_H

#if defined LINUX   // OS
#include "dpimpl/linux/display/displaykey.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/display/displaykey.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#endif  // DPIMPL_COMMON_DISPLAY_DISPLAYKEY_H
