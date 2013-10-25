#include "dpimpl/util/export.h"
#include "dp/window/window.h"

#include "dpimpl/linux/window/window.h"
#include "dpimpl/common/window/window.h"
#include "dp/window/windowflags.h"
#include "dp/common/stringconverter.h"
#include "dp/common/primitives.h"

#include "dpimpl/linux/xlib/xlib.h"
#include "dpimpl/linux/window/xutil.h"
#include <X11/Xatom.h>
#include <thread>
#include <utility>
#include <errno.h>
#include <mutex>
#include <condition_variable>

namespace {
    Atom    WM_DELETE_WINDOW;

    Atom    _NET_WM_STATE;
    Atom    _NET_WM_STATE_ABOVE;

    struct Position
    {
        dp::Bool    initialized;
        dp::Int     x;
        dp::Int     y;

        Position(
        )
            : initialized( false )
        {
        }
    };

    struct Size
    {
        dp::Bool    initialized;
        dp::Int     width;
        dp::Int     height;

        Size(
        )
            : initialized( false )
        {
        }
    };

    struct Rect
    {
        dp::Int x;
        dp::Int y;
        dp::Int width;
        dp::Int height;

        Rect(
        )
            : width( 0 )
            , height( 0 )
        {
        }
    };

    void unresizable(
        ::Display &         _xDisplay
        , const ::Window &  _X_WINDOW
        , dp::Int           _width
        , dp::Int           _height
    )
    {
        XSizeHints  sizeHints;

        sizeHints.min_width = sizeHints.max_width = _width;
        sizeHints.min_height = sizeHints.max_height = _height;

        sizeHints.flags = PMaxSize | PMinSize;

        XSetWMNormalHints(
            &_xDisplay
            , _X_WINDOW
            , &sizeHints
        );
    }

    void alwaysOnTop(
        ::Display &         _xDisplay
        , const ::Window &  _X_WINDOW
    )
    {
        XChangeProperty(
            &_xDisplay
            , _X_WINDOW
            , _NET_WM_STATE
            , XA_ATOM
            , 32
            , PropModeReplace
            , reinterpret_cast< dp::UByte * >( &_NET_WM_STATE_ABOVE )
            , 1
        );
    }

    void setTitle(
        ::Display &             _xDisplay
        , const ::Window &      _X_WINDOW
        , const dp::String &    _TITLE_STRING
    )
    {
        XStoreName(
            &_xDisplay
            , _X_WINDOW
            , _TITLE_STRING.c_str()
        );
    }

    ::Bool isMainThreadEvent(
        ::Display *
        , XEvent *  _event
        , XPointer  _arg
    )
    {
        const auto &    WINDOW = *reinterpret_cast< const ::Window * >( _arg );

        return _event->xany.window == WINDOW;
    }

    dp::Bool copyWhenChanged(
        Size &          _size
        , const Size &  _SIZE_FROM_MAIN_THREAD
    )
    {
        const auto  CHANGED =
            _SIZE_FROM_MAIN_THREAD.initialized &&
            (
                _size.initialized == false ||
                _size.width != _SIZE_FROM_MAIN_THREAD.width ||
                _size.height != _SIZE_FROM_MAIN_THREAD.height
            )
        ;

        if( CHANGED ) {
            _size = _SIZE_FROM_MAIN_THREAD;
        }

        return CHANGED;
    }

    void copyAndClear(
        Rect &      _invalidateRect
        , Rect &    _invalidateRectFromMainThread
    )
    {
        _invalidateRect = _invalidateRectFromMainThread;

        // 幅を0にして無効領域を初期化
        _invalidateRectFromMainThread.width = 0;
    }

