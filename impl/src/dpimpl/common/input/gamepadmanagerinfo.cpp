#include "dpimpl/util/export.h"
#include "dp/input/gamepadmanager.h"

#include "dpimpl/common/input/gamepadmanagerinfo.h"

#include <new>

namespace {
    dp::GamePadManagerInfo * gamePadManagerInfoNew(
        const dp::GamePadManagerConnectEventHandler &   _CONNECT_EVENT_HANDLER
    )
    {
        dp::GamePadManagerInfoPtr   infoPtr( new( std::nothrow )dp::GamePadManagerInfo );
        if( infoPtr.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoPtr;

        info.connectEventHandler = _CONNECT_EVENT_HANDLER;

        return infoPtr.release();
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
