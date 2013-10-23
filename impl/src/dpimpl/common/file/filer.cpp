#include "dpimpl/util/export.h"
#include "dp/file/filer.h"

#include "dpimpl/common/file/filer.h"
#include "dpimpl/common/file/fileimpl.h"
#include "dp/common/primitives.h"

#include <new>

namespace dp {
    FileR * newFileR(
        const Utf32 &   _FILE_PATH
    )
    {
        auto    fileUnique = unique( new( std::nothrow )FileR );
        if( fileUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  file = *fileUnique;

        auto &  impl = file.impl;
        if( initializeFileImplR(
            impl
            , _FILE_PATH
        ) == false ) {
            return nullptr;
        }

        return fileUnique.release();
    }

    void free(
        FileR & _file
    )
    {
        delete &_file;
    }

    Bool read(
        FileR &     _file
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
        FileR &     _file
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

    Bool getPosition(
        FileR &     _file
        , Long &    _position
    )
    {
        return getPosition(
            _file.impl
            , _position
        );
    }

    Bool setPosition(
        FileR & _file
        , Long  _position
    )
    {
        return setPosition(
            _file.impl
            , _position
        );
    }

    Bool setPositionFromEnd(
        FileR & _file
        , Long  _position
    )
    {
        return setPositionFromEnd(
            _file.impl
            , _position
        );
    }
}
