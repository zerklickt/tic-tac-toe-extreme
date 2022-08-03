#pragma once

#include "Player.hpp"

class RandomBot : public Player {

public:
	RandomBot() {};
	RandomBot(const char symbol)
		: Player("RandomBot#" + std::to_string(RandomBot::m_botId), symbol)
	{
		RandomBot::m_botId++;
	};
	~RandomBot() {};
	std::pair<int, int> makeMove(const std::string message, Playground playground) override;
	static std::pair<int, int> performRandomMove(Playground& playground);

private:
	static int m_botId;
};

