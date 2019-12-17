#pragma once
#include <string>
std::string test(unsigned& x, unsigned& y, unsigned& id) {
	unsigned xTest, yTest;
	std::string direction = "";
	switch (id) {
	case 0:
		xTest = 5;
		yTest = 5;
		break;
	case 1:
		xTest = 14;
		yTest = 16;
		break;
	default:
		xTest = 0;
		yTest = 0;
		break;
	}
	if (yTest < y)
		direction = "S";
	else if (yTest > y)
		direction = "N";
	if (xTest < x)
		direction += "W";
	else if (xTest > x)
		direction += "E";
	return direction;
}