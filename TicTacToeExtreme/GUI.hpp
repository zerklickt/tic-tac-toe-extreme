#pragma once

#include "Playground.hpp"

class GUI {

public:
	GUI() {};
	~GUI() {};
	void printPlayground(const Playground& playground) const;

private:
	void printSymbol(const int y, const int x, const std::vector<std::vector<char>> field) const;
	void printSingleCell(const int, const int, const std::vector<std::vector<char>> field) const;
};
