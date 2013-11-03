#include "dpimpl/linux/input/gamepadmanager.h"
#include "dpimpl/common/input/gamepadmanager.h"
#include "dp/input/gamepadmanager.h"
#include "dpimpl/linux/input/gamepadkey.h"
#include "dp/input/gamepadkey.h"
#include "dp/common/thread.h"
#include "dpimpl/linux/common/thread.h"
#include "dp/common/memory.h"
#include "dp/common/primitives.h"

#include <libudev.h>
#include <poll.h>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <utility>
#include <cstring>

template<>
void free(
    const udev &    _UDEV
)
{
    udev_unref( const_cast< udev * >( &_UDEV ) );
}

template<>
void free(
    const udev_monitor &    _MONITOR
)
{
    udev_monitor_unref( const_cast< udev_monitor * >( &_MONITOR ) );
}

template<>
void free(
    const udev_device & _DEVICE
)
{
    udev_device_unref( const_cast< udev_device * >( &_DEVICE ) );
}

template<>
void free(
    const udev_enumerate &  _ENUMERATE
)
{
    udev_enumerate_unref( const_cast< udev_enumerate * >( &_ENUMERATE ) );
}

namespace {
    const auto  SUBSYSTEM = "input";

    udev * newUdev(
    )
    {
        return udev_new();
    }

