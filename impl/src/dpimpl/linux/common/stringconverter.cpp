#include "dpimpl/util/export.h"
#include "dp/common/stringconverter.h"

#include "dp/common/primitives.h"

#include <locale.h>
#include <langinfo.h>
#include <iconv.h>
#include <vector>

namespace {
    const auto  STRING_MAX_CHARACTER_COUNT = 6; // UTF-8の1文字最大サイズ
    const auto  UTF8_MAX_CHARACTER_COUNT = 6;   // UTF-8の1文字最大符号数
    const auto  UTF16_MAX_CHARACTER_COUNT = 2;  // UTF-16の1文字最大符号数
    const auto  UTF32_MAX_CHARACTER_COUNT = 1;  // UTF-32の1文字最大符号数

    const dp::Utf16Char UTF16_BOM = 0xfeff;
    const dp::Utf32Char UTF32_BOM = 0xfeff;

    const dp::StringChar *  STRING_ENCODE;
    const dp::StringChar    UTF8_ENCODE[] = "UTF-8";
    const dp::StringChar    UTF16_ENCODE[] = "UTF-16";
    const dp::StringChar    UTF32_ENCODE[] = "UTF-32";

    iconv_t UTF8_TO_STRING;
    iconv_t UTF16_TO_STRING;
    iconv_t UTF32_TO_STRING;

    iconv_t STRING_TO_UTF8;
    iconv_t UTF16_TO_UTF8;
    iconv_t UTF32_TO_UTF8;

    iconv_t STRING_TO_UTF16;
    iconv_t UTF8_TO_UTF16;
    iconv_t UTF32_TO_UTF16;

    iconv_t STRING_TO_UTF32;
    iconv_t UTF8_TO_UTF32;
    iconv_t UTF16_TO_UTF32;

    dp::Bool convert(
        const iconv_t & _ICONV
        , void *        _output
        , size_t        _outputSize
        , const void *  _INPUT
        , size_t        _inputSize
    )
    {
        auto    output = static_cast< dp::Byte * >( _output );

        auto    input = static_cast< dp::Byte * >(
            const_cast< void * >(
                _INPUT
            )
        );

        if( iconv(
            _ICONV
            , &input
            , &_inputSize
            , &output
            , &_outputSize
        ) < 0 ) {
            return false;
        }

        if( _inputSize > 0 ) {
            return false;
        }

        return true;
    }

    template< class IN_T >
    dp::Bool toString(
        const iconv_t & _ICONV
        , dp::String &  _out
        , const IN_T &  _IN
    )
    {
        typedef typename IN_T::value_type IN_CHAR;

        auto    length = _IN.length() + 1;

        auto    outputLength = length * STRING_MAX_CHARACTER_COUNT;

        std::vector< dp::StringChar >    out( outputLength );

        auto    output = const_cast< dp::StringChar * >( out.data() );
        auto    outputSize = outputLength * sizeof( dp::StringChar );

        auto    input = _IN.c_str();
        auto    inputSize = length * sizeof( IN_CHAR );

        const auto  CONVERTED = convert(
            _ICONV
            , output
            , outputSize
            , input
            , inputSize
        );

        if( CONVERTED ) {
            _out.assign( output );
        }

        return CONVERTED;
    }

    template< class IN_T >
    dp::Bool toUtf8(
        const iconv_t & _ICONV
        , dp::Utf8 &    _out
        , const IN_T &  _IN
    )
    {
        typedef typename IN_T::value_type IN_CHAR;

        auto    length = _IN.length() + 1;

        auto    outputLength = length * UTF8_MAX_CHARACTER_COUNT;

        std::vector< dp::Utf8Char > out( outputLength );

        auto    output = const_cast< dp::Utf8Char * >( out.data() );
        auto    outputSize = outputLength * sizeof( dp::Utf8Char );

        auto    input = _IN.c_str();
        auto    inputSize = length * sizeof( IN_CHAR );

        const auto  CONVERTED = convert(
            _ICONV
            , output
            , outputSize
            , input
            , inputSize
        );

        if( CONVERTED ) {
            _out.assign( output );
        }

        return CONVERTED;
    }

    template< class IN_T >
    dp::Bool toUtf16(
        const iconv_t & _ICONV
        , dp::Utf16 &   _out
        , const IN_T &  _IN
    )
    {
        typedef typename IN_T::value_type IN_CHAR;

        auto    length = _IN.length() + 1;  // +1は末尾のNULL文字の分

        auto    outputLength = ( length * UTF16_MAX_CHARACTER_COUNT ) + 1;    // +1はBOMの分

        std::vector< dp::Utf16Char >    out( outputLength );

        auto    output = const_cast< dp::Utf16Char * >( out.data() );
        auto    outputSize = outputLength * sizeof( dp::Utf16Char );
        auto    input = _IN.c_str();
        auto    inputSize = length * sizeof( IN_CHAR );

        const auto  CONVERTED = convert(
            _ICONV
            , output
            , outputSize
            , input
            , inputSize
        );

        if( CONVERTED ) {
            if( *output == UTF16_BOM ) {
                output++;
            }

            _out.assign( output );
        }

        return CONVERTED;
    }

