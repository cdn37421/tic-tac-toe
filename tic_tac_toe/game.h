#ifndef GAME
#define GAME

#include "board.h"
#include "player.h"

class game {
public:
	game();
	void newGame();
	void endGame();
private:
	int boardSize;
	int gameType;
	board *board;
	player players[2]; // Fix to two players
};
#endif