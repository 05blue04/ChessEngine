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

uint64_t mask_king_attacks(int square){

    uint64_t attacks = 0ull;

    uint64_t bitboard = 0ull;

    set_bit(bitboard,square);

    if (bitboard >> 8) attacks |= (bitboard >> 8);
    if ((bitboard >> 9) & not_h_file) attacks |= (bitboard >> 9);
    if ((bitboard >> 7) & not_a_file) attacks |= (bitboard >> 7);
    if ((bitboard >> 1) & not_h_file) attacks |= (bitboard >> 1);

    if (bitboard << 8) attacks |= (bitboard << 8);
    if ((bitboard << 9) & not_a_file) attacks |= (bitboard << 9);
    if ((bitboard << 7) & not_h_file) attacks |= (bitboard << 7);
    if ((bitboard << 1) & not_a_file) attacks |= (bitboard << 1);
    
    return attacks;
}

void generate_king_attacks(uint64_t king_attacks[64]){

    for(int square = 0; square < 64; square++){
        king_attacks[square] = mask_king_attacks(square);
    }
}

uint64_t mask_knight_attacks(int square){

    uint64_t attacks = 0ull;

    uint64_t bitboard = 0ull;

    set_bit(bitboard,square);

    //generate knight attacks 17, 15, 10, 6
    if((bitboard >> 17) & not_h_file)
        attacks |= (bitboard >> 17);
    if((bitboard >> 15) & not_a_file)
        attacks |= (bitboard >> 15);
    if((bitboard >> 10) & not_hg_file)
        attacks |= (bitboard >> 10);
    if((bitboard >> 6) & not_ab_file)
        attacks |= (bitboard >> 6);
    
    if((bitboard << 17) & not_a_file)
        attacks |= (bitboard << 17);
    if((bitboard << 15) & not_h_file)
        attacks |= (bitboard << 15);
    if((bitboard << 10) & not_ab_file)
        attacks |= (bitboard << 10);
    if((bitboard << 6) & not_hg_file)
        attacks |= (bitboard << 6);
    

    return attacks;

}

void generate_knight_attacks(uint64_t knight_attacks[64]){
    for(int square = 0; square < 64; square++){
        knight_attacks[square] = mask_knight_attacks(square);
    }
}