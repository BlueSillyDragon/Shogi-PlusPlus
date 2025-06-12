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

kif::PIECE squareToPiece(SQUARE square) {
    switch (square) {
        case EMPTY:
            return kif::NONE;
        case PAWN:
            return kif::PAWN;
        case LANCE:
            return kif::LANCE;
        case KNIGHT:
            return kif::KNIGHT;
        case SILVER:
            return kif::SILVER;
        case GOLD:
            return kif::GOLD;
        case BISHOP:
            return kif::BISHOP;
        case ROOK:
            return kif::ROOK;
        case KING:
            return kif::KING;
    }
    return kif::NONE;
}

int pieceToSquare(kif::PIECE piece) {
    switch (piece) {
        case kif::NONE:
            return EMPTY;
        case kif::PAWN:
            return PAWN;
        case kif::LANCE:
            return LANCE;
        case kif::KNIGHT:
            return KNIGHT;
        case kif::SILVER:
            return SILVER;
        case kif::GOLD:
            return GOLD;
        case kif::BISHOP:
            return BISHOP;
        case kif::ROOK:
            return ROOK;
        case kif::KING:
            return KING;
    }
    return EMPTY;
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

    if (move.square < 11) {
        return false;
    }

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

//======================
// shogi::Game functions
//======================

shogi::Game::Game() {

}

int shogi::Game::calculatePawn(unsigned int toSquare, unsigned int &pieceSquare) {
    int ret;

    if (toSquare < 11 || toSquare > 99) {
        return 0;
    }

    unsigned int file = (toSquare / 10);
    unsigned int rank = (toSquare % 10);
    printf("File %d | Rank %d\n", file, rank);

    if (piece_at_pos(file, rank + 1) == kif::PAWN) {
        printf("Valid pawn move!\n");
        pieceSquare = ((file * 10) + rank + 1);
        ret = piece_at_pos(file, rank) == EMPTY ? 1 : -1;
    } else {
        printf("Invalid pawn move!\n");
        ret = 0;
    }
    printf("ret: %d\n", ret);
    return ret;
}

bool shogi::Game::findPieceInHand(SIDE side, kif::PIECE piece, int &id) {
    switch (side) {
        case SENTE:
            if (senteHand.empty()) {
                return false;
            }
            for (int i = 0; i < senteHand.size(); i++) {
                if (senteHand[i] == piece) {
                    id = i;
                    return true;
                }
            } return false;
        case GOTE:
            if (goteHand.empty()) {
                return false;
            }
            for (int i = 0; i < goteHand.size(); i++) {
                if (goteHand[i] == piece) {
                    id = i;
                    return true;
                }
            } return false;
        default:
            return false;
    }
    // Unreachable, but just in case
    __builtin_unreachable();
}


void shogi::Game::performPieceOp(kif::OPERATION op, const unsigned int toSquare, const unsigned int pieceSquare) {
    unsigned int file = (toSquare / 10);
    unsigned int rank = (toSquare % 10);
    unsigned int originFile = (pieceSquare / 10);
    unsigned int originRank = (pieceSquare % 10);
    kif::PIECE oldPiece;
    kif::PIECE pieceToOp;
    int handId = 0;

    // NOTE! It's very important that isValidMove is called before this,
    // especially due to this line. We save the toSquare and put it in the player's hand
    // regardless of whether or not it's EMPTY (Only if the operation is kif::CAPTURE)
    oldPiece = squareToPiece((SQUARE)piece_at_pos(file, rank));

    pieceToOp = squareToPiece((SQUARE)piece_at_pos(originFile, originRank));
    print_piece_type(piece_at_pos(file, rank));
    print_piece_type(piece_at_pos(originFile, originRank));

    if (op == kif::MOVE) {
        piece[file_to_index(file) + rank_to_index(rank)] = pieceToSquare(pieceToOp);
        piece[file_to_index(originFile) + rank_to_index(originRank)] = EMPTY;
    }
}

bool shogi::Game::isValidMove(kif::kifMove_t move, unsigned int &pieceSquare) {

    int calcResult = 0;

    switch (move.piece) {
        case kif::PAWN:
            calcResult = calculatePawn(move.square, pieceSquare);
            break;
    }

    if (calcResult == 0) {
        return false;
    }

    switch (move.operation) {
        case kif::MOVE:
            if (calcResult != 1) {
                return false;
            }
            break;
        case kif::CAPTURE:
            if (calcResult != -1) {
                return false;
            }
            break;
        case kif::STRIKE:
            if (senteHand.empty()) {
                return false;
            }
            break;
    }

    return true;
}


void shogi::Game::gameStart() {
    onGoing = true;
    unsigned int pieceSquare;
    while (onGoing) {
        display_board();

        if (!parse_kif_move(currentMove)) {
            printf("Parse error!\n");
        } else printf("Parse success!\n");

        while (!isValidMove(currentMove, pieceSquare)) {
            printf("Please try again!\n");
            parse_kif_move(currentMove);
        }

        performPieceOp(currentMove.operation, currentMove.square, pieceSquare);
    }
}
