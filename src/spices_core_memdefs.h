#ifndef SPICES_SRC_SPICES_CORE_MEMDEFS_H
#define SPICES_SRC_SPICES_CORE_MEMDEFS_H

#include <stdint.h>

struct spices_vec__ {
  uint64_t item_size;
  uint64_t size;
  uint64_t top;
  uint8_t flags;
  uint8_t exp_multip;
  uint8_t *data;
};

#endif //SPICES_SRC_SPICES_CORE_MEMDEFS_H
