#ifndef DPIMPL_LINUX_COMMON_DESCRIPTORCLOSER_H
#define DPIMPL_LINUX_COMMON_DESCRIPTORCLOSER_H

#include "dp/common/primitives.h"

#include <memory>
#include <unistd.h>

namespace dp {
    struct DescriptorClose
    {
        void operator()(
            Int *   _descriptor
        )
        {
            close( *_descriptor );
        }
    };

    typedef std::unique_ptr<
        Int
        , DescriptorClose
    > DescriptorCloser;
}

#endif  // DPIMPL_LINUX_COMMON_DESCRIPTORCLOSER_H
