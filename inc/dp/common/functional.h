#ifndef DP_COMMON_FUNCTIONAL_H
#define DP_COMMON_FUNCTIONAL_H

#include "dp/common/primitives.h"

template< typename T >
void dpFree(
    const T &
);

template< typename T >
dp::Bool dpLess(
    const T &
    , const T &
);

namespace dp {
    template< typename T >
    struct Free
    {
        void operator()(
            const T * _OBJ
        ) const
        {
            ::dpFree( *_OBJ );
        }
    };

    template< typename T >
    struct Less
    {
        Bool operator()(
            const T &   _KEY1
            , const T & _KEY2
        ) const
        {
            return ::dpLess(
                *_KEY1
                , *_KEY2
            );
        }
    };
}

#endif  // DP_COMMON_FUNCTIONAL_H
