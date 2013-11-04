#include "dpimpl/util/export.h"
#include "dp/opengl/glcontext.h"

#include "dpimpl/common/opengl/glcontextinfo.h"
#include "dp/common/primitives.h"

#include <new>

namespace {
    dp::GLContextInfo * newGLContextInfo(
        dp::Bool    _doubleBuffer
        , dp::Bool  _existsAuxBuffers
        , dp::Int   _auxBuffers
        , dp::Bool  _existsRedBits
        , dp::Int   _redBits
        , dp::Bool  _existsGreenBits
        , dp::Int   _greenBits
        , dp::Bool  _existsBlueBits
        , dp::Int   _blueBits
        , dp::Bool  _existsAlphaBits
        , dp::Int   _alphaBits
        , dp::Bool  _existsDepthBits
        , dp::Int   _depthBits
        , dp::Bool  _existsStencilBits
        , dp::Int   _stencilBits
        , dp::Bool  _existsAccumRedBits
        , dp::Int   _accumRedBits
        , dp::Bool  _existsAccumGreenBits
        , dp::Int   _accumGreenBits
        , dp::Bool  _existsAccumBlueBits
        , dp::Int   _accumBlueBits
        , dp::Bool  _existsAccumAlphaBits
        , dp::Int   _accumAlphaBits
    )
    {
        auto    infoUnique = dp::unique( new( std::nothrow )dp::GLContextInfo );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoUnique;

        info.doubleBuffer = _doubleBuffer;
        info.existsAuxBuffers_ = _existsAuxBuffers;
        info.auxBuffers = _auxBuffers;
        info.existsRedBits_ = _existsRedBits;
        info.redBits = _redBits;
        info.existsGreenBits_ = _existsGreenBits;
        info.greenBits = _greenBits;
        info.existsBlueBits_ = _existsBlueBits;
        info.blueBits = _blueBits;
        info.existsAlphaBits_ = _existsAlphaBits;
        info.alphaBits = _alphaBits;
        info.existsDepthBits_ = _existsDepthBits;
        info.depthBits = _depthBits;
        info.existsStencilBits_ = _existsStencilBits;
        info.stencilBits = _stencilBits;
        info.existsAccumRedBits_ = _existsAccumRedBits;
        info.accumRedBits = _accumRedBits;
        info.existsAccumGreenBits_ = _existsAccumGreenBits;
        info.accumGreenBits = _accumGreenBits;
        info.existsAccumBlueBits_ = _existsAccumBlueBits;
        info.accumBlueBits = _accumBlueBits;
        info.existsAccumAlphaBits_ = _existsAccumAlphaBits;
        info.accumAlphaBits = _accumAlphaBits;

        return infoUnique.release();
    }
}

template<>
void dpFree(
    const dp::GLContextInfo &   _INFO
)
{
    delete &_INFO;
}

namespace dp {
    GLContextInfo * newGLContextInfo(
    )
    {
        return ::newGLContextInfo(
            true
            , false
            , 0
            , false
            , 0
            , false
            , 0
            , false
            , 0
            , false
            , 0
            , false
            , 0
            , false
            , 0
            , false
            , 0
            , false
            , 0
            , false
            , 0
            , false
            , 0
        );
    }

    GLContextInfo * clone(
        const GLContextInfo &   _OTHER
    )
    {
        return ::newGLContextInfo(
            _OTHER.doubleBuffer
            , _OTHER.existsAuxBuffers_
            , _OTHER.auxBuffers
            , _OTHER.existsRedBits_
            , _OTHER.redBits
            , _OTHER.existsGreenBits_
            , _OTHER.greenBits
            , _OTHER.existsBlueBits_
            , _OTHER.blueBits
            , _OTHER.existsAlphaBits_
            , _OTHER.alphaBits
            , _OTHER.existsDepthBits_
            , _OTHER.depthBits
            , _OTHER.existsStencilBits_
            , _OTHER.stencilBits
            , _OTHER.existsAccumRedBits_
            , _OTHER.accumRedBits
            , _OTHER.existsAccumGreenBits_
            , _OTHER.accumGreenBits
            , _OTHER.existsAccumBlueBits_
            , _OTHER.accumBlueBits
            , _OTHER.existsAccumAlphaBits_
            , _OTHER.accumAlphaBits
        );
    }

    Bool getDoubleBuffer(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.doubleBuffer;
    }

    void setDoubleBuffer(
        GLContextInfo & _info
        , Bool          _doubleBuffer
    )
    {
        _info.doubleBuffer = _doubleBuffer;
    }

    Bool existsAuxBuffers(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsAuxBuffers_;
    }

    Int getAuxBuffers(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.auxBuffers;
    }

