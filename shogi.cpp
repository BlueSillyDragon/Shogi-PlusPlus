//
// Created by blues on 5/22/2025.
//
#include <iostream>
#include <string>
#include <vector>
#include <shogi.hpp>

#define VALUE_PAWN 1
#define VALUE_LANCE 3
#define VALUE_KNIGHT 4
#define VALUE_SILVER 5
#define VALUE_GOLD 6
#define VALUE_BISHOP 8
#define VALUE_ROOK 9

int piece[81] = {
    LANCE, KNIGHT, SILVER, GOLD, KING, GOLD, SILVER, KNIGHT, LANCE,
    EMPTY, ROOK, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BISHOP, EMPTY,
    PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
    EMPTY, BISHOP, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, ROOK, EMPTY,
    LANCE, KNIGHT, SILVER, GOLD, KING, GOLD, SILVER, KNIGHT, LANCE};

int color[81] = {
    GOTE, GOTE, GOTE, GOTE, GOTE, GOTE, GOTE, GOTE, GOTE,
    EMPTY, GOTE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, GOTE, EMPTY,
    GOTE, GOTE, GOTE, GOTE, GOTE, GOTE, GOTE, GOTE, GOTE,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    SENTE, SENTE, SENTE, SENTE, SENTE, SENTE, SENTE, SENTE, SENTE,
    EMPTY, SENTE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, SENTE, EMPTY,
    SENTE, SENTE, SENTE, SENTE, SENTE, SENTE, SENTE, SENTE, SENTE};

int empty_squares() {
    // This function checks to see how many spaces are empty
    int emptyNum = 0;
    for (int i = 0; i < 81; i++) {
            if (piece[i] == EMPTY) {
                emptyNum++;
            }
        }
    return emptyNum;
}

int occupied_squares() {
    // This function checks to see how many spaces are occupied
    int occupyNum = 0;
    for (int i = 0; i < 81; i++) {
            if (piece[i] != EMPTY) {
                occupyNum++;
            }
        }
    return occupyNum;
}

int gote_pieces() {
    // This function returns the amount of pieces sente has
    int gotePieces = 0;
    for (int i = 0; i < 81; i++)
        {
            if (color[i] == GOTE)
                {
                    gotePieces++;
                }
        }
    return gotePieces;
}

