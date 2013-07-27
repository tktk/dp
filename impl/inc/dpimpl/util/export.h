#ifndef DPIMPL_UTIL_EXPORT_H
#define DPIMPL_UTIL_EXPORT_H

#if defined LINUX   // OS
#   define DPEXPORT __attribute__( ( visibility( "default" ) ) )
#elif defined WINDOWS   // OS
#   define DPEXPORT __declspec( dllexport )
#else   // OS
#   error 未対応のOS
#endif  // OS

#endif  // DPIMPL_UTIL_EXPORT_H
