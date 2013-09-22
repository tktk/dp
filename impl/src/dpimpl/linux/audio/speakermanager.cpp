#include "dpimpl/linux/audio/speakermanager.h"
#include "dpimpl/linux/audio/pulseaudio.h"
#include "dpimpl/common/audio/speakermanager.h"
#include "dp/audio/speakermanager.h"
#include "dpimpl/linux/audio/speakerkey.h"
#include "dp/common/primitives.h"

#include <pulse/context.h>
#include <pulse/operation.h>
#include <pulse/introspect.h>
#include <pulse/subscribe.h>

namespace {
    void callConnectEventHandler(
        dp::SpeakerManager &    _manager
        , dp::UInt              _index
        , dp::Bool              _connected
    )
    {
        dp::SpeakerKeyUnique    keyUnique(
            dp::newSpeakerKey(
                _index
            )
        );
        if( keyUnique.get() == nullptr ) {
            return;
        }

        dp::callConnectEventHandler(
            _manager
            , std::move( keyUnique )
            , _connected
        );
    }

    void subscriptionEventNew(
        dp::UInt                _index
        , dp::SpeakerManager &  _manager
    )
    {
        callConnectEventHandler(
            _manager
            , _index
            , true
        );
    }

    void subscriptionEventRemove(
        dp::UInt                _index
        , dp::SpeakerManager &  _manager
    )
    {
        callConnectEventHandler(
            _manager
            , _index
            , false
        );
    }

    void subscriptionEventSink(
        pa_subscription_event_type_t    _type
        , dp::UInt                      _index
        , dp::SpeakerManager &          _manager
    )
    {
        const auto  EVENT_TYPE = static_cast< pa_subscription_event_type_t >(
            _type & PA_SUBSCRIPTION_EVENT_TYPE_MASK
        );

        switch( EVENT_TYPE ) {
        case PA_SUBSCRIPTION_EVENT_NEW:
            subscriptionEventNew(
                _index
                , _manager
            );
            break;

        case PA_SUBSCRIPTION_EVENT_REMOVE:
            subscriptionEventRemove(
                _index
                , _manager
            );
            break;

        default:
            break;
        }
    }

    void subscribeCallback(
        pa_context *                    _paContext
        , pa_subscription_event_type_t  _type
        , dp::UInt                      _index
        , void *                        _manager
    )
    {
        auto &  manager = *static_cast< dp::SpeakerManager * >( _manager );

        const auto  EVENT_FACILITY = static_cast< pa_subscription_event_type_t >(
            _type & PA_SUBSCRIPTION_EVENT_FACILITY_MASK
        );

        switch( EVENT_FACILITY ) {
        case PA_SUBSCRIPTION_EVENT_SINK:
            subscriptionEventSink(
                _type
                , _index
                , manager
            );
            break;

        default:
            break;
        }
    }

    void getSinkInfoCallback(
        pa_context *
        , const pa_sink_info *  _INFO
        , dp::Int
        , void *                _manager
    )
    {
        if( _INFO == nullptr ) {
            return;
        }

        auto &  manager = *static_cast< dp::SpeakerManager * >( _manager );

        callConnectEventHandler(
            manager
            , _INFO->index
            , true
        );
    }

    void initSpeakers(
        pa_context &            _paContext
        , dp::SpeakerManager &  _manager
    )
    {
        pa_operation_unref(
            pa_context_get_sink_info_list(
                &_paContext
                , getSinkInfoCallback
                , &_manager
            )
        );
    }

    void monitorSpeakers(
        pa_context &            _paContext
        , dp::SpeakerManager &  _manager
    )
    {
        pa_context_set_subscribe_callback(
            &_paContext
            , subscribeCallback
            , &_manager
        );

        pa_operation_unref(
            pa_context_subscribe(
                &_paContext
                , PA_SUBSCRIPTION_MASK_SINK
                , nullptr
                , nullptr
            )
        );
    }

    void paContextReady(
        pa_context &            _paContext
        , dp::SpeakerManager &  _manager
    )
    {
        monitorSpeakers(
            _paContext
            , _manager
        );

        initSpeakers(
            _paContext
            , _manager
        );
    }

    void paContextStateCallback(
        pa_context *    _paContext
        , void *        _manager
    )
    {
        auto &  manager = *static_cast< dp::SpeakerManager * >( _manager );

        switch( pa_context_get_state( _paContext ) ) {
        case PA_CONTEXT_READY:
            paContextReady(
                *_paContext
                , manager
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

        auto &  paContextDisconnector = impl.paContextDisconnector;
        paContextDisconnector.reset(
            connect(
                paContext
            )
        );
        if( paContextDisconnector.get() == nullptr ) {
            return false;
        }

        return true;
    }
}