    void setAuxBuffers(
        GLContextInfo & _info
        , Int           _auxBuffers
    )
    {
        _info.auxBuffers = _auxBuffers;
        _info.existsAuxBuffers_ = true;
    }

    void clearAuxBuffers(
        GLContextInfo & _info
    )
    {
        _info.existsAuxBuffers_ = false;
    }

    Bool existsRedBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsRedBits_;
    }

    Int getRedBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.redBits;
    }

    void setRedBits(
        GLContextInfo & _info
        , Int           _redBits
    )
    {
        _info.redBits = _redBits;
        _info.existsRedBits_ = true;
    }

    void clearRedBits(
        GLContextInfo & _info
    )
    {
        _info.existsRedBits_ = false;
    }

    Bool existsGreenBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsGreenBits_;
    }

    Int getGreenBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.greenBits;
    }

    void setGreenBits(
        GLContextInfo & _info
        , Int           _greenBits
    )
    {
        _info.greenBits = _greenBits;
        _info.existsGreenBits_ = true;
    }

    void clearGreenBits(
        GLContextInfo & _info
    )
    {
        _info.existsGreenBits_ = false;
    }

    Bool existsBlueBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsBlueBits_;
    }

    Int getBlueBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.blueBits;
    }

    void setBlueBits(
        GLContextInfo & _info
        , Int           _blueBits
    )
    {
        _info.blueBits = _blueBits;
        _info.existsBlueBits_ = true;
    }

    void clearBlueBits(
        GLContextInfo & _info
    )
    {
        _info.existsBlueBits_ = false;
    }

    Bool existsAlphaBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsAlphaBits_;
    }

    Int getAlphaBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.alphaBits;
    }

    void setAlphaBits(
        GLContextInfo & _info
        , Int           _alphaBits
    )
    {
        _info.alphaBits = _alphaBits;
        _info.existsAlphaBits_ = true;
    }

    void clearAlphaBits(
        GLContextInfo & _info
    )
    {
        _info.existsAlphaBits_ = false;
    }

    Bool existsDepthBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsDepthBits_;
    }

    Int getDepthBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.depthBits;
    }

    void setDepthBits(
        GLContextInfo & _info
        , Int           _depthBits
    )
    {
        _info.depthBits = _depthBits;
        _info.existsDepthBits_ = true;
    }

    void clearDepthBits(
        GLContextInfo & _info
    )
    {
        _info.existsDepthBits_ = false;
    }

    Bool existsStencilBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsStencilBits_;
    }

    Int getStencilBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.stencilBits;
    }

    void setStencilBits(
        GLContextInfo & _info
        , Int           _stencilBits
    )
    {
        _info.stencilBits = _stencilBits;
        _info.existsStencilBits_ = true;
    }

    void clearStencilBits(
        GLContextInfo & _info
    )
    {
        _info.existsStencilBits_ = false;
    }

    Bool existsAccumRedBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsAccumRedBits_;
    }

    Int getAccumRedBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.accumRedBits;
    }

    void setAccumRedBits(
        GLContextInfo & _info
        , Int           _accumRedBits
    )
    {
        _info.accumRedBits = _accumRedBits;
        _info.existsAccumRedBits_ = true;
    }

    void clearAccumRedBits(
        GLContextInfo & _info
    )
    {
        _info.existsAccumRedBits_ = false;
    }

    Bool existsAccumGreenBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsAccumGreenBits_;
    }

    Int getAccumGreenBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.accumGreenBits;
    }

    void setAccumGreenBits(
        GLContextInfo & _info
        , Int           _accumGreenBits
    )
    {
        _info.accumGreenBits = _accumGreenBits;
        _info.existsAccumGreenBits_ = true;
    }

    void clearAccumGreenBits(
        GLContextInfo & _info
    )
    {
        _info.existsAccumGreenBits_ = false;
    }

    Bool existsAccumBlueBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsAccumBlueBits_;
    }

    Int getAccumBlueBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.accumBlueBits;
    }

    void setAccumBlueBits(
        GLContextInfo & _info
        , Int           _accumBlueBits
    )
    {
        _info.accumBlueBits = _accumBlueBits;
        _info.existsAccumBlueBits_ = true;
    }

    void clearAccumBlueBits(
        GLContextInfo & _info
    )
    {
        _info.existsAccumBlueBits_ = false;
    }

    Bool existsAccumAlphaBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsAccumAlphaBits_;
    }

    Int getAccumAlphaBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.accumAlphaBits;
    }

    void setAccumAlphaBits(
        GLContextInfo & _info
        , Int           _accumAlphaBits
    )
    {
        _info.accumAlphaBits = _accumAlphaBits;
        _info.existsAccumAlphaBits_ = true;
    }

    void clearAccumAlphaBits(
        GLContextInfo & _info
    )
    {
        _info.existsAccumAlphaBits_ = false;
    }
}