    void waitPaintThread(
        std::mutex &                _mutex
        , std::condition_variable & _cond
        , const Size &              _SIZE_FROM_MAIN_THREAD
        , Rect &                    _invalidateRectFromMainThread
        , const dp::Bool &          _ENDED
        , Size &                    _size
        , dp::Bool &                _sizeChanged
        , Rect &                    _invalidateRect
        , dp::Bool &                _exposed
    )
    {
        std::unique_lock< std::mutex >  lock( _mutex );

        _cond.wait(
            lock
            , [
                &_SIZE_FROM_MAIN_THREAD
                , &_invalidateRectFromMainThread
                , &_ENDED
                , &_size
                , &_sizeChanged
                , &_invalidateRect
                , &_exposed
            ]
            {
                _sizeChanged = copyWhenChanged(
                    _size
                    , _SIZE_FROM_MAIN_THREAD
                );

                copyAndClear(
                    _invalidateRect
                    , _invalidateRectFromMainThread
                );

                _exposed = _invalidateRect.width > 0 && _invalidateRect.height > 0;

                return _ENDED || _sizeChanged || _exposed;
            }
        );
    }

    void paintThreadProcMainLoop(
        dp::Window &                _window
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , const Size &              _SIZE_FROM_MAIN_THREAD
        , Rect &                    _invalidateRectFromMainThread
    )
    {
        auto &  impl = *( _window.implUnique );

        const auto &    ENDED = impl.ended;

        Size        size;
        dp::Bool    sizeChanged;

        Rect        invalidateRect;
        dp::Bool    exposed;

        while( 1 ) {
            waitPaintThread(
                _mutex
                , _cond
                , _SIZE_FROM_MAIN_THREAD
                , _invalidateRectFromMainThread
                , ENDED
                , size
                , sizeChanged
                , invalidateRect
                , exposed
            );

            if( ENDED ) {
                break;
            }

            if( sizeChanged ) {
                dp::callSizeEventHandler(
                    _window
                    , size.width
                    , size.height
                );
            }

            if( exposed ) {
                dp::callPaintEventHandler(
                    _window
                    , invalidateRect.x
                    , invalidateRect.y
                    , invalidateRect.width
                    , invalidateRect.height
                );
            }
        }
    }

    void paintThreadProc(
        dp::Window &                _window
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , const Size &              _SIZE_FROM_MAIN_THREAD
        , Rect &                    _invalidateRectFromMainThread
    )
    {
        dp::callBeginPaintEventHandler(
            _window
        );

        paintThreadProcMainLoop(
            _window
            , _mutex
            , _cond
            , _SIZE_FROM_MAIN_THREAD
            , _invalidateRectFromMainThread
        );

        dp::callEndPaintEventHandler(
            _window
        );
    }

    void clientMessage(
        dp::Window &                    _window
        , const XClientMessageEvent &   _EVENT
    )
    {
        const auto &    ATOM = static_cast< Atom >( _EVENT.data.l[ 0 ] );

        if( ATOM == WM_DELETE_WINDOW ) {
            dp::callCloseEventHandler(
                _window
            );
        }
    }

    void updateRange(
        dp::Int &   _from
        , dp::Int & _volume
        , dp::Int   _newFrom
        , dp::Int   _newVolume
    )
    {
        const auto  OLD_FROM = _from;
        const auto  OLD_VOLUME = _volume;

        const auto  OLD_TO = OLD_FROM + OLD_VOLUME;
        const auto  NEW_TO = _newFrom + _newVolume;

        const auto &    TO = OLD_TO > NEW_TO ? OLD_TO : NEW_TO;

        if( OLD_FROM > _newFrom ) {
            _from = _newFrom;
        }

        _volume = TO - _from;
    }

    void expose(
        dp::Window &                _window
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , Rect &                    _invalidateRect
        , const XExposeEvent &      _EVENT
    )
    {
        std::unique_lock< std::mutex >  lock( _mutex );

        if( _invalidateRect.width <= 0 || _invalidateRect.height <= 0 ) {
            _invalidateRect.x = _EVENT.x;
            _invalidateRect.y = _EVENT.y;
            _invalidateRect.width = _EVENT.width;
            _invalidateRect.height = _EVENT.height;
        } else {
            updateRange(
                _invalidateRect.x
                , _invalidateRect.width
                , _EVENT.x
                , _EVENT.width
            );
            updateRange(
                _invalidateRect.y
                , _invalidateRect.height
                , _EVENT.y
                , _EVENT.height
            );
        }

        _cond.notify_one();
    }

