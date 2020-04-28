#ifndef SPICES_SRC_SPICES_CORE_MEMDEFS_H
#define SPICES_SRC_SPICES_CORE_MEMDEFS_H

#include <stdint.h>

struct spices_vec__ {
    uint64_t item_size;
    uint64_t cap;
    uint64_t used;
    uint8_t tags;
    uint8_t status_flags;
    char *top_ptr;
    char *data;
};

#endif //SPICES_SRC_SPICES_CORE_MEMDEFS_H
