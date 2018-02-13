#include <stdlib.h>
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


//////////////////////////////////
// Constructors and Destructors //
//////////////////////////////////

BitSet *BitSet_new(int index_lo, int index_hi){
	BitSet *set_ptr = malloc( sizeof(BitSet) );
	
	set_ptr->index_lo = index_lo;
	set_ptr->index_hi = index_hi;
	set_ptr->size = index_hi - index_lo + 1;
	// Round up
	set_ptr->len_array = ( sizeof(unsigned) - 1 + set_ptr->size ) / sizeof(unsigned);
	
	set_ptr->array = malloc( set_ptr->len_array );

	return set_ptr;
}

BitSet *BitSet_clone(BitSet *set_ptr){
	BitSet *clone_set_ptr = malloc( sizeof(BitSet) );

	clone_set_ptr->index_lo = set_ptr->index_lo;
	clone_set_ptr->index_hi = set_ptr->index_hi;
	clone_set_ptr->size = set_ptr->size;
	clone_set_ptr->len_array = set_ptr->len_array;

	clone_set_ptr->array = malloc( clone_set_ptr->len_array * sizeof(unsigned) );
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

void BitSet_set_index(BitSet *set_ptr, int index, int value){

}

void BitSet_flip_index(BitSet *set_ptr, int index){

}

void BitSet_set_all(BitSet *set_ptr, int value){

}

void BitSet_not(BitSet *set_ptr){

}


/////////////////////////
// Operate on two sets //
/////////////////////////

void BitSet_and(BitSet *base_set_ptr, BitSet *other_set_ptr){

}

void BitSet_or(BitSet *base_set_ptr, BitSet *other_set_ptr){

}

void BitSet_xor(BitSet *base_set_ptr, BitSet *other_set_ptr){

}

void BitSet_difference(BitSet *base_set_ptr, BitSet *other_set_ptr){

}


//////////////
// Retrieve //
//////////////

int BitSet_get_index(BitSet *set_ptr, int index){

}

int BitSet_get_any(BitSet *set_ptr){

}

int BitSet_get_all(BitSet *set_ptr){

}
