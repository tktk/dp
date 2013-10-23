#ifndef DP_FILE_FILERW_H
#define DP_FILE_FILERW_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <memory>

namespace dp {
    struct FileRW;

    DPEXPORT FileRW * newFileRW(
        const Utf32 &
    );

    DPEXPORT void free(
        FileRW &
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

    //TODO

    typedef Unique< FileRW >::type FileRWUnique;

    typedef std::shared_ptr< FileRW > FileRWShared;

    typedef std::weak_ptr< FileRW > FileRWWeak;
}

#endif  // DP_FILE_FILERW_H
