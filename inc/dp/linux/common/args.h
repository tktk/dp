#ifndef DP_LINUX_COMMON_ARGS_H
#define DP_LINUX_COMMON_ARGS_H

#include "dp/common/args.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

namespace dp {
    DPEXPORT Bool initArgs(
        Args &
        , dp::StringChar **
    );
}

#endif  // DP_LINUX_COMMON_ARGS_H
