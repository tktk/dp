#ifndef DPIMPL_COMMON_FILE_FILEW_H
#define DPIMPL_COMMON_FILE_FILEW_H

#include "dpimpl/common/file/fileimpl.h"
#include "dp/common/primitives.h"

namespace dp {
    struct FileW
    {
        FileImpl    impl;
    };

    Bool initializeFileImplW(
        FileImpl &
        , const Utf32 &
    );
}

#endif  // DPIMPL_COMMON_FILE_FILEW_H
