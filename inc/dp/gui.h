#ifndef DP_GUI_H
#define DP_GUI_H

#if defined LINUX   // OS
#include "dp/linux/gui.h"
#elif defined WINDOWS   // OS
#include "dp/windows/gui.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#endif  // DP_GUI_H
