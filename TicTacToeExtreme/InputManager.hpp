#pragma once
#include <iostream>

class InputManager
{
public:

	InputManager() {};
	~InputManager() {};

	static std::string readString(std::string);
	static int readIntFromRange(std::string, int, int);
private:

};
