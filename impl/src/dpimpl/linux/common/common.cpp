#include "dpimpl/linux/common/common.h"
#include "dpimpl/linux/common/stringconverter.h"

namespace dp {
    void initializeCommon(
    )
    {
        initializeStringConverter();
    }

    void finalizeCommon(
    )
    {
        finalizeStringConverter();
    }
}
