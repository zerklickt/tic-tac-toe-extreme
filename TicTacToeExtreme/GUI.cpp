#include <iostream>
#include <string>
#include <stdlib.h>
#include <Windows.h>

#include "pch.hpp"
#include "GUI.hpp"


void GUI::printPlayground(const Playground& playground)
{
	int width = playground.getWidth();
	int height = playground.getHeight();
	std::vector<std::vector<char>> field = playground.getField();

	system("cls");

	for (int y = 0; y <= height; y++){
		for (int x = 0; x <= width; x++){
			printWhatsInTheField(x, y, field);
		}
		std::cout << std::endl;
	}
}


void GUI::printWhatsInTheField(int x, int y, std::vector<std::vector<char>> field) {
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
			return;;
		}
		else {
			std::cout << x << " |";
			return;
		}
	}
	else {
		printChip(x - 1, y - 1, field);
	}
}



void GUI::printChip(const int x, const int y, const std::vector<std::vector<char>> field){

	char checkSymbol = field[x][y];
	std::cout << checkSymbol << " |";


}

