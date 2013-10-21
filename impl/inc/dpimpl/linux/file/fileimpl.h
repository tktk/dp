#ifndef DPIMPL_LINUX_FILE_FILEIMPL_H
#define DPIMPL_LINUX_FILE_FILEIMPL_H

#include "dp/common/primitives.h"

#include <memory>

namespace dp {
    struct FreeFile
    {
        void operator()(
            FILE *
        ) const;
    };

    typedef std::unique_ptr<
        FILE
        , FreeFile
    > FileUnique;

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
