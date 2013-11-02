#include "dpimpl/util/export.h"
#include "dp/linux/common/args.h"

#include "dp/common/args.h"
#include "dpimpl/common/common/args.h"
#include "dp/common/primitives.h"

namespace dp {
    Bool initArgs(
        Args &          _args
        , StringChar ** _argv
    )
    {
        return initArgsImpl< String >(
            _args
            , _argv
            , [](
                Utf32 &             _to
                , const String &    _FROM
            )
            {
                return stringToUtf32(
                    _to
                    , _FROM
                );
            }
        );
    }
}
