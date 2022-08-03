#pragma once

#include <list>
#include <random>
#include <string>

#include "Player.hpp"


class SmartBot : public Player{

public:
	SmartBot() {};
	SmartBot(const char symbol)
		: Player("SmartBot#" + std::to_string(SmartBot::m_botId), symbol)
	{
		SmartBot::m_botId++;
	};

	~SmartBot() {};
	std::pair<int, int> makeMove(const std::string message, Playground playground) override;


	friend class SmartBotTest;
	//friend class testing::Test;

private:
	static int m_botId;
	bool simulateMove(Playground, int, int, char);
	std::pair<int, int> checkForDirectionOfPair(int, int, Playground&, char);
	std::pair<int, int> winWithPair(Playground&);
	std::pair<int, int> placeBetweenTwoToWin(Playground&);
	std::pair<int, int> preventWinByPlacingBetweenTwo(Playground&);
	std::pair<int, int> checkAroundOpposingField(int, int, Playground&, char);
	std::pair<int, int> preventWinWithPair(Playground&);
	std::pair<int, int> placeNextToLastPlaced(Playground&);
	std::pair<int, int> trySmartMove(Playground&);
	std::pair<int, int> placeRandom(Playground&);
	std::pair<int, int> findOpposingPair(Playground&, int, int);

	int m_lastX = 0;
	int m_lastY = 0;

};

