#include "dpimpl/util/export.h"
#include "dp/window/window.h"

#include "dpimpl/common/window/windowinfo.h"

#include <new>

namespace {
    dp::WindowInfo * newWindowInfo(
    )
    {
        dp::WindowInfoUnique    infoUnique( new( std::nothrow )dp::WindowInfo );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoUnique;

        //TODO

        return infoUnique.release();
    }
}

namespace dp {
    WindowInfo * newWindowInfo(
    )
    {
        return ::newWindowInfo(
        );
    }

    WindowInfo * clone(
        const WindowInfo &
    )
    {
        return ::newWindowInfo(
        );
    }

    void free(
        WindowInfo &    _info
    )
    {
        delete &_info;
    }
}
