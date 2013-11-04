#ifndef DP_FILE_FILEW_H
#define DP_FILE_FILEW_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

DPSTRUCT( dp, FileW )

namespace dp {
    DPEXPORT FileW * newFileW(
        const Utf32 &
    );

    DPEXPORT FileW * newFileA(
        const Utf32 &
    );

    DPEXPORT Bool write(
        FileW &
        , const void *
        , ULong
        , ULong &
    );

    DPEXPORT Bool write(
        FileW &
        , const void *
        , ULong &
    );

    DPEXPORT Bool getPosition(
        FileW &
        , Long &
    );

    DPEXPORT Bool setPosition(
        FileW &
        , Long
    );

    DPEXPORT Bool setPositionFromEnd(
        FileW &
        , Long
    );

    DPEXPORT Bool movePosition(
        FileW &
        , Long
    );

    DPEXPORT Bool truncate(
        FileW &
        , Long
    );

    typedef Unique< FileW >::type FileWUnique;

    typedef Shared< FileW >::type FileWShared;

    typedef Weak< FileW >::type FileWWeak;
}

#endif  // DP_FILE_FILEW_H
