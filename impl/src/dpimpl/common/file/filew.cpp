#include "dpimpl/util/export.h"
#include "dp/file/filew.h"

#include "dpimpl/common/file/filew.h"

namespace dp {
    void free(
        FileW & _file
    )
    {
        delete &_file;
    }
}
