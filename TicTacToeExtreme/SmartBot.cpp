#include "pch.hpp"
#include <random>

#include "SmartBot.hpp"

int SmartBot::m_botId = 1;


std::pair<int, int> SmartBot::makeMove(const std::string message, Playground playground) {
	
	for (int y = 0; y < playground.getHeight(); y++) {
		for (int x = 0; x < playground.getWidth(); x++) {
			if (playground.getField()[x][y] != ' ') {

			}
		}
	}
	int x = 0;
	int y = 0;
	return std::make_pair(x, y);
}

bool SmartBot::simulateMove(Playground playground, int column, int line,  char symbol) {
	return playground.placeSymbol(symbol, column, line);
	//return playground.checkForWin(column - 1, y - 1, symbol);
}
