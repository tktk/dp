#include "dpimpl/util/export.h"
#include "dp/display/display.h"

#include "dpimpl/linux/display/x11.h"
#include "dpimpl/common/display/display.h"
#include "dpimpl/common/display/displaykey.h"
#include "dpimpl/linux/display/displaymodekey.h"
#include "dp/display/displaymodekey.h"
#include "dp/display/displayrotate.h"
#include "dp/common/primitives.h"

#include <new>
#include "dpimpl/linux/display/xrandr.h"
#include "dpimpl/linux/common/xlib.h"

namespace {
    dp::Bool rotationToDisplayRotate(
        dp::DisplayRotate & _rotate
        , Rotation          _rotation
    )
    {
        switch( _rotation ) {
        case RR_Rotate_0:
            _rotate = dp::DisplayRotate::NORMAL;
            break;

        case RR_Rotate_90:
            _rotate = dp::DisplayRotate::LEFT;
            break;

        case RR_Rotate_180:
            _rotate = dp::DisplayRotate::INVERTED;
            break;

        case RR_Rotate_270:
            _rotate = dp::DisplayRotate::RIGHT;
            break;

        default:
            return false;
            break;
        }

        return true;
    }

    dp::Bool displayRotateToRotation(
        Rotation &          _rotation
        , dp::DisplayRotate _rotate
    )
    {
        switch( _rotate ) {
        case dp::DisplayRotate::NORMAL:
            _rotation = RR_Rotate_0;
            break;

        case dp::DisplayRotate::LEFT:
            _rotation = RR_Rotate_90;
            break;

        case dp::DisplayRotate::INVERTED:
            _rotation = RR_Rotate_180;
            break;

        case dp::DisplayRotate::RIGHT:
            _rotation = RR_Rotate_270;
            break;

        default:
            return false;
            break;
        }

        return true;
    }
}

namespace dp {
    Display * displayNewFromKey(
        const DisplayKey &  _KEY
    )
    {
        DisplayUnique   displayUnique( new( std::nothrow )Display );
        if( displayUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  display = *displayUnique;

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

        auto &  screenResources = *screenResourcesUnique;

        CrtcInfoUnique  crtcInfoUnique(
            crtcInfoNew(
                x11Display
                , screenResources
                , _KEY.crtc
            )
        );
        if( crtcInfoUnique.get() == nullptr ) {
            return nullptr;
        }

        const auto &    CRTC_INFO = *crtcInfoUnique;

        auto &  modeKeyUnique = display.modeKeyUnique;

        modeKeyUnique.reset(
            displayModeKeyNew(
                CRTC_INFO.mode
            )
        );
        if( modeKeyUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  rotate = display.rotate;

        if( rotationToDisplayRotate(
            rotate
            , CRTC_INFO.rotation
        ) == false ) {
            return nullptr;
        }

        display.x = CRTC_INFO.x;
        display.y = CRTC_INFO.y;
        display.width = CRTC_INFO.width;
        display.height = CRTC_INFO.height;

        return displayUnique.release();
    }

    Bool displayApply(
        const DisplayKey &  _KEY
        , const Display &   _DISPLAY
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

        auto &  screenResources = *screenResourcesUnique;

        const auto &    CRTC = _KEY.crtc;

        CrtcInfoUnique  crtcInfoUnique(
            crtcInfoNew(
                x11Display
                , screenResources
                , CRTC
            )
        );
        if( crtcInfoUnique.get() == nullptr ) {
            return false;
        }

        const auto &    CRTC_INFO = *crtcInfoUnique;

        if( CRTC_INFO.mode == None ) {
            return false;
        }

        Rotation    rotation;
        if( displayRotateToRotation(
            rotation
            , _DISPLAY.rotate
        ) == false ) {
            return false;
        }

        if( XRRSetCrtcConfig(
            &x11Display
            , &screenResources
            , CRTC
            , CurrentTime
            , _DISPLAY.x
            , _DISPLAY.y
            , displayGetModeKey( _DISPLAY ).mode
            , rotation
            , CRTC_INFO.outputs
            , CRTC_INFO.noutput
        ) != 0 ) {
            return false;
        }

        return true;
    }
}
