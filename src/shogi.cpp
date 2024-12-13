#include <cstdio>
#include <iostream>
#include <string>
#include "inc/shogi.hpp"

SQUARE standardBoard[81] = {G_LANCE, G_KNIGHT, G_SILVER, G_GOLD, G_KING, G_GOLD, G_SILVER, G_KNIGHT, G_LANCE,
                            EMPTY, G_ROOK, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, G_BISHOP, EMPTY,
                            G_PAWN, G_PAWN, G_PAWN, G_PAWN, G_PAWN, G_PAWN, G_PAWN, G_PAWN, G_PAWN,
                            EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
                            EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
                            EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
                            S_PAWN, S_PAWN, S_PAWN, S_PAWN, S_PAWN, S_PAWN, S_PAWN, S_PAWN, S_PAWN,
                            EMPTY, S_BISHOP, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, S_ROOK, EMPTY,
                            S_LANCE, S_KNIGHT, S_SILVER, S_GOLD, S_KING, S_GOLD, S_SILVER, S_KNIGHT, S_LANCE};

class kifMove {
    char piece;
    unsigned short int space;
};

void printBoard() {

    int row = 0;

    for (int i = 0; i < 81; i++) {

        switch (standardBoard[i])
        {
        case S_PAWN:
        case G_PAWN:
            std::cout << "歩";
            break;
        case S_LANCE:
        case G_LANCE:
            std::cout << "香";
            break;
        case S_KNIGHT:
        case G_KNIGHT:
            std::cout << "桂";
            break;
        case S_SILVER:
        case G_SILVER:
            std::cout << "銀";
            break;
        case S_GOLD:
        case G_GOLD:
            std::cout << "金";
            break;
        case S_KING:
            std::cout << "玉";
            break;
        case G_KING:
            std::cout << "王";
            break;
        case S_BISHOP:
        case G_BISHOP:
            std::cout << "角";
            break;
        case S_ROOK:
        case G_ROOK:        
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

void showCurrentPlayer(bool player) {
    
    std::cout << "Current player is: ";

    if (player)
    {
        std::cout << "Sente" << std::endl;
    }
    else
    {
        std::cout << "Gote" << std::endl;
    }
}

bool getMove() {
    std::string input;
    bool isValidMove;

    std::cout << "Please input move: ";
    std::cin >> input;

    if (input.size() < 3) {
        isValidMove = false;
        return isValidMove;
    }

    switch (input.at(0)) {
        case 'P':
            std::cout << "You're moving a Pawn" << std::endl;

            if (piece_at_pos(input.at(1) - '0', (input.at(2) - '0') + 1) != S_PAWN) 
            {
                std::cout << "Invalid Move!" << std::endl;
                isValidMove = false;
            }

            else        // Calculate Pawn movement
            {
                move_piece(input.at(1) - '0',
                            input.at(2) - '0' + 1,
                            input.at(1) - '0',
                            input.at(2) - '0');
                isValidMove = true;  
                return isValidMove;  
            }

            break;
        case 'L':
            std::cout << "You're moving a Lance" << std::endl;
            break;
        case 'N':
            std::cout << "You're moving a Knight" << std::endl;
            break;
        case 'S':
            std::cout << "You're moving a Silver General" << std::endl;
            break;
        case 'G':
            std::cout << "You're moving a Gold General" << std::endl;
            break;
        case 'B':
            std::cout << "You're moving a Bishop" << std::endl;
            break;
        case 'R':
            std::cout << "You're moving a Rook" << std::endl;
            break;
        case 'K':
            std::cout << "You're moving a King" << std::endl;
            break;
        default:
            isValidMove = false;
            return isValidMove;
        }

    for (int i = 0; i < input.size(); i++) {

    }

    switch (piece_at_pos(input.at(1) - '0', input.at(2) - '0')) {
        case S_PAWN:
        case G_PAWN:
            std::cout << "Pawn" << std::endl;
            break;
        case S_LANCE:
        case G_LANCE:
            std::cout << "Lance" << std::endl;
            break;
        case S_KNIGHT:
        case G_KNIGHT:
            std::cout << "Knight" << std::endl;
            break;
        case S_SILVER:
        case G_SILVER:
            std::cout << "Silver General" << std::endl;
            break;
        case S_GOLD:
        case G_GOLD:
            std::cout << "Gold General" << std::endl;
            break;
        case S_BISHOP:
        case G_BISHOP:
            std::cout << "Bishop" << std::endl;
            break;
        case S_ROOK:
        case G_ROOK:
            std::cout << "Rook" << std::endl;
            break;
        case S_KING:
            std::cout << "Sente King" << std::endl;
            break;
        case G_KING:
            std::cout << "Gote King" << std::endl;
            break;
        default:
            std::cout << "Empty Square" << std::endl;
    }

    isValidMove = true;
    return isValidMove;
}

int file_to_index(int file)
{
    return (9 - file);
}

int rank_to_index(int rank)
{
    int idx = (rank - 1) * 9;
    return idx;
}

SQUARE piece_at_pos(int file, int rank)
{
    return standardBoard[(file_to_index(file) + rank_to_index(rank))];
}

void move_piece(int from_file, int from_rank, int to_file, int to_rank)
{
    SQUARE piece;

    piece = standardBoard[(file_to_index(from_file) + rank_to_index(from_rank))];
    standardBoard[(file_to_index(from_file) + rank_to_index(from_rank))] = EMPTY;
    standardBoard[(file_to_index(to_file) + rank_to_index(to_rank))] = piece;
}