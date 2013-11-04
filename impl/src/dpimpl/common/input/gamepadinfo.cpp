#include "dpimpl/util/export.h"
#include "dp/input/gamepad.h"

#include "dpimpl/common/input/gamepadinfo.h"

#include <new>

namespace {
    dp::GamePadInfo * newGamePadInfo(
        const dp::GamePadButtonEventHandler &   _BUTTON_EVENT_HANDLER
        , const dp::GamePadAxisEventHandler &   _AXIS_EVENT_HANDLER
    )
    {
        auto    infoUnique = dp::unique( new( std::nothrow )dp::GamePadInfo );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoUnique;

        info.buttonEventHandler = _BUTTON_EVENT_HANDLER;
        info.axisEventHandler = _AXIS_EVENT_HANDLER;

        return infoUnique.release();
    }
}

template<>
void dpFree(
    const dp::GamePadInfo & _INFO
)
{
    delete &_INFO;
}

namespace dp {
    GamePadInfo * newGamePadInfo(
    )
    {
        return ::newGamePadInfo(
            nullptr
            , nullptr
        );
    }

    GamePadInfo * clone(
        const GamePadInfo & _OTHER
    )
    {
        return ::newGamePadInfo(
            _OTHER.buttonEventHandler
            , _OTHER.axisEventHandler
        );
    }

    const GamePadButtonEventHandler & getButtonEventHandler(
        const GamePadInfo & _INFO
    )
    {
        return _INFO.buttonEventHandler;
    }

    void setButtonEventHandler(
        GamePadInfo &                       _info
        , const GamePadButtonEventHandler & _EVENT_HANDLER
    )
    {
        _info.buttonEventHandler = _EVENT_HANDLER;
    }

    const GamePadAxisEventHandler & getAxisEventHandler(
        const GamePadInfo & _INFO
    )
    {
        return _INFO.axisEventHandler;
    }

    void setAxisEventHandler(
        GamePadInfo &                       _info
        , const GamePadAxisEventHandler &   _EVENT_HANDLER
    )
    {
        _info.axisEventHandler = _EVENT_HANDLER;
    }
}
