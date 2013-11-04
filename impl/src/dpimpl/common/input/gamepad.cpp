#include "dp/util/export.h"
#include "dp/input/gamepad.h"

#include "dpimpl/common/input/gamepad.h"
#include "dpimpl/common/input/gamepadinfo.h"
#include "dp/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <new>

template<>
void dpFree(
    const dp::GamePad & _GAME_PAD
)
{
    delete &_GAME_PAD;
}

template<>
void dpFree(
    const dp::GamePadImpl & _IMPL
)
{
    delete &_IMPL;
}

namespace dp {
    GamePad * newGamePad(
        const GamePadKey &      _KEY
        , const GamePadInfo &   _INFO
    )
    {
        auto    gamePadUnique = unique( new( std::nothrow )GamePad );
        if( gamePadUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  gamePad = *gamePadUnique;

        auto &  infoUnique = gamePad.infoUnique;
        infoUnique.reset(
            clone(
                _INFO
            )
        );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  implUnique = gamePad.implUnique;
        implUnique.reset( new( std::nothrow )GamePadImpl );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        if( initializeGamePadImpl(
            gamePad
            , _KEY
        ) == false ) {
            return nullptr;
        }

        return gamePadUnique.release();
    }

    void callButtonEventHandler(
        GamePad &   _gamePad
        , ULong     _index
        , Bool      _pressed
    )
    {
        const auto &    EVENT_HANDLER = _gamePad.infoUnique->buttonEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _gamePad
                , _index
                , _pressed
            );
        }
    }

    void callAxisEventHandler(
        GamePad &   _gamePad
        , ULong     _index
        , Long      _value
    )
    {
        const auto &    EVENT_HANDLER = _gamePad.infoUnique->axisEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _gamePad
                , _index
                , _value
            );
        }
    }
}
