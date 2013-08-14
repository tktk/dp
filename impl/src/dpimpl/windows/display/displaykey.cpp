#include "dpimpl/util/export.h"
#include "dp/display/displaykey.h"

#include "dpimpl/windows/display/displaykey.h"
#include "dp/common/primitives.h"

#include <new>

namespace {
    dp::DisplayKey * displayKeyNew(
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
    DisplayKey * displayKeyClone(
        const DisplayKey &  _OTHER
    )
    {
        return ::displayKeyNew(
            //TODO
        );
    }

    Bool displayKeyEquals(
        const DisplayKey &      _KEY1
        , const DisplayKey &    _KEY2
    )
    {
        //TODO
        return false;
    }

    Bool displayKeyLess(
        const DisplayKey &      _KEY1
        , const DisplayKey &    _KEY2
    )
    {
        //TODO
        return false;
    }

    DisplayKey * displayKeyNew(
        //TODO
    )
    {
        return ::displayKeyNew(
            //TODO
        );
    }
}
