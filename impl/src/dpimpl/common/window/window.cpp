#include "dpimpl/util/export.h"
#include "dp/window/window.h"

#include "dpimpl/common/window/window.h"
#include "dpimpl/common/window/windowinfo.h"
#include "dp/common/primitives.h"

#include <new>
#include <mutex>
#include <functional>

namespace {
    typedef std::function<
        dp::Bool(
            dp::Window &
        )
    > InitializeWindowImpl;

    dp::Window * newWindow(
        const dp::WindowInfo &          _INFO
        , const InitializeWindowImpl &  _INITIALIZE_WINDOW_IMPL
    )
    {
        dp::WindowUnique    windowUnique( new( std::nothrow )dp::Window );
        if( windowUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  window = *windowUnique;

        auto &  infoUnique = window.infoUnique;
        infoUnique.reset(
            clone(
                _INFO
            )
        );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  implUnique = window.implUnique;
        implUnique.reset( new( std::nothrow )dp::WindowImpl );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        if( _INITIALIZE_WINDOW_IMPL(
            window
        ) == false ) {
            return nullptr;
        }

        return windowUnique.release();
    }
}

namespace dp {
    Window * newWindow(
        const WindowInfo &  _INFO
        , const Utf32 &     _TITLE
        , ULong             _width
        , ULong             _height
    )
    {
        return newWindow(
            _INFO
            , _TITLE
            , _width
            , _height
            , WindowFlags::PLAIN
        );
    }

    Window * newWindow(
        const WindowInfo &  _INFO
        , const Utf32 &     _TITLE
        , ULong             _width
        , ULong             _height
        , WindowFlags       _flags
    )
    {
        return ::newWindow(
            _INFO
            , [
                &_TITLE
                , &_width
                , &_height
                , &_flags
            ]
            (
                dp::Window &    _window
            )
            {
                return dp::initializeWindowImpl(
                    _window
                    , _TITLE
                    , _width
                    , _height
                    , _flags
                );
            }
        );
    }

    Window * newWindow(
        const WindowInfo &  _INFO
        , const Utf32 &     _TITLE
        , Long              _x
        , Long              _y
        , ULong             _width
        , ULong             _height
    )
    {
        return newWindow(
            _INFO
            , _TITLE
            , _x
            , _y
            , _width
            , _height
            , WindowFlags::PLAIN
        );
    }

    Window * newWindow(
        const WindowInfo &  _INFO
        , const Utf32 &     _TITLE
        , Long              _x
        , Long              _y
        , ULong             _width
        , ULong             _height
        , WindowFlags       _flags
    )
    {
        return ::newWindow(
            _INFO
            , [
                &_TITLE
                , &_x
                , &_y
                , &_width
                , &_height
                , &_flags
            ]
            (
                dp::Window &    _window
            )
            {
                return dp::initializeWindowImpl(
                    _window
                    , _TITLE
                    , _x
                    , _y
                    , _width
                    , _height
                    , _flags
                );
            }
        );
    }

    void free(
        Window &    _window
    )
    {
        delete &_window;
    }

    void callCloseEventHandler(
        Window &    _window
    )
    {
        std::unique_lock< decltype( _window.mutexForCloseEventHandler ) >   lock( _window.mutexForCloseEventHandler );

        const auto &    EVENT_HANDLER = _window.infoUnique->closeEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _window
            );
        }
    }

    void callPositionEventHandler(
        Window &    _window
        , Long      _x
        , Long      _y
    )
    {
        std::unique_lock< decltype( _window.mutexForPositionEventHandler ) >    lock( _window.mutexForPositionEventHandler );

        const auto &    EVENT_HANDLER = _window.infoUnique->positionEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _window
                , _x
                , _y
            );
        }
    }

    void callSizeEventHandler(
        Window &    _window
        , ULong     _width
        , ULong     _height
    )
    {
        std::unique_lock< decltype( _window.mutexForSizeEventHandler ) >    lock( _window.mutexForSizeEventHandler );

        const auto &    EVENT_HANDLER = _window.infoUnique->sizeEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _window
                , _width
                , _height
            );
        }
    }

    void callBeginPaintEventHandler(
        Window &    _window
    )
    {
        std::unique_lock< decltype( _window.mutexForBeginPaintEventHandler ) >  lock( _window.mutexForBeginPaintEventHandler );

        const auto &    EVENT_HANDLER = _window.infoUnique->beginPaintEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _window
            );
        }
    }

    void callEndPaintEventHandler(
        Window &    _window
    )
    {
        std::unique_lock< decltype( _window.mutexForEndPaintEventHandler ) >    lock( _window.mutexForEndPaintEventHandler );

        const auto &    EVENT_HANDLER = _window.infoUnique->endPaintEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _window
            );
        }
    }

    void callPaintEventHandler(
        Window &    _window
        , ULong     _x
        , ULong     _y
        , ULong     _width
        , ULong     _height
    )
    {
        std::unique_lock< decltype( _window.mutexForPaintEventHandler ) >   lock( _window.mutexForPaintEventHandler );

        const auto &    EVENT_HANDLER = _window.infoUnique->paintEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _window
                , _x
                , _y
                , _width
                , _height
            );
        }
    }

    void free(
        WindowImpl &    _impl
    )
    {
        delete &_impl;
    }
}
