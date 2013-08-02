#include "dpimpl/util/export.h"
#include "dp/input/gamepadmanager.h"

#include "dpimpl/common/input/gamepadmanagerinfo.h"

#include <new>

namespace {
    dp::GamePadManagerInfo * gamePadManagerInfoNew(
        const dp::GamePadManagerConnectEventHandler &   _CONNECT_EVENT_HANDLER
    )
    {
        dp::GamePadManagerInfoUnique    infoUnique( new( std::nothrow )dp::GamePadManagerInfo );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoUnique;

        info.connectEventHandler = _CONNECT_EVENT_HANDLER;

        return infoUnique.release();
    }
}

namespace dp {
    GamePadManagerInfo * gamePadManagerInfoNew(
    )
    {
        return ::gamePadManagerInfoNew(
            nullptr
        );
    }

    GamePadManagerInfo * gamePadManagerInfoClone(
        const GamePadManagerInfo &  _OTHER
    )
    {
        return ::gamePadManagerInfoNew(
            _OTHER.connectEventHandler
        );
    }

    void gamePadManagerInfoDelete(
        GamePadManagerInfo &    _info
    )
    {
        delete &_info;
    }

    const GamePadManagerConnectEventHandler & gamePadManagerInfoGetConnectEventHandler(
        const GamePadManagerInfo &  _INFO
    )
    {
        return _INFO.connectEventHandler;
    }

    void gamePadManagerInfoSetConnectEventHandler(
        GamePadManagerInfo &                        _info
        , const GamePadManagerConnectEventHandler & _EVENT_HANDLER
    )
    {
        _info.connectEventHandler = _EVENT_HANDLER;
    }
}
