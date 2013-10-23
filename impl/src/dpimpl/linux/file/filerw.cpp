#include "dpimpl/common/file/filerw.h"
#include "dpimpl/linux/file/fileimpl.h"
#include "dp/common/primitives.h"

namespace dp {
    Bool initializeFileImplRW(
        FileImpl &      _impl
        , const Utf32 & _FILE_PATH
    )
    {
        return initializeFileImpl(
            _impl
            , _FILE_PATH
            , "r+"
        );
    }

    Bool initializeFileImplWR(
        FileImpl &      _impl
        , const Utf32 & _FILE_PATH
    )
    {
        return initializeFileImpl(
            _impl
            , _FILE_PATH
            , "w+"
        );
    }

    Bool initializeFileImplAR(
        FileImpl &      _impl
        , const Utf32 & _FILE_PATH
    )
    {
        return initializeFileImpl(
            _impl
            , _FILE_PATH
            , "a+"
        );
    }
}
