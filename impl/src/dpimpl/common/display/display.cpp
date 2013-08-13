#include "dpimpl/util/export.h"
#include "dp/display/display.h"

#include "dpimpl/common/display/display.h"
#include "dp/display/displaymodekey.h"
#include "dpimpl/common/display/displaymodekey.h"
#include "dp/display/displayrotate.h"
#include "dp/common/primitives.h"

#include <new>

namespace {
    dp::Display * displayNew(
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
    Display * displayNew(
        const DisplayModeKey &  _MODE_KEY
        , Long                  _x
        , Long                  _y
        , DisplayRotate         _rotate
    )
    {
        DisplayUnique   displayUnique(
            ::displayNew(
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

        if( displayModeKeyGetWidthAndHeight(
            *( display.modeKeyUnique )
            , display.width
            , display.height
        ) == false ) {
            return nullptr;
        }

        return displayUnique.release();
    }

    Display * displayClone(
        const Display & _DISPLAY
    )
    {
        DisplayUnique   displayUnique(
            ::displayNew(
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

    void displayDelete(
        Display &   _display
    )
    {
        delete &_display;
    }

    ULong displayGetWidth(
        const Display & _DISPLAY
    )
    {
        return _DISPLAY.width;
    }

    ULong displayGetHeight(
        const Display & _DISPLAY
    )
    {
        return _DISPLAY.height;
    }

    const DisplayModeKey & displayGetModeKey(
        const Display & _DISPLAY
    )
    {
        return *( _DISPLAY.modeKeyUnique );
    }

    Bool displaySetModeKey(
        Display &                   _display
        , const DisplayModeKey &    _MODE_KEY
    )
    {
        if( displayModeKeyGetWidthAndHeight(
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

    Long displayGetX(
        const Display & _DISPLAY
    )
    {
        return _DISPLAY.x;
    }

    void displaySetX(
        Display &   _display
        , Long      _x
    )
    {
        _display.x = _x;
    }

    Long displayGetY(
        const Display & _DISPLAY
    )
    {
        return _DISPLAY.y;
    }

    void displaySetY(
        Display &   _display
        , Long      _y
    )
    {
        _display.y = _y;
    }

    DisplayRotate displayGetRotate(
        const Display & _DISPLAY
    )
    {
        return _DISPLAY.rotate;
    }

    void displaySetRotate(
        Display &       _display
        , DisplayRotate _rotate
    )
    {
        _display.rotate = _rotate;
    }
}
