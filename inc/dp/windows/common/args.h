#ifndef DP_WINDOWS_COMMON_ARGS_H
#define DP_WINDOWS_COMMON_ARGS_H

#include "dp/common/args.h"
#include "dp/util/import.h"

namespace dp {
    DPEXPORT Bool initArgs(
        Args &
        , wchar_t **
    );
}

#endif  // DP_WINDOWS_COMMON_ARGS_H
