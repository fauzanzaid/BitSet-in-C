#ifndef INCLUDE_GUARD_9B590AB7DDEA4B46AA1D708278DE34E8
#define INCLUDE_GUARD_9B590AB7DDEA4B46AA1D708278DE34E8


/////////////////////
// Data Structures //
/////////////////////

typedef struct BitSet BitSet;


//////////////////////////////////
// Constructors and Destructors //
//////////////////////////////////

/**
 * Allocates memory and returns pointer to BitSet struct
 * @param  index_lo Lowest index
 * @param  index_hi Highest index
 * @return          Pointer to BitSet struct
 */
BitSet *BitSet_new(int index_lo, int index_hi);

/**
 * Allocates memory and returns a pointer to a clone of another BitSet struct
 * passed as a pointer
 * @param  set_ptr Pointer to struct which is to be copied
 * @return         Pointer to new, copied struct
 */
BitSet *BitSet_clone(BitSet *set_ptr);

/**
 * Deallocates all internal memory assigned to the BitSet struct
 * @param set_ptr Pointer to BitSet struct
 */
void BitSet_destroy(BitSet *set_ptr);


///////////////////////////
// Operate on single set //
///////////////////////////

void BitSet_set_index(BitSet *set_ptr, int index);

void BitSet_clear_index(BitSet *set_ptr, int index);

void BitSet_toggle_index(BitSet *set_ptr, int index);

void BitSet_set_all(BitSet *set_ptr);

void BitSet_clear_all(BitSet *set_ptr);

void BitSet_toggle_all(BitSet *set_ptr);


/////////////////////////
// Operate on two sets //
/////////////////////////

void BitSet_and(BitSet *base_set_ptr, BitSet *other_set_ptr);

void BitSet_or(BitSet *base_set_ptr, BitSet *other_set_ptr);

void BitSet_xor(BitSet *base_set_ptr, BitSet *other_set_ptr);

void BitSet_subtract(BitSet *base_set_ptr, BitSet *other_set_ptr);


//////////////
// Retrieve //
//////////////

int BitSet_get_index(BitSet *set_ptr, int index);

/**
 * Check if any element is set to 1
 * @param  set_ptr Pointer to BitSet struct
 * @return         0 or 1
 */
int BitSet_get_any(BitSet *set_ptr);

/**
 * Check if all elements are set to 1
 * @param  set_ptr Pointer to BitSet struct
 * @return         0 or 1
 */
int BitSet_get_all(BitSet *set_ptr);


#endif
