#include "attacks.h"

uint64_t mask_pawn_attacks(int color, int square){
    uint64_t attacks = 0ull;

    uint64_t bitboard = 0ull;

    set_bit(bitboard,square);

    if(color == white){
        if((bitboard >> 7) & not_a_file)
            attacks |= (bitboard >> 7);

        if((bitboard >> 9) & not_h_file)
            attacks |= (bitboard >> 9);
    } else{
        if((bitboard << 7) & not_h_file)
            attacks |= (bitboard << 7);

        if((bitboard << 9) & not_a_file)
            attacks |= (bitboard << 9);
    }
    return attacks;
}

void generate_pawn_attacks(uint64_t (*pawn_attacks)[64]){
    for(int square = 0; square < 64; square++){
        pawn_attacks[white][square] = mask_pawn_attacks(white,square);
        pawn_attacks[black][square] = mask_pawn_attacks(black, square);
    }
}