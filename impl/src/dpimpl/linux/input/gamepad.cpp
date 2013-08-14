﻿#include "dpimpl/util/export.h"
#include "dp/input/gamepad.h"

#include "dpimpl/linux/input/gamepad.h"
#include "dpimpl/common/input/gamepad.h"
#include "dpimpl/linux/input/gamepadkey.h"
#include "dp/common/stringconverter.h"
#include "dp/common/thread.h"
#include "dpimpl/linux/common/thread.h"
#include "dp/common/primitives.h"

#include <new>
#include <vector>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/joystick.h>
#include <utility>

namespace {
    const auto  MIN_NAME_LENGTH = 100;

    typedef std::vector< js_event > JsEvents;

    dp::Bool ioctlName(
        const dp::GamePad & _GAME_PAD
        , dp::Utf32 &       _result
    )
    {
        dp::String  buffer;

        dp::Int length = MIN_NAME_LENGTH;   // ioctl()の戻り値の型に合わせる

        while( 1 ) {
            buffer.resize( length );

            auto    result = ioctl(
                _GAME_PAD.implUnique->descriptor
                , JSIOCGNAME( length )
                , buffer.data()
            );
            if( result < 0 ) {
                return false;
            }

            if( result < length ) {
                break;
            }

            auto    newLength = length * 2;
            if( length > newLength ) {
                return false;
            }

            length = newLength;
        }

        if( dp::toUtf32(
            _result
            , buffer
        ) == false ) {
            return false;
        }

        return true;
    }

    dp::Bool ioctlUByte(
        const dp::GamePad & _GAME_PAD
        , dp::Int           _request
        , dp::UByte &       _result
    )
    {
        if( ioctl(
            _GAME_PAD.implUnique->descriptor
            , _request
            , &_result
        ) != 0 ) {
            return false;
        }

        return true;
    }

    template< typename T >
    dp::Bool ioctlUByte(
        const dp::GamePad & _GAME_PAD
        , dp::Int           _request
        , T &               _result
    )
    {
        dp::UByte   value;

        if( ioctlUByte(
            _GAME_PAD
            , _request
            , value
        ) == false ) {
            return false;
        }

        _result = value;

        return true;
    }

    void callButtonEventHandler(
        dp::GamePad &   _gamePad
        , dp::UByte     _index
        , dp::Short     _value
    )
    {
        const auto  PRESSED = _value != 0;

        gamePadCallButtonEventHandler(
            _gamePad
            , _index
            , PRESSED
        );
    }

    void callAxisEventHandler(
        dp::GamePad &   _gamePad
        , dp::UByte     _index
        , dp::Short     _value
    )
    {
        gamePadCallAxisEventHandler(
            _gamePad
            , _index
            , _value
        );
    }

    void callEventHandler(
        dp::GamePad &                   _gamePad
        , const JsEvents::value_type &  _JS_EVENT
    )
    {
        const auto &    INDEX = _JS_EVENT.number;

        const auto      TYPE = _JS_EVENT.type & ~JS_EVENT_INIT; // 初期化フラグを排除
        const auto &    VALUE = _JS_EVENT.value;

        switch( TYPE ) {
        case JS_EVENT_BUTTON:
            callButtonEventHandler(
                _gamePad
                , INDEX
                , VALUE
            );
            break;

        case JS_EVENT_AXIS:
            callAxisEventHandler(
                _gamePad
                , INDEX
                , VALUE
            );
            break;

        default:
            // ここに到達することはない
            break;
        }
    }

    void callEventHandlers(
        dp::GamePad &       _gamePad
        , const JsEvents &  _JS_EVENTS
    )
    {
        for( const auto & JS_EVENT : _JS_EVENTS ) {
            callEventHandler(
                _gamePad
                , JS_EVENT
            );
        }
    }

    const auto  BUFFER_COUNT = 10;

