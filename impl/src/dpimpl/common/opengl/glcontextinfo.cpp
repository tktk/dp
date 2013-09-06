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
        dp::GLContextInfoUnique infoUnique( new( std::nothrow )dp::GLContextInfo );
        if( infoUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  info = *infoUnique;

        info.doubleBuffer = _doubleBuffer;
        info.existsAuxBuffers = _existsAuxBuffers;
        info.auxBuffers = _auxBuffers;
        info.existsRedBits = _existsRedBits;
        info.redBits = _redBits;
        info.existsGreenBits = _existsGreenBits;
        info.greenBits = _greenBits;
        info.existsBlueBits = _existsBlueBits;
        info.blueBits = _blueBits;
        info.existsAlphaBits = _existsAlphaBits;
        info.alphaBits = _alphaBits;
        info.existsDepthBits = _existsDepthBits;
        info.depthBits = _depthBits;
        info.existsStencilBits = _existsStencilBits;
        info.stencilBits = _stencilBits;
        info.existsAccumRedBits = _existsAccumRedBits;
        info.accumRedBits = _accumRedBits;
        info.existsAccumGreenBits = _existsAccumGreenBits;
        info.accumGreenBits = _accumGreenBits;
        info.existsAccumBlueBits = _existsAccumBlueBits;
        info.accumBlueBits = _accumBlueBits;
        info.existsAccumAlphaBits = _existsAccumAlphaBits;
        info.accumAlphaBits = _accumAlphaBits;

        return infoUnique.release();
    }
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
            , _OTHER.existsAuxBuffers
            , _OTHER.auxBuffers
            , _OTHER.existsRedBits
            , _OTHER.redBits
            , _OTHER.existsGreenBits
            , _OTHER.greenBits
            , _OTHER.existsBlueBits
            , _OTHER.blueBits
            , _OTHER.existsAlphaBits
            , _OTHER.alphaBits
            , _OTHER.existsDepthBits
            , _OTHER.depthBits
            , _OTHER.existsStencilBits
            , _OTHER.stencilBits
            , _OTHER.existsAccumRedBits
            , _OTHER.accumRedBits
            , _OTHER.existsAccumGreenBits
            , _OTHER.accumGreenBits
            , _OTHER.existsAccumBlueBits
            , _OTHER.accumBlueBits
            , _OTHER.existsAccumAlphaBits
            , _OTHER.accumAlphaBits
        );
    }

    void free(
        GLContextInfo & _info
    )
    {
        delete &_info;
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

    Bool isExistsAuxBuffers(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsAuxBuffers;
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
        _info.existsAuxBuffers = true;
    }

    void clearAuxBuffers(
        GLContextInfo & _info
    )
    {
        _info.existsAuxBuffers = false;
    }

    Bool isExistsRedBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsRedBits;
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
        _info.existsRedBits = true;
    }

    void clearRedBits(
        GLContextInfo & _info
    )
    {
        _info.existsRedBits = false;
    }

    Bool isExistsGreenBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsGreenBits;
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
        _info.existsGreenBits = true;
    }

    void clearGreenBits(
        GLContextInfo & _info
    )
    {
        _info.existsGreenBits = false;
    }

    Bool isExistsBlueBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsBlueBits;
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
        _info.existsBlueBits = true;
    }

    void clearBlueBits(
        GLContextInfo & _info
    )
    {
        _info.existsBlueBits = false;
    }

    Bool isExistsAlphaBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsAlphaBits;
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
        _info.existsAlphaBits = true;
    }

    void clearAlphaBits(
        GLContextInfo & _info
    )
    {
        _info.existsAlphaBits = false;
    }

    Bool isExistsDepthBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsDepthBits;
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
        _info.existsDepthBits = true;
    }

    void clearDepthBits(
        GLContextInfo & _info
    )
    {
        _info.existsDepthBits = false;
    }

    Bool isExistsStencilBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsStencilBits;
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
        _info.existsStencilBits = true;
    }

    void clearStencilBits(
        GLContextInfo & _info
    )
    {
        _info.existsStencilBits = false;
    }

    Bool isExistsAccumRedBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsAccumRedBits;
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
        _info.existsAccumRedBits = true;
    }

    void clearAccumRedBits(
        GLContextInfo & _info
    )
    {
        _info.existsAccumRedBits = false;
    }

    Bool isExistsAccumGreenBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsAccumGreenBits;
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
        _info.existsAccumGreenBits = true;
    }

    void clearAccumGreenBits(
        GLContextInfo & _info
    )
    {
        _info.existsAccumGreenBits = false;
    }

    Bool isExistsAccumBlueBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsAccumBlueBits;
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
        _info.existsAccumBlueBits = true;
    }

    void clearAccumBlueBits(
        GLContextInfo & _info
    )
    {
        _info.existsAccumBlueBits = false;
    }

    Bool isExistsAccumAlphaBits(
        const GLContextInfo &   _INFO
    )
    {
        return _INFO.existsAccumAlphaBits;
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
        _info.existsAccumAlphaBits = true;
    }

    void clearAccumAlphaBits(
        GLContextInfo & _info
    )
    {
        _info.existsAccumAlphaBits = false;
    }
}
