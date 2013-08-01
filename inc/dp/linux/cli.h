#ifndef DP_LINUX_CLI_H
#define DP_LINUX_CLI_H

#include "dp/common/defmain.h"
#include "dp/common/primitives.h"
#include "dp/common/args.h"
#include "dp/linux/common/args.h"

dp::Int main(
    dp::Int             _argc
    , dp::StringChar ** _argv
)
{
    dp::Args    args( _argc );

    dp::initArgs(
        args
        , _argv
    );

    return dpMain(
        args
    );
}

#endif  // DP_LINUX_CLI_H
