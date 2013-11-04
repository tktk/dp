#include "dp/util/export.h"
#include "dp/audio/speakerkey.h"

#include "dpimpl/windows/audio/speakerkey.h"
#include "dp/common/primitives.h"

#include <new>

namespace {
    dp::SpeakerKey * newSpeakerKey(
        //TODO
    )
    {
        auto    keyUnique = dp::unique( new( std::nothrow )dp::SpeakerKey );
        if( keyUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  key = *keyUnique;

        //TODO

        return keyUnique.release();
    }
}

template<>
dp::Bool dpLess(
    const dp::SpeakerKey &      _KEY1
    , const dp::SpeakerKey &    _KEY2
)
{
    //TODO
    return false;
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

    SpeakerKey * newSpeakerKey(
        //TODO
    )
    {
        return ::newSpeakerKey(
            //TODO
        );
    }
}
