#ifndef DP_COMMON_PRIMITIVES_H
#define DP_COMMON_PRIMITIVES_H

#include <string>

namespace dp {
    typedef bool Bool;

    typedef char Byte;
    typedef unsigned char UByte;
    typedef short Short;
    typedef unsigned short UShort;
    typedef int Int;
    typedef unsigned int UInt;
    typedef long long Long;
    typedef unsigned long long ULong;

    typedef float Float;
    typedef double Double;

    typedef Byte StringChar;
    typedef UByte Utf8Char;
    typedef UShort Utf16Char;
    typedef UInt Utf32Char;

    typedef std::basic_string< StringChar > String;
    typedef std::basic_string< Utf8Char > Utf8;
    typedef std::basic_string< Utf16Char > Utf16;
    typedef std::basic_string< Utf32Char > Utf32;
}

#endif  // DP_COMMON_PRIMITIVES_H
