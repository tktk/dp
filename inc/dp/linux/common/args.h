#ifndef DP_LINUX_COMMON_ARGS_H
#define DP_LINUX_COMMON_ARGS_H

#include "dp/common/args.h"
#include "dp/util/import.h"

namespace dp {
    DPEXPORT void initArgs(
        Args &
        , char **
    );
}

#endif  // DP_LINUX_COMMON_ARGS_H
