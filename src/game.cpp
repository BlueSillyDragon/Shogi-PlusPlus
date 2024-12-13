#include "inc/game.hpp"
#include "inc/shogi.hpp"

PIECES pieceSet = Japanese;
LANG currentLanguage = ENG;

// English strings
std::string en_title = "Shogi++";

// Japanese strings
std::string jp_title = "将棋";

Game::Game()
{
    switch (currentLanguage) {
		case ENG:
			std::cout << en_title << std::endl;
			break;
		case JPN:
			std::cout << jp_title << std::endl;
			break;
	}

	player_turn = true;

	while (true)
	{
		printBoard();
		showCurrentPlayer(player_turn);

		while (!getMove()) {
			std::cout << "Invalid notation!" << std::endl;
		}

		player_turn = !player_turn;
	}
}

Game::~Game()
{

}