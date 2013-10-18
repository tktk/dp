#ifndef DPIMPL_COMMON_FILE_FILEW_H
#define DPIMPL_COMMON_FILE_FILEW_H

#if defined LINUX   // OS
#include "dpimpl/linux/file/filew.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/file/filew.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#endif  // DPIMPL_COMMON_FILE_FILEW_H
