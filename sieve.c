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
	printf("After the enter");
	scanf("%d", &n);
	printf("After the scan");
	
	printf("right before create");	
	vec = bv_create(n + 1);
	printf("right after create");
	for(i = 0; i < vec->size; i++){
		printf("i: %d", i);
		bv_insert(vec, i);
	}
	int a;
	for(j = 2; j < vec->size; j++){
		for(a = j+1; j < vec->size; a++){
			if(j % a == 0){
				printf("j: %d/na: %d",j ,a); 
				bv_remove(vec, a);
			}
		}

	} 	
	bv_remove(vec, 0);
	bv_remove(vec, 1);
	printVec(vec);	


	return 0;
}


