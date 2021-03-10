#ifndef WORDBOARD
#define WORDBOARD

#include "board.h"

class wordBoard : public board {
public:
	void genBoard();
	void setInBoard(int, int);
	int finish();
};
#endif