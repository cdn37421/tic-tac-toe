#ifndef DICE
#define DICE

#include <string>

class dice {
public:
	dice(std::string = " ?");
	void setValue(std::string);
	std::string getValue();
private:
	std::string value;
};
#endif