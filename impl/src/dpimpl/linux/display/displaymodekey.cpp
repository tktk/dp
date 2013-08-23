#include "dpimpl/util/export.h"
#include "dp/display/displaymodekey.h"

#include "dpimpl/linux/display/displaymodekey.h"
#include "dpimpl/linux/display/displaykey.h"
#include "dp/common/primitives.h"

#include "dpimpl/linux/common/xlib.h"
#include "dpimpl/linux/display/xrandr.h"
#include <new>
#include <algorithm>

namespace {
    dp::DisplayModeKey * newDisplayModeKey(
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

    dp::Bool appendModeKeyUniques(
        dp::DisplayModeKeyUniques & _modeKeyUniques
        , ::Display &               _xDisplay
        , XRRScreenResources &      _screenResources
        , const RROutput &          _OUTPUT
    )
    {
        dp::OutputInfoUnique    outputInfoUnique(
            dp::newOutputInfo(
                _xDisplay
                , _screenResources
                , _OUTPUT
            )
        );
        if( outputInfoUnique.get() == nullptr ) {
            return false;
        }

        const auto &    OUTPUT_INFO = *outputInfoUnique;

        auto    modesCount = OUTPUT_INFO.nmode;

        for( decltype( modesCount ) i = 0 ; i < modesCount ; i++ ) {
            const auto &    MODE = OUTPUT_INFO.modes[ i ];

            const auto  END = _modeKeyUniques.end();

            if( std::find_if(
                _modeKeyUniques.begin()
                , END
                , [
                    &MODE
                ]
                (
                    const dp::DisplayModeKeyUnique &    _MODE_KEY_UNIQUE
                )
                {
                    const auto &    MODE_KEY = *_MODE_KEY_UNIQUE;

                    return MODE_KEY.mode == MODE;
                }
            ) != END ) {
                continue;
            }

            _modeKeyUniques.push_back(
                dp::DisplayModeKeyUnique(
                    dp::newDisplayModeKey(
                        MODE
                    )
                )
            );
        }

        return true;
    }
}

namespace dp {
    DisplayModeKey * clone(
        const DisplayModeKey &  _KEY
    )
    {
        return ::newDisplayModeKey(
            _KEY.mode
        );
    }

    Bool equals(
        const DisplayModeKey &      _KEY1
        , const DisplayModeKey &    _KEY2
    )
    {
        return _KEY1.mode == _KEY2.mode;
    }

    Bool less(
        const DisplayModeKey &      _KEY1
        , const DisplayModeKey &    _KEY2
    )
    {
        return _KEY1.mode < _KEY2.mode;
    }

    Bool enumDisplayModeKeyUniques(
        const DisplayKey &          _KEY
        , DisplayModeKeyUniques &   _modeKeyUniques
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

        CrtcInfoUnique  crtcInfoUnique(
            newCrtcInfo(
                xDisplay
                , screenResources
                , _KEY.crtc
            )
        );
        if( crtcInfoUnique.get() == nullptr ) {
            return false;
        }

        const auto &    CRTC_INFO = *crtcInfoUnique;

        auto    outputsCount = CRTC_INFO.noutput;

        for( decltype( outputsCount ) i = 0 ; i < outputsCount ; i++ ) {
            const auto &    OUTPUT = CRTC_INFO.outputs[ i ];

            if( appendModeKeyUniques(
                _modeKeyUniques
                , xDisplay
                , screenResources
                , OUTPUT
            ) == false ) {
                return false;
            }
        }

        std::sort(
            _modeKeyUniques.begin()
            , _modeKeyUniques.end()
            , Less< DisplayModeKeyUnique >()
        );

        return true;
    }

    DisplayModeKey * newDisplayModeKey(
        const RRMode &  _MODE
    )
    {
        return ::newDisplayModeKey(
            _MODE
        );
    }
}
