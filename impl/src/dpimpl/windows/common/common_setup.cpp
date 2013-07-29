#include "dpimpl/windows/common/common.h"

#include <windows.h>

BOOL WINAPI DllMain(
    HINSTANCE
    , DWORD     _reason
    , LPVOID
)
{
    switch( _reason ) {
    case DLL_PROCESS_ATTACH:
        dp::initializeCommon();
        break;

    case DLL_PROCESS_DETACH:
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;

    default:
        break;
    }

    return TRUE;
}
