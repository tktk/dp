#include "dp/util/export.h"
#include "dp/common/stringconverter.h"

#include "dp/common/primitives.h"

#include <winnls.h>
#include <vector>
#include <windows.h>
#include <mbctype.h>

namespace {
    const auto  STRING_MAX_CHARACTER_COUNT = 6; // UTF-8の1文字最大符号数
    const auto  UTF8_MAX_CHARACTER_COUNT = 6;   // UTF-8の1文字最大符号数
    const auto  UTF16_MAX_CHARACTER_COUNT = 2;  // UTF-16の1文字最大符号数

    dp::Int CODEPAGE;

    template<
        class       CONVERTER
        , dp::Int   MAX_CHARACTER_COUNT
        , class     OUT_T
        , class     IN_T
    >
    dp::Bool convert(
        OUT_T &         _out
        , const IN_T &  _IN
    )
    {
        typedef OUT_T::value_type OUT_CHAR;
        typedef IN_T::value_type IN_CHAR;

        dp::Int inputLength = _IN.length() + 1;  // +1は末尾のNULL文字の分

        auto    outputLength = inputLength * MAX_CHARACTER_COUNT;

        std::vector< OUT_CHAR >   out( outputLength );

        auto    output = const_cast< OUT_CHAR * >( out.data() );
        auto    input = _IN.c_str();

        const auto  CONVERTED = CONVERTER()(
            output
            , outputLength
            , input
            , inputLength
        );

        if( CONVERTED ) {
            _out.assign( output );
        }

        return CONVERTED;
    }

    dp::Bool multiByteToWideChar(
        dp::Int             _codePage
        , dp::Utf16Char *   _output
        , dp::Int &         _outputLength
        , const void *      _INPUT
        , dp::Int           _inputLength
    )
    {
        _outputLength = MultiByteToWideChar(
            _codePage
            , 0
            , static_cast< LPCSTR >( _INPUT )
            , _inputLength
            , reinterpret_cast< LPWSTR >( _output )
            , _outputLength
        );

        if( _outputLength == 0 ) {
            return false;
        }

        return true;
    }

    struct StringToUtf16
    {
        dp::Bool operator()(
            dp::Utf16Char *             _output
            , dp::Int &                 _outputLength
            , const dp::StringChar *    _INPUT
            , dp::Int                   _inputLength
        ) const
        {
            return multiByteToWideChar(
                CODEPAGE
                , _output
                , _outputLength
                , _INPUT
                , _inputLength
            );
        }
    };

    struct Utf8ToUtf16
    {
        dp::Bool operator()(
            dp::Utf16Char *         _output
            , dp::Int &             _outputLength
            , const dp::Utf8Char *  _INPUT
            , dp::Int               _inputLength
        ) const
        {
            return multiByteToWideChar(
                CP_UTF8
                , _output
                , _outputLength
                , _INPUT
                , _inputLength
            );
        }
    };

    template<
        class   CONVERTER
        , class IN_T
    >
    dp::Bool toUtf16(
        dp::Utf16 &     _out
        , const IN_T &  _IN
    )
    {
        return convert<
            CONVERTER
            , UTF16_MAX_CHARACTER_COUNT
        >(
            _out
            , _IN
        );
    }

    const auto  UTF32_MAX_CHARACTER_COUNT = 1;    // UTF-32の1文字最大符号数

    const dp::Utf32Char MAX_BMP = 0xffff;
    const dp::Utf32Char MAX_UNICODE = 0x10ffff;

    const auto          UTF16_DATA_BITS_COUNT = 10;
    const dp::Utf16Char UTF16_DATA_BITS_MASK = ( 0x1 << UTF16_DATA_BITS_COUNT ) - 1;

    const auto  FROM_10FFFF_TO_FFFFF_BIT = 0x010000;

    const dp::Utf16Char SURROGATES_PAIR_HEADER_BITS_HIGH = 0xd800;
    const dp::Utf16Char SURROGATES_PAIR_HEADER_BITS_LOW = 0xdc00;

    template< typename T >
    T * incOutputCharPtr(
        T * &       _outputCharPtr
        , const T * _END_OF_OUTPUT
    )
    {
        if( _outputCharPtr >= _END_OF_OUTPUT ) {
            return nullptr;
        }

        auto    output = _outputCharPtr;

        _outputCharPtr++;

        return output;
    }

