#pragma once

#include <iostream>

#include "Playground.hpp"

class Player{

public:
    
    Player()
        : m_name("Player")
        , m_symbol(' ')
    {};
    
    Player(const std::string name, const char symbol)
        : m_name(name)
        , m_symbol(symbol)
    {};

    ~Player() {};

    std::string getName() const;

    char getSymbol() const;

    virtual std::pair<int, int> makeMove(const std::string, Playground) = 0; //{ return std::make_pair(1, 1); };

protected:

    std::string m_name;
    const char m_symbol;

};