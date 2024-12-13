#ifndef SHOGI_H
#define SHOGI_H

enum PLAYER {SENTE, GOTE};

enum SQUARE {S_PAWN, S_LANCE, S_KNIGHT, S_SILVER, S_GOLD, S_BISHOP, S_ROOK, S_KING,
            G_PAWN, G_LANCE, G_KNIGHT, G_SILVER, G_GOLD, G_BISHOP, G_ROOK, G_KING, EMPTY};

void printBoard ();
void showCurrentPlayer(bool player);
bool getMove();

int file_to_index(int file);
int rank_to_index(int rank);

SQUARE piece_at_pos(int file, int rank);      // Returns the piece at the given rank and file

void move_piece(int from_file, int from_rank, int to_file, int to_rank);

#endif