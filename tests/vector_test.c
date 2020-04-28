#include <stdio.h>

#include "../include/spices_core.h"

int main(void)
{
	spc_vec_t *vec;
	double val;
	int i;
	double *at_pos;

	vec = spc_veci(100, sizeof(double), 0);
	printf("len: %d, sizeof: %d", spc_vec_len(vec), spc_vec_sizeof(vec));

	for (i = 0; i < 10; i++) {
		val = 0.00 + (double)i;
		spc_vec_put_ord(vec, &val);
	}

	for (i = 0; i < 15; i++) {
		at_pos = spc_vec_popref(vec);
		if (at_pos) {
			printf("len: %d, sizeof: %d\n", spc_vec_len(vec), spc_vec_sizeof(vec));
			fprintf(stdout, "%d %.2f\n", i, *at_pos);
		}
	}

	spc_vec_free(vec);
	printf("done");
	return 0;
}