#include "pch.hpp"
#include <Windows.h>

#include "SmartBot.hpp"

int SmartBot::m_botId = 1;


std::pair<int, int> SmartBot::makeMove(const std::string message, Playground playground) {

	//Sleep(200);

	std::pair<int, int> directionOfOwnPair = checkForDirectionOfPair(m_lastX-1, m_lastY-1, playground, m_symbol);   //win with a double
	if (directionOfOwnPair.first != 0 || directionOfOwnPair.second != 0) {
		if (playground.canPlaceChip(m_lastX + directionOfOwnPair.first, m_lastY + directionOfOwnPair.second)) {
			m_lastX = m_lastX + directionOfOwnPair.first;
			m_lastY = m_lastY + directionOfOwnPair.second;
			return std::make_pair(m_lastX, m_lastY);
		}
		else if (playground.canPlaceChip(m_lastX + (-2) * directionOfOwnPair.first, m_lastY + (-2) * directionOfOwnPair.second)) {
			m_lastX = m_lastX + (-2) * directionOfOwnPair.first;
			m_lastY = m_lastY + (-2) * directionOfOwnPair.second;
			return std::make_pair(m_lastX, m_lastY);
		}
	}

	
	for (int y = 1; y <= playground.getHeight(); y++) {													// win with "|x| |x|"
		for (int x = 1; x <= playground.getWidth(); x++) {
			if (playground.canPlaceChip(x, y) && simulateMove(playground, x, y, m_symbol)) {
				return std::make_pair(x, y);
			}
		}
	}

	for (int y = 1; y <= playground.getHeight(); y++) {													// prevent win with "|x| |x|"
		for (int x = 1; x <= playground.getWidth(); x++) {
			char check = playground.getField()[x - 1][y - 1];
			if (check != m_symbol && check != ' ') {
				for (int ix = -1; ix <= 1; ix++) {
					for (int iy = -1; iy <= 1; iy++) {
						if (ix == 0 && iy == 0)
							continue;
						if (playground.canPlaceChip(x + ix, y + iy) /*playground.getField()[x + ix - 1][y + iy - 1] == ' '*/ && simulateMove(playground, x + ix, y + iy, check)) {
							return std::make_pair(x + ix, y + iy);
						}
					}
				}
			}
		}
	}
	
	for (int y = 0; y < playground.getHeight(); y++) {													//prevent the opponent from winning
		for (int x = 0; x < playground.getWidth(); x++) {
			if (playground.getField()[x][y] != ' ') {
				std::pair<int, int> directionOfPair = checkForDirectionOfPair(x, y, playground, playground.getField()[x][y]);
				if (directionOfPair.first != 0 || directionOfPair.second != 0) {
					if (playground.canPlaceChip(x + 1 + directionOfPair.first, y + 1 + directionOfPair.second)) {
						m_lastX = x + 1 + directionOfPair.first;
						m_lastY = y + 1 + directionOfPair.second;
						return std::make_pair(m_lastX, m_lastY);
					}
					else if (playground.canPlaceChip(x + 1 + (-2)*directionOfPair.first, y + 1 + (-2)*directionOfPair.second)) {
						m_lastX = x + 1 + (-2) * directionOfPair.first;
						m_lastY = y + 1 + (-2) * directionOfPair.second;
						return std::make_pair(m_lastX, m_lastY);
					}
				}
			}
		}
	}

	
	if (m_lastX != 0 && m_lastY != 0) {												//place chip next to your last-placed chip
		for (int i = m_lastX - 1; i <= m_lastX + 1; i++) {
			for (int j = m_lastY - 1; j <= m_lastY + 1; j++) {
				if (playground.canPlaceChip(i, j)) {
					m_lastX = i;
					m_lastY = j;
					return std::make_pair(i, j);
				}
			}
		}
	}
	if (m_lastX > 0) {
		//place a random chip, when there is no "good" chip
		int x, y;
		do {
			std::random_device dev;
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> distx(1, playground.getWidth());
			std::uniform_int_distribution<std::mt19937::result_type> disty(1, playground.getHeight());

			x = distx(rng);
			y = disty(rng);
		} while (!playground.canPlaceChip(x, y));
		return std::make_pair(x, y);
	}

	m_lastX = (playground.getWidth() + 1) / 2;										//ini the benninging place in the middle
	m_lastY = (playground.getHeight() + 1) / 2;
	return std::make_pair(m_lastX, m_lastY);
}

// simulates a move and checks if this move leads to a win
bool SmartBot::simulateMove(Playground playground, int column, int line,  char symbol) {
	playground.placeSymbol(symbol, column, line);
	return playground.checkForWin(symbol, column, line);
}

// returns vector to the next position of an existing pair
std::pair<int, int> SmartBot::checkForDirectionOfPair(int x, int y, Playground& playground, char symbol) {
	for (int ix = -1; ix <= 1; ix++) {
		for (int iy = -1; iy <= 1; iy++) {
			if (ix == 0 && iy == 0)
				continue;
			if (playground.countCells(x + ix, y + iy, ix, iy, symbol) >= 1) {
				return std::make_pair((-1) * ix, (-1) * iy);
			}
		}
	}
	return std::make_pair(0, 0);
	
}
