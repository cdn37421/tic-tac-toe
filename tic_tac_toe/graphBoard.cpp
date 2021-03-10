#include <iostream>
#include <iomanip>
#include "graphBoard.h"

using namespace std;

graphBoard::graphBoard(string names[2]) {
	while (true) {
		cout << "Please enter the size of board. It needs to be ODD number and between 3 to 9." << endl;
		cin >> this->size;
		if (size >= 3 && size <= 9 && (size % 2 == 1)) {
			this->size = size;
			this->dices = new dice[this->size * this->size];
			for (int i = 0; i < this->size * this->size; i++) {
				this->dices[i].setValue(to_string(i+1));
			}
			this->sign[0] = 'O';
			this->sign[1] = 'X';
			break;
		}
		else {
			cout << "Please set the useful ODD number between 3 to 9 (EX: 3, 5, 7, 9)" << endl;
			this->size = -1;
			this->sign[0] = 'N';
			this->sign[1] = 'N';
		}
	}
	for (int i = 0; i < 2; i++)
		this->names[i] = names[i];
}

graphBoard::~graphBoard() {
	delete[] this->dices;
}

void graphBoard::genBoard() {
	if (this->size == -1) {
		cout << "Board is invalid" << endl;
		return;
	}
	cout << "\t\tTic Tac Toe\t\t" << endl;
	cout << "Player (" << this->names[0] << ") <" << this->sign[0] << "> - Player (" << this->names[1] << ") <" << this->sign[1] << ">" << endl;
	int count = 0;
	for (int i = 0; i < this->size; i++) {
		// print top
		for (int j = 0; j < this->size; j++) {
			cout << "    ";
			cout << ((j < (this->size - 1)) ? "|" : " ");
		}
		cout << endl;
		// print middle
		for (int j = 0; j < this->size; j++) {
			if (this->dices[count].getValue().compare(this->sign[0]) == 0 || this->dices[count].getValue().compare(this->sign[1]) == 0) {
				cout << " " << setfill(' ') << setw(2) << this->dices[count].getValue() << " ";
			}
			else {
				cout << " " << setfill('0') << setw(2) << this->dices[count].getValue() << " ";
			}
			cout << ((j < (this->size - 1)) ? "|" : " ");
			count++;
		}
		cout << endl;
		// print bottom
		if (i < this->size - 1) {
			for (int j = 0; j < this->size; j++) {
				cout << "____";
				cout << ((j < (this->size - 1)) ? "|" : " ");
			}
			cout << endl;
		}
	}
}

void graphBoard::setInBoard(int index, int s) {
	if (index < 1 || index > (this->size * this->size)) {
		cout << "Invalid input value. Please input between 1 to " << (this->size * this->size) << endl;
	}
	else {
		this->dices[index - 1].setValue(this->sign[s]);
	}
}

//return sign to distinguish who win the game
int graphBoard::finish() {
	int count = 0; // Check the number of same sign

	// check by horizontal
	for (int s = 0; s < 2; s++) {
		string priorSign = this->sign[s];
		for (int row = 0; row < this->size; row++) {
			count = 0;
			for (int col = 0; col < this->size; col++) {
				string sign = this->dices[row * this->size + col].getValue();
				if (priorSign.compare(sign) == 0) {
					count++;
				}
			}
			if (count == this->size) {
				return s; // game end
			}
		}
	}

	// check by vertical
	for (int s = 0; s < 2; s++) {
		string priorSign = this->sign[s];
		for (int col = 0; col < this->size; col++) {
			count = 0;
			for (int row = 0; row < this->size; row++) {
				string sign = this->dices[row * this->size + col].getValue();
				if (priorSign.compare(sign) == 0) {
					count++;
				}
			}
			if (count == this->size) {
				return s; // game end
			}
		}
	}

	//check by diagonal
	for (int s = 0; s < 2; s++) {
		for (int direct = 0; direct < 2; direct++) { //left diagonal or right diagonal
			count = 0;
			string priorSign = this->sign[s];
			int rowIndex = 0, colIndex = 0;
			if (direct == 1) {
				rowIndex = this->size - 1;
			}
			while(true) {
				string sign = this->dices[rowIndex * this->size + colIndex].getValue();
				if (priorSign.compare(sign) == 0) {
					count++;
				}
				rowIndex += ((direct == 0) ? 1 : -1);
				colIndex++;
				if (rowIndex < 0 || rowIndex >= this->size) {
					break;
				}
			}
			if (count == this->size) {
				return s; // game end
			}
		}
	}

	return -1; // game continue
}