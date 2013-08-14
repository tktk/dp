#include "dpimpl/util/export.h"
#include "dp/display/displaykey.h"

#include "dpimpl/linux/display/displaykey.h"
#include "dp/common/primitives.h"

#include "dpimpl/linux/display/xrandr.h"
#include <new>

namespace {
    dp::DisplayKey * displayKeyNew(
        const RRCrtc &  _CRTC
    )
    {
        dp::DisplayKeyUnique    keyUnique( new( std::nothrow )dp::DisplayKey );
        if( keyUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  key = *keyUnique;

        key.crtc = _CRTC;

        return keyUnique.release();
    }
}

namespace dp {
    DisplayKey * displayKeyClone(
        const DisplayKey &  _OTHER
    )
    {
        return ::displayKeyNew(
            _OTHER.crtc
        );
    }

    Bool displayKeyEquals(
        const DisplayKey &      _KEY1
        , const DisplayKey &    _KEY2
    )
    {
        return _KEY1.crtc == _KEY2.crtc;
    }

    Bool displayKeyLess(
        const DisplayKey &      _KEY1
        , const DisplayKey &    _KEY2
    )
    {
        return _KEY1.crtc < _KEY2.crtc;
    }

    DisplayKey * displayKeyNew(
        const RRCrtc &  _CRTC
    )
    {
        return ::displayKeyNew(
            _CRTC
        );
    }
}
