#include "dice.h"

dice::dice(std::string str) {
	this->value = str;
}

std::string dice::getValue() {
	return this->value;
}

void dice::setValue(std::string str) {
	this->value = str;
}