#include "dpimpl/util/export.h"
#include "dp/audio/speakerkey.h"

#include "dpimpl/linux/audio/speakerkey.h"
#include "dp/common/primitives.h"

#include <new>

namespace {
    dp::SpeakerKey * newSpeakerKey(
        //TODO
    )
    {
        dp::SpeakerKeyUnique    keyUnique( new( std::nothrow )dp::SpeakerKey );
        if( keyUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  key = *keyUnique;

        //TODO

        return keyUnique.release();
    }
}

namespace dp {
    SpeakerKey * clone(
        const SpeakerKey &  _OTHER
    )
    {
        return ::newSpeakerKey(
            //TODO
        );
    }

    Bool equals(
        const SpeakerKey &      _KEY1
        , const SpeakerKey &    _KEY2
    )
    {
        //TODO
        return false;
    }

    Bool less(
        const SpeakerKey &      _KEY1
        , const SpeakerKey &    _KEY2
    )
    {
        //TODO
        return false;
    }

    SpeakerKey * newSpeakerKey(
        //TODO
    )
    {
        return ::newSpeakerKey(
            //TODO
        );
    }
}
