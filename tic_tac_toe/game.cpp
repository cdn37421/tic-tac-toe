#include <iostream>
#include "game.h"
#include "wordBoard.h"
#include "graphBoard.h"

game::game() {
	while (true) {
		cout << "Please enter the board type: word type (0) or graph type (1)" << endl;
		if (cin >> this->gameType && (this->gameType == 0 || this->gameType == 1)) {
			// Init two players
			string name = "";
			for (int p = 0; p < 2; p++) {
				this->players[p].setSign(p);	// Set the sign
				cout << "Please enter the player " << (p + 1) << "'s name:" << endl;
				cin >> name;
				this->players[p].setName(name);	// Set the name
			}
			break;
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

void game::newGame() {
	if (this->gameType == 0) {
		this->board = new wordBoard;
	}
	else {
		string names[2] = { this->players[0].getName(), this->players[1].getName() };
		this->board = new graphBoard(names);
	}
	// Init the board
	int num = -1;
	int endType = -1;
	while (true) { // keep to the end of game
		for (int p = 0; p < 2; p++) {
			if ((endType = this->board->finish()) >= 0) {
				this->board->genBoard();
				cout << "Congratulations " << this->players[endType].getName() << "! You're so genious!" << endl;
				return;
			}
			this->board->genBoard();
			cout << "Hello " << this->players[p].getName() << ", Please enter a index to pick the dice" << endl;
			if (cin >> num) {
				this->board->setInBoard(num, this->players[p].getSign());
			}
			else {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				p--;
			}
		}
	}
}

void game::endGame() {
	cout << endl << "Bye Bye!" << endl;
}