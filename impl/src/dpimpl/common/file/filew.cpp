#include "dpimpl/util/export.h"
#include "dp/file/filew.h"

#include "dpimpl/common/file/filew.h"
#include "dpimpl/common/file/fileimpl.h"
#include "dp/common/primitives.h"

#include <new>
#include <functional>

namespace {
    typedef std::function<
        dp::Bool(
            dp::FileImpl &
        )
    > Initializer;

    dp::FileW * newFileW(
        const Initializer & _INITIALIZER
    )
    {
        auto    fileUnique = dp::unique( new( std::nothrow )dp::FileW );
        if( fileUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  file = *fileUnique;

        auto &  impl = file.impl;
        if( _INITIALIZER(
            impl
        ) == false ) {
            return nullptr;
        }

        return fileUnique.release();
    }
}

namespace dp {
    FileW * newFileW(
        const Utf32 &   _FILE_PATH
    )
    {
        return ::newFileW(
            [
                &_FILE_PATH
            ]
            (
                FileImpl &  _impl
            )
            {
                return initializeFileImplW(
                    _impl
                    , _FILE_PATH
                );
            }
        );
    }

    FileW * newFileA(
        const Utf32 &   _FILE_PATH
    )
    {
        return ::newFileW(
            [
                &_FILE_PATH
            ]
            (
                FileImpl &  _impl
            )
            {
                return initializeFileImplA(
                    _impl
                    , _FILE_PATH
                );
            }
        );
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

    Bool setPositionFromEnd(
        FileW & _file
        , Long  _position
    )
    {
        return setPositionFromEnd(
            _file.impl
            , _position
        );
    }

    Bool movePosition(
        FileW & _file
        , Long  _position
    )
    {
        return movePosition(
            _file.impl
            , _position
        );
    }

    Bool truncate(
        FileW & _file
        , Long  _length
    )
    {
        return truncate(
            _file.impl
            , _length
        );
    }
}
