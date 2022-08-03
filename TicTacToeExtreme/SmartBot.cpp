#include <Windows.h>

#include "pch.hpp"
#include "SmartBot.hpp"
#include "RandomBot.hpp"

int SmartBot::m_botId{ 1 };

//called by gameManager 
std::pair<int, int> SmartBot::makeMove(const std::string message, Playground playground) {

	//Sleep(300);
	std::pair<int, int> returnedPair = trySmartMove(playground);
	if (returnedPair.first != 0 && returnedPair.second != 0) {
		return returnedPair;
	}
	if (m_lastX > 0) {
		returnedPair = placeRandom(playground);
		return returnedPair;
	}
	m_lastX = (playground.getWidth() + 1) / 2;										
	m_lastY = (playground.getHeight() + 1) / 2;
	return std::make_pair(m_lastX, m_lastY);
}

// simulates a move and checks if this move leads to a win
bool SmartBot::simulateMove(Playground playground, const int column, const int line, const char symbol) {
	playground.placeSymbol(symbol, column, line);
	return playground.checkForWin(symbol, column, line);
}

// returns vector to the next position of an existing pair
std::pair<int, int> SmartBot::checkForDirectionOfPair(Playground& playground, const int x, const int y, const char symbol) {

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

//recognizes a pair and returns the coordinates to make a triple (if possible)
std::pair<int, int> SmartBot::winWithPair(Playground& playground){

	std::pair<int, int> directionOfOwnPair = checkForDirectionOfPair(playground, m_lastX - 1, m_lastY - 1, m_symbol);
	if (directionOfOwnPair.first != 0 || directionOfOwnPair.second != 0) {
		if (playground.canPlaceSymbol(m_lastX + directionOfOwnPair.first, m_lastY + directionOfOwnPair.second)) {
			m_lastX = m_lastX + directionOfOwnPair.first;
			m_lastY = m_lastY + directionOfOwnPair.second;
			return std::make_pair(m_lastX, m_lastY);
		}
		else if (playground.canPlaceSymbol(m_lastX + (-2) * directionOfOwnPair.first, m_lastY + (-2) * directionOfOwnPair.second)) {
			m_lastX = m_lastX + (-2) * directionOfOwnPair.first;
			m_lastY = m_lastY + (-2) * directionOfOwnPair.second;
			return std::make_pair(m_lastX, m_lastY);
		}
	}
	return std::make_pair(0, 0);
}

//looks for a split ("|x| |x|"-situation) and places in the middle to win
std::pair<int, int> SmartBot::placeBetweenTwoToWin(Playground& playground){

	for (int y = 1; y <= playground.getHeight(); y++) {													
		for (int x = 1; x <= playground.getWidth(); x++) {
			if (playground.canPlaceSymbol(x, y) && simulateMove(playground, x, y, m_symbol)) {
				return std::make_pair(x, y);
			}
		}
	}
	return std::make_pair(0, 0);
}

//looks for a split ("|x| |x|"-situation) and places in the middle to prevent the opponent from winning
std::pair<int, int> SmartBot::preventWinByPlacingBetweenTwo(Playground& playground){

	for (int y = 1; y <= playground.getHeight(); y++) {													
		for (int x = 1; x <= playground.getWidth(); x++) {
			char check = playground.getField()[x - 1][y - 1];
			if (check != m_symbol && check != ' ') {
				std::pair<int, int> returnedPair = checkAroundOpposingField(playground, x, y, check);
				if (returnedPair.first != 0 || returnedPair.second != 0) {
					return returnedPair;
				}
				
			}
		}
	}
	return std::make_pair(0, 0);
}

//checks every field around an opposing field for a split ("|x| |x|"-situation) (helper-method for "preventWinByPlacingBetweenTwo()")
std::pair<int, int> SmartBot::checkAroundOpposingField(Playground& playground, const int x, const int y, const char check){

	for (int ix = -1; ix <= 1; ix++) {
		for (int iy = -1; iy <= 1; iy++) {
			if (ix == 0 && iy == 0)
				continue;
			if (playground.canPlaceSymbol(x + ix, y + iy) && simulateMove(playground, x + ix, y + iy, check)) {
				return std::make_pair(x + ix, y + iy);
			}
		}
	}
	return std::make_pair(0, 0);
}

//checks for oppsing pairs and places next to them to prevent them from winning
std::pair<int, int> SmartBot::preventWinWithPair(Playground& playground){

	for (int y = 0; y < playground.getHeight(); y++) {													
		for (int x = 0; x < playground.getWidth(); x++) {
			if (playground.getField()[x][y] != ' ') {
				std::pair<int, int> returnedPair = findOpposingPair(playground, x, y);
				if (returnedPair.first != 0 || returnedPair.second != 0) {
					return returnedPair;
				}
			}
		}
	}
	return std::make_pair(0, 0);
}

//finds opposing pair (helper-method for "preventWinWithPair()")
std::pair<int, int> SmartBot::findOpposingPair(Playground& playground, const int x, const int y){

	std::pair<int, int> directionOfPair = checkForDirectionOfPair(playground, x, y, playground.getField()[x][y]);
	if (directionOfPair.first != 0 || directionOfPair.second != 0) {
		if (playground.canPlaceSymbol(x + 1 + directionOfPair.first, y + 1 + directionOfPair.second)) {
			m_lastX = x + 1 + directionOfPair.first;
			m_lastY = y + 1 + directionOfPair.second;
			return std::make_pair(m_lastX, m_lastY);
		}
		else if (playground.canPlaceSymbol(x + 1 + (-2) * directionOfPair.first, y + 1 + (-2) * directionOfPair.second)) {
			m_lastX = x + 1 + (-2) * directionOfPair.first;
			m_lastY = y + 1 + (-2) * directionOfPair.second;
			return std::make_pair(m_lastX, m_lastY);
		}
	}
	return std::make_pair(0, 0);
}

//tries to place a chip next to his last placed chip
std::pair<int, int> SmartBot::placeNextToLastPlaced(Playground& playground){

	if (m_lastX != 0 && m_lastY != 0) {												
		for (int i = m_lastX - 1; i <= m_lastX + 1; i++) {
			for (int j = m_lastY - 1; j <= m_lastY + 1; j++) {
				if (playground.canPlaceSymbol(i, j)) {
					m_lastX = i;
					m_lastY = j;
					return std::make_pair(i, j);
				}
			}
		}
	}
	return std::make_pair(0, 0);
}

//try all smart moves in order: 1.try to win; 2. try to prevent win; 3. try to place next to your lastPlaced chip (=create a pair)
std::pair<int, int> SmartBot::trySmartMove(Playground& playground) {

	std::pair<int, int> returnedPair;
	returnedPair = winWithPair(playground);
	if (returnedPair.first != 0 || returnedPair.second != 0) {
		return returnedPair;
	}

	returnedPair = placeBetweenTwoToWin(playground);
	if (returnedPair.first != 0 || returnedPair.second != 0) {
		return returnedPair;
	}

	returnedPair = preventWinByPlacingBetweenTwo(playground);
	if (returnedPair.first != 0 || returnedPair.second != 0) {
		return returnedPair;
	}

	returnedPair = preventWinWithPair(playground);
	if (returnedPair.first != 0 || returnedPair.second != 0) {
		return returnedPair;
	}

	returnedPair = placeNextToLastPlaced(playground);
	if (returnedPair.first != 0 || returnedPair.second != 0) {
		return returnedPair;
	}
	return std::make_pair(0, 0);
}

//generates random coordinates using the RandomBot's algorithm
std::pair<int, int> SmartBot::placeRandom(Playground& playground) {
	return RandomBot::performRandomMove(playground);
}


