#include "dpimpl/util/export.h"
#include "dp/display/displaymodekey.h"

#include "dpimpl/linux/display/displaymodekey.h"
#include "dp/common/primitives.h"

#include "dpimpl/linux/display/xrandr.h"
#include <new>

namespace {
    dp::DisplayModeKey * displayModeKeyNew(
        const RRMode &  _MODE
    )
    {
        dp::DisplayModeKeyUnique    keyUnique( new( std::nothrow )dp::DisplayModeKey );
        if( keyUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  key = *keyUnique;

        key.mode = _MODE;

        return keyUnique.release();
    }
}

namespace dp {
    DisplayModeKey * displayModeKeyClone(
        const DisplayModeKey &  _KEY
    )
    {
        return ::displayModeKeyNew(
            _KEY.mode
        );
    }

    Bool displayModeKeyEquals(
        const DisplayModeKey &      _KEY1
        , const DisplayModeKey &    _KEY2
    )
    {
        return _KEY1.mode == _KEY2.mode;
    }

    Bool displayModeKeyLess(
        const DisplayModeKey &      _KEY1
        , const DisplayModeKey &    _KEY2
    )
    {
        return _KEY1.mode < _KEY2.mode;
    }

    DisplayModeKey * displayModeKeyNew(
        const RRMode &  _MODE
    )
    {
        return ::displayModeKeyNew(
            _MODE
        );
    }
}
