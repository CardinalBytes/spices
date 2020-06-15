#ifndef SPICES_LIBRARY_H
#define SPICES_LIBRARY_H

#include "../src/typedefs.h"

#ifndef SPICES_VEC
#define SPICES_VEC
enum spice_vec_tags {
    auto_alloc = 1u,
    n_alloc = 2u,
    cpy_ref = 4u,
    n_auto_rz = 8u,
    default_mode = auto_alloc | cpy_ref | n_auto_rz,
};
typedef struct spices_vec__ spc_vec_t;
typedef enum spice_vec_tags spc_vtags_t;
#endif

/**
 * Initialize a new vector
 * @param init_size the initial cap to be allocated
 * @param itm_size the cap of an individual item of this vector
 * @param tags vector feature tags
 * @return a pointer to the new vector
 */
spc_vec_t *spc_veci(u64 init_size, u64 itm_size, spc_vtags_t tags);

/**
 * Free the memory used by the vector
 * @param vec
 */
void spc_vec_free(spc_vec_t *vec);

/**
 * Zero fill the memory and free the vector
 * @param vec
 */
void spc_vec_clear(spc_vec_t *vec);

/**
 * Put an item in order I.E at the end of the vector
 * @param vec The vector to append the item to
 * @param item_ptr Pointer to the item
 * @return returns 0 on success
 */
int spc_vec_put_ord(spc_vec_t *vec, void *item_ptr);

/**
 * Get reference to item at the index
 * @param vec Vector to get a reference to the item
 * @param index Index to obtain the reference to
 * @return Pointer to the item
 */
void *spc_vec_greft(spc_vec_t *vec, u64 index);

/**
 * Get reference to the top item of the vector
 * @param vec Vector to operate on
 * @return A reference to the item at the top of the vector
 */
void *spc_vec_popref(spc_vec_t *vec);

/**
 * How many used allocations there are in the vector
 * @param vec
 * @return Number of used allocations in the vector
 */
u64 spc_vec_len(spc_vec_t *vec);

/**
 * How much space is allocated for the vector in memory used or not
 * @param vec
 * @return Space that is allocated and may or may not be used
 */
u64 spc_vec_sizeof(spc_vec_t *vec);

#endif //SPICES_LIBRARY_H
