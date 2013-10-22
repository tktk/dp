﻿#include "dpimpl/common/file/fileimpl.h"
#include "dp/common/stringconverter.h"
#include "dp/common/primitives.h"

#include <cstdio>

namespace dp {
    void FreeFile::operator()(
        FILE *  _file
    ) const
    {
        std::fclose( _file );
    }

    Bool initializeFileImpl(
        FileImpl &              _impl
        , const Utf32 &         _FILE_PATH
        , const StringChar *    _MODE
    )
    {
        String  filePathString;
        if( toString(
            filePathString
            , _FILE_PATH
        ) == false ) {
            return false;
        }

        auto &  fileUnique = _impl.fileUnique;
        fileUnique.reset(
            fopen64(
                filePathString.c_str()
                , _MODE
            )
        );
        if( fileUnique.get() == nullptr ) {
            return false;
        }

        return true;
    }

    Bool read(
        FileImpl &  _impl
        , void *    _data
        , ULong     _size
        , ULong &   _count
    )
    {
        auto &  file = *( _impl.fileUnique );

        _count = std::fread(
            _data
            , _size
            , _count
            , &file
        );

        if( std::ferror( &file ) != 0 ) {
            return false;
        }

        return true;
    }

    Bool read(
        FileImpl &  _impl
        , void *    _data
        , ULong &   _size
    )
    {
        return read(
            _impl
            , _data
            , 1
            , _size
        );
    }

    Bool write(
        FileImpl &      _impl
        , const void *  _DATA
        , ULong         _size
        , ULong &       _count
    )
    {
        auto &  file = *( _impl.fileUnique );

        _count = std::fwrite(
            _DATA
            , _size
            , _count
            , &file
        );

        if( std::ferror( &file ) != 0 ) {
            return false;
        }

        return true;
    }

    Bool write(
        FileImpl &      _impl
        , const void *  _DATA
        , ULong &       _size
    )
    {
        return write(
            _impl
            , _DATA
            , 1
            , _size
        );
    }
}