    void checkSize(
        dp::Window &                _window
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , Size &                    _size
        , const XConfigureEvent &   _EVENT
    )
    {
        const auto &    NEW_WIDTH = _EVENT.width;
        const auto &    NEW_HEIGHT = _EVENT.height;

        if(
            _size.initialized == false ||
            _size.width != NEW_WIDTH ||
            _size.height != NEW_HEIGHT
        ) {
            std::unique_lock< std::mutex >  lock( _mutex );

            _size.initialized = true;
            _size.width = NEW_WIDTH;
            _size.height = NEW_HEIGHT;

            _cond.notify_one();
        }
    }

    void checkPosition(
        dp::Window &                _window
        , Position &                _position
        , const XConfigureEvent &   _EVENT
    )
    {
        const auto &    NEW_X = _EVENT.x;
        const auto &    NEW_Y = _EVENT.y;

        if(
            _position.initialized == false ||
            _position.x != NEW_X ||
            _position.y != NEW_Y
        ) {
            _position.initialized = true;
            _position.x = NEW_X;
            _position.y = NEW_Y;

            dp::callPositionEventHandler(
                _window
                , _position.x
                , _position.y
            );
        }
    }

    void configureNotify(
        dp::Window &                _window
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , Size &                    _size
        , Position &                _position
        , const XConfigureEvent &   _EVENT
    )
    {
        checkSize(
            _window
            , _mutex
            , _cond
            , _size
            , _EVENT
        );
        checkPosition(
            _window
            , _position
            , _EVENT
        );
    }

