#include "dpimpl/util/export.h"
#include "dp/window/window.h"

#include "dpimpl/windows/window/window.h"
#include "dp/window/windowflags.h"
#include "dp/common/primitives.h"

namespace dp {
    WindowImpl * newWindowImpl(
        Window &        _window
        , const Utf32 & _TITLE
        , ULong         _width
        , ULong         _height
        , WindowFlags   _flags
    )
    {
        //TODO
        return nullptr;
    }

    WindowImpl * newWindowImpl(
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
        return nullptr;
    }

    void free(
        WindowImpl &    _impl
    )
    {
        //TODO
    }

    void close(
        Window &    _window
    )
    {
        //TODO
    }

    void setTitle(
        Window &        _window
        , const Utf32 & _TITLE
    )
    {
        //TODO
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
}
