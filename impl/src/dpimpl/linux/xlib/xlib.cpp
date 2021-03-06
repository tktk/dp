﻿#include "dp/util/export.h"
#include "dpimpl/linux/xlib/xlib.h"

#include <utility>

namespace {
    dp::XDisplayUnique  xDisplayUnique;
    ::Window            xRootWindow;
}

namespace dp {
    void initializeXlib(
    )
    {
        XInitThreads();

        xDisplayUnique.reset( newXDisplay() );
        if( xDisplayUnique.get() == nullptr ) {
            //FIXME 初期化失敗時の処理
            return;
        }

        auto &  xDisplay = *xDisplayUnique;

        xRootWindow = DefaultRootWindow( &xDisplay );
    }

    void finalizeXlib(
    )
    {
        auto    xDisplayUnique = std::move( ::xDisplayUnique );
    }

    ::Display & getXDisplay(
    )
    {
        return *xDisplayUnique;
    }

    ::Window & getXRootWindow(
    )
    {
        return xRootWindow;
    }
}
