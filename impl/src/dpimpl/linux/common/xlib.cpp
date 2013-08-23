#include "dpimpl/util/export.h"
#include "dpimpl/linux/common/xlib.h"

#include <utility>

namespace {
    dp::X11DisplayUnique    x11DisplayUnique;
    ::Window                x11Window;
}

namespace dp {
    void initializeXlib(
    )
    {
        x11DisplayUnique.reset( x11DisplayNew() );
        if( x11DisplayUnique.get() == nullptr ) {
            //FIXME 初期化失敗時の処理
            return;
        }

        auto &  x11Display = *x11DisplayUnique;

        x11Window = DefaultRootWindow( &x11Display );
    }

    void finalizeXlib(
    )
    {
        auto    x11DisplayUnique = std::move( ::x11DisplayUnique );
    }

    ::Display & getX11Display(
    )
    {
        return *x11DisplayUnique;
    }

    ::Window & getX11Window(
    )
    {
        return x11Window;
    }
}
