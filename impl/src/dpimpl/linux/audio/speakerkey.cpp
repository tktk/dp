#include "dpimpl/util/export.h"
#include "dp/audio/speakerkey.h"

#include "dpimpl/linux/audio/speakerkey.h"
#include "dp/common/primitives.h"

#include <new>

namespace {
    dp::SpeakerKey * newSpeakerKey(
        dp::UInt    _index
    )
    {
        dp::SpeakerKeyUnique    keyUnique( new( std::nothrow )dp::SpeakerKey );
        if( keyUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  key = *keyUnique;

        key.index = _index;

        return keyUnique.release();
    }
}

namespace dp {
    SpeakerKey * clone(
        const SpeakerKey &  _OTHER
    )
    {
        return ::newSpeakerKey(
            _OTHER.index
        );
    }

    Bool equals(
        const SpeakerKey &      _KEY1
        , const SpeakerKey &    _KEY2
    )
    {
        return _KEY1.index == _KEY2.index;
    }

    Bool less(
        const SpeakerKey &      _KEY1
        , const SpeakerKey &    _KEY2
    )
    {
        return _KEY1.index < _KEY2.index;
    }

    SpeakerKey * newSpeakerKey(
        UInt    _index
    )
    {
        return ::newSpeakerKey(
            _index
        );
    }
}
