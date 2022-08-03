#include <iostream>

#include "pch.hpp"
#include "GUI.hpp"


void GUI::printPlayground(const Playground& playground) const {
	int width = playground.getWidth();
	int height = playground.getHeight();
	std::vector<std::vector<char>> field = playground.getField();
	system("cls");
	for (int y = 0; y <= height; y++){
		for (int x = 0; x <= width; x++){
			printSingleCell(x, y, field);
		}
		std::cout << std::endl;
	}
}


void GUI::printSingleCell(const int x, const int y, const std::vector<std::vector<char>> field) const {
	if (x == 0 && y == 0) {
		std::cout << "  |";
		return;
	}
	if (x == 0) {
		if (y > 9) {
			std::cout << y << "|";
			return;
		}
		else {
			std::cout << y << " |";
			return;
		}
	}
	if (y == 0) {
		if (x > 9) {
			std::cout << x << "|";
			return;
		}
		else {
			std::cout << x << " |";
			return;
		}
	}
	else {
		printSymbol(x - 1, y - 1, field);
	}
}


void GUI::printSymbol(const int x, const int y, const std::vector<std::vector<char>> field) const {
	char checkSymbol = field[x][y];
	std::cout << checkSymbol << " |";
}

