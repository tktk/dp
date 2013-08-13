﻿#ifndef DPIMPL_LINUX_COMMON_COMMON_SETUP_H
#define DPIMPL_LINUX_COMMON_COMMON_SETUP_H

#include "dpimpl/linux/common/stringconverter.h"

namespace dp {
    inline void initializeCommon(
    )
    {
        initializeStringConverter();
    }

    inline void finalizeCommon(
    )
    {
        finalizeStringConverter();
    }
}

#endif  // DPIMPL_LINUX_COMMON_COMMON_SETUP_H
