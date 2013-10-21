#include "dpimpl/util/export.h"
#include "dp/file/filew.h"

#include "dpimpl/common/file/fileimpl.h"
#include "dp/common/primitives.h"

namespace dp {
    Bool initializeFileImplW(
        FileImpl &      _impl
        , const Utf32 & _FILE_PATH
    )
    {
        return initializeFileImpl(
            _impl
            , _FILE_PATH
            , "w"
        );
    }
}
