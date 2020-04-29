#ifndef SPICES_SRC_SPICES_CORE_MEMDEFS_H
#define SPICES_SRC_SPICES_CORE_MEMDEFS_H

#include "typedefs.h"

struct spices_vec__ {
    u64 item_size;
    u64 cap;
    u64 used;
    u8 tags;
    u8 status_flags;
    char *top_ptr;
    char *data;
};

#endif //SPICES_SRC_SPICES_CORE_MEMDEFS_H
