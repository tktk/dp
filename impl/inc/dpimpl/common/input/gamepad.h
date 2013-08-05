#ifndef DPIMPL_COMMON_INPUT_GAMEPAD_H
#define DPIMPL_COMMON_INPUT_GAMEPAD_H

#include "dp/input/gamepad.h"

#include <mutex>

namespace dp {
    struct GamePad
    {
        GamePadInfoUnique   infoUnique;
        std::mutex          mutexForButtonEventHandler;
        std::mutex          mutexForAxisEventHandler;

        //TODO implUnique
    };
}

#endif  // DPIMPL_COMMON_INPUT_GAMEPAD_H
