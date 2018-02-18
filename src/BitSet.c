#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "BitSet.h"

/////////////////////
// Data Structures //
/////////////////////

typedef struct BitSet {
	int index_lo, index_hi;
	int size;
	int len_array;
	unsigned *array;
} BitSet;


///////////////////////
// Private functions //
///////////////////////

static int compatibility_check(BitSet *set1_ptr, BitSet *set2_ptr){
	if(set1_ptr->index_lo == set2_ptr->index_lo &&
		set1_ptr->index_hi == set2_ptr->index_hi)
		return 1;
	return 0;
}

static void index_check(BitSet *set_ptr, int index){
	if(index < set_ptr->index_lo || index > set_ptr->index_hi){
		fprintf(stderr, "BitSet : index %d out of range [%d,%d]\n", index, set_ptr->index_lo, set_ptr->index_hi);
		exit(1);
	}
}


//////////////////////////////////
// Constructors and Destructors //
//////////////////////////////////

BitSet *BitSet_new(int index_lo, int index_hi){
	BitSet *set_ptr = malloc( sizeof(BitSet) );
	
	set_ptr->index_lo = index_lo;
	set_ptr->index_hi = index_hi;
	set_ptr->size = index_hi - index_lo + 1;
	// Round up
	set_ptr->len_array = ( (8*sizeof(unsigned)) - 1 + set_ptr->size ) / (8*sizeof(unsigned));
	
	set_ptr->array = malloc( sizeof(unsigned) * set_ptr->len_array );
	memset(set_ptr->array, 0, sizeof(unsigned) * set_ptr->len_array );

	return set_ptr;
}

BitSet *BitSet_clone(BitSet *set_ptr){
	BitSet *clone_set_ptr = malloc( sizeof(BitSet) );

	clone_set_ptr->index_lo = set_ptr->index_lo;
	clone_set_ptr->index_hi = set_ptr->index_hi;
	clone_set_ptr->size = set_ptr->size;
	clone_set_ptr->len_array = set_ptr->len_array;

	clone_set_ptr->array = malloc( sizeof(unsigned) * clone_set_ptr->len_array );
	memcpy(clone_set_ptr->array, set_ptr->array, clone_set_ptr->len_array * sizeof(unsigned) );

	return clone_set_ptr;
}

void BitSet_destroy(BitSet *set_ptr){
	free(set_ptr->array);
	free(set_ptr);
}


///////////////////////////
// Operate on single set //
///////////////////////////

void BitSet_set_bit(BitSet *set_ptr, int index){
	index_check(set_ptr, index);

	int i = (index - set_ptr->index_lo) / (8*sizeof(unsigned));
	int j = (index - set_ptr->index_lo) % (8*sizeof(unsigned));

	set_ptr->array[i] |= 1u << j;
}

void BitSet_clear_bit(BitSet *set_ptr, int index){
	index_check(set_ptr, index);

	int i = (index - set_ptr->index_lo) / (8*sizeof(unsigned));
	int j = (index - set_ptr->index_lo) % (8*sizeof(unsigned));

	set_ptr->array[i] &= ~(1u << j);
}

void BitSet_toggle_bit(BitSet *set_ptr, int index){
	index_check(set_ptr, index);

	int i = (index - set_ptr->index_lo) / (8*sizeof(unsigned));
	int j = (index - set_ptr->index_lo) % (8*sizeof(unsigned));

	set_ptr->array[i] ^= 1u << j;
}

void BitSet_set_all(BitSet *set_ptr){
	memset(set_ptr->array, -1, sizeof(unsigned) * set_ptr->len_array );
}

void BitSet_clear_all(BitSet *set_ptr){
	memset(set_ptr->array, 0, sizeof(unsigned) * set_ptr->len_array );
}

void BitSet_toggle_all(BitSet *set_ptr){
	for (int i = 0; i < set_ptr->len_array; ++i)
	{
		set_ptr->array[i] ^= -1;
	}
}


/////////////////////////
// Operate on two sets //
/////////////////////////

void BitSet_and(BitSet *base_set_ptr, BitSet *other_set_ptr){
	if(!compatibility_check(base_set_ptr, other_set_ptr))
		return;
	for (int i = 0; i < base_set_ptr->len_array; ++i)
	{
		base_set_ptr->array[i] &= other_set_ptr->array[i];
	}
}

void BitSet_or(BitSet *base_set_ptr, BitSet *other_set_ptr){
	if(!compatibility_check(base_set_ptr, other_set_ptr))
		return;
	for (int i = 0; i < base_set_ptr->len_array; ++i)
	{
		base_set_ptr->array[i] |= other_set_ptr->array[i];
	}
}

void BitSet_xor(BitSet *base_set_ptr, BitSet *other_set_ptr){
	if(!compatibility_check(base_set_ptr, other_set_ptr))
		return;
	for (int i = 0; i < base_set_ptr->len_array; ++i)
	{
		base_set_ptr->array[i] ^= other_set_ptr->array[i];
	}
}

void BitSet_subtract(BitSet *base_set_ptr, BitSet *other_set_ptr){
	if(!compatibility_check(base_set_ptr, other_set_ptr))
		return;
	for (int i = 0; i < base_set_ptr->len_array; ++i)
	{
		base_set_ptr->array[i] &= ~other_set_ptr->array[i];
	}
}


//////////////
// Retrieve //
//////////////

int BitSet_get_bit(BitSet *set_ptr, int index){
	index_check(set_ptr, index);

	int i = (index - set_ptr->index_lo) / (8*sizeof(unsigned));
	int j = (index - set_ptr->index_lo) % (8*sizeof(unsigned));

	return (set_ptr->array[i] >> j ) & 1u; 
}

int BitSet_get_any(BitSet *set_ptr){
	int i;
	for (i = 0; i < set_ptr->size / (8*sizeof(unsigned)); ++i)
		if(set_ptr->array[i] != 0u)
			return 1;

	int j = set_ptr->size % (8*sizeof(unsigned));
	if(j){
		int check = (~(-1<<j))&set_ptr->array[i];
		if(check != 0)
			return 1;
	}

	return 0;
}

int BitSet_get_all(BitSet *set_ptr){
	int i;
	for (int i = 0; i < set_ptr->size / (8*sizeof(unsigned)); ++i)
		if(set_ptr->array[i] != -1)
			return 0;

	int j = set_ptr->size % (8*sizeof(unsigned));
	if(j){
		int check = (-1<<j)|set_ptr->array[i];
		if(check != -1)
			return 0;
	}

	return 1;
}
