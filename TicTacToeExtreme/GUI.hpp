#pragma once
#include "Playground.hpp"

class GUI {

public:
	GUI() {};
	~GUI() {};

	void printPlayground(const Playground& playground);

private:
	void printChip(const int y, const int x, const std::vector<std::vector<char>> field);
};
