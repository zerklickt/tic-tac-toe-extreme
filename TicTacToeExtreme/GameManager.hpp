#pragma once
#include <vector>
#include <string>
#include "Playground.hpp"
#include "Player.hpp"
#include "GUI.hpp"

class GameManager
{
public:
    GameManager() {};
    ~GameManager() {};

    int chooseNumberOf(std::string, int, int);
    void startGame();
    /*
    void endGame(const std::string name) const;

    Playground* getPlayground();
    void chooseBot(Player*&, char, std::string);
    */

private:
    std::vector<Player*> m_players;

    /*
    void gameLoop(Player* player1, Player* player2);
    int m_gameMode;
    Playground m_playground;
    */
};