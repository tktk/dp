#ifndef DP_DISPLAY_DISPLAYKEY_H
#define DP_DISPLAY_DISPLAYKEY_H

#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <memory>

namespace dp {
    struct DisplayKey;

    DPEXPORT DisplayKey * displayKeyClone(
        const DisplayKey &
    );

    DPEXPORT void displayKeyDelete(
        DisplayKey &
    );

    DPEXPORT Bool displayKeyEquals(
        const DisplayKey &
        , const DisplayKey &
    );

    DPEXPORT Bool displayKeyLess(
        const DisplayKey &
        , const DisplayKey &
    );

    struct DisplayKeyDelete
    {
        void operator()(
            DisplayKey *    _key
        ) const
        {
            displayKeyDelete( *_key );
        }
    };

    typedef std::unique_ptr<
        DisplayKey
        , DisplayKeyDelete
    > DisplayKeyUnique;

    typedef std::shared_ptr< DisplayKey > DisplayKeyShared;

    inline DisplayKeyShared displayKeyShared(
        DisplayKey &    _key
    )
    {
        return DisplayKeyShared(
            &_key
            , DisplayKeyDelete()
        );
    }

    typedef std::weak_ptr< DisplayKey > DisplayKeyWeak;

    template< typename T >
    struct DisplayKeyLess
    {
        Bool operator()(
            const T &   _KEY1
            , const T & _KEY2
        ) const
        {
            return displayKeyLess(
                *_KEY1
                , *_KEY2
            );
        }
    };
}

#endif  // DP_DISPLAY_DISPLAYKEY_H
