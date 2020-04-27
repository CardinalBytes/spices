#ifndef SPICES_LIBRARY_H
#define SPICES_LIBRARY_H

#include <stdint.h>

#ifndef SPICES_VEC
#define SPICES_VEC
enum spice_vec_flags {
  auto_alloc 	= 1,
  n_aalloc		= 2,
  cpy_ref		= 4,
  default_mode	= auto_alloc,
};
typedef struct spices_vec__ spc_vec_t;
typedef enum spice_vec_flags spc_vflags_t;
#endif

/**
 * Initialize a new vector
 * @param isize the initial size to be allocated
 * @param size_itm the size of an individual item of this vector
 * @param flags vector feature flags
 * @return a pointer to the new vector
 */
spc_vec_t *spc_veci(uint64_t isize, uint64_t size_itm, spc_vflags_t flags);

void spc_free_vec(spc_vec_t *vec);

void spc_clear_vec(spc_vec_t *vec);

int spc_vecapd(spc_vec_t vec, void *ite_ptr);

#endif //SPICES_LIBRARY_H
