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

    int chooseNumberOf(std::string, int, int);
    void startGame();
    void printAsciiArt();
    
    void endGame(const std::string name) const;

    Playground* getPlayground();
    
    

private:
    //std::vector<Player> m_players;
    //std::vector<Player> m_players;
    std::list<Player*> m_players;

    int m_playerCount;
    void gameLoop();
    Playground m_playground;
    
};