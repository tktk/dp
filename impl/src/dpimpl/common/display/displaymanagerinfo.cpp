#include "dpimpl/util/export.h"
#include "dp/display/displaymanager.h"

#include "dpimpl/common/display/displaymanagerinfo.h"

#include <new>

namespace {
    dp::DisplayManagerInfo * newDisplayManagerInfo(
        const dp::DisplayManagerConnectEventHandler &   _CONNECT_EVENT_HANDLER
    )
    {
        auto    infoUnique = dp::unique( new( std::nothrow )dp::DisplayManagerInfo );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoUnique;

        info.connectEventHandler = _CONNECT_EVENT_HANDLER;

        return infoUnique.release();
    }
}

namespace dp {
    DisplayManagerInfo * newDisplayManagerInfo(
    )
    {
        return ::newDisplayManagerInfo(
            nullptr
        );
    }

    DisplayManagerInfo * clone(
        const DisplayManagerInfo &  _OTHER
    )
    {
        return ::newDisplayManagerInfo(
            _OTHER.connectEventHandler
        );
    }

    void free(
        DisplayManagerInfo &    _info
    )
    {
        delete &_info;
    }

    const DisplayManagerConnectEventHandler & getConnectEventHandler(
        const DisplayManagerInfo &  _INFO
    )
    {
        return _INFO.connectEventHandler;
    }

    void setConnectEventHandler(
        DisplayManagerInfo &                        _info
        , const DisplayManagerConnectEventHandler & _EVENT_HANDLER
    )
    {
        _info.connectEventHandler = _EVENT_HANDLER;
    }
}
