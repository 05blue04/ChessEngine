#ifndef ATTACKS_H
#define ATTACKS_H
#include "bit_utils.h"
#include "board.h"

// not A file constant
static const uint64_t not_a_file = 18374403900871474942ULL;

// not H file constant
static const uint64_t not_h_file = 9187201950435737471ULL;

// not HG file constant
static const uint64_t not_hg_file = 4557430888798830399ULL;

// not AB file constant
static const uint64_t not_ab_file = 18229723555195321596ULL;

// mask pawn attack 
uint64_t mask_pawn_attacks(int color, int square);

// generate attack table for pawns
void generate_pawn_attacks(uint64_t (*pawn_attacks)[64]);
#endif