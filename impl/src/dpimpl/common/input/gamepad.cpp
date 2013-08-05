#include "dpimpl/util/export.h"
#include "dp/input/gamepad.h"

#include "dpimpl/common/input/gamepad.h"

#include <new>

namespace dp {
    GamePad * gamePadNew(
        const GamePadKey &
        , const GamePadInfo &
    )
    {
        GamePadUnique   gamePadUnique( new( std::nothrow )GamePad );
        if( gamePadUnique.get() == nullptr ) {
            return nullptr;
        }

        //TODO

        return gamePadUnique.release();
    }

    void gamePadDelete(
        GamePad &   _gamePad
    )
    {
        delete &_gamePad;
    }

    Bool gamePadGetName(
        const GamePad &
        , Utf32 &
    )
    {
        //TODO
        return false;
    }

    Bool gamePadGetButtons(
        const GamePad &
        , ULong &
    )
    {
        //TODO
        return false;
    }

    Bool gamePadGetAxes(
        const GamePad &
        , ULong &
    )
    {
        //TODO
        return false;
    }

    const GamePadInfo & gamePadGetInfo(
        const GamePad & _GAME_PAD
    )
    {
        return *( _GAME_PAD.infoUnique );
    }

    GamePadInfo & gamePadGetInfoMutable(
        GamePad &   _gamePad
    )
    {
        return *( _gamePad.infoUnique );
    }

    std::mutex & gamePadGetMutexForButtonEventHandler(
        GamePad &   _gamePad
    )
    {
        return _gamePad.mutexForButtonEventHandler;
    }

    std::mutex & gamePadGetMutexForAxisEventHandler(
        GamePad &   _gamePad
    )
    {
        return _gamePad.mutexForAxisEventHandler;
    }
}
