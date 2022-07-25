#include "pch.h"
#include <iostream>

#include "GUI.hpp"

/*
void GUI::printPlayground(const Playground& playground)
{
	int width = playground.getWidth();
	int height = playground.getHeight();
	std::vector<std::vector<Color>> field = playground.getField();

	system("cls");

	for (int y = 0; y <= height; y++) // going up a row
	{
		for (int x = 0; x <= width; x++) // filling up a row with spaces or chips (if placed)

		{
			if (x == 0 && y == 0)
			{
				std::cout << "  ";
				continue;
			}
			if (x == 0)
			{
				std::cout << y << " ";
				continue;
			}
			if (y == 0)
			{
				std::cout << x << " ";
				continue;
			}
			else
			{
				printChip(x - 1, y - 1, field);;
			}
		}
		std::cout << std::endl;
	}
}
*/


// depending on the color of the player: blue = x, yellow = o
void GUI::printChip(const int x, const int y, const std::vector<std::vector<Color>> field)

{

	char checkSymbol = field[x][y];
	std::cout << checkSymbol;
}
