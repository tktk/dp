﻿#include "dpimpl/util/export.h"
#include "dp/display/displaykey.h"

#include "dpimpl/windows/display/displaykey.h"
#include "dp/common/primitives.h"

#include <new>

namespace {
    dp::DisplayKey * newDisplayKey(
        //TODO
    )
    {
        dp::DisplayKeyUnique    keyUnique( new( std::nothrow )dp::DisplayKey );
        if( keyUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  key = *keyUnique;

        //TODO

        return keyUnique.release();
    }
}

namespace dp {
    DisplayKey * clone(
        const DisplayKey &  _OTHER
    )
    {
        return ::newDisplayKey(
            //TODO
        );
    }

    Bool equals(
        const DisplayKey &      _KEY1
        , const DisplayKey &    _KEY2
    )
    {
        //TODO
        return false;
    }

    Bool less(
        const DisplayKey &      _KEY1
        , const DisplayKey &    _KEY2
    )
    {
        //TODO
        return false;
    }

    DisplayKey * newDisplayKey(
        //TODO
    )
    {
        return ::newDisplayKey(
            //TODO
        );
    }
}
