#include "dpimpl/util/export.h"
#include "dp/opengl/glcontext.h"

#include "dpimpl/linux/opengl/glcontext.h"
#include "dpimpl/common/opengl/glcontextinfo.h"
#include "dp/opengl/types.h"
#include "dpimpl/linux/window/window.h"
#include "dp/common/primitives.h"

#include "dpimpl/linux/xlib/xlib.h"
#include "dpimpl/linux/opengl/glx.h"
#include <new>
#include <memory>
#include <vector>
#include <functional>
#include <utility>

namespace {
    dp::XDisplayUnique  xDisplayUnique;
    dp::Int             xDefaultScreen;

    typedef std::function<
        void(
            const ::Window &
        )
    > SwapInterval;

    SwapInterval    swapInterval;

    struct FreeXVisualInfo
    {
        void operator()(
            XVisualInfo *   _xVisualInfo
        )
        {
            XFree( _xVisualInfo );
        }
    };

    typedef std::unique_ptr<
        XVisualInfo
        , FreeXVisualInfo
    > XVisualInfoUnique;

    XVisualInfo * newXVisualInfo(
        const dp::GLContextInfo &   _INFO
    )
    {
        std::vector< dp::Int >  attrs;
        attrs.push_back( GLX_USE_GL );
        attrs.push_back( GLX_RGBA );
        attrs.push_back( GLX_DOUBLEBUFFER );
        attrs.push_back( _INFO.doubleBuffer ? True : False );
        if( _INFO.existsAuxBuffers_ ) {
            attrs.push_back( GLX_AUX_BUFFERS );
            attrs.push_back( _INFO.auxBuffers );
        }
        if( _INFO.existsRedBits_ ) {
            attrs.push_back( GLX_RED_SIZE );
            attrs.push_back( _INFO.redBits );
        }
        if( _INFO.existsGreenBits_ ) {
            attrs.push_back( GLX_GREEN_SIZE );
            attrs.push_back( _INFO.greenBits );
        }
        if( _INFO.existsBlueBits_ ) {
            attrs.push_back( GLX_BLUE_SIZE );
            attrs.push_back( _INFO.blueBits );
        }
        if( _INFO.existsAlphaBits_ ) {
            attrs.push_back( GLX_ALPHA_SIZE );
            attrs.push_back( _INFO.alphaBits );
        }
        if( _INFO.existsDepthBits_ ) {
            attrs.push_back( GLX_DEPTH_SIZE );
            attrs.push_back( _INFO.depthBits );
        }
        if( _INFO.existsStencilBits_ ) {
            attrs.push_back( GLX_STENCIL_SIZE );
            attrs.push_back( _INFO.stencilBits );
        }
        if( _INFO.existsAccumRedBits_ ) {
            attrs.push_back( GLX_ACCUM_RED_SIZE );
            attrs.push_back( _INFO.accumRedBits );
        }
        if( _INFO.existsAccumGreenBits_ ) {
            attrs.push_back( GLX_ACCUM_GREEN_SIZE );
            attrs.push_back( _INFO.accumGreenBits );
        }
        if( _INFO.existsAccumBlueBits_ ) {
            attrs.push_back( GLX_ACCUM_BLUE_SIZE );
            attrs.push_back( _INFO.accumBlueBits );
        }
        if( _INFO.existsAccumAlphaBits_ ) {
            attrs.push_back( GLX_ACCUM_ALPHA_SIZE );
            attrs.push_back( _INFO.accumAlphaBits );
        }
        attrs.push_back( None );

        auto &  xDisplay = *xDisplayUnique;

        return glXChooseVisual(
            &xDisplay
            , xDefaultScreen
            , attrs.data()
        );
    }

    void initializeX(
    )
    {
        xDisplayUnique.reset( dp::newXDisplay() );
        if( xDisplayUnique.get() == nullptr ) {
            //FIXME 初期化失敗時の処理
            return;
        }

        auto &  xDisplay = *xDisplayUnique;

        xDefaultScreen = DefaultScreen( &xDisplay );
    }

