﻿#include "dpimpl/util/export.h"
#include "dp/window/window.h"

#include "dpimpl/common/window/windowinfo.h"

#include <new>

namespace {
    dp::WindowInfo * newWindowInfo(
        const dp::WindowCloseEventHandler &         _CLOSE_EVENT_HANDLER
        , const dp::WindowPositionEventHandler &    _POSITION_EVENT_HANDLER
        , const dp::WindowSizeEventHandler &        _SIZE_EVENT_HANDLER
        , const dp::WindowBeginPaintEventHandler &  _BEGIN_PAINT_EVENT_HANDLER
        , const dp::WindowEndPaintEventHandler &    _END_PAINT_EVENT_HANDLER
        , const dp::WindowPaintEventHandler &       _PAINT_EVENT_HANDLER
    )
    {
        dp::WindowInfoUnique    infoUnique( new( std::nothrow )dp::WindowInfo );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoUnique;

        info.closeEventHandler = _CLOSE_EVENT_HANDLER;
        info.positionEventHandler = _POSITION_EVENT_HANDLER;
        info.sizeEventHandler = _SIZE_EVENT_HANDLER;
        info.beginPaintEventHandler = _BEGIN_PAINT_EVENT_HANDLER;
        info.endPaintEventHandler = _END_PAINT_EVENT_HANDLER;
        info.paintEventHandler = _PAINT_EVENT_HANDLER;

        return infoUnique.release();
    }
}

namespace dp {
    WindowInfo * newWindowInfo(
    )
    {
        return ::newWindowInfo(
            nullptr
            , nullptr
            , nullptr
            , nullptr
            , nullptr
            , nullptr
        );
    }

    WindowInfo * clone(
        const WindowInfo &  _OTHER
    )
    {
        return ::newWindowInfo(
            _OTHER.closeEventHandler
            , _OTHER.positionEventHandler
            , _OTHER.sizeEventHandler
            , _OTHER.beginPaintEventHandler
            , _OTHER.endPaintEventHandler
            , _OTHER.paintEventHandler
        );
    }

    void free(
        WindowInfo &    _info
    )
    {
        delete &_info;
    }

    const WindowCloseEventHandler & getCloseEventHandler(
        const WindowInfo &  _INFO
    )
    {
        return _INFO.closeEventHandler;
    }

    void setCloseEventHandler(
        WindowInfo &                        _info
        , const WindowCloseEventHandler &   _EVENT_HANDLER
    )
    {
        _info.closeEventHandler = _EVENT_HANDLER;
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

    const WindowBeginPaintEventHandler & getBeginPaintEventHandler(
        const WindowInfo &  _INFO
    )
    {
        return _INFO.beginPaintEventHandler;
    }

    void setBeginPaintEventHandler(
        WindowInfo &                            _info
        , const WindowBeginPaintEventHandler &  _EVENT_HANDLER
    )
    {
        _info.beginPaintEventHandler = _EVENT_HANDLER;
    }

    const WindowEndPaintEventHandler & getEndPaintEventHandler(
        const WindowInfo &  _INFO
    )
    {
        return _INFO.endPaintEventHandler;
    }

    void setEndPaintEventHandler(
        WindowInfo &                            _info
        , const WindowEndPaintEventHandler &    _EVENT_HANDLER
    )
    {
        _info.endPaintEventHandler = _EVENT_HANDLER;
    }

    const WindowPaintEventHandler & getPaintEventHandler(
        const WindowInfo &  _INFO
    )
    {
        return _INFO.paintEventHandler;
    }

    void setPaintEventHandler(
        WindowInfo &                        _info
        , const WindowPaintEventHandler &   _EVENT_HANDLER
    )
    {
        _info.paintEventHandler = _EVENT_HANDLER;
    }
}