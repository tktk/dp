#ifndef DP_WINDOW_WINDOW_H
#define DP_WINDOW_WINDOW_H

#include "dp/window/windowflags.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"
#include "dp/util/import.h"

#include <mutex>
#include <functional>
#include <memory>

namespace dp {
    struct Window;

    struct WindowInfo;

    typedef std::function<
        void(
            Window &
        )
    > WindowCloseEventHandler;

    typedef std::function<
        void(
            Window &
            , Long
            , Long
        )
    > WindowPositionEventHandler;

    typedef std::function<
        void(
            Window &
            , ULong
            , ULong
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
            , ULong
            , ULong
            , ULong
            , ULong
        )
    > WindowPaintEventHandler;

    DPEXPORT Window * newWindow(
        const WindowInfo &
        , const Utf32 &
        , ULong
        , ULong
    );

    DPEXPORT Window * newWindow(
        const WindowInfo &
        , const Utf32 &
        , ULong
        , ULong
        , WindowFlags
    );

    DPEXPORT Window * newWindow(
        const WindowInfo &
        , const Utf32 &
        , Long
        , Long
        , ULong
        , ULong
    );

    DPEXPORT Window * newWindow(
        const WindowInfo &
        , const Utf32 &
        , Long
        , Long
        , ULong
        , ULong
        , WindowFlags
    );

    DPEXPORT void free(
        Window &
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
        , Long
        , Long
    );

    DPEXPORT void setSize(
        Window &
        , ULong
        , ULong
    );

    DPEXPORT void repaint(
        Window &
        , ULong
        , ULong
        , ULong
        , ULong
    );

    DPEXPORT WindowInfo * newWindowInfo(
    );

    DPEXPORT WindowInfo * clone(
        const WindowInfo &
    );

    DPEXPORT void free(
        WindowInfo &
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

    typedef Unique< Window >::type WindowUnique;

    typedef std::shared_ptr< Window > WindowShared;

    typedef std::weak_ptr< Window > WindowWeak;

    typedef Unique< WindowInfo >::type WindowInfoUnique;

    typedef std::shared_ptr< WindowInfo > WindowInfoShared;

    typedef std::weak_ptr< WindowInfo > WindowInfoWeak;
}

#endif  // DP_WINDOW_WINDOW_H
