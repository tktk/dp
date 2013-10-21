#ifndef DPIMPL_COMMON_FILE_FILER_H
#define DPIMPL_COMMON_FILE_FILER_H

#include "dpimpl/common/file/fileimpl.h"
#include "dp/common/primitives.h"

namespace dp {
    struct FileR
    {
        FileImpl    impl;
    };

    Bool initializeFileImplR(
        FileImpl &
        , const Utf32 &
    );
}

#endif  // DPIMPL_COMMON_FILE_FILER_H
