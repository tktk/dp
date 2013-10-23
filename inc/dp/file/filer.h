#ifndef DP_FILE_FILER_H
#define DP_FILE_FILER_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <memory>

namespace dp {
    struct FileR;

    DPEXPORT FileR * newFileR(
        const Utf32 &
    );

    DPEXPORT void free(
        FileR &
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

    //TODO

    typedef Unique< FileR >::type FileRUnique;

    typedef std::shared_ptr< FileR > FileRShared;

    typedef std::weak_ptr< FileR > FileRWeak;
}

#endif  // DP_FILE_FILER_H
