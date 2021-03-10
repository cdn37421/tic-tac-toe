#ifndef PLAYER
#define PLAYER

#include <string>

using namespace std;

class player {
public:
	player(string = "NONE", int = -1, int = 0);
	void setName(string);
	string getName();
	void setSign(int);
	int getSign();
	void setScore();
	int getScore();
private:
	string name;
	int sign;
	int score;
};

#endif
