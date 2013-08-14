#ifndef DPIMPL_COMMON_DISPLAY_DISPLAYMODEKEY_H
#define DPIMPL_COMMON_DISPLAY_DISPLAYMODEKEY_H

#if defined LINUX   // OS
#include "dpimpl/linux/display/displaymodekey.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/display/displaymodekey.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#endif  // DPIMPL_COMMON_DISPLAY_DISPLAYMODEKEY_H
