#ifndef DP_DISPLAY_DISPLAY_H
#define DP_DISPLAY_DISPLAY_H

#include "dp/display/displaykey.h"
#include "dp/display/displaymodekey.h"
#include "dp/display/displayrotate.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

#include <memory>

DPSTRUCT( dp, Display )

namespace dp {
    DPEXPORT Display * newDisplay(
        const DisplayModeKey &
        , Int
        , Int
        , DisplayRotate
    );

    DPEXPORT Display * newDisplay(
        const DisplayKey &
    );

    DPEXPORT Display * clone(
        const Display &
    );

    DPEXPORT Int getWidth(
        const Display &
    );

    DPEXPORT Int getHeight(
        const Display &
    );

    DPEXPORT const DisplayModeKey & getModeKey(
        const Display &
    );

    DPEXPORT Bool setModeKey(
        Display &
        , const DisplayModeKey &
    );

    DPEXPORT Int getX(
        const Display &
    );

    DPEXPORT void setX(
        Display &
        , Int
    );

    DPEXPORT Int getY(
        const Display &
    );

    DPEXPORT void setY(
        Display &
        , Int
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

    typedef Unique< Display >::type DisplayUnique;

    typedef std::shared_ptr< Display > DisplayShared;

    typedef std::weak_ptr< Display > DisplayWeak;
}

#endif  // DP_DISPLAY_DISPLAY_H
