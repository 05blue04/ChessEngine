#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "attacks.h"

// pawn attack tables
uint64_t pawn_attacks[2][64];

int main(int argc, char **argv){
    
    generate_pawn_attacks(pawn_attacks);

    for(int i = 0; i < 64;i++){
        print_board(pawn_attacks[white][i]);
    }

    Board *b = create_board_default();

    free(b);

    return EXIT_SUCCESS;
}