    template< class IN_T >
    dp::Bool toUtf32(
        const iconv_t & _ICONV
        , dp::Utf32 &   _out
        , const IN_T &  _IN
    )
    {
        typedef typename IN_T::value_type IN_CHAR;

        auto    length = _IN.length() + 1;  // +1は末尾のNULL文字の分

        auto    outputLength = ( length * UTF32_MAX_CHARACTER_COUNT ) + 1;    // +1はBOMの分

        std::vector< dp::Utf32Char >    out( outputLength );

        auto    output = const_cast< dp::Utf32Char * >( out.data() );
        auto    outputSize = outputLength * sizeof( dp::Utf32Char );

        auto    input = _IN.c_str();
        auto    inputSize = length * sizeof( IN_CHAR );

        const auto  CONVERTED = convert(
            _ICONV
            , output
            , outputSize
            , input
            , inputSize
        );

        if( CONVERTED ) {
            if( *output == UTF32_BOM ) {
                output++;
            }

            _out.assign( output );
        }

        return CONVERTED;
    }
}

namespace dp {
    void initializeStringConverter(
    )
    {
        setlocale( LC_CTYPE, "" );

        STRING_ENCODE = nl_langinfo( CODESET );

        UTF8_TO_STRING = iconv_open(
            STRING_ENCODE
            , UTF8_ENCODE
        );
        UTF16_TO_STRING = iconv_open(
            STRING_ENCODE
            , UTF16_ENCODE
        );
        UTF32_TO_STRING = iconv_open(
            STRING_ENCODE
            , UTF32_ENCODE
        );

        STRING_TO_UTF8 = iconv_open(
            UTF8_ENCODE
            , STRING_ENCODE
        );
        UTF16_TO_UTF8 = iconv_open(
            UTF8_ENCODE
            , UTF16_ENCODE
        );
        UTF32_TO_UTF8 = iconv_open(
            UTF8_ENCODE
            , UTF32_ENCODE
        );

        STRING_TO_UTF16 = iconv_open(
            UTF16_ENCODE
            , STRING_ENCODE
        );
        UTF8_TO_UTF16 = iconv_open(
            UTF16_ENCODE
            , UTF8_ENCODE
        );
        UTF32_TO_UTF16 = iconv_open(
            UTF16_ENCODE
            , UTF32_ENCODE
        );

        STRING_TO_UTF32 = iconv_open(
            UTF32_ENCODE
            , STRING_ENCODE
        );
        UTF8_TO_UTF32 = iconv_open(
            UTF32_ENCODE
            , UTF8_ENCODE
        );
        UTF16_TO_UTF32 = iconv_open(
            UTF32_ENCODE
            , UTF16_ENCODE
        );
    }

    void finalizeStringConverter(
    )
    {
        iconv_close( UTF8_TO_STRING );
        iconv_close( UTF16_TO_STRING );
        iconv_close( UTF32_TO_STRING );

        iconv_close( STRING_TO_UTF8 );
        iconv_close( UTF16_TO_UTF8 );
        iconv_close( UTF32_TO_UTF8 );

        iconv_close( STRING_TO_UTF16 );
        iconv_close( UTF8_TO_UTF16 );
        iconv_close( UTF32_TO_UTF16 );

        iconv_close( STRING_TO_UTF32 );
        iconv_close( UTF8_TO_UTF32 );
        iconv_close( UTF16_TO_UTF32 );
    }

    Bool toString(
        String &        _string
        , const Utf8 &  _UTF8
    )
    {
        return ::toString(
            UTF8_TO_STRING
            , _string
            , _UTF8
        );
    }

    Bool toString(
        String &        _string
        , const Utf16 & _UTF16
    )
    {
        return ::toString(
            UTF16_TO_STRING
            , _string
            , _UTF16
        );
    }

    Bool toString(
        String &        _string
        , const Utf32 & _UTF32
    )
    {
        return ::toString(
            UTF32_TO_STRING
            , _string
            , _UTF32
        );
    }

    Bool toUtf8(
        Utf8 &              _utf8
        , const String &    _STRING
    )
    {
        return ::toUtf8(
            STRING_TO_UTF8
            , _utf8
            , _STRING
        );
    }

    Bool toUtf8(
        Utf8 &          _utf8
        , const Utf16 & _UTF16
    )
    {
        return ::toUtf8(
            UTF16_TO_UTF8
            , _utf8
            , _UTF16
        );
    }

    Bool toUtf8(
        Utf8 &          _utf8
        , const Utf32 & _UTF32
    )
    {
        return ::toUtf8(
            UTF32_TO_UTF8
            , _utf8
            , _UTF32
        );
    }

    Bool toUtf16(
        Utf16 &             _utf16
        , const String &    _STRING
    )
    {
        return ::toUtf16(
            STRING_TO_UTF16
            , _utf16
            , _STRING
        );
    }

    Bool toUtf16(
        Utf16 &         _utf16
        , const Utf8 &  _UTF8
    )
    {
        return ::toUtf16(
            UTF8_TO_UTF16
            , _utf16
            , _UTF8
        );
    }

    Bool toUtf16(
        Utf16 &         _utf16
        , const Utf32 & _UTF32
    )
    {
        return ::toUtf16(
            UTF32_TO_UTF16
            , _utf16
            , _UTF32
        );
    }

    Bool toUtf32(
        Utf32 &             _utf32
        , const String &    _STRING
    )
    {
        return ::toUtf32(
            STRING_TO_UTF32
            , _utf32
            , _STRING
        );
    }

    Bool toUtf32(
        Utf32 &         _utf32
        , const Utf8 &  _UTF8
    )
    {
        return ::toUtf32(
            UTF8_TO_UTF32
            , _utf32
            , _UTF8
        );
    }

    Bool toUtf32(
        Utf32 &         _utf32
        , const Utf16 & _UTF16
    )
    {
        return ::toUtf32(
            UTF16_TO_UTF32
            , _utf32
            , _UTF16
        );
    }
}
