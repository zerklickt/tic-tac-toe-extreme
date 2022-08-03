#include <iostream>
#include <string>

#include "pch.hpp"
#include "InputManager.hpp"



std::string InputManager::readString(const std::string message) {
	std::string text;
	std::cout << message << std::endl;
	std::cin >> text;
	return text;
}

// reads an int and only allows values between min and max
int InputManager::readIntFromRange(const std::string message, const int min, const int max) {
	bool flag = false;
	int ret = 0;
	do {
		try {
			ret = std::stoi(readString(message));
		}
		catch (std::invalid_argument) {
			std::cout << "Input is NaN! Please enter a number." << std::endl;
			continue;
		}
		if (ret >= min && ret <= max) {
			flag = true;
		}
		else {
			std::cout << "Invalid number entered! Numbers need to be between " << min << " and " << max << std::endl;
		}
	} while (flag == false);
	return ret;
}
