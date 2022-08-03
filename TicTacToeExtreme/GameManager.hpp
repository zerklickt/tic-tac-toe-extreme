#pragma once

#include <string>
#include <list>

#include "Playground.hpp"
#include "Player.hpp"
#include "GUI.hpp"
#include "Human.hpp"
#include "FileManager.hpp"

class GameManager {

public:
    GameManager() {
        FileManager filemanager;
        m_playground = Playground(filemanager.getFieldWidth(), filemanager.getFieldHeight());
    };
    ~GameManager() {};
    void startGame();
    Playground& getPlayground();

    friend class GameManagerTest;
    
private:
    std::list<Player*> m_players;
    int m_playerCount;
    Playground m_playground;
    GUI m_gui;

    Player* turnToNextPlayer(std::list<Player*>::iterator& turn, const unsigned int& counter);
    std::pair<int, int> promptMove(Player* currentPlayer);
    void gameLoop();
    void printAsciiArt() const;
    void createPlayers(const int humanCount, const int randomBotCount, const int smartBotCount);
    void playerSetup(int& humanCount, int& randomBotCount, int& smartBotCount);
    void displayPlayerInformation(const int& humanCount, const int& randomBotCount, const int& smartBotCount) const;
    void endGame(const Player* winner) const;
};