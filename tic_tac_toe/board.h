#ifndef BOARD
#define BOARD

#include "player.h"

class board {
public:
	virtual void genBoard() = 0;
	virtual void setInBoard(int, int) = 0;
	virtual int finish() = 0;
protected:
	player players[2];
};
#endif