#include <stdio.h>

#include "BitSet.h"

int main(int argc, char const *argv[])
{
	BitSet *set1_ptr = BitSet_new(5,8);
	BitSet *set2_ptr = BitSet_new(5,8);

	BitSet_set_bit(set1_ptr, 6);
	BitSet_set_bit(set1_ptr, 7);
	BitSet_set_bit(set2_ptr, 7);
	BitSet_set_bit(set2_ptr, 8);

	printf("Set 1 original\t");
	for (int i = 5; i <= 8; ++i)	printf(" %d", BitSet_get_bit(set1_ptr, i));
	printf("\tAny:%d All:%d\n", BitSet_get_any(set1_ptr), BitSet_get_all(set1_ptr));

	printf("Set 2 original\t");
	for (int i = 5; i <= 8; ++i)	printf(" %d", BitSet_get_bit(set2_ptr, i));
	printf("\tAny:%d All:%d\n", BitSet_get_any(set2_ptr), BitSet_get_all(set2_ptr));

	
	
	BitSet *set_and_ptr = BitSet_clone(set1_ptr);
	BitSet *set_or_ptr = BitSet_clone(set1_ptr);
	BitSet *set_xor_ptr = BitSet_clone(set1_ptr);
	BitSet *set_subtract_ptr = BitSet_clone(set1_ptr);
	BitSet *set_set_all_ptr = BitSet_clone(set1_ptr);
	BitSet *set_clear_all_ptr = BitSet_clone(set1_ptr);
	BitSet *set_clear_bit_ptr = BitSet_clone(set1_ptr);



	BitSet_and(set_and_ptr, set2_ptr);
	BitSet_or(set_or_ptr, set2_ptr);
	BitSet_xor(set_xor_ptr, set2_ptr);
	BitSet_subtract(set_subtract_ptr, set2_ptr);
	BitSet_set_all(set_set_all_ptr);
	BitSet_clear_all(set_clear_all_ptr);
	BitSet_clear_bit(set_clear_bit_ptr, 7);


	printf("Set 1 & 2\t");
	for (int i = 5; i <= 8; ++i)	printf(" %d", BitSet_get_bit(set_and_ptr, i));
	printf("\tAny:%d All:%d\n", BitSet_get_any(set_and_ptr), BitSet_get_all(set_and_ptr));

	printf("Set 1 | 2\t");
	for (int i = 5; i <= 8; ++i)	printf(" %d", BitSet_get_bit(set_or_ptr, i));
	printf("\tAny:%d All:%d\n", BitSet_get_any(set_or_ptr), BitSet_get_all(set_or_ptr));

	printf("Set 1 ^ 2\t");
	for (int i = 5; i <= 8; ++i)	printf(" %d", BitSet_get_bit(set_xor_ptr, i));
	printf("\tAny:%d All:%d\n", BitSet_get_any(set_xor_ptr), BitSet_get_all(set_xor_ptr));

	printf("Set 1 - 2\t");
	for (int i = 5; i <= 8; ++i)	printf(" %d", BitSet_get_bit(set_subtract_ptr, i));
	printf("\tAny:%d All:%d\n", BitSet_get_any(set_subtract_ptr), BitSet_get_all(set_subtract_ptr));

	printf("Set 1 set all\t");
	for (int i = 5; i <= 8; ++i)	printf(" %d", BitSet_get_bit(set_set_all_ptr, i));
	printf("\tAny:%d All:%d\n", BitSet_get_any(set_set_all_ptr), BitSet_get_all(set_set_all_ptr));

	printf("Set 1 clear all\t");
	for (int i = 5; i <= 8; ++i)	printf(" %d", BitSet_get_bit(set_clear_all_ptr, i));
	printf("\tAny:%d All:%d\n", BitSet_get_any(set_clear_all_ptr), BitSet_get_all(set_clear_all_ptr));

	printf("Set 1 clear 7\t");
	for (int i = 5; i <= 8; ++i)	printf(" %d", BitSet_get_bit(set_clear_bit_ptr, i));
	printf("\tAny:%d All:%d\n", BitSet_get_any(set_clear_bit_ptr), BitSet_get_all(set_clear_bit_ptr));


	BitSet_destroy(set1_ptr);
	BitSet_destroy(set2_ptr);

	BitSet_destroy(set_and_ptr);
	BitSet_destroy(set_or_ptr);
	BitSet_destroy(set_xor_ptr);
	BitSet_destroy(set_subtract_ptr);
	BitSet_destroy(set_set_all_ptr);
	BitSet_destroy(set_clear_all_ptr);
	BitSet_destroy(set_clear_bit_ptr);

	return 0;
}
