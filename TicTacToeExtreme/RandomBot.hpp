#pragma once

#include "Player.hpp"

class RandomBot : public Player{

public:

	RandomBot() {};
	RandomBot(const char symbol)
		: Player("RandomBot#" + std::to_string(RandomBot::m_botId), symbol)
	{
		RandomBot::m_botId++;
	};

	~RandomBot() {};

	//int makeMove(const std::string message, Playground playground) override;

private:
	static int m_botId;

};

