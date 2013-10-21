﻿#ifndef DPIMPL_COMMON_FILE_FILEIMPL_H
#define DPIMPL_COMMON_FILE_FILEIMPL_H

#if defined LINUX   // OS
#include "dpimpl/linux/file/fileimpl.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/file/fileimpl.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#include "dp/common/primitives.h"

namespace dp {
    struct FileImpl;

    ULong read(
        FileImpl &
        , void *
        , ULong
    );

    Bool write(
        FileImpl &
        , const void *
        , ULong
    );
}

#endif  // DPIMPL_COMMON_FILE_FILEIMPL_H
