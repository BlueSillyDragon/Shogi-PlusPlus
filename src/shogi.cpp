#include <iostream>
#include "inc/shogi.h"

enum PLAYER {SENTE, GOTE};

enum SQUARE {PAWN, LANCE, KNIGHT, SILVER, GOLD, BISHOP, ROOK, KING, EMPTY};

SQUARE standardBoard[81] = {LANCE, KNIGHT, SILVER, GOLD, KING, GOLD, SILVER, KNIGHT, LANCE,
                            EMPTY, ROOK, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BISHOP, EMPTY,
                            PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
                            EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
                            EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
                            EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
                            PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
                            EMPTY, BISHOP, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, ROOK, EMPTY,
                            LANCE, KNIGHT, SILVER, GOLD, KING, GOLD, SILVER, KNIGHT, LANCE};

void printBoard() {

    int row = 0;

    for (int i = 0; i < 81; i++) {
        switch (standardBoard[i])
        {
        case PAWN:
            std::cout << "歩";
            break;
        case LANCE:
            std::cout << "香";
            break;
        case KNIGHT:
            std::cout << "桂";
            break;
        case SILVER:
            std::cout << "銀";
            break;
        case GOLD:
            std::cout << "金";
            break;
        case KING:
            std::cout << "王";
            break;
        case BISHOP:
            std::cout << "角";
            break;
        case ROOK:
            std::cout << "飛";
            break;
        case EMPTY:
            std::cout << "空";
            break;
        
        default:
            break;
        }

        row++;
        if (row > 8) {row = 0; std::cout << std::endl;}
    }

}