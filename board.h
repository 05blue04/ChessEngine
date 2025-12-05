#ifndef BOARD_H
#define BOARD_H
#include "bit_utils.h"
#include <stdio.h>
#include <stdlib.h>

static uint64_t white_pawn_start = 71776119061217280;
static uint64_t black_pawn_start = 65280;
static uint64_t white_knight_start = 4755801206503243776;
static uint64_t black_knight_start = 66;
static uint64_t white_bishop_start = 2594073385365405696;
static uint64_t black_bishop_start = 36;
static uint64_t white_rook_start = 9295429630892703744;
static uint64_t black_rook_start = 129;
static uint64_t white_queen_start = 576460752303423488;
static uint64_t black_queen_start = 8;
static uint64_t white_king_start = 1152921504606846976;
static uint64_t black_king_start = 16;

static uint64_t all_pieces_start = 0xffff00000000ffffULL;
static uint64_t white_start = 0x000000000000ffffULL;
static uint64_t black_start = 0xffff000000000000ULL;




typedef enum {
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1
} Square;

enum {white, black};

typedef struct{
    // White pieces
    uint64_t white_pawns;
    uint64_t white_knights;
    uint64_t white_bishops;
    uint64_t white_rooks;
    uint64_t white_queens;
    uint64_t white_king;
    
    // Black pieces
    uint64_t black_pawns;
    uint64_t black_knights;
    uint64_t black_bishops;
    uint64_t black_rooks;
    uint64_t black_queens;
    uint64_t black_king;

    //Board state 
    uint64_t all_pieces;
    uint64_t white_pieces;
    uint64_t black_pieces;

    int turn;
} Board;

//initalize board
Board *create_board_default();

//print board_mask
void print_board(uint64_t b);

#endif