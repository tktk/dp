#include "dpimpl/util/export.h"
#include "dp/input/gamepad.h"

#include "dpimpl/linux/input/gamepad.h"
#include "dpimpl/common/input/gamepad.h"
#include "dpimpl/linux/input/gamepadkey.h"
#include "dp/common/stringconverter.h"
#include "dp/common/primitives.h"

#include <new>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/joystick.h>
#include <utility>

namespace {
    const auto  MIN_NAME_LENGTH = 100;

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

    void threadProc(
        dp::GamePad &       _gamePad
        , dp::GamePadImpl & _impl
    )
    {
        //TODO
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
        delete &_impl;
    }
}
