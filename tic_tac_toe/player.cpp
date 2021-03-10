#include "player.h"

player::player(string name, int sign, int score) {
	this->name = name;
	this->sign = sign;
	this->score = score;
}

void player::setName(string name) {
	this->name = name;
}

string player::getName() {
	return this->name;
}

void player::setSign(int sign) {
	this->sign = sign;
}

int player::getSign() {
	return this->sign;
}


void player::setScore() {
	this->score = score;
}

int player::getScore() {
	return this->score;
}