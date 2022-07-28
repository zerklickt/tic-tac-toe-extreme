#include "pch.hpp"
#include <iostream>


#include "Human.hpp"
#include "InputManager.hpp"


//places chip in column depending on column input
std::pair<int, int> Human::makeMove(const std::string message, Playground playground)
{
	std::cout << message << std::endl;
	int y = InputManager::readIntFromRange("Input Line: ", 1, playground.getHeight());
	int x = InputManager::readIntFromRange("Input Column: ", 1, playground.getWidth());
	

	return std::make_pair(x,y);
}

