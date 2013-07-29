#ifndef DP_LINUX_CLI_H
#define DP_LINUX_CLI_H

#include "dp/common/defmain.h"
#include "dp/common/args.h"
#include "dp/linux/common/args.h"

int main(
    int         _argc
    , char **   _argv
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
