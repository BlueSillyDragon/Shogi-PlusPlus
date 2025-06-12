//
// Created by blues on 5/22/2025.
//

#ifndef SHOGI_HPP
#define SHOGI_HPP

#include <vector>

enum SIDE {SENTE, GOTE};
enum SQUARE {PAWN, LANCE, KNIGHT, SILVER, GOLD, BISHOP, ROOK, KING, EMPTY};

namespace kif {
    enum OPERATION {MOVE, CAPTURE, STRIKE};
    enum PIECE {PAWN, LANCE, KNIGHT, SILVER, GOLD, BISHOP, ROOK, KING, NONE};

    typedef struct {
        PIECE piece;
        OPERATION operation;
        unsigned int square;
    } kifMove_t;
}

namespace shogi {
    class Game {
    public:
        Game();
        void gameStart();
        // Calculate functions ouputs the piece's origin square, make sure it's still accessible
        // when invoked via isValidMove
        bool isValidMove(kif::kifMove_t move, unsigned int &pieceSquare);
        // This performs an operation on a piece, regardless of the legality of the move
        // isValidMove should be called first to ensure the move is legal
        void performPieceOp(kif::OPERATION op, unsigned int toSquare, unsigned int pieceSquare);
        bool findPieceInHand(SIDE side, kif::PIECE piece, int &id);
    private:
        bool onGoing = false;
        bool currentSide = true; // true = Sente; false = Gote
        bool sIsCheck = false;
        bool gIsCheck = false;
        kif::kifMove_t currentMove;
        std::vector<kif::PIECE> senteHand;
        std::vector<kif::PIECE> goteHand;

        /* These functions calculate whether or not a piece can move to a certain square
           the return values are as follows
           0 = Invalid Move (or no piece of that type is able to reach that square)
           1 = A valid move
           -1 = Valid, but another piece occupies that square (isValidMove will check if the player
           is trying to capture that piece*/
        int calculatePawn(unsigned int toSquare, unsigned int &pieceSquare);
        int calculateLance(unsigned int toSquare, unsigned int &pieceSquare);
        int calculateKnight(unsigned int toSquare, unsigned int &pieceSquare);
        int calculateSilver(unsigned int toSquare, unsigned int &pieceSquare);
        int calculateGold(unsigned int toSquare, unsigned int &pieceSquare);
        int calculateBishop(unsigned int toSquare, unsigned int &pieceSquare);
        int calculateRook(unsigned int toSquare, unsigned int &pieceSquare);
    };
}

// Returns the amount of empty/occupied squares
int empty_squares();
int occupied_squares();

// Returns the amount of pieces Gote/Sente has
int gote_pieces();
int sente_pieces();

// File/Rank operations
int file_to_index(int file);
int rank_to_index(int rank);
int piece_at_pos(int file, int rank);

bool parse_kif_move(kif::kifMove_t &move);

void print_piece_type(int piece);
int color_at_pos(int file, int rank);
void print_color_type(int color);
int eval();

void display_board();

#endif //SHOGI_HPP
