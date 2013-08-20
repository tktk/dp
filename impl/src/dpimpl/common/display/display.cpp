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
        , dp::Long                  _x
        , dp::Long                  _y
        , dp::DisplayRotate         _rotate
    )
    {
        dp::DisplayUnique   displayUnique( new( std::nothrow )dp::Display );
        if( displayUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  display = *displayUnique;

        auto &  modeKeyUnique = display.modeKeyUnique;
        modeKeyUnique.reset(
            dp::displayModeKeyClone(
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

namespace dp {
    Display * newDisplay(
        const DisplayModeKey &  _MODE_KEY
        , Long                  _x
        , Long                  _y
        , DisplayRotate         _rotate
    )
    {
        DisplayUnique   displayUnique(
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

        if( displayModeGetWidthAndHeightFromModeKey(
            *( display.modeKeyUnique )
            , display.width
            , display.height
        ) == false ) {
            return nullptr;
        }

        return displayUnique.release();
    }

    Display * clone(
        const Display & _DISPLAY
    )
    {
        DisplayUnique   displayUnique(
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

    void free(
        Display &   _display
    )
    {
        delete &_display;
    }

    ULong getWidth(
        const Display & _DISPLAY
    )
    {
        return _DISPLAY.width;
    }

    ULong getHeight(
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
        if( displayModeGetWidthAndHeightFromModeKey(
            _MODE_KEY
            , _display.width
            , _display.height
        ) == false ) {
            return false;
        }

        DisplayModeKeyUnique    modeKeyUnique(
            displayModeKeyClone(
                _MODE_KEY
            )
        );
        if( modeKeyUnique.get() == nullptr ) {
            return false;
        }

        _display.modeKeyUnique = std::move( modeKeyUnique );

        return true;
    }

    Long getX(
        const Display & _DISPLAY
    )
    {
        return _DISPLAY.x;
    }

    void setX(
        Display &   _display
        , Long      _x
    )
    {
        _display.x = _x;
    }

    Long getY(
        const Display & _DISPLAY
    )
    {
        return _DISPLAY.y;
    }

    void setY(
        Display &   _display
        , Long      _y
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
