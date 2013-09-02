#include "dpimpl/util/export.h"
#include "dp/window/window.h"

#include "dpimpl/common/window/windowinfo.h"

#include <new>

namespace {
    dp::WindowInfo * newWindowInfo(
        const dp::WindowClosingEventHandler &   _CLOSING_EVENT_HANDLER
    )
    {
        dp::WindowInfoUnique    infoUnique( new( std::nothrow )dp::WindowInfo );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoUnique;

        info.closingEventHandler = _CLOSING_EVENT_HANDLER;

        return infoUnique.release();
    }
}

namespace dp {
    WindowInfo * newWindowInfo(
    )
    {
        return ::newWindowInfo(
            nullptr
        );
    }

    WindowInfo * clone(
        const WindowInfo &  _OTHER
    )
    {
        return ::newWindowInfo(
            _OTHER.closingEventHandler
        );
    }

    void free(
        WindowInfo &    _info
    )
    {
        delete &_info;
    }

    const WindowClosingEventHandler & getClosingEventHandler(
        const WindowInfo &  _INFO
    )
    {
        return _INFO.closingEventHandler;
    }

    void setClosingEventHandler(
        WindowInfo &                        _info
        , const WindowClosingEventHandler & _EVENT_HANDLER
    )
    {
        _info.closingEventHandler = _EVENT_HANDLER;
    }

    const WindowPositionEventHandler & getPositionEventHandler(
        const WindowInfo &  _INFO
    )
    {
        return _INFO.positionEventHandler;
    }

    void setPositionEventHandler(
        WindowInfo &                            _info
        , const WindowPositionEventHandler &    _EVENT_HANDLER
    )
    {
        _info.positionEventHandler = _EVENT_HANDLER;
    }

    const WindowSizeEventHandler & getSizeEventHandler(
        const WindowInfo &  _INFO
    )
    {
        return _INFO.sizeEventHandler;
    }

    void setSizeEventHandler(
        WindowInfo &                        _info
        , const WindowSizeEventHandler &    _EVENT_HANDLER
    )
    {
        _info.sizeEventHandler = _EVENT_HANDLER;
    }
}
