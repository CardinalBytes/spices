#include "../include/spices_core.h"

#include "spices_core_memdefs.h"
#include "typedefs.h"
#include <stdlib.h>
#include <string.h>

int vec_rsz_by(spc_vec_t *vec, double multipl)
{
	u64 reloc_size;

	if ((vec->tags & n_alloc) != 0)
		return -1;

	reloc_size = (vec->cap * multipl) * vec->item_size;
	vec->data = (char *)realloc((void *)vec->data, reloc_size);
	if (!vec->data)
		return -1;

	vec->cap = vec->cap * multipl;
	/* update the pointer to the vector topmost item */
	vec->top_ptr = vec->data + (vec->used * vec->item_size);
	return 0;
}

spc_vec_t *spc_veci(u64 init_size, u64 itm_size, spc_vtags_t tags)
{
	spc_vec_t *vec = 0;
	char *data = 0;
	u64 data_size;

	vec = malloc(sizeof(spc_vec_t));
	if (!vec)
		goto spc_vec_alloc_fault;

	data_size = init_size * itm_size;

	data = (char *)malloc(data_size);
	if (!data)
		goto spc_vec_alloc_fault;

	if (!tags)
		tags = default_mode;

	vec->item_size = itm_size;
	vec->cap = init_size;
	vec->used = 0;
	vec->tags = tags;
	vec->status_flags = 0;
	vec->top_ptr = data;
	vec->data = data;

	return vec;
    spc_vec_alloc_fault:
	free(vec);
	free(data);
	return NULL;
}

void spc_vec_free(spc_vec_t *vec)
{
	free((void *)vec->data);
	free((void *)vec);
	vec = NULL;
}

void spc_vec_clear(spc_vec_t *vec)
{
	memset(vec->data, 0xFF, sizeof(spc_vec_t) + (vec->cap * vec->item_size));
	spc_vec_free(vec);
}

int spc_vec_put_ord(spc_vec_t *vec, void *item_ptr)
{
	char *itm_addr;

	if (vec->used >= vec->cap)
		vec_rsz_by(vec, 2.0f);

	vec->used++;
	itm_addr = memcpy((void *)vec->top_ptr, item_ptr, vec->item_size);
	if (!itm_addr)
		return -1;

	vec->top_ptr += vec->item_size;
	return 0;
}

void *spc_vec_greft(spc_vec_t *vec, u64 index)
{
	u64 offset;
	void *offset_ptr;

	if (index > vec->used - 1)
		return NULL;

	offset = index != 0 ? index * vec->item_size : 0;
	offset_ptr = (void *)vec->data + offset;

	return offset_ptr;
}

void *spc_vec_popref(spc_vec_t *vec)
{
	void *ref;

	if (vec->used <= (vec->cap / 2) && (vec->tags & 8) == 0)
		vec_rsz_by(vec, 0.5f);

	if (vec->top_ptr == vec->data + vec->item_size && vec->used > 0) {
		ref = vec->data;
		vec->used--;
		return ref;
	} else if (vec->used <= 0) {
		return NULL;
	}

	ref = (void *)vec->top_ptr - vec->item_size;
	vec->top_ptr -= vec->item_size;
	vec->used--;

	return ref;
}

u64 spc_vec_len(spc_vec_t *vec)
{
	return vec->used;
}

u64 spc_vec_sizeof(spc_vec_t *vec)
{
	return vec->cap;
}