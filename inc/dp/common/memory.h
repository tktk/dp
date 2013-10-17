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
    typename Unique< typename std::remove_pointer< T >::type >::type unique(
        T   _ptr
    )
    {
        return typename Unique< typename std::remove_pointer< T >::type >::type(
            _ptr
        );
    }

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

    template< typename T >
    std::weak_ptr< typename T::element_type > weak(
        T   _shared
    )
    {
        return std::weak_ptr< typename T::element_type >(
            _shared
        );
    }
}

#endif  // DP_COMMON_MEMORY_H
