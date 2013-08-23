#include "dpimpl/util/export.h"
#include "dp/window/window.h"

#include "dpimpl/common/window/window.h"
#include "dp/common/primitives.h"

#include <new>

namespace dp {
    Window * newWindow(
        const WindowInfo &  _INFO
        , const Utf32 &     _TITLE
        , ULong             _width
        , ULong             _height
    )
    {
        WindowUnique    windowUnique( new( std::nothrow )Window );
        if( windowUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  window = *windowUnique;

        auto &  infoUnique = window.infoUnique;
        infoUnique.reset(
            clone(
                _INFO
            )
        );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  implUnique = window.implUnique;
        implUnique.reset(
            newWindowImpl(
                window
            )
        );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        return windowUnique.release();
    }

    void free(
        Window &    _window
    )
    {
        delete &_window;
    }
}
