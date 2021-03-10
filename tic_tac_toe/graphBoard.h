#ifndef GRAPHBOARD
#define GRAPHBOARD

#include "board.h"
#include "dice.h"

class graphBoard : public board {
public:
	graphBoard(string[2]);
	~graphBoard();
	void genBoard();
	void setInBoard(int, int);
	int finish();
private:
	int size;
	dice *dices;
	string sign[2];
	string names[2];
};
#endif
