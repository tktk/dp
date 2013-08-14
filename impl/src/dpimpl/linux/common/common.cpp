#include "dpimpl/linux/common/common.h"
#include "dpimpl/linux/common/stringconverter.h"
#include "dpimpl/linux/common/x11.h"

namespace dp {
    void initializeCommon(
    )
    {
        initializeStringConverter();
        initializeX11();
    }

    void finalizeCommon(
    )
    {
        finalizeStringConverter();
    }
}
