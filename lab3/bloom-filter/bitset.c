#include "bitset.h"
#include <stdlib.h>

// create a new, empty bit vector set with a universe of 'size' items
struct bitset * bitset_new(int size) {
  /* struct bitset *result;
  result = malloc(sizeof(struct bitset));
  float  word_size = sizeof(uint64_t) * 8;
  result->universe_size = size;
  int words = result->universe_size;
  words= words/(int) word_size;
  result->size_in_words = words;
  result->bits = malloc(sizeof(uint64_t) * words);
  for (int i = 0; i < words; i++)
    {
        result->bits[i] = 0;
    }
    return result;*/
  struct bitset *result = malloc(sizeof(struct bitset));

    float word_size = sizeof(uint64_t) * 8;
    result->universe_size = size;
    int words = result->universe_size /(int) word_size;
    result->size_in_words = words;
    result->bits = malloc(sizeof(uint64_t) * words);
    for (int i = 0; i < words; i++)
    {
        result->bits[i] = 0;
    }
    return result;
  
}

// get the size of the universe of items that could be stored in the set
int bitset_size(struct bitset * this) {

  return this->universe_size;
  
}

// get the number of items that are stored in the set
int bitset_cardinality(struct bitset * this){

  int num = 0;
  for (int i = 0; i< this->size_in_words; i++)
   {
     if (this->bits[i])
       {
	 num++;
       }
     this->bits[i] >>= 1;
   }
  return num;
  
}

// check to see if an item is in the set
int bitset_lookup(struct bitset * this, int item){

  
  return 2;
}

// add an item, with number 'item' to the set
// has no effect if the item is already in the set
void bitset_add(struct bitset * this, int item) {

   int word_size = sizeof(uint64_t) * 8;
    int words = item / word_size;
    int bit = item % word_size;
    uint64_t old_val = this->bits[words];
    uint64_t mask = 1ul << bit;
    this->bits[words] = old_val | mask;
}

// remove an item with number 'item' from the set
void bitset_remove(struct bitset * this, int item) {
}

// place the union of src1 and src2 into dest;
// all of src1, src2, and dest must have the same size universe
void bitset_union(struct bitset * dest, struct bitset * src1,
    struct bitset * src2) {
}

// place the intersection of src1 and src2 into dest
// all of src1, src2, and dest must have the same size universe
void bitset_intersect(struct bitset * dest, struct bitset * src1,
    struct bitset * src2) {
}
