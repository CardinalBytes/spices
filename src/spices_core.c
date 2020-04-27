#include "../include/spices_core.h"

#include "spices_core_memdefs.h"
#include <stdlib.h>

spc_vec_t *spc_veci(uint64_t isize, uint64_t size_itm, spc_vflags_t flags) {
  spc_vec_t *vec = 0;

  vec = malloc(sizeof(spc_vec_t));
  if (vec == 0)
    goto except;

except:
  free(vec);
  return 0;
}
