﻿#ifndef DP_WINDOW_WINDOW_H
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
    > WindowClosingEventHandler;

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

    //TODO ウィンドウに対する処理(タイトルやサイズの設定など)

    DPEXPORT WindowInfo * newWindowInfo(
    );

    DPEXPORT WindowInfo * clone(
        const WindowInfo &
    );

    DPEXPORT void free(
        WindowInfo &
    );

    DPEXPORT const WindowClosingEventHandler & getClosingEventHandler(
        const WindowInfo &
    );

    DPEXPORT void setClosingEventHandler(
        WindowInfo &
        , const WindowClosingEventHandler &
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

    //TODO 描画イベントのハンドラ取得、設定など

    typedef Unique< Window >::type WindowUnique;

    typedef std::shared_ptr< Window > WindowShared;

    typedef std::weak_ptr< Window > WindowWeak;

    typedef Unique< WindowInfo >::type WindowInfoUnique;

    typedef std::shared_ptr< WindowInfo > WindowInfoShared;

    typedef std::weak_ptr< WindowInfo > WindowInfoWeak;
}

#endif  // DP_WINDOW_WINDOW_H
