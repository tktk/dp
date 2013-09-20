#include "dpimpl/linux/audio/speakermanager.h"
#include "dpimpl/linux/audio/pulseaudio.h"
#include "dpimpl/common/audio/speakermanager.h"
#include "dp/audio/speakermanager.h"
#include "dp/common/primitives.h"

#include <pulse/context.h>

namespace {
    void paContextReady(
        dp::SpeakerManager &    _manager
    )
    {
        //TODO
    }

    void paContextStateCallback(
        pa_context *    _context
        , void *        _manager
    )
    {
        auto &  manager = *static_cast< dp::SpeakerManager * >( _manager );

        switch( pa_context_get_state( _context ) ) {
        case PA_CONTEXT_READY:
            paContextReady(
                manager
            );
            break;

        default:
            break;
        }
    }
}

namespace dp {
    Bool initializeSpeakerManagerImpl(
        SpeakerManager &    _manager
    )
    {
        auto &  impl = *( _manager.implUnique );

        auto &  paContextUnique = impl.paContextUnique;
        paContextUnique.reset( newPAContext() );
        if( paContextUnique.get() == nullptr ) {
            return false;
        }

        auto &  paContext = *paContextUnique;

        pa_context_set_state_callback(
            &paContext
            , paContextStateCallback
            , &_manager
        );

        if( pa_context_connect(
            &paContext
            , nullptr
            , PA_CONTEXT_NOFAIL
            , nullptr
        ) < 0 ) {
            return false;
        }

        return true;
    }
}
