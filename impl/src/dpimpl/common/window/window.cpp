﻿#include "dpimpl/util/export.h"
#include "dp/window/window.h"

#include "dpimpl/common/window/window.h"
#include "dpimpl/common/window/windowinfo.h"
#include "dp/window/key.h"
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
        , Int               _width
        , Int               _height
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
        , Int               _width
        , Int               _height
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
        , Int               _x
        , Int               _y
        , Int               _width
        , Int               _height
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
        , Int               _x
        , Int               _y
        , Int               _width
        , Int               _height
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

    const WindowInfo & getInfo(
        const Window &  _WINDOW
    )
    {
        return *( _WINDOW.infoUnique );
    }

    WindowInfo & getInfoMutable(
        Window &    _window
    )
    {
        return *( _window.infoUnique );
    }

    std::mutex & getMutexForCloseEventHandler(
        Window &    _window
    )
    {
        return _window.mutexForCloseEventHandler;
    }

    std::mutex & getMutexForPositionEventHandler(
        Window &    _window
    )
    {
        return _window.mutexForPositionEventHandler;
    }

    std::mutex & getMutexForSizeEventHandler(
        Window &    _window
    )
    {
        return _window.mutexForSizeEventHandler;
    }

    std::mutex & getMutexForBeginPaintEventHandler(
        Window &    _window
    )
    {
        return _window.mutexForBeginPaintEventHandler;
    }

    std::mutex & getMutexForEndPaintEventHandler(
        Window &    _window
    )
    {
        return _window.mutexForEndPaintEventHandler;
    }

    std::mutex & getMutexForPaintEventHandler(
        Window &    _window
    )
    {
        return _window.mutexForPaintEventHandler;
    }

    std::mutex & getMutexForKeyEventHandler(
        Window &    _window
    )
    {
        return _window.mutexForKeyEventHandler;
    }

    std::mutex & getMutexForMouseButtonEventHandler(
        Window &    _window
    )
    {
        return _window.mutexForMouseButtonEventHandler;
    }

    std::mutex & getMutexForMouseMotionEventHandler(
        Window &    _window
    )
    {
        return _window.mutexForMouseMotionEventHandler;
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
        , Int       _x
        , Int       _y
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
        , Int       _width
        , Int       _height
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
        , Int       _x
        , Int       _y
        , Int       _width
        , Int       _height
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

    void callKeyEventHandler(
        Window &            _window
        , Key               _key
        , const Utf32Char * _char
        , Bool              _pressed
    )
    {
        std::unique_lock< decltype( _window.mutexForKeyEventHandler ) > lock( _window.mutexForKeyEventHandler );

        const auto &    EVENT_HANDLER = _window.infoUnique->keyEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _window
                , _key
                , _char
                , _pressed
            );
        }
    }

    void callMouseButtonEventHandler(
        Window &    _window
        , ULong     _index
        , Bool      _pressed
    )
    {
        std::unique_lock< decltype( _window.mutexForMouseButtonEventHandler ) > lock( _window.mutexForMouseButtonEventHandler );

        const auto &    EVENT_HANDLER = _window.infoUnique->mouseButtonEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _window
                , _index
                , _pressed
            );
        }
    }

    void callMouseMotionEventHandler(
        Window &    _window
        , ULong     _index
        , Int       _x
        , Int       _y
    )
    {
        std::unique_lock< decltype( _window.mutexForMouseMotionEventHandler ) > lock( _window.mutexForMouseMotionEventHandler );

        const auto &    EVENT_HANDLER = _window.infoUnique->mouseMotionEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _window
                , _index
                , _x
                , _y
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
