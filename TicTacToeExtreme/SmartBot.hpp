#pragma once
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

private:
	static int m_botId;

};