    struct Utf16ToUtf32
    {
        dp::Bool operator()(
            dp::Utf32Char *         _output
            , dp::Int               _outputLength
            , const dp::Utf16Char * _INPUT
            , dp::Int               _inputLength
        ) const
        {
            const auto  END_OF_OUTPUT = _output + _outputLength;
            const auto  END_OF_INPUT = _INPUT + _inputLength;

            auto    output = _output;
            for( auto input = _INPUT ; input < END_OF_INPUT ; input++ ) {
                const auto &    UTF16 = *input;

                auto    utf32Ptr = incOutputCharPtr(
                    output
                    , END_OF_OUTPUT
                );
                if( utf32Ptr == nullptr ) {
                    return false;
                }

                auto &  utf32 = *utf32Ptr;

                if( ( UTF16 & ~UTF16_DATA_BITS_MASK ) == SURROGATES_PAIR_HEADER_BITS_HIGH ) {
                    input++;
                    if( input >= END_OF_INPUT ) {
                        return false;
                    }

                    const auto &    UTF16_LOW = *input;

                    if( ( UTF16_LOW & ~UTF16_DATA_BITS_MASK ) == SURROGATES_PAIR_HEADER_BITS_LOW ) {
                        utf32 = ( ( UTF16 & UTF16_DATA_BITS_MASK ) << UTF16_DATA_BITS_COUNT ) | ( UTF16_LOW & UTF16_DATA_BITS_MASK ) + FROM_10FFFF_TO_FFFFF_BIT;
                    } else {
                        return false;
                    }
                } else {
                    utf32 = UTF16;
                }
            }

            return true;
        }
    };

    template<
        class   TO_UTF16
        , class IN_T
    >
    dp::Bool toUtf32(
        dp::Utf32Char * _output
        , dp::Int       _outputLength
        , const IN_T    _INPUT
        , dp::Int       _inputLength
    )
    {
        auto    utf16Length = _inputLength * UTF16_MAX_CHARACTER_COUNT;

        std::vector< dp::Utf16Char >    utf16( utf16Length );

        auto    utf16Ptr = const_cast< dp::Utf16Char * >( utf16.data() );

        if( TO_UTF16()(
            utf16Ptr
            , utf16Length
            , _INPUT
            , _inputLength
        ) == false ) {
            return false;
        }

        if( Utf16ToUtf32()(
            _output
            , _outputLength
            , utf16Ptr
            , utf16Length
        ) == false ) {
            return false;
        }

        return true;
    }

    struct StringToUtf32
    {
        dp::Bool operator()(
            dp::Utf32Char *             _output
            , dp::Int                   _outputLength
            , const dp::StringChar *    _INPUT
            , dp::Int                   _inputLength
        ) const
        {
            return toUtf32< StringToUtf16 >(
                _output
                , _outputLength
                , _INPUT
                , _inputLength
            );
        }
    };

    struct Utf8ToUtf32
    {
        dp::Bool operator()(
            dp::Utf32Char *         _output
            , dp::Int               _outputLength
            , const dp::Utf8Char *  _INPUT
            , dp::Int               _inputLength
        ) const
        {
            return toUtf32< Utf8ToUtf16 >(
                _output
                , _outputLength
                , _INPUT
                , _inputLength
            );
        }
    };

    template<
        class   CONVERTER
        , class IN_T
    >
    dp::Bool toUtf32(
        dp::Utf32 &     _out
        , const IN_T &  _IN
    )
    {
        return convert<
            CONVERTER
            , UTF32_MAX_CHARACTER_COUNT
        >(
            _out
            , _IN
        );
    }

    struct Utf32ToUtf16
    {
        dp::Bool operator()(
            dp::Utf16Char *         _output
            , dp::Int &             _outputLength
            , const dp::Utf32Char * _INPUT
            , dp::Int               _inputLength
        ) const
        {
            const auto  END_OF_OUTPUT = _output + _outputLength;
            const auto  END_OF_INPUT = _INPUT + _inputLength;

            auto    output = _output;
            for( auto input = _INPUT ; input < END_OF_INPUT ; input++ ) {
                const auto &    UTF32 = *input;

                auto    utf16Ptr = incOutputCharPtr(
                    output
                    , END_OF_OUTPUT
                );
                if( utf16Ptr == nullptr ) {
                    return false;
                }

                auto &  utf16 = *utf16Ptr;

                if( UTF32 <= MAX_BMP ) {
                    utf16 = UTF32;
                } else if( UTF32 <= MAX_UNICODE ) {
                    utf16 = ( ( UTF32  - FROM_10FFFF_TO_FFFFF_BIT ) >> UTF16_DATA_BITS_COUNT ) | SURROGATES_PAIR_HEADER_BITS_HIGH;

                    auto    utf16Ptr = incOutputCharPtr(
                        output
                        , END_OF_OUTPUT
                    );
                    if( utf16Ptr == nullptr ) {
                        return false;
                    }

                    auto &  utf16 = *utf16Ptr;

                    utf16 = ( UTF32 & UTF16_DATA_BITS_MASK ) | SURROGATES_PAIR_HEADER_BITS_LOW;
                } else {
                    return false;
                }
            }

            _outputLength = output - _output;

            return true;
        }
    };

