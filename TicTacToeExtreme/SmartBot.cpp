#include "pch.hpp"
#include <random>

#include "SmartBot.hpp"

int SmartBot::m_botId = 1;


// places a chip in a random column
std::pair<int, int> SmartBot::makeMove(const std::string message, Playground playground)
{
	//Random Number generator copied from https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distx(1, playground.getWidth());
	std::uniform_int_distribution<std::mt19937::result_type> disty(1, playground.getHeight());

	int x = distx(rng);
	int y = disty(rng);
	return std::make_pair(x, y);
}


