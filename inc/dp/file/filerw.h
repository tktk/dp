#ifndef DP_FILE_FILERW_H
#define DP_FILE_FILERW_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

DPSTRUCT( dp, FileRW )

namespace dp {
    DPEXPORT FileRW * newFileRW(
        const Utf32 &
    );

    DPEXPORT FileRW * newFileWR(
        const Utf32 &
    );

    DPEXPORT FileRW * newFileAR(
        const Utf32 &
    );

    DPEXPORT Bool read(
        FileRW &
        , void *
        , ULong
        , ULong &
    );

    DPEXPORT Bool read(
        FileRW &
        , void *
        , ULong &
    );

    DPEXPORT Bool write(
        FileRW &
        , const void *
        , ULong
        , ULong &
    );

    DPEXPORT Bool write(
        FileRW &
        , const void *
        , ULong &
    );

    DPEXPORT Bool getPosition(
        FileRW &
        , Long &
    );

    DPEXPORT Bool setPosition(
        FileRW &
        , Long
    );

    DPEXPORT Bool setPositionFromEnd(
        FileRW &
        , Long
    );

    DPEXPORT Bool movePosition(
        FileRW &
        , Long
    );

    DPEXPORT Bool truncate(
        FileRW &
        , Long
    );

    typedef Unique< FileRW >::type FileRWUnique;

    typedef Shared< FileRW >::type FileRWShared;

    typedef Weak< FileRW >::type FileRWWeak;
}

#endif  // DP_FILE_FILERW_H