int sente_pieces()
{
    // This function returns the amount of pieces sente has
    int sentePieces = 0;
    for (int i = 0; i < 81; i++)
        {
            if (color[i] == SENTE)
                {
                    sentePieces++;
                }
        }
    return sentePieces;
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

int piece_at_pos(int file, int rank)
{
    return piece[(file_to_index(file) + rank_to_index(rank))];
}

void print_piece_type(int piece)
{
    switch (piece) {
        case PAWN:
            std::cout << "Pawn" << std::endl;
            break;
        case LANCE:
            std::cout << "Lance" << std::endl;
            break;
        case KNIGHT:
            std::cout << "Knight" << std::endl;
            break;
        case SILVER:
            std::cout << "Silver General" << std::endl;
            break;
        case GOLD:
            std::cout << "Gold General" << std::endl;
            break;
        case BISHOP:
            std::cout << "Bishop" << std::endl;
            break;
        case ROOK:
            std::cout << "Rook" << std::endl;
            break;
        case KING:
            std::cout << "King" << std::endl;
            break;
        default:
            std::cout << "Empty Square" << std::endl;
    }
}

// Asks the user for a string and parses it for KIF notation
bool parse_kif_move(kif::kifMove_t &move) {

    std::string kifMove;
    std::cin >> kifMove;

    if (!isalpha(kifMove.at(0))) {
        std::cout << "Invalid Move!" << std::endl;
        return false;
    }
    switch(kifMove.at(0)) {
        case 'P':
            std::cout << "A Pawn is ";
            move.piece = kif::PAWN;
            break;
        case 'N':
            std::cout << "A Knight is ";
            move.piece = kif::KNIGHT;
            break;
        case 'L':
            std::cout << "A Lance is ";
            move.piece = kif::LANCE;
            break;
        case 'S':
            std::cout << "A Silver is ";
            move.piece = kif::SILVER;
            break;
        case 'G':
            std::cout << "A Gold is ";
            move.piece = kif::GOLD;
            break;
        case 'B':
            std::cout << "A Bishop is ";
            move.piece = kif::BISHOP;
            break;
        case 'R':
            std::cout << "A Rook is ";
            move.piece = kif::ROOK;
            break;
        case 'K':
            std::cout << "The King is ";
            move.piece = kif::KING;
            break;
        default:
            std::cout << "Not a valid piece" << std::endl;
            return false;
    }

    switch(kifMove.at(1)) {
        case '-':
            std::cout << "moving" << std::endl;
            move.operation = kif::MOVE;
            break;
        case 'x':
            std::cout << "capturing" << std::endl;
            move.operation = kif::CAPTURE;
            break;
        case '*':
            std::cout << "being placed" << std::endl;
            move.operation = kif::STRIKE;
            break;
        default:
            std::cout << "Invalid move indicator" << std::endl;
            return false;
    }
    kifMove.erase(0, 2);
    move.square = atoi(kifMove.c_str());

    return true;
}


int color_at_pos(int file, int rank) {
    return color[(file_to_index(file) + rank_to_index(rank))];
}

void print_color_type(int color) {
    switch (color) {
        case SENTE:
            std::cout << "Sente" << std::endl;
            break;
        case GOTE:
            std::cout << "Gote" << std::endl;
            break;
        default:
            std::cout << "Empty" << std::endl;
    }
}

int eval() {
    float sente_score = 0;
    float gote_score = 0;
    float final_score = 0;

    bool isSenteBetter = false;

    for (int i = 0; i < 81; i++) {
            switch (piece[i]) {
                case PAWN:
                    if (color[i] == SENTE) {
                            sente_score += VALUE_PAWN;
                        }
                    else if (color[i] == GOTE) {
                            gote_score += VALUE_PAWN;
                        }
                    break;
                case LANCE:
                    if (color[i] == SENTE) {
                            sente_score += VALUE_LANCE;
                        }
                    else if (color[i] == GOTE) {
                            gote_score += VALUE_LANCE;
                        }
                    break;
                case KNIGHT:
                    if (color[i] == SENTE) {
                            sente_score += VALUE_KNIGHT;
                        }
                    else if (color[i] == GOTE) {
                            gote_score += VALUE_KNIGHT;
                        }
                    break;
                case SILVER:
                    if (color[i] == SENTE) {
                            sente_score += VALUE_SILVER;
                        }
                    else if (color[i] == GOTE) {
                            gote_score += VALUE_SILVER;
                        }
                    break;
                case GOLD:
                    if (color[i] == SENTE) {
                            sente_score += VALUE_GOLD;
                        }
                    else if (color[i] == GOTE) {
                            gote_score += VALUE_GOLD;
                        }
                    break;
                case BISHOP:
                    if (color[i] == SENTE) {
                            sente_score += VALUE_BISHOP;
                        }
                    else if (color[i] == GOTE) {
                            gote_score += VALUE_BISHOP;
                        }
                    break;
                case ROOK:
                    if (color[i] == SENTE) {
                            sente_score += VALUE_ROOK;
                        }
                    else if (color[i] == GOTE) {
                            gote_score += VALUE_ROOK;
                        }
                    break;
                default:
                    break;
                }
    }

    std::cout << "Sente Eval: " << sente_score << std::endl;
    std::cout << "Gote Eval: " << gote_score << std::endl;

    if (sente_score > gote_score) {
            std::cout << "Sente is better" << std::endl;
            isSenteBetter = true;
        }
    else if (gote_score > sente_score) {
            std::cout << "Gote is better" << std::endl;
            isSenteBetter = false;
        }
    else {
            std::cout << "Position is completely equal" << std::endl;
            isSenteBetter = false;
        }

        final_score = sente_score - gote_score;

        if (isSenteBetter || sente_score == gote_score) {
                return final_score;
            }
        else {
                final_score = final_score * -2;
                return final_score;
            }
}

void display_board() {
    for (int i = 0; i < 81; i++) {
        if (i % 9 == 0) {
            std::cout << std::endl;
        }
        switch (piece[i]) {
            case PAWN:
                std::cout << "[P]";
                break;
            case LANCE:
                std::cout << "[L]";
                break;
            case KNIGHT:
                std::cout << "[N]";
                break;
            case SILVER:
                std::cout << "[S]";
                break;
            case GOLD:
                std::cout << "[G]";
                break;
            case BISHOP:
                std::cout << "[B]";
                break;
            case ROOK:
                std::cout << "[R]";
                break;
            case KING:
                std::cout << "[K]";
                break;
            default:
                std::cout << "[ ]";
        }
    }
    std::cout << std::endl;
}

shogi::Game::Game() {

}

void shogi::Game::gameStart() {
    onGoing = true;
    while (onGoing) {
        display_board();

        if (!parse_kif_move(currentMove)) {
            printf("Parse error!\n");
        } else printf("Parse success!\n");
    }
}
