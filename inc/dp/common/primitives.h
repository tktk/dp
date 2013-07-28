#ifndef DP_COMMON_PRIMITIVES_H
#define DP_COMMON_PRIMITIVES_H

#include <string>

namespace dp {
    typedef bool Bool;

    typedef signed char Byte;
    typedef unsigned char UByte;
    typedef signed short Short;
    typedef unsigned short UShort;
    typedef signed long Int;
    typedef unsigned long UInt;
    typedef signed long long Long;
    typedef unsigned long long ULong;

    typedef char StringChar;
    typedef UByte Utf8Char;
    typedef UShort Utf16Char;
    typedef UInt Utf32Char;

    typedef std::basic_string< StringChar > String;
    typedef std::basic_string< Utf8Char > Utf8;
    typedef std::basic_string< Utf16Char > Utf16;
    typedef std::basic_string< Utf32Char > Utf32;
}

#endif  // DP_COMMON_PRIMITIVES_H
