#ifndef DP_DISPLAY_DISPLAY_H
#define DP_DISPLAY_DISPLAY_H

#include "dp/display/displaykey.h"
#include "dp/display/displaymodekey.h"
#include "dp/display/displayrotate.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <memory>

namespace dp {
    struct Display;

    DPEXPORT Display * displayNew(
        const DisplayModeKey &
        , Long
        , Long
        , DisplayRotate
    );

    DPEXPORT Display * displayNewFromKey(
        const DisplayKey &
    );

    DPEXPORT Display * displayClone(
        const Display &
    );

    DPEXPORT void displayDelete(
        Display &
    );

    DPEXPORT ULong displayGetWidth(
        const Display &
    );

    DPEXPORT ULong displayGetHeight(
        const Display &
    );

    DPEXPORT const DisplayModeKey & displayGetModeKey(
        const Display &
    );

    DPEXPORT Bool displaySetModeKey(
        Display &
        , const DisplayModeKey &
    );

    DPEXPORT Long displayGetX(
        const Display &
    );

    DPEXPORT void displaySetX(
        Display &
        , Long
    );

    DPEXPORT Long displayGetY(
        const Display &
    );

    DPEXPORT void displaySetY(
        Display &
        , Long
    );

    DPEXPORT DisplayRotate displayGetRotate(
        const Display &
    );

    DPEXPORT void displaySetRotate(
        Display &
        , DisplayRotate
    );

    DPEXPORT Bool displayApply(
        const DisplayKey &
        , const Display &
    );

    struct DisplayDelete
    {
        void operator()(
            Display *   _display
        ) const
        {
            displayDelete( *_display );
        }
    };

    typedef std::unique_ptr<
        Display
        , DisplayDelete
    > DisplayUnique;

    typedef std::shared_ptr< Display > DisplayShared;

    inline DisplayShared displayShared(
        Display &   _display
    )
    {
        return DisplayShared(
            &_display
            , DisplayDelete()
        );
    }

    typedef std::weak_ptr< Display > DisplayWeak;
}

#endif  // DP_DISPLAY_DISPLAY_H
