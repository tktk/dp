#ifndef DPIMPL_COMMON_COMMON_ARGS_H
#define DPIMPL_COMMON_COMMON_ARGS_H

#include "dp/common/args.h"
#include "dp/common/stringconverter.h"

#include <vector>

namespace dp {
    template< class ARG_T >
    void initArgsImpl(
        Args &                          _args
        , typename ARG_T::value_type ** _argv
    )
    {
        auto    argv = _argv;

        Args::value_type    arg;
        for( auto & arg : _args ) {
            const auto  ARG = *argv;
            argv++;

            toUtf32(
                arg
                , ARG_T( ARG )
            );
        }
    }
}

#endif  // DPIMPL_COMMON_COMMON_ARGS_H