    dp::Key toKey(
        KeySym  _keySym
    )
    {
        // ASCIIコードの図形文字の範囲ならそのまま
        if( _keySym >= XK_space && _keySym <= XK_asciitilde ) {
            return static_cast< dp::Key >( _keySym );
        }

#define TO_KEY( _KEY, _KEYSYM ) \
        case _KEYSYM:   \
            return dp::Key::_KEY;   \
            break;  \

        switch( _keySym ) {
        TO_KEY( KP_SPACE, XK_KP_Space )
        TO_KEY( KP_EQUAL, XK_KP_Equal )
        TO_KEY( KP_ASTERISK, XK_KP_Multiply )
        TO_KEY( KP_PLUS, XK_KP_Add )
        TO_KEY( KP_COMMA, XK_KP_Separator )
        TO_KEY( KP_MINUS, XK_KP_Subtract )
        TO_KEY( KP_PERIOD, XK_KP_Decimal )
        TO_KEY( KP_SLASH, XK_KP_Divide )
        TO_KEY( KP_0, XK_KP_0 )
        TO_KEY( KP_1, XK_KP_1 )
        TO_KEY( KP_2, XK_KP_2 )
        TO_KEY( KP_3, XK_KP_3 )
        TO_KEY( KP_4, XK_KP_4 )
        TO_KEY( KP_5, XK_KP_5 )
        TO_KEY( KP_6, XK_KP_6 )
        TO_KEY( KP_7, XK_KP_7 )
        TO_KEY( KP_8, XK_KP_8 )
        TO_KEY( KP_9, XK_KP_9 )

        TO_KEY( LEFT, XK_Left )
        TO_KEY( UP, XK_Up )
        TO_KEY( RIGHT, XK_Right )
        TO_KEY( DOWN, XK_Down )
        TO_KEY( PAGE_UP, XK_Page_Up )
        TO_KEY( PAGE_DOWN, XK_Page_Down )
        TO_KEY( HOME, XK_Home )
        TO_KEY( END, XK_End )
        TO_KEY( SHIFT_LEFT, XK_Shift_L )
        TO_KEY( SHIFT_RIGHT, XK_Shift_R )
        TO_KEY( CONTROL_LEFT, XK_Control_L )
        TO_KEY( CONTROL_RIGHT, XK_Control_R )
        TO_KEY( ALT_LEFT, XK_Alt_L )
        TO_KEY( ALT_RIGHT, XK_Alt_R )
        TO_KEY( SUPER_LEFT, XK_Super_L )
        TO_KEY( SUPER_RIGHT, XK_Super_R )
        TO_KEY( BACK_SPACE, XK_BackSpace )
        TO_KEY( TAB, XK_Tab )
        TO_KEY( ENTER, XK_Return )
        TO_KEY( ESCAPE, XK_Escape )
        TO_KEY( DELETE, XK_Delete )
        TO_KEY( INSERT, XK_Insert )
        TO_KEY( BREAK, XK_Break )
        TO_KEY( CAPS_LOCK, XK_Caps_Lock )
        TO_KEY( NUM_LOCK, XK_Num_Lock )
        TO_KEY( SCROLL_LOCK, XK_Scroll_Lock )
        TO_KEY( PRINT_SCREEN, XK_Print )
        TO_KEY( PAUSE, XK_Pause )
        TO_KEY( APPLICATION, XK_Menu )
        TO_KEY( BEGIN, XK_Begin )
        TO_KEY( EISU, XK_Eisu_toggle )
        TO_KEY( MUHENKAN, XK_Muhenkan )
        TO_KEY( HENKAN, XK_Henkan_Mode )
        TO_KEY( HIRAGANA_KATAKANA, XK_Hiragana_Katakana )
        TO_KEY( ZENKAKU_HANKAKU, XK_Zenkaku_Hankaku )

        TO_KEY( KP_LEFT, XK_KP_Left )
        TO_KEY( KP_UP, XK_KP_Up )
        TO_KEY( KP_RIGHT, XK_KP_Right )
        TO_KEY( KP_DOWN, XK_KP_Down )
        TO_KEY( KP_PAGE_UP, XK_KP_Page_Up )
        TO_KEY( KP_PAGE_DOWN, XK_KP_Page_Down )
        TO_KEY( KP_HOME, XK_KP_Home )
        TO_KEY( KP_END, XK_KP_End )
        TO_KEY( KP_TAB, XK_KP_Tab )
        TO_KEY( KP_ENTER, XK_KP_Enter )
        TO_KEY( KP_DELETE, XK_KP_Delete )
        TO_KEY( KP_INSERT, XK_KP_Insert )
        TO_KEY( KP_BEGIN, XK_KP_Begin )

        TO_KEY( F1, XK_F1 )
        TO_KEY( F2, XK_F2 )
        TO_KEY( F3, XK_F3 )
        TO_KEY( F4, XK_F4 )
        TO_KEY( F5, XK_F5 )
        TO_KEY( F6, XK_F6 )
        TO_KEY( F7, XK_F7 )
        TO_KEY( F8, XK_F8 )
        TO_KEY( F9, XK_F9 )
        TO_KEY( F10, XK_F10 )
        TO_KEY( F11, XK_F11 )
        TO_KEY( F12, XK_F12 )
        }
#undef  TO_KEY

        return dp::Key::INVALID;
    }

    dp::Key getKey(
        const XKeyEvent &   _EVENT
    )
    {
        auto &  event = const_cast< XKeyEvent & >( _EVENT );

        const auto  KEY_SYM = XLookupKeysym(
            &event
            , 0
        );

        return toKey( KEY_SYM );
    }

    const dp::Utf32Char * getCharPtr(
        const XKeyEvent &   _EVENT
        , dp::Utf32Char &   _ch
    )
    {
        auto &  event = const_cast< XKeyEvent & >( _EVENT );

        dp::StringChar  stringChar;

        auto    length = XLookupString(
            &event
            , &stringChar
            , 1
            , nullptr
            , nullptr
        );

        if( length < 1 ) {
            return nullptr;
        } else if( stringChar < 0x20 || stringChar > 0x7e ) {
            return nullptr;
        }

        _ch = stringChar;

        return &_ch;
    }

