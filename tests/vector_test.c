#include <stdio.h>

#include "../include/spices_core.h"


int main(void)
{
	spc_vec_t *vec;
	double val;
	int i;
	double *at_pos;

	vec = spc_veci(100, sizeof(double), 0);

	for (i = 0; i < 10; i++) {
		val = 0.00 + (double)i;
		spc_vec_put_ord (vec, &val);
	}

	for (i = 0; i < 15; i++) {
		at_pos = spc_vec_get_ref_at (vec, i);
		if (at_pos)
			fprintf(stdout, "%.2f\n", *at_pos);
	}

	spc_free_vec(vec);
	return 0;
}