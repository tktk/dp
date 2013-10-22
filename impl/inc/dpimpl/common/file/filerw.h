#ifndef DPIMPL_COMMON_FILE_FILERW_H
#define DPIMPL_COMMON_FILE_FILERW_H

#include "dpimpl/common/file/fileimpl.h"
#include "dp/common/primitives.h"

namespace dp {
    struct FileRW
    {
        FileImpl    impl;
    };

    Bool initializeFileImplRW(
        FileImpl &
        , const Utf32 &
    );
}

#endif  // DPIMPL_COMMON_FILE_FILERW_H
