#ifndef DP_COMMON_MEMORY_H
#define DP_COMMON_MEMORY_H

#include "dp/common/functional.h"

#include <memory>
#include <type_traits>

namespace dp {
    template< typename T >
    struct Unique
    {
        typedef std::unique_ptr<
            T
            , Free< T >
        > type;
    };

    template< typename T >
    std::shared_ptr< typename std::remove_pointer< T >::type > shared(
        T   _ptr
    )
    {
        return std::shared_ptr< typename std::remove_pointer< T >::type >(
            _ptr
            , Free< typename std::remove_pointer< T >::type >()
        );
    }
}

#endif  // DP_COMMON_MEMORY_H
