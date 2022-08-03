#include "pch.hpp"
#include <random>

#include "RandomBot.hpp"

int RandomBot::m_botId{ 1 };

// places symbol in a random spot
std::pair<int, int> RandomBot::makeMove(const std::string message, Playground playground) {
	return performRandomMove(playground);
}

std::pair<int, int> RandomBot::performRandomMove(Playground& playground) {
	int x, y;
	do {
		//Random Number generator copied from https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> distx(1, playground.getWidth());
		std::uniform_int_distribution<std::mt19937::result_type> disty(1, playground.getHeight());
		x = distx(rng);
		y = disty(rng);
	} while (!playground.canPlaceSymbol(x, y));
	return std::make_pair(x, y);
}

