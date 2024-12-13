#pragma once

#include <iostream>
#include <vector>
#include "shogi.hpp"
#include "language.hpp"

class Game
{
    public:
        Game();
        ~Game();
    private:
        bool player_turn;   // This keeps track of which player's turn it is; true = Sente, false = Gote
        bool is_check;      // Used in conjunction with player_turn to know who's in check
        bool is_tsume;      // Used in conjunction with player_turn to know who's been checkmated

        std::vector<SQUARE> sente_hand;     // The Sente's hand
        std::vector<SQUARE> gote_hand;      // The Gote's hand

        PLAYER currentPlayer;
};