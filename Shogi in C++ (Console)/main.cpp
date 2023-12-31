#include <iostream>
#include <vector>
#include "language.h"

using namespace std;

// Global Variables
enum space {EMPTY, KING, GOLD, SILVER, KNIGHT, LANCE, BISHOP, ROOK, PAWN, wKING, wGOLD, wSILVER, wKNIGHT, wLANCE, wBISHOP, wROOK, wPAWN};
bool valid_move;
bool sente_turn = true;
bool kanji_pieces = true;
bool japanese = true;

string turn = "Sente";

vector<vector<space>> board {

    {wLANCE, wKNIGHT, wSILVER, wGOLD, wKING, wGOLD, wSILVER, wKNIGHT, wLANCE},
    {EMPTY, wROOK, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, wBISHOP, EMPTY},
    {wPAWN, wPAWN, wPAWN, wPAWN, wPAWN, wPAWN, wPAWN, wPAWN, wPAWN},
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
    char choice;
    bool go_back;
    bool invalid;

    if (japanese == false)
        cout << en_title << endl << endl;
    else
        cout << jp_title << endl << endl;
    display_board(board);

    do {

        if (japanese == false)
            cout << endl << en_options_prompt << endl;
        else
            cout << endl << jp_options_prompt << endl;
        cin >> choice;

        switch (choice) {

        case 'n':
        case 'N':
            if (japanese == false)
                cout << en_newgame_start << endl << endl;
            else
                cout << jp_newgame_start << endl;
            go_back = false;
            invalid = false;
            break;
        case 's':
        case 'S':
            if (japanese == false)
                cout << en_settings << endl;
            else
                cout << jp_settings << endl;
            go_back = false;
            invalid = false;
            cin >> choice;

            switch (choice) {

                case 'l':
                case 'L':
                    if (japanese == false)
                        cout << en_language_change << endl;
                    else
                        cout << jp_language_change << endl;
                    cin >> choice;

                    switch (choice) {

                        case 'e':
                        case 'E':
                            japanese = false;
                            break;
                        case 'j':
                        case 'J':
                            japanese = true;
                            break;
                        default:
                            if (japanese == false)
                                cout << en_invalid_choice << endl;
                            else
                                cout << jp_invalid_choice << endl;
                    }

                    go_back = true;
                    invalid = false;

                    break;
                case 'p':
                case 'P':
                    if (japanese == false)
                        cout << en_piece_change << endl;
                    else
                        cout << jp_piece_change << endl;
                    cin >> choice;

                    switch (choice) {

                        case 'k':
                        case 'K':
                            kanji_pieces = true;
                            go_back = true;
                            break;
                        case 'i':
                        case 'I':
                            kanji_pieces = false;
                            go_back = true;
                            break;
                        default:
                            if (japanese == false)
                                cout << en_invalid_choice << endl;
                            else
                                cout << jp_invalid_choice << endl;
                            invalid = true;
                            break;
                    }

                    break;
                case 'b':
                case 'B':
                    go_back = true;
                    break;
                default:
                    if (japanese == false)
                        cout << en_invalid_choice << endl;
                    else
                        cout << jp_invalid_choice << endl;
                    invalid = true;
            }

            break;
        case 'q':
        case 'Q':
            if (japanese == false)
                cout << en_exit << endl;
            else
                cout << jp_exit << endl;
            return 0;
        default:
            if (japanese == false)
                cout << en_invalid_choice << endl;
            else
                cout << jp_invalid_choice << endl;
            invalid = true;
            break;
        }
    } while (go_back == true || invalid == true);


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
            if (kanji_pieces == true) {

                switch (board[i][k]) {

                    case EMPTY:
                        cout << "空";
                        break;
                    case KING:
                    case wKING:
                        cout << "王";
                        break;
                    case GOLD:
                    case wGOLD:
                        cout << "金";
                        break;
                    case SILVER:
                    case wSILVER:
                        cout << "銀";
                        break;
                    case KNIGHT:
                    case wKNIGHT:
                        cout << "桂";
                        break;
                    case LANCE:
                    case wLANCE:
                        cout << "香";
                        break;
                    case BISHOP:
                    case wBISHOP:
                        cout << "角";
                        break;
                    case ROOK:
                    case wROOK:
                        cout << "飛";
                        break;
                    case PAWN:
                    case wPAWN:
                        cout << "歩";
                        break;
                }
            }

            else if (kanji_pieces == false) {

                switch (board[i][k]) {

                    case EMPTY:
                        cout << "#";
                        break;
                    case KING:
                        cout << "K";
                        break;
                    case GOLD:
                        cout << "G";
                        break;
                    case SILVER:
                        cout << "S";
                        break;
                    case KNIGHT:
                        cout << "N";
                        break;
                    case LANCE:
                        cout << "L";
                        break;
                    case BISHOP:
                        cout << "B";
                        break;
                    case ROOK:
                        cout << "R";
                        break;
                    case PAWN:
                        cout << "P";
                        break;
                }
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

        valid_move_check(from_row, from_col, to_row, to_col, b);

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

                if (((to_row - 1) != (from_row - 1) - 1 || (to_col - 1) != (from_col - 1)) || sente_turn == false) {

                    cout << "Not a valid Pawn move! Or you tried to move an opponents piece!" << endl;
                    valid_move = false;
                    return;
                }

            valid_move = true;

            break;
        case wPAWN:

            if (((to_row - 1) != (from_row - 1) + 1 || (to_col - 1) != (from_col - 1)) || sente_turn == true) {

                    cout << "Not a valid Pawn move! Or you tried to move an opponents piece!" << endl;
                    valid_move = false;
                    return;
                }

            valid_move = true;
            break;

        case KNIGHT:

                if (((to_row - 1) != (from_row - 1) - 2 && ((to_col - 1) != (from_col - 1) - 1 || (to_col - 1) != (from_col - 1) + 1)) || sente_turn == false) {

                    cout << "Not a valid Knight move! Or you tried to move an opponents piece!" << endl;
                    valid_move = false;
                    return;
                }

            valid_move = true;

            break;
        case wKNIGHT:

                if (((to_row - 1) != (from_row - 1) + 2 && ((to_col - 1) != (from_col - 1) - 1 || (to_col - 1) != (from_col - 1) + 1)) || sente_turn == true) {

                    cout << "Not a valid Knight move! Or you tried to move an opponents piece!" << endl;
                    valid_move = false;
                    return;
                }

            valid_move = true;

            break;

        case LANCE:
            int total_spaces;
            bool stop_check;

            if (sente_turn == true) {

                total_spaces = (from_row - 1) - 1;

                for (int i = (from_row - 1) - 1; i >= 0; i--) {

                    switch (b[i][from_col - 1]) {

                        case EMPTY:
                            //cout << "fine" << endl;
                            break;
                        default:
                            stop_check = true;
                            break;
                    }

                    if (stop_check == true) {

                        //cout << "STOPPING CHECK" << endl;
                        break;
                    }

                    //cout << total_spaces << endl;
                    total_spaces--;
                }

                if (((to_row - 1) > (from_row - 1) || (to_row - 1) < total_spaces) || (to_col - 1) != (from_col - 1)) {

                    cout << "Not a valid Lance move! Or you tried to move an opponents piece!" << endl;
                    valid_move = false;
                    return;
                }
            }

            else if (sente_turn != true) {

                total_spaces = (from_row - 1) + 1;

                for (int i = (from_row - 1) + 1; i <= 8; i++) {

                    switch (b[i][from_col - 1]) {

                        case EMPTY:
                            //cout << "fine" << endl;
                            break;
                        default:
                            stop_check = true;
                            break;
                    }

                    if (stop_check == true) {

                        //cout << "STOPPING CHECK" << endl;
                        break;
                    }

                    cout << total_spaces << endl;
                    total_spaces++;
                }

                if (((to_row - 1) < (from_row - 1) || (to_row - 1) > total_spaces) || (to_col - 1) != (from_col - 1)) {

                    cout << "Not a valid Lance move! Or you tried to move an opponents piece!" << endl;
                    valid_move = false;
                    return;
                }
            }

            valid_move = true;
            break;

        case ROOK:
            int min_spaces_h;
            int max_spaces_h;
            int min_spaces_v;
            int max_spaces_v;

            bool no_check;

            if (sente_turn == true) {

                min_spaces_h = (from_row - 1) + 1;
                max_spaces_h = (from_row - 1) - 1;
                min_spaces_v = (from_col - 1) - 1;
                max_spaces_v = (from_col - 1) + 1;

                //Horizontal Check
                for (int i = (from_row - 1) + 1; i <= 8; i++) {     //Behind

                    switch (b[i][from_col - 1]) {

                        case EMPTY:
                            //cout << "fine" << endl;
                            break;
                        default:
                            no_check = true;
                            break;
                    }

                    if (no_check == true) {

                        //cout << "STOPPING CHECK" << endl;
                        break;
                    }

                    //cout << "min: " << min_spaces_h << endl;
                    min_spaces_h++;
                }

                no_check = false;       //Set the value of no check back

                for (int i = (from_row - 1) - 1; i >= 0; i--) {     //In front

                    switch (b[i][from_col - 1]) {

                        case EMPTY:
                            //cout << "fine" << endl;
                            break;
                        default:
                            no_check = true;
                            break;
                    }

                    if (no_check == true) {

                        //cout << "STOPPING CHECK" << endl;
                        break;
                    }

                    //cout << "max: " << max_spaces_h << endl;
                    max_spaces_h--;
                }

                no_check = false;

                //Vertical Checks
                for (int i = (from_col - 1) + 1; i <= 8; i++) {

                    switch (b[from_row - 1][i]) {

                        case EMPTY:
                            //cout << "fine" << endl;
                            break;
                        default:
                            no_check = true;
                            break;
                    }

                    if (no_check == true) {

                        //cout << "STOPPING CHECK" << endl;
                        break;
                    }

                    //cout << "vmax: " << max_spaces_v << endl;
                    max_spaces_v++;
                }

                no_check = false;

                for (int i = (from_col - 1) - 1; i >= 0; i--) {

                    switch (b[from_row - 1][i]) {

                        case EMPTY:
                            //cout << "fine" << endl;
                            break;
                        default:
                            no_check = true;
                            break;
                    }

                    if (no_check == true) {

                        //cout << "STOPPING CHECK" << endl;
                        break;
                    }

                    //cout << "vmin: " << min_spaces_v << endl;
                    min_spaces_v--;
                }
            }

            if (((to_row - 1) > min_spaces_h || (to_row - 1) < max_spaces_h) || ((to_col - 1) > max_spaces_v || (to_col - 1) < min_spaces_v)) {

                    cout << "Not a valid Rook move! Or you tried to move an opponents piece!" << endl;
                    valid_move = false;
                    return;
                }
    }

        if (b[to_row - 1][to_col - 1] != EMPTY) {

            if ((b[to_row - 1][to_col - 1] == PAWN || b[to_row - 1][to_col - 1] == KNIGHT || b[to_row - 1][to_col - 1] == LANCE || b[to_row - 1][to_col - 1] == SILVER || b[to_row - 1][to_col - 1] == GOLD || b[to_row - 1][to_col - 1] == ROOK || b[to_row - 1][to_col - 1] == BISHOP || b[to_row - 1][to_col - 1] == KING) && (sente_turn == true)) {

                cout << "You can not capture one of your own pieces!" << endl;
                valid_move = false;
                return;
            }

            else if ((b[to_row - 1][to_col - 1] == wPAWN || b[to_row - 1][to_col - 1] == wKNIGHT || b[to_row - 1][to_col - 1] == wLANCE || b[to_row - 1][to_col - 1] == wSILVER || b[to_row - 1][to_col - 1] == wGOLD || b[to_row - 1][to_col - 1] == wROOK || b[to_row - 1][to_col - 1] == wBISHOP || b[to_row - 1][to_col - 1] == wKING) && (sente_turn == false)) {

                cout << "You can not capture one of your own pieces!" << endl;
                valid_move = false;
                return;
            }

            else {

                cout << "CAPTURE" << endl;
                valid_move = true;
                return;
            }

            //cout << "That is not a empty space!" << endl;
            //valid_move = false;
            //return;
        }

        else {

            valid_move = true;
        }

    return;
}
