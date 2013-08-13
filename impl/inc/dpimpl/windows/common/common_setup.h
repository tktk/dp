#ifndef DPIMPL_WINDOWS_COMMON_COMMON_SETUP_H
#define DPIMPL_WINDOWS_COMMON_COMMON_SETUP_H

#include "dpimpl/windows/common/stringconverter.h"

namespace dp {
    inline void initializeCommon(
    )
    {
        initializeStringConverter();
    }
}

#endif  // DPIMPL_WINDOWS_COMMON_COMMON_SETUP_H
