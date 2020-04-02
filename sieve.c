#include <stdio.h>

#include "bitvector.h"

void
printVec(struct bit_vector *vec)
{
	int isFirst, i;
	printf("{");
	isFirst = 1;
	for (i = 0; i < vec->size; i++)
		if (bv_contains(vec, i)) {
			if (!isFirst)
				printf(", ");
			printf("%d", i);
			isFirst = 0;
		}
	printf("} \n");
}

int
main(void)
{
	int n, i, j;
	struct bit_vector *vec;

	printf("Enter max int-> ");
	scanf("%d", &n);
	
	vec = bv_create(n + 1);
	for(i = 0; i < vec->size; i++){
		bv_insert(vec, i);
	}
	int a;
	for(j = 2; j < vec->size; j++){
		for(a = j+1; a < vec->size; a++){
			if((a % j) == 0){
				bv_remove(vec, a);
			}
		}

	} 	
	bv_remove(vec, 0);
	bv_remove(vec, 1);
	printVec(vec);	
	bv_destroy(vec);

	return 0;
}


