﻿#ifndef DP_WINDOWS_GUI_H
#define DP_WINDOWS_GUI_H

#include "dp/common/defmain.h"
#include "dp/common/primitives.h"
#include "dp/common/args.h"
#include "dp/windows/common/args.h"

#include <windows.h>

dp::Int WINAPI wWinMain(
    HINSTANCE
    , HINSTANCE
    , LPWSTR
    , dp::Int
)
{
    dp::Args    args( __argc );

    if( dp::initArgs(
        args
        , __wargv
    ) == false ) {
        //TODO

        return 1;
    }

    return dpMain(
        args
    );
}

#endif  // DP_WINDOWS_GUI_H