    void key(
        dp::Window &        _window
        , const XKeyEvent & _EVENT
        , dp::Bool          _pressed
    )
    {
        const auto  KEY = getKey(
            _EVENT
        );

        dp::Utf32Char   ch;

        const auto  CH_PTR = getCharPtr(
            _EVENT
            , ch
        );

        dp::callKeyEventHandler(
            _window
            , KEY
            , CH_PTR
            , _pressed
        );
    }

    void keyPress(
        dp::Window &        _window
        , const XKeyEvent & _EVENT
    )
    {
        key(
            _window
            , _EVENT
            , true
        );
    }

    void keyRelease(
        dp::Window &        _window
        , const XKeyEvent & _EVENT
    )
    {
        key(
            _window
            , _EVENT
            , false
        );
    }

    void button(
        dp::Window &            _window
        , const XButtonEvent &  _EVENT
        , dp::Bool              _pressed
    )
    {
        const auto  INDEX = _EVENT.button - 1;

        dp::callMouseButtonEventHandler(
            _window
            , INDEX
            , _pressed
        );
    }

    void buttonPress(
        dp::Window &            _window
        , const XButtonEvent &  _EVENT
    )
    {
        button(
            _window
            , _EVENT
            , true
        );
    }

    void buttonRelease(
        dp::Window &            _window
        , const XButtonEvent &  _EVENT
    )
    {
        button(
            _window
            , _EVENT
            , false
        );
    }

    void motionNotify(
        dp::Window &            _window
        , const XMotionEvent &  _EVENT
    )
    {
        dp::callMouseMotionEventHandler(
            _window
            , _EVENT.x
            , _EVENT.y
        );
    }

    void mainThreadProc(
        dp::Window &                _window
        , std::mutex &              _mutex
        , std::condition_variable & _cond
        , Size &                    _size
        , Rect &                    _invalidateRect
    )
    {
        Position    position;

        auto &  impl = *( _window.implUnique );

        const auto &    ENDED = impl.ended;

        auto &  xDisplay = *( impl.xDisplayUnique );
        auto &  xWindow = impl.xWindow;

        XEvent  event;
        while( 1 ) {
            XIfEvent(
                &xDisplay
                , &event
                , isMainThreadEvent
                , reinterpret_cast< XPointer >( &xWindow )
            );

            if( ENDED ) {
                break;
            }

            switch( event.type ) {
            case ClientMessage:
                clientMessage(
                    _window
                    , event.xclient
                );
                break;

            case Expose:
                expose(
                    _window
                    , _mutex
                    , _cond
                    , _invalidateRect
                    , event.xexpose
                );
                break;

            case ConfigureNotify:
                configureNotify(
                    _window
                    , _mutex
                    , _cond
                    , _size
                    , position
                    , event.xconfigure
                );
                break;

            case KeyPress:
                keyPress(
                    _window
                    , event.xkey
                );
                break;

            case KeyRelease:
                keyRelease(
                    _window
                    , event.xkey
                );
                break;

            case ButtonPress:
                buttonPress(
                    _window
                    , event.xbutton
                );
                break;

            case ButtonRelease:
                buttonRelease(
                    _window
                    , event.xbutton
                );
                break;

            case MotionNotify:
                motionNotify(
                    _window
                    , event.xmotion
                );
                break;

            default:
                // ここに到達することはない
                break;
            }
        }
    }

    void notifyPaintThread(
        std::mutex &                _mutex
        , std::condition_variable & _cond
    )
    {
        std::unique_lock< std::mutex >  lock( _mutex );

        _cond.notify_one();
    }

    void threadProc(
        dp::Window &        _window
    )
    {
        std::mutex              mutex;
        std::condition_variable cond;

        Size    size;
        Rect    invalidateRect;

        std::thread paintThread(
            [
                &_window
                , &mutex
                , &cond
                , &size
                , &invalidateRect
            ]
            {
                paintThreadProc(
                    _window
                    , mutex
                    , cond
                    , size
                    , invalidateRect
                );
            }
        );
        dp::ThreadJoiner    threadJoiner( &paintThread );

        mainThreadProc(
            _window
            , mutex
            , cond
            , size
            , invalidateRect
        );

        //FIXME 可能ならstd::unique_ptrのdeleterで実行
        notifyPaintThread(
            mutex
            , cond
        );
    }

