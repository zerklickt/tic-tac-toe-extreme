#pragma once
#include <vector>
#include <string>
#include "Playground.hpp"
#include "Player.hpp"
#include "GUI.hpp"
#include "Human.hpp"
#include <list>
#include "FileManager.hpp"

class GameManager
{
public:
    GameManager() {
        FileManager filemanager;
        m_playground = Playground(filemanager.getFieldWidth(), filemanager.getFieldHeight());
    };
    ~GameManager() {
     
    };

    void startGame();
    void printAsciiArt();
    
    void endGame(const Player& winner) const;

    Playground* getPlayground();
    
    

private:
    std::list<Player*> m_players;

    int m_playerCount;
    void gameLoop();
    Playground m_playground;

    void createPlayers(int humanCount, int randomBotCount, int smartBotCount);
    void displayPlayerInformation(int humanCount, int randomBotCount, int smartBotCount);
};