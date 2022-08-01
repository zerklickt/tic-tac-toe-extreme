#include "pch.hpp"
#include <Windows.h>

#include "SmartBot.hpp"

int SmartBot::m_botId = 1;


std::pair<int, int> SmartBot::makeMove(const std::string message, Playground playground) {

	Sleep(1000);
	std::pair<int, int> directionOfOwnPair = checkForDirectionOfPair(m_lastX-1, m_lastY-1, playground, m_symbol);
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
	
	for (int y = 0; y < playground.getHeight(); y++) {
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

	
	if (m_lastX != 0 && m_lastY != 0) {
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

	int newX = (playground.getWidth() + 1) / 2;
	int newY = (playground.getHeight() + 1) / 2;
	m_lastX = newX;
	m_lastY = newY;
	return std::make_pair(newX, newY);
}

bool SmartBot::simulateMove(Playground playground, int column, int line,  char symbol) {
	playground.placeSymbol(symbol, column, line);
	return playground.checkForWin(column - 1, line - 1, symbol);
}

std::pair<int, int> SmartBot::checkForDirectionOfPair(int x, int y, Playground& playground, char symbol) {
	if (playground.countCells(x - 1, y, -1, 0, symbol) >= 1) {
		return std::make_pair(1, 0);
	}
	else if (playground.countCells(x + 1, y, 1, 0, symbol) >= 1) {
		return std::make_pair(-1, 0);
	}
	else if (playground.countCells(x, y - 1, 0, -1, symbol) >= 1) {
		return std::make_pair(0, 1);
	}
	else if (playground.countCells(x, y + 1, 0, 1, symbol) >= 1) {
		return std::make_pair(0, -1);
	}
	else if (playground.countCells(x - 1, y - 1, -1, -1, symbol) >= 1) {
		return std::make_pair(1, 1);
	}
	else if (playground.countCells(x + 1, y + 1, 1, 1, symbol) >= 1) {
		return std::make_pair(-1, -1);
	}
	else if (playground.countCells(x - 1, y + 1, -1, 1, symbol) >= 1) {
		return std::make_pair(1, -1);
	}
	else if (playground.countCells(x + 1, y - 1, 1, -1, symbol) >= 1) {
		return std::make_pair(-1, 1);
	}
	else{
		return std::make_pair(0, 0);
	}
			
	
}
