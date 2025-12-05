#include "board.h"

Board *create_board_default(){
    Board *b = malloc(sizeof(*b));
    if(b == NULL)
        return NULL;
    
    b->all_pieces = all_pieces_start;
    b->white_pieces = white_start;
    b->black_pieces = black_start;

    b->white_pawns = white_pawn_start;
    b->black_pawns = black_pawn_start;
    b->white_knights = white_knight_start;
    b->black_knights = black_knight_start;
    b->white_bishops = white_bishop_start;
    b->black_bishops = black_bishop_start;
    b->white_rooks = white_rook_start;
    b->black_rooks = black_rook_start;
    b->white_queens = white_queen_start;
    b->black_queens = black_queen_start;
    b->white_king = white_king_start;
    b->black_king = black_king_start;

    b->turn = white;

    return b;
}

void print_board(uint64_t b){
    fprintf(stdout,"\n");

    for(int r = 0; r < 8; r++){
        for(int f = 0; f < 8; f++){
            int square = r * 8 + f;

            if(!f)
                printf(" %d | ",8 - r);
            
            fprintf(stdout," %d ",get_bit(b,square) ? 1 : 0);
        }
        fprintf(stdout, "\n");
    }

    printf("       _  _  _  _  _  _  _  _\n");
    printf("       a  b  c  d  e  f  g  h\n");

    printf("\n       Bitboard: %llu\n\n",b);
    printf("\n       Hexval: 0x%016llx\n", (unsigned long long)b);
}