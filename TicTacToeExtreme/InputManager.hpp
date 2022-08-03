#pragma once

#include <iostream>

class InputManager {

public:
	InputManager() {};
	~InputManager() {};

	static std::string readString(const std::string);
	static int readIntFromRange(const std::string, const int, const int);
};
