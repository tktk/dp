#include "dpimpl/util/export.h"
#include "dp/display/displaykey.h"

#include "dpimpl/common/display/displaykey.h"

template<>
void free(
    const dp::DisplayKey &  _KEY
)
{
    delete &_KEY;
}
