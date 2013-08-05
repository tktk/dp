#include "dpimpl/util/export.h"
#include "dp/input/gamepad.h"

#include "dpimpl/common/input/gamepadinfo.h"

#include <new>

namespace {
    dp::GamePadInfo * gamePadInfoNew(
        dp::GamePadButtonEventHandler   _buttonEventHandler
        , dp::GamePadAxisEventHandler   _axisEventHandler
    )
    {
        dp::GamePadInfoUnique   infoUnique( new( std::nothrow )dp::GamePadInfo );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoUnique;

        info.buttonEventHandler = _buttonEventHandler;
        info.axisEventHandler = _axisEventHandler;

        return infoUnique.release();
    }
}

namespace dp {
    GamePadInfo * gamePadInfoNew(
    )
    {
        return ::gamePadInfoNew(
            nullptr
            , nullptr
        );
    }

    GamePadInfo * gamePadInfoClone(
        const GamePadInfo & _OTHER
    )
    {
        return ::gamePadInfoNew(
            _OTHER.buttonEventHandler
            , _OTHER.axisEventHandler
        );
    }

    void gamePadInfoDelete(
        GamePadInfo &   _info
    )
    {
        delete &_info;
    }

    const GamePadButtonEventHandler & gamePadInfoGetButtonEventHandler(
        const GamePadInfo & _INFO
    )
    {
        return _INFO.buttonEventHandler;
    }

    void gamePadInfoSetButtonEventHandler(
        GamePadInfo &                       _info
        , const GamePadButtonEventHandler & _EVENT_HANDLER
    )
    {
        _info.buttonEventHandler = _EVENT_HANDLER;
    }

    const GamePadAxisEventHandler & gamePadInfoGetAxisEventHandler(
        const GamePadInfo & _INFO
    )
    {
        return _INFO.axisEventHandler;
    }

    void gamePadInfoSetAxisEventHandler(
        GamePadInfo &                       _info
        , const GamePadAxisEventHandler &   _EVENT_HANDLER
    )
    {
        _info.axisEventHandler = _EVENT_HANDLER;
    }
}
