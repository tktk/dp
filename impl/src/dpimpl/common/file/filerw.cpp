#include "dpimpl/util/export.h"
#include "dp/file/filerw.h"

#include "dpimpl/common/file/filerw.h"
#include "dpimpl/common/file/fileimpl.h"
#include "dp/common/primitives.h"

#include <new>

namespace dp {
    FileRW * newFileRW(
        const Utf32 &   _FILE_PATH
    )
    {
        auto    fileUnique = unique( new( std::nothrow )FileRW );
        if( fileUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  file = *fileUnique;

        auto &  impl = file.impl;
        if( initializeFileImplRW(
            impl
            , _FILE_PATH
        ) == false ) {
            return nullptr;
        }

        return fileUnique.release();
    }

    void free(
        FileRW &    _file
    )
    {
        delete &_file;
    }

    Bool read(
        FileRW &    _file
        , void *    _data
        , ULong     _size
        , ULong &   _count
    )
    {
        return read(
            _file.impl
            , _data
            , _size
            , _count
        );
    }

    Bool read(
        FileRW &    _file
        , void *    _data
        , ULong &   _size
    )
    {
        return read(
            _file.impl
            , _data
            , _size
        );
    }

    Bool write(
        FileRW &        _file
        , const void *  _DATA
        , ULong         _size
        , ULong &       _count
    )
    {
        return write(
            _file.impl
            , _DATA
            , _size
            , _count
        );
    }

    Bool write(
        FileRW &        _file
        , const void *  _DATA
        , ULong &       _size
    )
    {
        return write(
            _file.impl
            , _DATA
            , _size
        );
    }
}
