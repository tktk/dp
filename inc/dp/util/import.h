#ifndef DP_UTIL_IMPORT_H
#define DP_UTIL_IMPORT_H

#ifndef DPEXPORT
#   if defined LINUX   // OS
#       define DPEXPORT
#   elif defined WINDOWS   // OS
#       define DPEXPORT __declspec( dllimport )
#   else   // OS
#       error 未対応のOS
#   endif  // OS
#endif  // DPEXPORT

#endif  // DP_UTIL_IMPORT_H
