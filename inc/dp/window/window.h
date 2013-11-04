#ifndef DP_WINDOW_WINDOW_H
#define DP_WINDOW_WINDOW_H

#include "dp/window/windowflags.h"
#include "dp/window/key.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"
#include "dp/util/struct.h"

#include <functional>

DPSTRUCT( dp, Window )

DPSTRUCT( dp, WindowInfo )

namespace dp {
    typedef std::function<
        void(
            Window &
        )
    > WindowCloseEventHandler;

    typedef std::function<
        void(
            Window &
            , Int
            , Int
        )
    > WindowPositionEventHandler;

    typedef std::function<
        void(
            Window &
            , Int
            , Int
        )
    > WindowSizeEventHandler;

    typedef std::function<
        void(
            Window &
        )
    > WindowBeginPaintEventHandler;

    typedef std::function<
        void(
            Window &
        )
    > WindowEndPaintEventHandler;

    typedef std::function<
        void(
            Window &
            , Int
            , Int
            , Int
            , Int
        )
    > WindowPaintEventHandler;

    typedef std::function<
        void(
            Window &
            , Key
            , const Utf32Char *
            , Bool
        )
    > WindowKeyEventHandler;

    typedef std::function<
        void(
            Window &
            , ULong
            , Bool
        )
    > WindowMouseButtonEventHandler;

    typedef std::function<
        void(
            Window &
            , Int
            , Int
        )
    > WindowMouseMotionEventHandler;

    DPEXPORT Window * newWindow(
        const WindowInfo &
        , const Utf32 &
        , Int
        , Int
    );

    DPEXPORT Window * newWindow(
        const WindowInfo &
        , const Utf32 &
        , Int
        , Int
        , WindowFlags
    );

    DPEXPORT Window * newWindow(
        const WindowInfo &
        , const Utf32 &
        , Int
        , Int
        , Int
        , Int
    );

    DPEXPORT Window * newWindow(
        const WindowInfo &
        , const Utf32 &
        , Int
        , Int
        , Int
        , Int
        , WindowFlags
    );

    DPEXPORT void close(
        Window &
    );

    DPEXPORT Bool setTitle(
        Window &
        , const Utf32 &
    );

    DPEXPORT void setPosition(
        Window &
        , Int
        , Int
    );

    DPEXPORT void setSize(
        Window &
        , Int
        , Int
    );

    DPEXPORT void repaint(
        Window &
        , Int
        , Int
        , Int
        , Int
    );

    DPEXPORT WindowInfo * newWindowInfo(
    );

    DPEXPORT WindowInfo * clone(
        const WindowInfo &
    );

    DPEXPORT const WindowCloseEventHandler & getCloseEventHandler(
        const WindowInfo &
    );

    DPEXPORT void setCloseEventHandler(
        WindowInfo &
        , const WindowCloseEventHandler &
    );

    DPEXPORT const WindowPositionEventHandler & getPositionEventHandler(
        const WindowInfo &
    );

    DPEXPORT void setPositionEventHandler(
        WindowInfo &
        , const WindowPositionEventHandler &
    );

    DPEXPORT const WindowSizeEventHandler & getSizeEventHandler(
        const WindowInfo &
    );

    DPEXPORT void setSizeEventHandler(
        WindowInfo &
        , const WindowSizeEventHandler &
    );

    DPEXPORT const WindowBeginPaintEventHandler & getBeginPaintEventHandler(
        const WindowInfo &
    );

    DPEXPORT void setBeginPaintEventHandler(
        WindowInfo &
        , const WindowBeginPaintEventHandler &
    );

    DPEXPORT const WindowEndPaintEventHandler & getEndPaintEventHandler(
        const WindowInfo &
    );

    DPEXPORT void setEndPaintEventHandler(
        WindowInfo &
        , const WindowEndPaintEventHandler &
    );

    DPEXPORT const WindowPaintEventHandler & getPaintEventHandler(
        const WindowInfo &
    );

    DPEXPORT void setPaintEventHandler(
        WindowInfo &
        , const WindowPaintEventHandler &
    );

    DPEXPORT const WindowKeyEventHandler & getKeyEventHandler(
        const WindowInfo &
    );

    DPEXPORT void setKeyEventHandler(
        WindowInfo &
        , const WindowKeyEventHandler &
    );

    DPEXPORT const WindowMouseButtonEventHandler & getMouseButtonEventHandler(
        const WindowInfo &
    );

    DPEXPORT void setMouseButtonEventHandler(
        WindowInfo &
        , const WindowMouseButtonEventHandler &
    );

    DPEXPORT const WindowMouseMotionEventHandler & getMouseMotionEventHandler(
        const WindowInfo &
    );

    DPEXPORT void setMouseMotionEventHandler(
        WindowInfo &
        , const WindowMouseMotionEventHandler &
    );

    typedef Unique< Window >::type WindowUnique;

    typedef Shared< Window >::type WindowShared;

    typedef Weak< Window >::type WindowWeak;

    typedef Unique< WindowInfo >::type WindowInfoUnique;

    typedef Shared< WindowInfo >::type WindowInfoShared;

    typedef Weak< WindowInfo >::type WindowInfoWeak;
}

#endif  // DP_WINDOW_WINDOW_H
