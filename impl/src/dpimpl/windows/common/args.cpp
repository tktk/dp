#include "dpimpl/util/export.h"
#include "dp/windows/common/args.h"

#include "dp/common/args.h"
#include "dpimpl/common/common/args.h"
#include "dp/common/primitives.h"

namespace dp {
    void initArgs(
        Args &          _args
        , wchar_t **    _argv
    )
    {
        initArgsImpl< Utf16 >(
            _args
            , reinterpret_cast< Utf16Char ** >( _argv )
        );
    }
}
