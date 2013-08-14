#include "dpimpl/util/export.h"
#include "dp/display/displaymode.h"

#include "dpimpl/linux/display/x11.h"
#include "dpimpl/common/display/displaymode.h"
#include "dpimpl/linux/display/displaymodekey.h"
#include "dp/display/displaymodekey.h"
#include "dp/common/primitives.h"

#include "dpimpl/linux/display/xrandr.h"

namespace {
    const XRRModeInfo * getXRRModeInfo(
        const XRRScreenResources &  _SCREEN_RESOURCES
        , const RRMode &            _MODE
    )
    {
        const auto &    MODE_INFOS = _SCREEN_RESOURCES.modes;

        auto    modeInfosCount = _SCREEN_RESOURCES.nmode;

        for( decltype( modeInfosCount ) i = 0 ; i < modeInfosCount ; i++ ) {
            const auto &    MODE_INFO = MODE_INFOS[ i ];

            if( MODE_INFO.id == _MODE ) {
                return &MODE_INFO;
            }
        }

        return nullptr;
    }
}

namespace dp {
    DisplayMode * displayModeNew(
        const DisplayModeKey &  _MODE_KEY
    )
    {
        DisplayModeUnique   modeUnique( new( std::nothrow )DisplayMode );
        if( modeUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  mode = *modeUnique;

        auto &  x11Display = getX11Display();
        auto &  x11Window = getX11Window();

        ScreenResourcesUnique   screenResourcesUnique(
            screenResourcesNew(
                x11Display
                , x11Window
            )
        );
        if( screenResourcesUnique.get() == nullptr ) {
            return nullptr;
        }

        const auto &    SCREEN_RESOURCES = *screenResourcesUnique;

        const auto  MODE_INFO_PTR = getXRRModeInfo(
            SCREEN_RESOURCES
            , _MODE_KEY.mode
        );
        if( MODE_INFO_PTR == nullptr ) {
            return nullptr;
        }

        const auto &    MODE_INFO = *MODE_INFO_PTR;

        mode.width = MODE_INFO.width;
        mode.height = MODE_INFO.height;

        const auto &    DOT_CLOCK = MODE_INFO.dotClock;
        const auto &    H_TOTAL = MODE_INFO.hTotal;
        const auto &    V_TOTAL = MODE_INFO.vTotal;

        mode.refreshRate = static_cast< Float >( DOT_CLOCK ) / ( static_cast< Float >( H_TOTAL ) * static_cast< Float >( V_TOTAL ) );

        return modeUnique.release();
    }

    Bool displayModeGetWidthAndHeightFromModeKey(
        const DisplayModeKey &  _MODE_KEY
        , ULong &               _width
        , ULong &               _height
    )
    {
        auto &  x11Display = getX11Display();
        auto &  x11Window = getX11Window();

        ScreenResourcesUnique   screenResourcesUnique(
            screenResourcesNew(
                x11Display
                , x11Window
            )
        );
        if( screenResourcesUnique.get() == nullptr ) {
            return false;
        }

        const auto &    SCREEN_RESOURCES = *screenResourcesUnique;

        const auto  MODE_INFO_PTR = getXRRModeInfo(
            SCREEN_RESOURCES
            , _MODE_KEY.mode
        );
        if( MODE_INFO_PTR == nullptr ) {
            return false;
        }

        const auto &    MODE_INFO = *MODE_INFO_PTR;

        _width = MODE_INFO.width;
        _height = MODE_INFO.height;

        return true;
    }
}
