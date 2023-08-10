#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Global Variables
enum space {EMPTY, KING, GOLD, SILVER, KNIGHT, LANCE, BISHOP, ROOK, PAWN};
bool valid_move;
bool sente_turn = true;

string turn = "Sente";

vector<vector<space>> board {

    {LANCE, KNIGHT, SILVER, GOLD, KING, GOLD, SILVER, KNIGHT, LANCE},
    {EMPTY, ROOK, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BISHOP, EMPTY},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {EMPTY, BISHOP, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, ROOK, EMPTY},
    {LANCE, KNIGHT, SILVER, GOLD, KING, GOLD, SILVER, KNIGHT, LANCE}

};

// Functions

void display_board(const vector<vector<space>>& b);
void move_piece(vector<vector<space>>& b);
void valid_move_check(int from_row, int from_col, int to_row, int to_col, const vector<vector<space>> b);

int main()
{
    while (true) {

        display_board(board);
        move_piece(board);
    }
    return 0;
}

void display_board(const vector<vector<space>>& b) {

    for (int i = 0; i < b.size(); i++) {

        for (int k = 0; k < b[i].size(); k++) {

            //cout << "#";
            switch (board[i][k]) {

                case EMPTY:
                    cout << "空";
                    break;
                case KING:
                    cout << "王";
                    break;
                case GOLD:
                    cout << "金";
                    break;
                case SILVER:
                    cout << "銀";
                    break;
                case KNIGHT:
                    cout << "桂";
                    break;
                case LANCE:
                    cout << "香";
                    break;
                case BISHOP:
                    cout << "角";
                    break;
                case ROOK:
                    cout << "飛";
                    break;
                case PAWN:
                    cout << "歩";
                    break;
            }
        }
        cout << endl;
    }
}

void move_piece(vector<vector<space>>& b) {

    int from_row;
    int from_col;
    int to_row;
    int to_col;

    space piece_to_move;

    do {

        cout << "Please input where the piece is you want to move. Row first then Column. Turn: " << turn << endl;
        cin >> from_row;
        cin >> from_col;

        cout << "Please input where you want to move your piece. Row first then Column." << endl;
        cin >> to_row;
        cin >> to_col;

        valid_move_check(from_row, from_col, to_row, to_col, board);

        if (valid_move != true) {

            //cout << "Not a valid move!" << endl;
            continue;
        }

        piece_to_move = b[from_row - 1][from_col - 1];

        b[from_row - 1][from_col - 1] = EMPTY;
        b[to_row - 1][to_col - 1] = piece_to_move;

        if (sente_turn == true) {

            sente_turn = false;
            turn = "Gote";
        }

        else {

            sente_turn = true;
            turn = "Sente";
        }

    } while (valid_move != true);

    return;

}

void valid_move_check(int from_row, int from_col, int to_row, int to_col, const vector<vector<space>> b) {

    switch (b[from_row - 1][from_col - 1]) {

        case EMPTY:
            cout << "You cannot choose an empty space!" << endl;
            valid_move = false;
            return;
        case PAWN:
            if (sente_turn == true) {

                if ((to_row - 1) != (from_row - 1) - 1 || (to_col - 1) != (from_col - 1)) {

                    cout << "Not a valid Pawn move! Or you tried to move an opponents piece!" << endl;
                    valid_move = false;
                    return;
                }
            }

            else if (sente_turn != true) {

                if ((to_row - 1) != (from_row - 1) + 1 || (to_col - 1) != (from_col - 1)) {

                    cout << "Not a valid Pawn move! Or you tried to move an opponents piece!" << endl;
                    valid_move = false;
                    return;
                }
            }

            valid_move = true;

            break;

        case KNIGHT:
            if (sente_turn == true) {

                if ((to_row - 1) != (from_row - 1) - 2 && ((to_col - 1) != (from_col - 1) - 1 || (to_col - 1) != (from_col - 1) + 1)) {

                    cout << "Not a valid Knight move! Or you tried to move an opponents piece!" << endl;
                    valid_move = false;
                    return;
                }
            }

            else if (sente_turn != true) {

                if ((to_row - 1) != (from_row - 1) + 2 && ((to_col - 1) != (from_col - 1) - 1 || (to_col - 1) != (from_col - 1) + 1)) {

                    cout << "Not a valid Knight move! Or you tried to move an opponents piece!" << endl;
                    valid_move = false;
                    return;
                }
            }

            valid_move = true;

            break;
    }

        if (b[to_row - 1][to_col - 1] != EMPTY) {

            cout << "That is not a empty space!" << endl;
            valid_move = false;
            return;
        }

        else {

            valid_move = true;
        }

    return;
}

