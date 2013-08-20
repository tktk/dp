#ifndef DP_DISPLAY_DISPLAY_H
#define DP_DISPLAY_DISPLAY_H

#include "dp/display/displaykey.h"
#include "dp/display/displaymodekey.h"
#include "dp/display/displayrotate.h"
#include "dp/common/functional.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <memory>

namespace dp {
    struct Display;

    DPEXPORT Display * newDisplay(
        const DisplayModeKey &
        , Long
        , Long
        , DisplayRotate
    );

    DPEXPORT Display * newDisplay(
        const DisplayKey &
    );

    DPEXPORT Display * clone(
        const Display &
    );

    DPEXPORT void free(
        Display &
    );

    DPEXPORT ULong getWidth(
        const Display &
    );

    DPEXPORT ULong getHeight(
        const Display &
    );

    DPEXPORT const DisplayModeKey & getModeKey(
        const Display &
    );

    DPEXPORT Bool setModeKey(
        Display &
        , const DisplayModeKey &
    );

    DPEXPORT Long getX(
        const Display &
    );

    DPEXPORT void setX(
        Display &
        , Long
    );

    DPEXPORT Long getY(
        const Display &
    );

    DPEXPORT void setY(
        Display &
        , Long
    );

    DPEXPORT DisplayRotate getRotate(
        const Display &
    );

    DPEXPORT void setRotate(
        Display &
        , DisplayRotate
    );

    DPEXPORT Bool apply(
        const DisplayKey &
        , const Display &
    );

    typedef std::unique_ptr<
        Display
        , Free< Display >
    > DisplayUnique;

    typedef std::shared_ptr< Display > DisplayShared;

    typedef std::weak_ptr< Display > DisplayWeak;
}

#endif  // DP_DISPLAY_DISPLAY_H