    udev_monitor * newUdevMonitor(
        udev &  _udev
    )
    {
        auto    monitorUnique = dp::unique(
            udev_monitor_new_from_netlink(
                &_udev
                , "udev"
            )
        );
        if( monitorUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  monitor = *monitorUnique;

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

        return monitorUnique.release();
    }

    typedef dp::Unique< udev_device >::type UdevDeviceUnique;

    typedef std::vector< UdevDeviceUnique > UdevDeviceUniques;

    udev_enumerate * newUdevEnumerate(
        udev &  _udev
    )
    {
        auto    enumerateUnique = dp::unique(
            udev_enumerate_new( &_udev )
        );
        if( enumerateUnique.get() == nullptr ) {
            return nullptr;
        }

        auto &  enumerate = *enumerateUnique;

        if( udev_enumerate_add_match_subsystem(
            &enumerate
            , SUBSYSTEM
        ) != 0 ) {
            return nullptr;
        }

        if( udev_enumerate_scan_devices( &enumerate ) != 0 ) {
            return nullptr;
        }

        return enumerateUnique.release();
    }

    void callConnectEventHandlerCommon(
        dp::GamePadManager &        _manager
        , const dp::StringChar *    _PATH
        , dp::Bool                  _connected
    )
    {
        auto    keyUnique = dp::unique(
            dp::newGamePadKey(
                _PATH
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
        auto    enumerateUnique = dp::unique(
            newUdevEnumerate(
                _udev
            )
        );
        if( enumerateUnique.get() == nullptr ) {
            return;
        }

        auto &  enumerate = *enumerateUnique;

        auto    list = udev_enumerate_get_list_entry( &enumerate );

        udev_list_entry *   entry;
        udev_list_entry_foreach( entry, list ) {
            const auto  SYSPATH = udev_list_entry_get_name( entry );
            if( SYSPATH == nullptr ) {
                continue;
            }

            auto    deviceUnique = dp::unique(
                udev_device_new_from_syspath(
                    &_udev
                    , SYSPATH
                )
            );
            if( deviceUnique.get() == nullptr ) {
                continue;
            }

            auto &  device = *deviceUnique;

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

    void monitorGamePadsEventLoop(
        dp::GamePadManager &    _manager
        , udev_monitor &        _monitor
        , UdevDeviceUniques &   _deviceUniques
    )
    {
        auto &  impl = *( _manager.implUnique );

        auto &  mutex = impl.mutex;
        auto &  cond = impl.cond;

        pollfd  fd;
        fd.fd = udev_monitor_get_fd( &_monitor );
        fd.events = POLLIN;

        while( 1 ) {
            errno = 0;
            while( poll( &fd, 1, -1 ) <= 0 ) {
                if( errno == EINTR ) {
                    errno = 0;
                } else {
                    return;
                }
            }

            auto    deviceUnique = dp::unique(
                udev_monitor_receive_device( &_monitor )
            );
            if( deviceUnique.get() == nullptr ) {
                continue;
            }

            std::unique_lock< std::mutex >  lock( mutex );

            _deviceUniques.push_back( std::move( deviceUnique ) );

            cond.notify_one();
        }
    }

    void monitorGamePadsManageLoopMainProc(
        dp::GamePadManager &        _manager
        , const UdevDeviceUniques & _DEVICE_PTRS
    )
    {
        for( auto & deviceUnique : _DEVICE_PTRS ) {
            if( deviceUnique.get() == nullptr ) {
                continue;
            }

            auto &  device = *deviceUnique;

            const auto  PATH = udev_device_get_devnode( &device );
            if( PATH == nullptr ) {
                continue;
            }

            if( isGamePadPath( PATH ) == false ) {
                continue;
            }

            const auto  ACTION = udev_device_get_action( &device );
            if( ACTION == nullptr ) {
                continue;
            }

            if( std::strcmp(
                ACTION
                , "add"
            ) == 0 ) {
                callConnectEventHandler(
                    _manager
                    , PATH
                );
            } else if( std::strcmp(
                ACTION
                , "remove"
            ) == 0 ) {
                callDisconnectEventHandler(
                    _manager
                    , PATH
                );
            }
        }
    }

    dp::Bool swapWhenNotEmpty(
        UdevDeviceUniques &     _deviceUniquesForEventLoop
        , UdevDeviceUniques &   _deviceUniques
    )
    {
        const auto  NOT_EMPTY = _deviceUniquesForEventLoop.empty() == false;

        if( NOT_EMPTY ) {
            std::swap(
                _deviceUniquesForEventLoop
                , _deviceUniques
            );
        }

        return NOT_EMPTY;
    }

    void waitManageLoop(
        std::mutex &                _mutex
        , std::condition_variable & _cond
        , const dp::Bool &          _ENDED
        , UdevDeviceUniques &       _deviceUniquesForEventLoop
        , UdevDeviceUniques &       _deviceUniques
    )
    {
        std::unique_lock< std::mutex >  lock( _mutex );

        _cond.wait(
            lock
            , [
                &_ENDED
                , &_deviceUniquesForEventLoop
                , &_deviceUniques
            ]
            {
                const auto  NOT_EMPTY = swapWhenNotEmpty(
                    _deviceUniquesForEventLoop
                    , _deviceUniques
                );

                return _ENDED || NOT_EMPTY;
            }
        );
    }

    void monitorGamePadsManageLoop(
        dp::GamePadManager &    _manager
        , UdevDeviceUniques &   _deviceUniquesForEventLoop
    )
    {
        auto &  impl = *( _manager.implUnique );

        auto &  mutex = impl.mutex;
        auto &  cond = impl.cond;

        const auto &    ENDED = impl.ended;

        while( 1 ) {
            UdevDeviceUniques  deviceUniques;

            waitManageLoop(
                mutex
                , cond
                , ENDED
                , _deviceUniquesForEventLoop
                , deviceUniques
            );

            if( ENDED ) {
                break;
            }

            monitorGamePadsManageLoopMainProc(
                _manager
                , deviceUniques
            );
        }
    }

    void monitorGamePads(
        dp::GamePadManager &    _manager
        , udev_monitor &        _monitor
    )
    {
        UdevDeviceUniques   deviceUniques;

        std::thread eventThread(
            [
                &_manager
                , &_monitor
                , &deviceUniques
            ]
            {
                monitorGamePadsEventLoop(
                    _manager
                    , _monitor
                    , deviceUniques
                );
            }
        );
        dp::ThreadJoiner    threadJoiner( &eventThread );
        dp::ThreadCanceller threadCanceller( &eventThread );

        monitorGamePadsManageLoop(
            _manager
            , deviceUniques
        );
    }

    void threadProc(
        dp::GamePadManager &    _manager
    )
    {
        auto    udevUnique = dp::unique( newUdev() );
        if( udevUnique.get() == nullptr ) {
            return;
        }

        auto &  udev = *udevUnique;

        auto    monitorUnique = dp::unique(
            newUdevMonitor(
                udev
            )
        );
        if( monitorUnique.get() == nullptr ) {
            return;
        }

        auto &  monitor = *monitorUnique;

        initGamePads(
            _manager
            , udev
        );

        monitorGamePads(
            _manager
            , monitor
        );
    }
}

namespace dp {
    Bool initializeGamePadManagerImpl(
        GamePadManager &    _manager
    )
    {
        auto &  impl = *( _manager.implUnique );

        impl.ended = false;

        impl.thread = std::move(
            std::thread(
                [
                    &_manager
                ]
                {
                    threadProc(
                        _manager
                    );
                }
            )
        );
        impl.threadJoiner.reset( &( impl.thread ) );
        impl.threadExiter.reset( &impl );

        return true;
    }

    void GamePadManagerImpl::ExitThread::operator()(
        GamePadManagerImpl *    _impl
    ) const
    {
        auto &  mutex = _impl->mutex;

        std::unique_lock< std::mutex >  lock( mutex );

        _impl->ended = true;

        _impl->cond.notify_one();
    }
}
