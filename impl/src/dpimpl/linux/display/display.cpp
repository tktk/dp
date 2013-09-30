#include "dpimpl/util/export.h"
#include "dp/display/display.h"

#include "dpimpl/common/display/display.h"
#include "dpimpl/common/display/displaykey.h"
#include "dpimpl/linux/display/displaymodekey.h"
#include "dp/display/displaymodekey.h"
#include "dp/display/displayrotate.h"
#include "dp/common/primitives.h"

#include "dpimpl/linux/xlib/xlib.h"
#include "dpimpl/linux/display/xrandr.h"
#include <new>

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
    Display * newDisplay(
        const DisplayKey &  _KEY
    )
    {
        DisplayUnique   displayUnique( new( std::nothrow )Display );
        if( displayUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  display = *displayUnique;

        auto &  xDisplay = getXDisplay();
        auto &  xRootWindow = getXRootWindow();

        ScreenResourcesUnique   screenResourcesUnique(
            newScreenResources(
                xDisplay
                , xRootWindow
            )
        );
        if( screenResourcesUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  screenResources = *screenResourcesUnique;

        CrtcInfoUnique  crtcInfoUnique(
            newCrtcInfo(
                xDisplay
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
            newDisplayModeKey(
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

    Bool apply(
        const DisplayKey &  _KEY
        , const Display &   _DISPLAY
    )
    {
        auto &  xDisplay = getXDisplay();
        auto &  xRootWindow = getXRootWindow();

        ScreenResourcesUnique   screenResourcesUnique(
            newScreenResources(
                xDisplay
                , xRootWindow
            )
        );
        if( screenResourcesUnique.get() == nullptr ) {
            return false;
        }

        auto &  screenResources = *screenResourcesUnique;

        const auto &    CRTC = _KEY.crtc;

        CrtcInfoUnique  crtcInfoUnique(
            newCrtcInfo(
                xDisplay
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
            &xDisplay
            , &screenResources
            , CRTC
            , CurrentTime
            , _DISPLAY.x
            , _DISPLAY.y
            , _DISPLAY.modeKeyUnique->mode
            , rotation
            , CRTC_INFO.outputs
            , CRTC_INFO.noutput
        ) != 0 ) {
            return false;
        }

        return true;
    }
}
