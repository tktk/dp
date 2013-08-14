#include "dpimpl/util/export.h"
#include "dp/display/displaymanager.h"

#include "dpimpl/common/display/displaymanagerinfo.h"

#include <new>

namespace {
    dp::DisplayManagerInfo * displayManagerInfoNew(
        const dp::DisplayManagerConnectEventHandler &   _CONNECT_EVENT_HANDLER
    )
    {
        dp::DisplayManagerInfoUnique    infoUnique( new( std::nothrow )dp::DisplayManagerInfo );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoUnique;

        info.connectEventHandler = _CONNECT_EVENT_HANDLER;

        return infoUnique.release();
    }
}

namespace dp {
    DisplayManagerInfo * displayManagerInfoNew(
    )
    {
        return ::displayManagerInfoNew(
            nullptr
        );
    }

    DisplayManagerInfo * displayManagerInfoClone(
        const DisplayManagerInfo &  _OTHER
    )
    {
        return ::displayManagerInfoNew(
            _OTHER.connectEventHandler
        );
    }

    void displayManagerInfoDelete(
        DisplayManagerInfo &    _info
    )
    {
        delete &_info;
    }

    const DisplayManagerConnectEventHandler & displayManagerInfoGetConnectEventHandler(
        const DisplayManagerInfo &  _INFO
    )
    {
        return _INFO.connectEventHandler;
    }

    void displayManagerInfoSetConnectEventHandler(
        DisplayManagerInfo &                        _info
        , const DisplayManagerConnectEventHandler & _EVENT_HANDLER
    )
    {
        _info.connectEventHandler = _EVENT_HANDLER;
    }
}
