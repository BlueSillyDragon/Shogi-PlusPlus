//
// Created by blues on 5/22/2025.
//

#ifndef SHOGI_HPP
#define SHOGI_HPP

enum SIDE {SENTE, GOTE};
enum SQUARE {PAWN, LANCE, KNIGHT, SILVER, GOLD, BISHOP, ROOK, KING, EMPTY};

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

void parse_kif_move();

void print_piece_type(int piece);
int color_at_pos(int file, int rank);
void print_color_type(int color);
int eval();

#endif //SHOGI_HPP
