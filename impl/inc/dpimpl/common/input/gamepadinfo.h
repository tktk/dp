#ifndef DPIMPL_COMMON_INPUT_GAMEPADINFO_H
#define DPIMPL_COMMON_INPUT_GAMEPADINFO_H

#include "dp/input/gamepad.h"

namespace dp {
    struct GamePadInfo
    {
        GamePadButtonEventHandler   buttonEventHandler;
        GamePadAxisEventHandler     axisEventHandler;
    };
}

#endif  // DPIMPL_COMMON_INPUT_GAMEPADINFO_H
