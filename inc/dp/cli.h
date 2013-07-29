#ifndef DP_CLI_H
#define DP_CLI_H

#if defined LINUX   // OS
#include "dp/linux/cli.h"
#elif defined WINDOWS   // OS
#include "dp/windows/cli.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#endif  // DP_CLI_H
