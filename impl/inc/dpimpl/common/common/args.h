﻿#ifndef DPIMPL_COMMON_COMMON_ARGS_H
#define DPIMPL_COMMON_COMMON_ARGS_H

#include "dp/common/args.h"
#include "dp/common/stringconverter.h"

#include <vector>
#include <functional>

namespace dp {
    template< class ARG_T >
    Bool initArgsImpl(
        Args &                          _args
        , typename ARG_T::value_type ** _argv
        , const std::function<
            Bool(
                Args::value_type &
                , const ARG_T &
            )
        >                               _TO_UTF32
    )
    {
        auto    argv = _argv;

        Args::value_type    arg;
        for( auto & arg : _args ) {
            const auto  ARG = *argv;
            argv++;

            if( _TO_UTF32(
                arg
                , ARG_T( ARG )
            ) == false ) {
                return false;
            }
        }

        return true;
    }
}

#endif  // DPIMPL_COMMON_COMMON_ARGS_H
