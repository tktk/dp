#include "dpimpl/util/export.h"
#include "dp/input/gamepadmanager.h"

#include "dpimpl/common/input/gamepadmanagerinfo.h"

#include <new>

namespace {
    dp::GamePadManagerInfo * newGamePadManagerInfo(
        const dp::GamePadManagerConnectEventHandler &   _CONNECT_EVENT_HANDLER
    )
    {
        auto    infoUnique = dp::unique( new( std::nothrow )dp::GamePadManagerInfo );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoUnique;

        info.connectEventHandler = _CONNECT_EVENT_HANDLER;

        return infoUnique.release();
    }
}

template<>
void free(
    const dp::GamePadManagerInfo &  _INFO
)
{
    delete &_INFO;
}

namespace dp {
    GamePadManagerInfo * newGamePadManagerInfo(
    )
    {
        return ::newGamePadManagerInfo(
            nullptr
        );
    }

    GamePadManagerInfo * clone(
        const GamePadManagerInfo &  _OTHER
    )
    {
        return ::newGamePadManagerInfo(
            _OTHER.connectEventHandler
        );
    }

    const GamePadManagerConnectEventHandler & getConnectEventHandler(
        const GamePadManagerInfo &  _INFO
    )
    {
        return _INFO.connectEventHandler;
    }

    void setConnectEventHandler(
        GamePadManagerInfo &                        _info
        , const GamePadManagerConnectEventHandler & _EVENT_HANDLER
    )
    {
        _info.connectEventHandler = _EVENT_HANDLER;
    }
}
