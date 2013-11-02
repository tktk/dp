#include "dpimpl/util/export.h"
#include "dp/windows/common/args.h"

#include "dp/common/args.h"
#include "dpimpl/common/common/args.h"
#include "dp/common/primitives.h"

namespace dp {
    Bool initArgs(
        Args &          _args
        , wchar_t **    _argv
    )
    {
        return initArgsImpl< Utf16 >(
            _args
            , reinterpret_cast< Utf16Char ** >( _argv )
            , [](
                Utf32 &         _to
                , const Utf16 & _FROM
            )
            {
                return toUtf32(
                    _to
                    , _FROM
                );
            }
        );
    }
}
