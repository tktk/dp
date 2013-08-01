#ifndef DPIMPL_LINUX_INPUT_GAMEPADKEY_H
#define DPIMPL_LINUX_INPUT_GAMEPADKEY_H

#include "dp/input/gamepadkey.h"
#include "dp/common/primitives.h"

namespace dp {
    struct GamePadKey
    {
        String  path;
    };

    GamePadKey * gamePadKeyNew(
        const StringChar *
    );

    const String & gamePadKeyGetPath(
        const GamePadKey &
    );
}

#endif  // DPIMPL_LINUX_INPUT_GAMEPADKEY_H
