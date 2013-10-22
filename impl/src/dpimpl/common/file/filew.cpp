#include "dpimpl/util/export.h"
#include "dp/file/filew.h"

#include "dpimpl/common/file/filew.h"
#include "dpimpl/common/file/fileimpl.h"
#include "dp/common/primitives.h"

#include <new>

namespace dp {
    FileW * newFileW(
        const Utf32 &   _FILE_PATH
    )
    {
        auto    fileUnique = unique( new( std::nothrow )FileW );
        if( fileUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  file = *fileUnique;

        auto &  impl = file.impl;
        if( initializeFileImplW(
            impl
            , _FILE_PATH
        ) == false ) {
            return nullptr;
        }

        return fileUnique.release();
    }

    void free(
        FileW & _file
    )
    {
        delete &_file;
    }

    Bool write(
        FileW &         _file
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
        FileW &         _file
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

    Bool getPosition(
        FileW &     _file
        , Long &    _position
    )
    {
        return getPosition(
            _file.impl
            , _position
        );
    }

    Bool setPosition(
        FileW & _file
        , Long  _position
    )
    {
        return setPosition(
            _file.impl
            , _position
        );
    }
}
