#include "dpimpl/util/export.h"
#include "dp/window/window.h"

#include "dpimpl/common/window/window.h"
#include "dpimpl/common/window/windowinfo.h"
#include "dp/common/primitives.h"

#include <new>
#include <mutex>
#include <functional>

namespace {
    typedef std::function<
        dp::WindowImpl *(
            dp::Window &
        )
    > NewWindowImpl;

    struct NewWindowImplWithoutPosition
    {
    private:
        const dp::Utf32 &       TITLE;
        const dp::ULong &       WIDTH;
        const dp::ULong &       HEIGHT;
        const dp::WindowFlags & FLAGS;

    public:
        NewWindowImplWithoutPosition(
            const dp::Utf32 &           _TITLE
            , const dp::ULong &         _WIDTH
            , const dp::ULong &         _HEIGHT
            , const dp::WindowFlags &   _FLAGS
        )
            : TITLE( _TITLE )
            , WIDTH( _WIDTH )
            , HEIGHT( _HEIGHT )
            , FLAGS( _FLAGS )
        {
        }

        dp::WindowImpl * operator()(
            dp::Window &    _window
        ) const
        {
            return dp::newWindowImpl(
                _window
                , this->TITLE
                , this->WIDTH
                , this->HEIGHT
                , this->FLAGS
            );
        }
    };

    dp::Window * newWindow(
        const dp::WindowInfo &  _INFO
        , const NewWindowImpl & _newWindowImpl
    )
    {
        dp::WindowUnique    windowUnique( new( std::nothrow )dp::Window );
        if( windowUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  window = *windowUnique;

        auto &  infoUnique = window.infoUnique;
        infoUnique.reset(
            clone(
                _INFO
            )
        );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  implUnique = window.implUnique;
        implUnique.reset(
            _newWindowImpl(
                window
            )
        );
        if( implUnique.get() == nullptr ) {
            return nullptr;
        }

        return windowUnique.release();
    }
}

namespace dp {
    Window * newWindow(
        const WindowInfo &  _INFO
        , const Utf32 &     _TITLE
        , ULong             _width
        , ULong             _height
    )
    {
        return newWindow(
            _INFO
            , _TITLE
            , _width
            , _height
            , WindowFlags::PLAIN
        );
    }

    Window * newWindow(
        const WindowInfo &  _INFO
        , const Utf32 &     _TITLE
        , ULong             _width
        , ULong             _height
        , WindowFlags       _flags
    )
    {
        return newWindow(
            _INFO
            , NewWindowImplWithoutPosition(
                _TITLE
                , _width
                , _height
                , _flags
            )
        );
    }

    void free(
        Window &    _window
    )
    {
        delete &_window;
    }

    void callClosingEventHandler(
        Window &    _window
    )
    {
        std::unique_lock< decltype( _window.mutexForClosingEventHandler ) > lock( _window.mutexForClosingEventHandler );

        const auto &    EVENT_HANDLER = _window.infoUnique->closingEventHandler;
        if( EVENT_HANDLER != nullptr ) {
            EVENT_HANDLER(
                _window
            );
        }
    }
}
