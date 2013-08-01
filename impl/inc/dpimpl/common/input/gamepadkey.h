#ifndef DPIMPL_COMMON_INPUT_GAMEPADKEY_H
#define DPIMPL_COMMON_INPUT_GAMEPADKEY_H

#if defined LINUX   // OS
#include "dpimpl/linux/input/gamepadkey.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/input/gamepadkey.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#endif  // DPIMPL_COMMON_INPUT_GAMEPADKEY_H
