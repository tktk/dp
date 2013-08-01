#include "dpimpl/linux/input/gamepadmanager.h"
#include "dpimpl/common/input/gamepadmanager.h"
#include "dp/input/gamepadmanager.h"
#include "dpimpl/linux/input/gamepadkey.h"
#include "dp/input/gamepadkey.h"
#include "dp/common/primitives.h"

#include <libudev.h>
#include <new>
#include <thread>
#include <memory>
#include <utility>
#include <cstring>

namespace {
    const auto  SUBSYSTEM = "input";

    struct UdevDeleter
    {
        void operator()(
            udev *  _udev
        )
        {
            udev_unref( _udev );
        }
    };

    typedef std::unique_ptr<
        udev
        , UdevDeleter
    > UdevPtr;

    udev * udevNew(
    )
    {
        return udev_new();
    }

    struct UdevMonitorDeleter
    {
        void operator()(
            udev_monitor *  _monitor
        )
        {
            udev_monitor_unref( _monitor );
        }
    };

    typedef std::unique_ptr<
        udev_monitor
        , UdevMonitorDeleter
    > UdevMonitorPtr;

    udev_monitor * udevMonitorNew(
        udev &  _udev
    )
    {
        UdevMonitorPtr  monitorPtr(
            udev_monitor_new_from_netlink(
                &_udev
                , "udev"
            )
        );
        if( monitorPtr.get() == nullptr ) {
            return nullptr;
        }

        auto &  monitor = *monitorPtr;

        if( udev_monitor_filter_add_match_subsystem_devtype(
            &monitor
            , SUBSYSTEM
            , nullptr
        ) != 0 ) {
            return nullptr;
        }

        if( udev_monitor_enable_receiving( &monitor ) != 0 ) {
            return nullptr;
        }

        return monitorPtr.release();
    }

    struct UdevDeviceDeleter
    {
        void operator()(
            udev_device *   _device
        )
        {
            udev_device_unref( _device );
        }
    };

    typedef std::unique_ptr<
        udev_device
        , UdevDeviceDeleter
    > UdevDevicePtr;

    struct UdevEnumerateDeleter
    {
        void operator()(
            udev_enumerate *    _enumerate
        )
        {
            udev_enumerate_unref( _enumerate );
        }
    };

    typedef std::unique_ptr<
        udev_enumerate
        , UdevEnumerateDeleter
    > UdevEnumeratePtr;

    udev_enumerate * udevEnumerateNew(
        udev &  _udev
    )
    {
        UdevEnumeratePtr    enumeratePtr(
            udev_enumerate_new( &_udev )
        );
        if( enumeratePtr.get() == nullptr ) {
            return nullptr;
        }

        auto &  enumerate = *enumeratePtr;

        if( udev_enumerate_add_match_subsystem(
            &enumerate
            , SUBSYSTEM
        ) != 0 ) {
            return nullptr;
        }

        if( udev_enumerate_scan_devices( &enumerate ) != 0 ) {
            return nullptr;
        }

        return enumeratePtr.release();
    }

    void callConnectEventHandlerCommon(
        dp::GamePadManager &        _manager
        , const dp::StringChar *    _PATH
        , dp::Bool                  _connected
    )
    {
        dp::GamePadKeyPtr   keyPtr(
            dp::gamePadKeyNew(
                _PATH
            )
        );
        if( keyPtr.get() == nullptr ) {
            return;
        }

        const auto &    KEY = *keyPtr;

        dp::gamePadManagerCallConnectEventHandler(
            _manager
            , KEY
            , _connected
        );
    }

    void callConnectEventHandler(
        dp::GamePadManager &        _manager
        , const dp::StringChar *    _PATH
    )
    {
        callConnectEventHandlerCommon(
            _manager
            , _PATH
            , true
        );
    }

    void callDisconnectEventHandler(
        dp::GamePadManager &        _manager
        , const dp::StringChar *    _PATH
    )
    {
        callConnectEventHandlerCommon(
            _manager
            , _PATH
            , false
        );
    }

    dp::Bool isGamePadPath(
        const dp::StringChar *  _PATH
    )
    {
        const auto  NAME = std::strrchr(
            _PATH
            , '/'
        );
        if( NAME == nullptr ) {
            return false;
        }

        dp::UInt    tmp;
        if( std::sscanf(
            NAME
            , "/js%u"
            , &tmp
        ) != 1 ) {
            return false;
        }

        return true;
    }

    void initGamePads(
        dp::GamePadManager &    _manager
        , udev &                _udev
    )
    {
        UdevEnumeratePtr    enumeratePtr(
            udevEnumerateNew(
                _udev
            )
        );
        if( enumeratePtr.get() == nullptr ) {
            return;
        }

        auto &  enumerate = *enumeratePtr;

        auto    list = udev_enumerate_get_list_entry( &enumerate );

        udev_list_entry *   entry;
        udev_list_entry_foreach( entry, list ) {
            const auto  SYSPATH = udev_list_entry_get_name( entry );
            if( SYSPATH == nullptr ) {
                continue;
            }

            UdevDevicePtr   devicePtr(
                udev_device_new_from_syspath(
                    &_udev
                    , SYSPATH
                )
            );
            if( devicePtr.get() == nullptr ) {
                continue;
            }

            auto &  device = *devicePtr;

            const auto  PATH = udev_device_get_devnode( &device );
            if( PATH == nullptr ) {
                continue;
            }

            if( isGamePadPath( PATH ) == false ) {
                continue;
            }

            callConnectEventHandler(
                _manager
                , PATH
            );
        }
    }

    void monitorGamePads(
        dp::GamePadManager &        _manager
        , dp::GamePadManagerImpl &  _impl
        , udev &                    _udev
        , udev_monitor &            _monitor
    )
    {
        //TODO
    }

    void threadProc(
        dp::GamePadManager &        _manager
        , dp::GamePadManagerImpl &  _impl
    )
    {
        UdevPtr udevPtr( udevNew() );
        if( udevPtr.get() == nullptr ) {
            return;
        }

        auto &  udev = *udevPtr;

        UdevMonitorPtr  monitorPtr(
            udevMonitorNew(
                udev
            )
        );
        if( monitorPtr.get() == nullptr ) {
            return;
        }

        auto &  monitor = *monitorPtr;

        initGamePads(
            _manager
            , udev
        );

        monitorGamePads(
            _manager
            , _impl
            , udev
            , monitor
        );
    }
}

namespace dp {
    GamePadManagerImpl * gamePadManagerImplNew(
        GamePadManager &    _manager
    )
    {
        GamePadManagerImplPtr   implPtr( new( std::nothrow )GamePadManagerImpl );
        if( implPtr.get() == nullptr ) {
            return nullptr;
        }

        auto &  impl = *implPtr;

        impl.ended = false;
        impl.thread = std::move(
            std::thread(
                [
                    &_manager
                    , &impl
                ]
                {
                    threadProc(
                        _manager
                        , impl
                    );
                }
            )
        );

        return implPtr.release();
    }

    void gamePadManagerImplDelete(
        GamePadManagerImpl &    _impl
    )
    {
        _impl.ended = true;
        _impl.thread.join();

        delete &_impl;
    }
}