    dp::Bool utf16ToMultiByte(
        dp::Int                 _codePage
        , void *                _output
        , dp::Int               _outputLength
        , const dp::Utf16Char * _INPUT
        , dp::Int               _inputLength
    )
    {
        BOOL    usedDefaultChar = FALSE;

        auto    outputLength = WideCharToMultiByte(
            _codePage
            , 0
            , reinterpret_cast< LPCWSTR >( _INPUT )
            , _inputLength
            , static_cast< LPSTR >( _output )
            , _outputLength
            , nullptr
            , _codePage == CP_UTF8  // UTF-8の場合、nullptrを設定しないとエラーになる
                ? nullptr
                : &usedDefaultChar
        );

        if( outputLength == 0 ) {
            return false;
        }

        if( usedDefaultChar == TRUE ) {
            return false;
        }

        return true;
    }

    struct Utf16ToString
    {
        dp::Bool operator()(
            dp::StringChar *        _output
            , dp::Int               _outputLength
            , const dp::Utf16Char * _INPUT
            , dp::Int               _inputLength
        ) const
        {
            return utf16ToMultiByte(
                CODEPAGE
                , _output
                , _outputLength
                , _INPUT
                , _inputLength
            );
        }
    };

    template<
        class   TO_UTF16
        , class IN_T
    >
    dp::Bool toString(
        dp::StringChar *    _output
        , dp::Int           _outputLength
        , const IN_T        _INPUT
        , dp::Int           _inputLength
    )
    {
        auto    utf16Length = _inputLength * UTF16_MAX_CHARACTER_COUNT;

        std::vector< dp::Utf16Char >    utf16( utf16Length );

        auto    utf16Ptr = const_cast< dp::Utf16Char * >( utf16.data() );

        if( TO_UTF16()(
            utf16Ptr
            , utf16Length
            , _INPUT
            , _inputLength
        ) == false ) {
            return false;
        }

        if( Utf16ToString()(
            _output
            , _outputLength
            , utf16Ptr
            , utf16Length
        ) == false ) {
            return false;
        }

        return true;
    }

    struct Utf8ToString
    {
        dp::Bool operator()(
            dp::StringChar *        _output
            , dp::Int               _outputLength
            , const dp::Utf8Char *  _INPUT
            , dp::Int               _inputLength
        ) const
        {
            return toString< Utf8ToUtf16 >(
                _output
                , _outputLength
                , _INPUT
                , _inputLength
            );
        }
    };

    struct Utf32ToString
    {
        dp::Bool operator()(
            dp::StringChar *        _output
            , dp::Int               _outputLength
            , const dp::Utf32Char * _INPUT
            , dp::Int               _inputLength
        ) const
        {
            return toString< Utf32ToUtf16 >(
                _output
                , _outputLength
                , _INPUT
                , _inputLength
            );
        }
    };

    template<
        class   CONVERTER
        , class IN_T
    >
    dp::Bool toString(
        dp::String &    _out
        , const IN_T &  _IN
    )
    {
        return convert<
            CONVERTER
            , STRING_MAX_CHARACTER_COUNT
        >(
            _out
            , _IN
        );
    }

    struct Utf16ToUtf8
    {
        dp::Bool operator()(
            dp::Utf8Char *          _output
            , dp::Int               _outputLength
            , const dp::Utf16Char * _INPUT
            , dp::Int               _inputLength
        ) const
        {
            return utf16ToMultiByte(
                CP_UTF8
                , _output
                , _outputLength
                , _INPUT
                , _inputLength
            );
        }
    };