    Bool initializeWindowImpl(
        dp::Window &        _window
        , const dp::Utf32 & _TITLE
        , dp::Int           _width
        , dp::Int           _height
        , dp::WindowFlags   _flags
    )
    {
        auto &  impl = *( _window.implUnique );

        auto &  xDisplayUnique = impl.xDisplayUnique;
        xDisplayUnique.reset( dp::newXDisplay() );
        if( xDisplayUnique.get() == nullptr ) {
            return false;
        }

        auto &  xDisplay = *xDisplayUnique;

        dp::String  titleString;
        if( dp::toString(
            titleString
            , _TITLE
        ) == false ) {
            return false;
        }

        impl.ended = false;

        auto &  xWindow = impl.xWindow;

        auto &  xRootWindow = DefaultRootWindow( &xDisplay );

        XSetWindowAttributes    attributes;

        attributes.event_mask =
            ExposureMask |
            StructureNotifyMask |
            KeyPressMask |
            KeyReleaseMask |
            ButtonPressMask |
            ButtonReleaseMask |
            PointerMotionMask
        ;

        errno = 0;
        xWindow = XCreateWindow(
            &xDisplay
            , xRootWindow
            , 0
            , 0
            , _width
            , _height
            , 0
            , CopyFromParent
            , InputOutput
            , DefaultVisual(
                &xDisplay
                , DefaultScreen( &xDisplay )
            )
            , CWEventMask
            , &attributes
        );
        if( errno != 0 ) {
            return false;
        }

        impl.xWindowDestroyer.reset( &xWindow );

        XSetWMProtocols(
            &xDisplay
            , xWindow
            , &WM_DELETE_WINDOW
            , 1
        );

        if( ( _flags & dp::WindowFlags::UNRESIZABLE ) != 0 ) {
            unresizable(
                xDisplay
                , xWindow
                , _width
                , _height
            );
        }

        if( ( _flags & dp::WindowFlags::ALWAYS_ON_TOP ) != 0 ) {
            alwaysOnTop(
                xDisplay
                , xWindow
            );
        }

        setTitle(
            xDisplay
            , xWindow
            , titleString
        );

        XMapWindow(
            &xDisplay
            , xWindow
        );

        impl.thread = std::move(
            std::thread(
                [
                    &_window
                ]
                {
                    threadProc(
                        _window
                    );
                }
            )
        );
        impl.threadJoiner.reset( &( impl.thread ) );
        impl.threadExiter.reset( &impl );

        return true;
    }

    void sendEvent(
        XEvent &    _event
        , dp::Int   _eventMask
    )
    {
        auto &  xDisplay = _event.xany.display;
        auto &  xWindow = _event.xany.window;

        XSendEvent(
            xDisplay
            , xWindow
            , False
            , _eventMask
            , &_event
        );
    }
}

namespace dp {
    void initializeWindow(
    )
    {
        auto &  xDisplay = getXDisplay();

        WM_DELETE_WINDOW = XInternAtom(
            &xDisplay
            , "WM_DELETE_WINDOW"
            , True
        );

        _NET_WM_STATE_ABOVE = XInternAtom(
            &xDisplay
            , "_NET_WM_STATE_ABOVE"
            , True
        );

        _NET_WM_STATE= XInternAtom(
            &xDisplay
            , "_NET_WM_STATE"
            , True
        );
    }

