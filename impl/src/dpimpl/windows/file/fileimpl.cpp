#include "dpimpl/common/file/fileimpl.h"
#include "dp/common/primitives.h"

namespace dp {
    Bool read(
        FileImpl &  _impl
        , void *    _data
        , ULong     _size
        , ULong &   _count
    )
    {
        //TODO
        return false;
    }

    Bool read(
        FileImpl &  _impl
        , void *    _data
        , ULong &   _size
    )
    {
        //TODO
        return false;
    }

    Bool write(
        FileImpl &      _impl
        , const void *  _DATA
        , ULong         _size
        , ULong &       _count
    )
    {
        //TODO
        return false;
    }

    Bool write(
        FileImpl &      _impl
        , const void *  _DATA
        , ULong &       _size
    )
    {
        //TODO
        return false;
    }

    Bool getPosition(
        FileImpl &  _impl
        , Long &    _position
    )
    {
        //TODO
        return false;
    }

    Bool setPosition(
        FileImpl &  _impl
        , Long      _position
    )
    {
        //TODO
        return false;
    }

    Bool setPositionFromEnd(
        FileImpl &  _impl
        , Long      _position
    )
    {
        //TODO
        return false;
    }

    Bool movePosition(
        FileImpl &  _impl
        , Long      _position
    )
    {
        //TODO
        return false;
    }
}
