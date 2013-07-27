#include "dpimpl/util/export.h"
#include "dp/input/gamepadmanager.h"

#include "dpimpl/common/input/gamepadmanagerinfo.h"

#include <new>

namespace {
    dp::GamePadManagerInfo * gamePadManagerInfoNew(
        const dp::GamePadManagerConnectEventHandler &   _CONNECT_EVENT_HANDLER
    )
    {
        auto    info = new( std::nothrow )dp::GamePadManagerInfo;

        info->connectEventHandler = _CONNECT_EVENT_HANDLER;

        return info;
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

    void gamePadManagerInfoCopy(
        GamePadManagerInfo &            _to
        , const GamePadManagerInfo &    _FROM
    )
    {
        _to.connectEventHandler = _FROM.connectEventHandler;
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
