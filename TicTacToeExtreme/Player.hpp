#pragma once

#include <iostream>

//#include "Playground.hpp"

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

    //virtual int makeMove(const std::string, Playground) = 0;

protected:

    std::string m_name;
    const char m_symbol;

};