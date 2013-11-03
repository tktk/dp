#ifndef DPIMPL_LINUX_FILE_FILEIMPL_H
#define DPIMPL_LINUX_FILE_FILEIMPL_H

#include "dp/common/memory.h"
#include "dp/common/primitives.h"

namespace dp {
    typedef dp::Unique< FILE >::type FileUnique;

    struct FileImpl
    {
        FileUnique  fileUnique;
    };

    Bool initializeFileImpl(
        FileImpl &
        , const Utf32 &
        , const StringChar *
    );
}

#endif  // DPIMPL_LINUX_FILE_FILEIMPL_H
