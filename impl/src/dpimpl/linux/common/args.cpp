#include "dpimpl/util/export.h"
#include "dp/linux/common/args.h"

#include "dp/common/args.h"
#include "dpimpl/common/common/args.h"
#include "dp/common/primitives.h"

namespace dp {
    void initArgs(
        Args &      _args
        , char **   _argv
    )
    {
        initArgsImpl< String >(
            _args
            , _argv
        );
    }
}
