#include "../include/spices_core.h"

#include "spices_core_memdefs.h"
#include <stdlib.h>
#include <string.h>

int vec_exp_by (spc_vec_t *vec, uint64_t by)
{
	uint64_t reloc_size;

	if ((vec->tags & n_alloc) != 0)
		return -1;

	reloc_size = (vec->cap * by) * vec->item_size;
	vec->data = (char *)realloc ((void *)vec->data, reloc_size);
	if (!vec->data)
		return -1;

	vec->cap = vec->cap * by;
	/* update the pointer to the vector topmost item */
	vec->top_ptr = vec->data + (vec->used * vec->item_size);
	return 0;
}

spc_vec_t *spc_veci (uint64_t init_size, uint64_t itm_size, spc_vtags_t tags)
{
	spc_vec_t *vec = 0;
	char *data = 0;

	vec = malloc (sizeof (spc_vec_t));
	if (!vec)
		goto spc_vec_alloc_fault;

	data = (char *)malloc (itm_size * init_size);
	if (!data)
		goto spc_vec_alloc_fault;

	if (!tags)
		tags = default_mode;

	vec->item_size = itm_size;
	vec->cap = init_size;
	vec->used = 0;
	vec->tags = tags;
	vec->top_ptr = data;
	vec->data = data;

    spc_vec_alloc_fault:
	free (vec);
	free (data);
	return 0;
}

void spc_free_vec (spc_vec_t *vec)
{
	free ((void *)vec->data);
	free ((void *)vec);
}

int spc_vec_put_ord (spc_vec_t *vec, void *item_ptr)
{
	char *itm_addr;

	if (vec->used >= vec->cap)
		vec_exp_by (vec, 2);

	vec->used++;
	itm_addr = memcpy ((void *)vec->top_ptr, item_ptr, vec->item_size);
	if (!itm_addr)
		return -1;

	vec->top_ptr = itm_addr + vec->item_size;
	return 0;
}


