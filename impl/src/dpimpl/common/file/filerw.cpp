#include "dp/util/export.h"
#include "dp/file/filerw.h"

#include "dpimpl/common/file/filerw.h"
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

    dp::FileRW * newFileRW(
        const Initializer & _INITIALIZER
    )
    {
        auto    fileUnique = dp::unique( new( std::nothrow )dp::FileRW );
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

template<>
void dpFree(
    const dp::FileRW &  _FILE
)
{
    delete &_FILE;
}

namespace dp {
    FileRW * newFileRW(
        const Utf32 &   _FILE_PATH
    )
    {
        return ::newFileRW(
            [
                &_FILE_PATH
            ]
            (
                dp::FileImpl &  _impl
            )
            {
                return initializeFileImplRW(
                    _impl
                    , _FILE_PATH
                );
            }
        );
    }

    FileRW * newFileWR(
        const Utf32 &   _FILE_PATH
    )
    {
        return ::newFileRW(
            [
                &_FILE_PATH
            ]
            (
                dp::FileImpl &  _impl
            )
            {
                return initializeFileImplWR(
                    _impl
                    , _FILE_PATH
                );
            }
        );
    }

    FileRW * newFileAR(
        const Utf32 &   _FILE_PATH
    )
    {
        return ::newFileRW(
            [
                &_FILE_PATH
            ]
            (
                dp::FileImpl &  _impl
            )
            {
                return initializeFileImplAR(
                    _impl
                    , _FILE_PATH
                );
            }
        );
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

    Bool getPosition(
        FileRW &    _file
        , Long &    _position
    )
    {
        return getPosition(
            _file.impl
            , _position
        );
    }

    Bool setPosition(
        FileRW &    _file
        , Long      _position
    )
    {
        return setPosition(
            _file.impl
            , _position
        );
    }

    Bool setPositionFromEnd(
        FileRW &    _file
        , Long      _position
    )
    {
        return setPositionFromEnd(
            _file.impl
            , _position
        );
    }

    Bool movePosition(
        FileRW &    _file
        , Long      _position
    )
    {
        return movePosition(
            _file.impl
            , _position
        );
    }

    Bool truncate(
        FileRW &    _file
        , Long      _length
    )
    {
        return truncate(
            _file.impl
            , _length
        );
    }
}
