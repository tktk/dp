#ifndef DP_WINDOW_WINDOWFLAGS_H
#define DP_WINDOW_WINDOWFLAGS_H

#include "dp/common/primitives.h"

namespace dp {
    enum WindowFlags
    {
        PLAIN = 0x0,

        UNRESIZABLE = 0x1,
        ALWAYS_ON_TOP = 0x2,
    };

    inline WindowFlags operator|(
        const WindowFlags &     _FLAGS1
        , const WindowFlags &   _FLAGS2
    )
    {
        return static_cast< WindowFlags >(
            static_cast< dp::Int >( _FLAGS1 ) |
            static_cast< dp::Int >( _FLAGS2 )
        );
    }
}

#endif  // DP_WINDOW_WINDOWFLAGS_H
