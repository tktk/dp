#ifndef DP_DISPLAY_DISPLAYMODE_H
#define DP_DISPLAY_DISPLAYMODE_H

#include "dp/display/displaymodekey.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <memory>

namespace dp {
    struct DisplayMode;

    DPEXPORT DisplayMode * displayModeNew(
        const DisplayModeKey &
    );

    DPEXPORT void displayModeDelete(
        DisplayMode &
    );

    DPEXPORT ULong displayModeGetWidth(
        const DisplayMode &
    );

    DPEXPORT ULong displayModeGetHeight(
        const DisplayMode &
    );

    DPEXPORT Float displayModeGetRefreshRate(
        const DisplayMode &
    );

    struct DisplayModeDelete
    {
        void operator()(
            DisplayMode *   _mode
        ) const
        {
            displayModeDelete( *_mode );
        }
    };

    typedef std::unique_ptr<
        DisplayMode
        , DisplayModeDelete
    > DisplayModeUnique;

    typedef std::shared_ptr< DisplayMode > DisplayModeShared;

    inline DisplayModeShared displayModeShared(
        DisplayMode &   _mode
    )
    {
        return DisplayModeShared(
            &_mode
            , DisplayModeDelete()
        );
    }

    typedef std::weak_ptr< DisplayMode > DisplayModeWeak;
}

#endif  // DP_DISPLAY_DISPLAYMODE_H
