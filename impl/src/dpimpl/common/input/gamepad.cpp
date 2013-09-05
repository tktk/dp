#include "dpimpl/util/export.h"
#include "dp/input/gamepad.h"

#include "dpimpl/common/input/gamepad.h"
#include "dpimpl/common/input/gamepadinfo.h"
#include "dp/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <new>

namespace dp {
    GamePad * newGamePad(
        const GamePadKey &      _KEY
        , const GamePadInfo &   _INFO
    )
    {
        GamePadUnique   gamePadUnique( new( std::nothrow )GamePad );
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

    void free(
        GamePad &   _gamePad
    )
    {
        delete &_gamePad;
    }

    const GamePadInfo & getInfo(
        const GamePad & _GAME_PAD
    )
    {
        return *( _GAME_PAD.infoUnique );
    }

    GamePadInfo & getInfoMutable(
        GamePad &   _gamePad
    )
    {
        return *( _gamePad.infoUnique );
    }

    std::mutex & getMutexForButtonEventHandler(
        GamePad &   _gamePad
    )
    {
        return _gamePad.mutexForButtonEventHandler;
    }

    std::mutex & getMutexForAxisEventHandler(
        GamePad &   _gamePad
    )
    {
        return _gamePad.mutexForAxisEventHandler;
    }

    void callButtonEventHandler(
        GamePad &   _gamePad
        , ULong     _index
        , Bool      _pressed
    )
    {
        std::unique_lock< decltype( _gamePad.mutexForButtonEventHandler ) > lock( _gamePad.mutexForButtonEventHandler );

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
        std::unique_lock< decltype( _gamePad.mutexForAxisEventHandler ) >   lock( _gamePad.mutexForAxisEventHandler );

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
