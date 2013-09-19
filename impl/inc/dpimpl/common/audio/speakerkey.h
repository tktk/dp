#ifndef DPIMPL_COMMON_AUDIO_SPEAKERKEY_H
#define DPIMPL_COMMON_AUDIO_SPEAKERKEY_H

#if defined LINUX   // OS
#include "dpimpl/linux/audio/speakerkey.h"
#elif defined WINDOWS   // OS
#include "dpimpl/windows/audio/speakerkey.h"
#else   // OS
#error  未対応のOS
#endif  // OS

#endif  // DPIMPL_COMMON_AUDIO_SPEAKERKEY_H
