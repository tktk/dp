#ifndef DP_COMMON_STRINGCONVERTER_H
#define DP_COMMON_STRINGCONVERTER_H

#include "dp/common/primitives.h"
#include "dp/util/import.h"

namespace dp {
    DPEXPORT Bool toString(
        String &
        , const Utf8 &
    );

    DPEXPORT Bool toString(
        String &
        , const Utf16 &
    );

    DPEXPORT Bool toString(
        String &
        , const Utf32 &
    );

    DPEXPORT Bool toUtf8(
        Utf8 &
        , const String &
    );

    DPEXPORT Bool toUtf8(
        Utf8 &
        , const Utf16 &
    );

    DPEXPORT Bool toUtf8(
        Utf8 &
        , const Utf32 &
    );

    DPEXPORT Bool toUtf16(
        Utf16 &
        , const String &
    );

    DPEXPORT Bool toUtf16(
        Utf16 &
        , const Utf8 &
    );

    DPEXPORT Bool toUtf16(
        Utf16 &
        , const Utf32 &
    );

    DPEXPORT Bool toUtf32(
        Utf32 &
        , const String &
    );

    DPEXPORT Bool toUtf32(
        Utf32 &
        , const Utf8 &
    );

    DPEXPORT Bool toUtf32(
        Utf32 &
        , const Utf16 &
    );
}

#endif  // DP_COMMON_STRINGCONVERTER_H
