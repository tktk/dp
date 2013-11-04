#include "dp/util/export.h"
#include "dp/display/displaykey.h"

#include "dpimpl/linux/display/displaykey.h"
#include "dp/common/primitives.h"

#include "dpimpl/linux/display/xrandr.h"
#include <new>

namespace {
    dp::DisplayKey * newDisplayKey(
        const RRCrtc &  _CRTC
    )
    {
        auto    keyUnique = dp::unique( new( std::nothrow )dp::DisplayKey );
        if( keyUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  key = *keyUnique;

        key.crtc = _CRTC;

        return keyUnique.release();
    }
}

template<>
dp::Bool dpLess(
    const dp::DisplayKey &      _KEY1
    , const dp::DisplayKey &    _KEY2
)
{
    return _KEY1.crtc < _KEY2.crtc;
}

namespace dp {
    DisplayKey * clone(
        const DisplayKey &  _OTHER
    )
    {
        return ::newDisplayKey(
            _OTHER.crtc
        );
    }

    Bool equals(
        const DisplayKey &      _KEY1
        , const DisplayKey &    _KEY2
    )
    {
        return _KEY1.crtc == _KEY2.crtc;
    }

    DisplayKey * newDisplayKey(
        const RRCrtc &  _CRTC
    )
    {
        return ::newDisplayKey(
            _CRTC
        );
    }
}
