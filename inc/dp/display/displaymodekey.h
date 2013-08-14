#ifndef DP_DISPLAY_DISPLAYMODEKEY_H
#define DP_DISPLAY_DISPLAYMODEKEY_H

#include "dp/display/displaykey.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <memory>
#include <vector>

namespace dp {
    struct DisplayModeKey;

    DPEXPORT DisplayModeKey * displayModeKeyClone(
        const DisplayModeKey &
    );

    DPEXPORT void displayModeKeyDelete(
        DisplayModeKey &
    );

    DPEXPORT Bool displayModeKeyEquals(
        const DisplayModeKey &
        , const DisplayModeKey &
    );

    DPEXPORT Bool displayModeKeyLess(
        const DisplayModeKey &
        , const DisplayModeKey &
    );

    struct DisplayModeKeyDelete
    {
        void operator()(
            DisplayModeKey *    _key
        ) const
        {
            displayModeKeyDelete( *_key );
        }
    };

    typedef std::unique_ptr<
        DisplayModeKey
        , DisplayModeKeyDelete
    > DisplayModeKeyUnique;

    typedef std::shared_ptr< DisplayModeKey > DisplayModeKeyShared;

    inline DisplayModeKeyShared displayModeKeyShared(
        DisplayModeKey &    _key
    )
    {
        return DisplayModeKeyShared(
            &_key
            , DisplayModeKeyDelete()
        );
    }

    typedef std::weak_ptr< DisplayModeKey > DisplayModeKeyWeak;

    template< typename T >
    struct DisplayModeKeyLess
    {
        Bool operator()(
            const T &   _KEY1
            , const T & _KEY2
        ) const
        {
            return displayModeKeyLess(
                *_KEY1
                , *_KEY2
            );
        }
    };

    typedef std::vector< DisplayModeKeyUnique > DisplayModeKeyUniques;

    DPEXPORT Bool displayModeKeyEnumUniques(
        const DisplayKey &
        , DisplayModeKeyUniques &
    );
}

#endif  // DP_DISPLAY_DISPLAYMODEKEY_H
