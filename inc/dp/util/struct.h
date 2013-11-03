#ifndef DP_UTIL_STRUCT_H
#define DP_UTIL_STRUCT_H

#include "dp/common/primitives.h"
#include "dp/util/import.h"

#define DPSTRUCT(    \
    _namespace  \
    , _struct   \
)   \
    namespace _namespace {  \
        struct _struct; \
    }   \
    template<>  \
    DPEXPORT void free(  \
        const _namespace::_struct & \
    );   \

#define DPKEYSTRUCT( \
    _namespace  \
    , _struct   \
)   \
    DPSTRUCT(   \
        _namespace  \
        , _struct   \
    )   \
    template<>  \
    DPEXPORT dp::Bool less(  \
        const _namespace::_struct & \
        , const _namespace::_struct &   \
    );  \

#endif  // DP_UTIL_STRUCT_H
