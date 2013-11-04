#include "dpimpl/util/export.h"
#include "dp/display/display.h"

#include "dpimpl/common/display/display.h"
#include "dp/display/displaymodekey.h"
#include "dpimpl/common/display/displaymodekey.h"
#include "dpimpl/common/display/displaymode.h"
#include "dp/display/displayrotate.h"
#include "dp/common/primitives.h"

#include <new>

namespace {
    dp::Display * newDisplay(
        const dp::DisplayModeKey &  _MODE_KEY
        , dp::Int                   _x
        , dp::Int                   _y
        , dp::DisplayRotate         _rotate
    )
    {
        auto    displayUnique = dp::unique( new( std::nothrow )dp::Display );
        if( displayUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  display = *displayUnique;

        auto &  modeKeyUnique = display.modeKeyUnique;
        modeKeyUnique.reset(
            dp::clone(
                _MODE_KEY
            )
        );
        if( modeKeyUnique.get() == nullptr ) {
            return nullptr;
        }

        display.x = _x;
        display.y = _y;
        display.rotate = _rotate;

        return displayUnique.release();
    }
}

template<>
void dpFree(
    const dp::Display & _DISPLAY
)
{
    delete &_DISPLAY;
}

namespace dp {
    Display * newDisplay(
        const DisplayModeKey &  _MODE_KEY
        , Int                   _x
        , Int                   _y
        , DisplayRotate         _rotate
    )
    {
        auto    displayUnique = unique(
            ::newDisplay(
                _MODE_KEY
                , _x
                , _y
                , _rotate
            )
        );
        if( displayUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  display = *displayUnique;

        if( getWidthAndHeightFromModeKey(
            display.width
            , display.height
            , *( display.modeKeyUnique )
        ) == false ) {
            return nullptr;
        }

        return displayUnique.release();
    }

    Display * clone(
        const Display & _DISPLAY
    )
    {
        auto    displayUnique = unique(
            ::newDisplay(
                *( _DISPLAY.modeKeyUnique )
                , _DISPLAY.x
                , _DISPLAY.y
                , _DISPLAY.rotate
            )
        );
        if( displayUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  display = *displayUnique;

        display.width = _DISPLAY.width;
        display.height = _DISPLAY.height;

        return displayUnique.release();
    }

    Int getWidth(
        const Display & _DISPLAY
    )
    {
        return _DISPLAY.width;
    }

    Int getHeight(
        const Display & _DISPLAY
    )
    {
        return _DISPLAY.height;
    }

    const DisplayModeKey & getModeKey(
        const Display & _DISPLAY
    )
    {
        return *( _DISPLAY.modeKeyUnique );
    }

    Bool setModeKey(
        Display &                   _display
        , const DisplayModeKey &    _MODE_KEY
    )
    {
        if( getWidthAndHeightFromModeKey(
            _display.width
            , _display.height
            , _MODE_KEY
        ) == false ) {
            return false;
        }

        auto    modeKeyUnique = unique(
            clone(
                _MODE_KEY
            )
        );
        if( modeKeyUnique.get() == nullptr ) {
            return false;
        }

        _display.modeKeyUnique = std::move( modeKeyUnique );

        return true;
    }

    Int getX(
        const Display & _DISPLAY
    )
    {
        return _DISPLAY.x;
    }

    void setX(
        Display &   _display
        , Int       _x
    )
    {
        _display.x = _x;
    }

    Int getY(
        const Display & _DISPLAY
    )
    {
        return _DISPLAY.y;
    }

    void setY(
        Display &   _display
        , Int       _y
    )
    {
        _display.y = _y;
    }

    DisplayRotate getRotate(
        const Display & _DISPLAY
    )
    {
        return _DISPLAY.rotate;
    }

    void setRotate(
        Display &       _display
        , DisplayRotate _rotate
    )
    {
        _display.rotate = _rotate;
    }
}
