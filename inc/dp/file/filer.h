#ifndef DP_FILE_FILER_H
#define DP_FILE_FILER_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

DPSTRUCT( dp, FileR )

namespace dp {
    DPEXPORT FileR * newFileR(
        const Utf32 &
    );

    DPEXPORT Bool read(
        FileR &
        , void *
        , ULong
        , ULong &
    );

    DPEXPORT Bool read(
        FileR &
        , void *
        , ULong &
    );

    DPEXPORT Bool getPosition(
        FileR &
        , Long &
    );

    DPEXPORT Bool setPosition(
        FileR &
        , Long
    );

    DPEXPORT Bool setPositionFromEnd(
        FileR &
        , Long
    );

    DPEXPORT Bool movePosition(
        FileR &
        , Long
    );

    typedef Unique< FileR >::type FileRUnique;

    typedef Shared< FileR >::type FileRShared;

    typedef Weak< FileR >::type FileRWeak;
}

#endif  // DP_FILE_FILER_H
