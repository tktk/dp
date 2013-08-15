﻿#include "dpimpl/util/export.h"
#include "dp/input/gamepadmanager.h"

#include "dpimpl/common/input/gamepadmanagerinfo.h"

#include <new>

namespace {
    dp::GamePadManagerInfo * newGamePadManagerInfo(
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

    void free(
        GamePadManagerInfo &    _info
    )
    {
        delete &_info;
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
