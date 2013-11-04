#include "dp/util/export.h"
#include "dp/window/window.h"

#include "dpimpl/windows/window/window.h"
#include "dp/window/windowflags.h"
#include "dp/common/primitives.h"

namespace dp {
    Bool initializeWindowImpl(
        Window &        _window
        , const Utf32 & _TITLE
        , Int           _width
        , Int           _height
        , WindowFlags   _flags
    )
    {
        //TODO
        return false;
    }

    Bool initializeWindowImpl(
        Window &        _window
        , const Utf32 & _TITLE
        , Int           _x
        , Int           _y
        , Int           _width
        , Int           _height
        , WindowFlags   _flags
    )
    {
        //TODO
        return false;
    }

    void close(
        Window &    _window
    )
    {
        //TODO
    }

    Bool setTitle(
        Window &        _window
        , const Utf32 & _TITLE
    )
    {
        //TODO

        return false;
    }

    void setPosition(
        Window &    _window
        , Int       _x
        , Int       _y
    )
    {
        //TODO
    }

    void setSize(
        Window &    _window
        , Int       _width
        , Int       _height
    )
    {
        //TODO
    }

    void repaint(
        Window &    _window
        , Int       _x
        , Int       _y
        , Int       _width
        , Int       _height
    )
    {
        //TODO
    }
}
