#ifndef SPICES_LIBRARY_H
#define SPICES_LIBRARY_H

#include <stdint.h>

#ifndef SPICES_VEC
#define SPICES_VEC
enum spice_vec_flags {
    auto_alloc = 1u,
    n_alloc = 2u,
    cpy_ref = 4u,
    default_mode = auto_alloc | cpy_ref,
};
typedef struct spices_vec__ spc_vec_t;
typedef enum spice_vec_flags spc_vtags_t;
#endif

/**
 * Initialize a new vector
 * @param init_size the initial cap to be allocated
 * @param itm_size the cap of an individual item of this vector
 * @param tags vector feature tags
 * @return a pointer to the new vector
 */
spc_vec_t *spc_veci (uint64_t init_size, uint64_t itm_size, spc_vtags_t tags);

void spc_free_vec (spc_vec_t *vec);

//void spc_clear_vec (spc_vec_t *vec);

int spc_vec_put_ord (spc_vec_t *vec, void *item_ptr);

#endif //SPICES_LIBRARY_H