    Bool initializeWindowImpl(
        Window &        _window
        , const Utf32 & _TITLE
        , Int           _width
        , Int           _height
        , WindowFlags   _flags
    )
    {
        if( ::initializeWindowImpl(
            _window
            , _TITLE
            , _width
            , _height
            , _flags
        ) == false ) {
            return false;
        }

        auto &  impl = *( _window.implUnique );

        auto &  xDisplay = *( impl.xDisplayUnique );

        XFlush( &xDisplay );

        return true;
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
        if( ::initializeWindowImpl(
            _window
            , _TITLE
            , _width
            , _height
            , _flags
        ) == false ) {
            return false;
        }

        auto &  impl = *( _window.implUnique );

        auto &  xDisplay = *( impl.xDisplayUnique );
        auto &  xWindow = impl.xWindow;

        XMoveWindow(
            &xDisplay
            , xWindow
            , _x
            , _y
        );

        XFlush( &xDisplay );

        return true;
    }

    void close(
        Window &    _window
    )
    {
        auto &  impl = *( _window.implUnique );

        auto &  xDisplay = *( impl.xDisplayUnique );
        auto &  xWindow = impl.xWindow;

        XEvent  event;
        event.xclient.display = &xDisplay;
        event.xclient.window = xWindow;
        event.xclient.type = ClientMessage;
        event.xclient.format = 32;
        event.xclient.data.l[ 0 ] = WM_DELETE_WINDOW;

        sendEvent(
            event
            , NoEventMask
        );

        XFlush( &xDisplay );
    }

    Bool setTitle(
        Window &        _window
        , const Utf32 & _TITLE
    )
    {
        String  titleString;
        if( toString(
            titleString
            , _TITLE
        ) == false ) {
            return false;
        }

        auto &  impl = *( _window.implUnique );

        auto &  xDisplay = *( impl.xDisplayUnique );
        auto &  xWindow = impl.xWindow;

        ::setTitle(
            xDisplay
            , xWindow
            , titleString
        );

        XFlush( &xDisplay );

        return true;
    }

    void setPosition(
        Window &    _window
        , Int       _x
        , Int       _y
    )
    {
        auto &  impl = *( _window.implUnique );

        auto &  xDisplay = *( impl.xDisplayUnique );
        auto &  xWindow = impl.xWindow;

        XMoveWindow(
            &xDisplay
            , xWindow
            , _x
            , _y
        );
        XFlush( &xDisplay );
    }

    void setSize(
        Window &    _window
        , Int       _width
        , Int       _height
    )
    {
        auto &  impl = *( _window.implUnique );

        auto &  xDisplay = *( impl.xDisplayUnique );
        auto &  xWindow = impl.xWindow;

        XResizeWindow(
            &xDisplay
            , xWindow
            , _width
            , _height
        );
        XFlush( &xDisplay );
    }

    void repaint(
        Window &    _window
        , Int       _x
        , Int       _y
        , Int       _width
        , Int       _height
    )
    {
        auto &  impl = *( _window.implUnique );

        auto &  xDisplay = *( impl.xDisplayUnique );
        auto &  xWindow = impl.xWindow;

        XEvent  event;

        auto &  exposeEvent = event.xexpose;

        exposeEvent.type = Expose;
        exposeEvent.display = &xDisplay;
        exposeEvent.window = xWindow;
        exposeEvent.x = _x;
        exposeEvent.y = _y;
        exposeEvent.width = _width;
        exposeEvent.height = _height;
        exposeEvent.count = 0;

        sendEvent(
            event
            , ExposureMask
        );

        XFlush( &xDisplay );
    }

    void WindowImpl::ExitThread::operator()(
        WindowImpl *    _impl
    ) const
    {
        _impl->ended = true;

        auto &  xDisplay = *( _impl->xDisplayUnique );
        auto &  xWindow = _impl->xWindow;

        XEvent  event;
        event.xclient.display = &xDisplay;
        event.xclient.window = xWindow;
        event.xclient.type = ClientMessage;
        event.xclient.format = 8;

        sendEvent(
            event
            , NoEventMask
        );

        XFlush( &xDisplay );
    }

    const ::Window & getXWindow(
        const Window &  _window
    )
    {
        return _window.implUnique->xWindow;
    }
}
