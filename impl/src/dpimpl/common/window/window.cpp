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
        dp::WindowImpl *(
            dp::Window &
        )
    > NewWindowImpl;

    dp::Window * newWindow(
        const dp::WindowInfo &  _INFO
        , const NewWindowImpl & _NEW_WINDOW_IMPL
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
        implUnique.reset(
            _NEW_WINDOW_IMPL(
                window
            )
        );
        if( implUnique.get() == nullptr ) {
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
                return dp::newWindowImpl(
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
                return dp::newWindowImpl(
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

    void callClosingEventHandler(
        Window &    _window
    )
    {
        std::unique_lock< decltype( _window.mutexForClosingEventHandler ) > lock( _window.mutexForClosingEventHandler );

        const auto &    EVENT_HANDLER = _window.infoUnique->closingEventHandler;
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
}
