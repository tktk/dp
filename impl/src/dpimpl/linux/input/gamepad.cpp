#include "dpimpl/util/export.h"
#include "dp/input/gamepad.h"

#include "dpimpl/linux/input/gamepad.h"
#include "dpimpl/common/input/gamepad.h"
#include "dpimpl/linux/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <new>
#include <fcntl.h>
#include <utility>

namespace {
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
        //TODO
        return false;
    }

    Bool gamePadGetButtons(
        const GamePad & _GAME_PAD
        , ULong &       _buttons
    )
    {
        //TODO
        return false;
    }

    Bool gamePadGetAxes(
        const GamePad & _GAME_PAD
        , ULong &       _axes
    )
    {
        //TODO
        return false;
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
