#include <stdlib.h>


#include "BitSet.h"

/////////////////////
// Data Structures //
/////////////////////

typedef struct BitSet {
	
} BitSet;


//////////////////////////////////
// Constructors and Destructors //
//////////////////////////////////

BitSet *BitSet_new(int index_lo, int index_hi){

}

BitSet *BitSet_clone(BitSet *set_ptr){

}

void BitSet_destroy(BitSet *set_ptr){

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
