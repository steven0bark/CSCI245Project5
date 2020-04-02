#include <stdlib.h>

#include "bitvector.h"


int
numBytes(int n)
{
	return (n/8)+1;
}


struct bit_vector *
bv_create(int size)
{
	
	struct bit_vector *v = malloc(numBytes(size));
	v->size = size;
	v->vector = malloc(size);
	return v;
	
}

void
v_destroy(struct bit_vector *v)
{
	free(v->vector);
	free(v);
}

int
bv_contains(struct bit_vector *v, int i)
{
	return (v->vector[i/8] & 1 << i % 8);
}

void
bv_insert(struct bit_vector *v, int i)
{
	v->vector[i/8] = v->vector[i/8] | (1<<(i%8));
}

void
bv_remove(struct bit_vector *v, int i)
{
	v->vector[i/8] = v->vector[i/8] & ((~0) - (1<<(i%8)));
}

struct bit_vector *
bv_complement(struct bit_vector *v)
{	
	struct bit_vector *toreturn = bv_create(v->size);
	int i;
	for(i = 0; i< v->size; i++)
		toreturn->vector[i] = ~v->vector[i];
	return toreturn;
}

struct bit_vector *
bv_union(struct bit_vector *v1, struct bit_vector *v2)
{
	struct bit_vector *toreturn = bv_create(v1->size);
	int i;
	for(i = 0; i< v1->size; i++)
		toreturn->vector[i] = v1->vector[i] | v2->vector[i];
	return toreturn;
}

struct bit_vector *
bv_intersection(struct bit_vector *v1, struct bit_vector *v2)
{
	struct bit_vector *toreturn = bv_create(v1->size);
	int i;
	for(i = 0; i< v1->size; i++)
		toreturn->vector[i] = v1->vector[i] & v2->vector[i];
	return toreturn;
}

struct bit_vector *
bv_difference(struct bit_vector *v1, struct bit_vector *v2)
{
	struct bit_vector *toreturn = bv_create(v1->size);
	int i;
	for(i = 0; i< v1->size; i++)
		toreturn->vector[i] = v1->vector[i] & ~(v2->vector[i] & v2->vector[i]);
	return toreturn;
}
