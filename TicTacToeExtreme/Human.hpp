#pragma once
#include "Player.hpp"

class Human : public Player{

public:

    Human(const std::string name, char symbol)
        : Player(name, symbol)

    {};

    ~Human() {};

    std::pair<int,int> makeMove(std::string message, Playground playground) override;

private:

};