    void initializeGLX(
    )
    {
        auto    glXSwapIntervalEXT_p = reinterpret_cast< PFNGLXSWAPINTERVALEXTPROC >(
            glXGetProcAddress(
                reinterpret_cast< const dp::GLubyte * >( "glXSwapIntervalEXT" )
            )
        );
        if( glXSwapIntervalEXT_p != nullptr ) {
            swapInterval = [
                glXSwapIntervalEXT_p
            ]
            (
                const ::Window &    _X_WINDOW
            )
            {
                auto &  xDisplay = *xDisplayUnique;

                glXSwapIntervalEXT_p(
                    &xDisplay
                    , _X_WINDOW
                    , 1
                );
            };

            return;
        }

        auto    glXSwapIntervalSGI_p = reinterpret_cast< PFNGLXSWAPINTERVALSGIPROC >(
            glXGetProcAddress(
                reinterpret_cast< const dp::GLubyte * >( "glXSwapIntervalSGI" )
            )
        );
        if( glXSwapIntervalSGI_p != nullptr ) {
            swapInterval = [
                glXSwapIntervalSGI_p
            ]
            (
                const ::Window &
            )
            {
                glXSwapIntervalSGI_p( 1 );
            };

            return;
        }

        auto    glXSwapIntervalMESA_p = reinterpret_cast< PFNGLXSWAPINTERVALMESAPROC >(
            glXGetProcAddress(
                reinterpret_cast< const dp::GLubyte * >( "glXSwapIntervalMESA" )
            )
        );
        if( glXSwapIntervalMESA_p != nullptr ) {
            swapInterval = [
                glXSwapIntervalMESA_p
            ]
            (
                const ::Window &
            )
            {
                glXSwapIntervalMESA_p( 1 );
            };

            return;
        }

        swapInterval = nullptr;
    }

    void finalizeX(
    )
    {
        auto    xDisplayUnique = std::move( ::xDisplayUnique );
    }

    dp::GLContext * newGLContext(
        const dp::GLContextInfo &   _INFO
        , GLXContext                _shareList
    )
    {
        auto    glContextUnique = dp::unique( new( std::nothrow )dp::GLContext );
        if( glContextUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  glContext = *glContextUnique;

        XVisualInfoUnique    xVisualInfoUnique(
            newXVisualInfo(
                _INFO
            )
        );
        if( xVisualInfoUnique.get() == nullptr ) {
            return nullptr;
        }
        auto &  xVisualInfo = *xVisualInfoUnique;

        auto &  xDisplay = *xDisplayUnique;

        auto &  glxContextUnique = glContext.glxContextUnique;
        glxContextUnique.reset(
            glXCreateContext(
                &xDisplay
                , &xVisualInfo
                , _shareList
                , True
            )
        );
        if( glxContextUnique.get() == nullptr ) {
            return nullptr;
        }

        return glContextUnique.release();
    }

    void glMakeCurrent(
        GLXDrawable     _drawable
        , GLXContext    _glxContext
    )
    {
        auto &  xDisplay = *xDisplayUnique;

        glXMakeCurrent(
            &xDisplay
            , _drawable
            , _glxContext
        );
    }
}

namespace dp {
    void initializeGLContext(
    )
    {
        initializeX();
        initializeGLX();
    }

    void finalizeGLContext(
    )
    {
        finalizeX();
    }

    GLContext * newGLContext(
        const GLContextInfo &   _INFO
    )
    {
        return ::newGLContext(
            _INFO
            , nullptr
        );
    }

    GLContext * newGLContext(
        const GLContextInfo &   _INFO
        , GLContext &           _glContext
    )
    {
        return ::newGLContext(
            _INFO
            , _glContext.glxContextUnique.get()
        );
    }

    void glMakeCurrent(
        Window &        _window
        , GLContext &   _glContext
        , Bool          _vSync
    )
    {
        auto &  xWindow = getXWindow( _window );

        ::glMakeCurrent(
            xWindow
            , _glContext.glxContextUnique.get()
        );

        if( _vSync && swapInterval != nullptr ) {
            swapInterval(
                xWindow
            );
        }
    }

    void glMakeCurrent(
    )
    {
        ::glMakeCurrent(
            None
            , nullptr
        );
    }

    void glSwapBuffers(
        Window &    _window
    )
    {
        auto &  xDisplay = *xDisplayUnique;

        glXSwapBuffers(
            &xDisplay
            , getXWindow( _window )
        );
    }

    void GLContext::FreeGLXContext::operator()(
        GLXContext  _glxContext
    ) const
    {
        auto &  xDisplay = *xDisplayUnique;

        glXDestroyContext(
            &xDisplay
            , _glxContext
        );
    }
}
