#ifndef BIT_UTILS_H
#define BIT_UTILS_H
#include <stdint.h>

// set/get/pop macros

#define get_bit(mask, square) (mask & (1ULL << square))
#define set_bit(mask, square) (mask |= (1ULL << square))
#define clear_bit(mask, square) (mask &= ~(1UL << square))
#define toggle_bit(mask, square) (mask ^= (1ULL << square))

#endif // BIT_UTILS_H