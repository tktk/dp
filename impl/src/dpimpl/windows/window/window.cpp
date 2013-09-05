#include "dpimpl/util/export.h"
#include "dp/window/window.h"

#include "dpimpl/windows/window/window.h"
#include "dp/window/windowflags.h"
#include "dp/common/primitives.h"

namespace dp {
    Bool initializeWindowImpl(
        Window &        _window
        , const Utf32 & _TITLE
        , ULong         _width
        , ULong         _height
        , WindowFlags   _flags
    )
    {
        //TODO
        return false;
    }

    Bool initializeWindowImpl(
        Window &        _window
        , const Utf32 & _TITLE
        , Long          _x
        , Long          _y
        , ULong         _width
        , ULong         _height
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
        , Long      _x
        , Long      _y
    )
    {
        //TODO
    }

    void setSize(
        Window &    _window
        , ULong     _width
        , ULong     _height
    )
    {
        //TODO
    }

    void repaint(
        Window &    _window
        , ULong     _x
        , ULong     _y
        , ULong     _width
        , ULong     _height
    )
    {
        //TODO
    }
}