    template<
        class   TO_UTF16
        , class IN_T
    >
    dp::Bool toUtf8(
        dp::Utf8Char *  _output
        , dp::Int       _outputLength
        , const IN_T    _INPUT
        , dp::Int       _inputLength
    )
    {
        auto    utf16Length = _inputLength * UTF16_MAX_CHARACTER_COUNT;

        std::vector< dp::Utf16Char >    utf16( utf16Length );

        auto    utf16Ptr = const_cast< dp::Utf16Char * >( utf16.data() );

        if( TO_UTF16()(
            utf16Ptr
            , utf16Length
            , _INPUT
            , _inputLength
        ) == false ) {
            return false;
        }

        if( Utf16ToUtf8()(
            _output
            , _outputLength
            , utf16Ptr
            , utf16Length
        ) == false ) {
            return false;
        }

        return true;
    }

    struct StringToUtf8
    {
        dp::Bool operator()(
            dp::Utf8Char *              _output
            , dp::Int                   _outputLength
            , const dp::StringChar *    _INPUT
            , dp::Int                   _inputLength
        ) const
        {
            return toUtf8< StringToUtf16 >(
                _output
                , _outputLength
                , _INPUT
                , _inputLength
            );
        }
    };

    struct Utf32ToUtf8
    {
        dp::Bool operator()(
            dp::Utf8Char *          _output
            , dp::Int               _outputLength
            , const dp::Utf32Char * _INPUT
            , dp::Int               _inputLength
        ) const
        {
            return toUtf8< Utf32ToUtf16 >(
                _output
                , _outputLength
                , _INPUT
                , _inputLength
            );
        }
    };

    template<
        class   CONVERTER
        , class IN_T
    >
    dp::Bool toUtf8(
        dp::Utf8 &      _out
        , const IN_T &  _IN
    )
    {
        return convert<
            CONVERTER
            , UTF8_MAX_CHARACTER_COUNT
        >(
            _out
            , _IN
        );
    }
}

namespace dp {
    void initializeStringConverter(
    )
    {
        CODEPAGE = _getmbcp();
    }

    Bool toString(
        String &        _string
        , const Utf8 &  _UTF8
    )
    {
        return ::toString< Utf8ToString >(
            _string
            , _UTF8
        );
    }

    Bool toString(
        String &        _string
        , const Utf16 & _UTF16
    )
    {
        return ::toString< Utf16ToString >(
            _string
            , _UTF16
        );
    }

    Bool toString(
        String &        _string
        , const Utf32 & _UTF32
    )
    {
        return ::toString< Utf32ToString >(
            _string
            , _UTF32
        );
    }

    Bool stringToUtf8(
        Utf8 &              _utf8
        , const String &    _STRING
    )
    {
        return ::toUtf8< StringToUtf8 >(
            _utf8
            , _STRING
        );
    }

    Bool toUtf8(
        Utf8 &          _utf8
        , const Utf16 & _UTF16
    )
    {
        return ::toUtf8< Utf16ToUtf8 >(
            _utf8
            , _UTF16
        );
    }

    Bool toUtf8(
        Utf8 &          _utf8
        , const Utf32 & _UTF32
    )
    {
        return ::toUtf8< Utf32ToUtf8 >(
            _utf8
            , _UTF32
        );
    }

    Bool stringToUtf16(
        Utf16 &             _utf16
        , const String &    _STRING
    )
    {
        return ::toUtf16< StringToUtf16 >(
            _utf16
            , _STRING
        );
    }

    Bool toUtf16(
        Utf16 &         _utf16
        , const Utf8 &  _UTF8
    )
    {
        return ::toUtf16< Utf8ToUtf16 >(
            _utf16
            , _UTF8
        );
    }

    Bool toUtf16(
        Utf16 &         _utf16
        , const Utf32 & _UTF32
    )
    {
        return ::toUtf16< Utf32ToUtf16 >(
            _utf16
            , _UTF32
        );
    }

    Bool stringToUtf32(
        Utf32 &             _utf32
        , const String &    _STRING
    )
    {
        return ::toUtf32< StringToUtf32 >(
            _utf32
            , _STRING
        );
    }

    Bool toUtf32(
        Utf32 &         _utf32
        , const Utf8 &  _UTF8
    )
    {
        return ::toUtf32< Utf8ToUtf32 >(
            _utf32
            , _UTF8
        );
    }

    Bool toUtf32(
        Utf32 &         _utf32
        , const Utf16 & _UTF16
    )
    {
        return ::toUtf32< Utf16ToUtf32 >(
            _utf32
            , _UTF16
        );
    }
}
