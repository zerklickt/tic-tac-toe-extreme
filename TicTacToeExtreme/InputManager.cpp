#include <iostream>
#include <string>

#include "pch.hpp"
#include "InputManager.hpp"



std::string InputManager::readString(std::string message)
{
	std::string text;
	std::cout << message << std::endl;
	std::cin >> text;
	return text;
}

int InputManager::readIntFromRange(static std::string message, int min, int max)
{
	bool flag = false;
	int ret = 0;
	do
	{
		try {
			ret = std::stoi(readString(message));
		}
		catch (std::invalid_argument) {
			std::cout << "Eingabe ungueltig, bitte erneut eingeben!" << std::endl;
			continue;
		}
		if (ret >= min && ret <= max)
		{
			flag = true;
		}
		else
		{
			std::cout << "Eingabe ungueltig, bitte erneut eingeben!" << std::endl;
		}
	} while (flag == false);
	return ret;
}
