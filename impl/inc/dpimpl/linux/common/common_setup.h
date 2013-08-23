#ifndef DPIMPL_LINUX_COMMON_COMMON_SETUP_H
#define DPIMPL_LINUX_COMMON_COMMON_SETUP_H

#include "dpimpl/linux/common/stringconverter.h"
#include "dpimpl/linux/common/xlib.h"

namespace dp {
    inline void initializeCommon(
    )
    {
        initializeStringConverter();
        initializeXlib();
    }

    inline void finalizeCommon(
    )
    {
        finalizeXlib();
    }
}

#endif  // DPIMPL_LINUX_COMMON_COMMON_SETUP_H