    void threadEventLoop(
        dp::GamePadImpl &   _impl
        , JsEvents &        _jsEvents
    )
    {
        auto &  mutex = _impl.mutex;
        auto &  cond = _impl.cond;

        const auto &    DESCRIPTOR = _impl.descriptor;

        while( 1 ) {
            JsEvents::value_type    jsEvent;

            auto    readSize = read(
                DESCRIPTOR
                , &jsEvent
                , sizeof( jsEvent )
            );
            if( readSize <= 0 ) {
                break;
            }

            std::unique_lock< std::mutex >  lock( mutex );

            _jsEvents.push_back( jsEvent );

            cond.notify_one();
        }
    }

    void threadManageLoop(
        dp::GamePad &       _gamePad
        , dp::GamePadImpl & _impl
        , JsEvents &        _jsEventsForEventLoop
    )
    {
        auto &  mutex = _impl.mutex;
        auto &  cond = _impl.cond;
        auto &  ended = _impl.ended;

        while( 1 ) {
            JsEvents    jsEvents;

            {
                std::unique_lock< std::mutex >  lock( mutex );

                cond.wait(
                    lock
                    , [
                        &ended
                        , &_jsEventsForEventLoop
                    ]
                    {
                        return
                            ended == true ||
                            _jsEventsForEventLoop.empty() == false
                        ;
                    }
                );

                if( ended ) {
                    break;
                }

                std::swap(
                    jsEvents
                    , _jsEventsForEventLoop
                );
            }

            callEventHandlers(
                _gamePad
                , jsEvents
            );
        }
    }

    void threadProc(
        dp::GamePad &       _gamePad
        , dp::GamePadImpl & _impl
    )
    {
        JsEvents    jsEvents;

        std::thread eventThread(
            [
                &_impl
                , &jsEvents
            ]
            {
                threadEventLoop(
                    _impl
                    , jsEvents
                );
            }
        );
        dp::ThreadJoiner    threadJoiner( &eventThread );
        dp::ThreadCanceller threadCanceller( &eventThread );

        threadManageLoop(
            _gamePad
            , _impl
            , jsEvents
        );
    }

    void setEnd(
        dp::GamePadImpl &   _impl
    )
    {
        auto &  mutex = _impl.mutex;

        std::unique_lock< std::mutex >  lock( mutex );

        _impl.ended = true;

        _impl.cond.notify_one();
    }
}

namespace dp {
    Bool gamePadGetName(
        const GamePad & _GAME_PAD
        , Utf32 &       _name
    )
    {
        return ioctlName(
            _GAME_PAD
            , _name
        );
    }

    Bool gamePadGetButtons(
        const GamePad & _GAME_PAD
        , ULong &       _buttons
    )
    {
        return ioctlUByte(
            _GAME_PAD
            , JSIOCGBUTTONS
            , _buttons
        );
    }

    Bool gamePadGetAxes(
        const GamePad & _GAME_PAD
        , ULong &       _axes
    )
    {
        return ioctlUByte(
            _GAME_PAD
            , JSIOCGAXES
            , _axes
        );
    }

    GamePadImpl * gamePadImplNew(
        GamePad &               _gamePad
        , const GamePadKey &    _KEY
    )
    {
        GamePadImplUnique   implUnique( new( std::nothrow )GamePadImpl );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  impl = *implUnique;

        impl.ended = false;

        impl.descriptor = open(
            _KEY.path.c_str()
            , O_RDONLY
            , 0
        );
        if( impl.descriptor == -1 ) {
            return nullptr;
        }
        impl.descriptorCloser.reset( &( impl.descriptor ) );

        impl.thread = std::move(
            std::thread(
                [
                    &_gamePad
                    , &impl
                ]
                {
                    threadProc(
                        _gamePad
                        , impl
                    );
                }
            )
        );
        impl.threadJoiner.reset( &( impl.thread ) );

        return implUnique.release();
    }

    void gamePadImplDelete(
        GamePadImpl &   _impl
    )
    {
        setEnd(
            _impl
        );

        delete &_impl;
    }
}