#ifndef DP_WINDOWS_CLI_H
#define DP_WINDOWS_CLI_H

#include "dp/common/defmain.h"
#include "dp/common/primitives.h"
#include "dp/common/args.h"
#include "dp/windows/common/args.h"

dp::Int wmain(
    dp::Int         _argc
    , wchar_t **    _argv
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

#endif  // DP_WINDOWS_CLI_H
