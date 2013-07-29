#ifndef DPIMPL_LINUX_UTIL_EXPORT_H
#define DPIMPL_LINUX_UTIL_EXPORT_H

#define DPCONSTRUCTOR extern "C" __attribute__( ( constructor ) )
#define DPDESTRUCTOR extern "C" __attribute__( ( destructor ) )

#endif  // DPIMPL_LINUX_UTIL_EXPORT_H
