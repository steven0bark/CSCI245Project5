#include <stdio.h>

#include "bitvector.h"

void
printVec(struct bit_vector *vec)
{
	int isFirst, i;
	printf("{");
	isFirst = 1;
	for (i = 0; i < 10; i++)
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
		for(a = j+1; j < vec->size; a++){
			if(j % a == 0){
				bv_remove(vec, a);
			}
		}

	} 	
	bv_remove(vec, 0);
	bv_remove(vec, 1);
	printVec(vec);	


	return 0;
}


