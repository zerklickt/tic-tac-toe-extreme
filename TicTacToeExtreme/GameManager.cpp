#include "pch.hpp"
#include <iostream>
#include <windows.h>

#include "GameManager.hpp"
#include "GUI.hpp"
#include "Playground.hpp"
#include "Human.hpp"
#include "InputManager.hpp"
#include "RandomBot.hpp"
#include "SmartBot.hpp"
//#include "Gamemode.hpp"

using namespace std;

// choosing a gamemode 
int GameManager::chooseNumberOf(std::string text, int lowest, int highest){

    int Count = InputManager::readIntFromRange("Insert number of " + text + ":", lowest, highest);
    //system("cls");
    return Count;
}

// initializing players or bots depending on the gamemode
void GameManager::startGame(){



    cout << "READY PLAYER 1" << endl;
    m_playerCount = chooseNumberOf("Players", 2, 26);
    int humanCount = chooseNumberOf("Humans", 0, m_playerCount);
    int randomBotCount = chooseNumberOf("RandomBots", 0, m_playerCount - humanCount);
    int smartBotCount = m_playerCount - humanCount - randomBotCount;

    cout << "Players:" << m_playerCount << endl;
    cout << "Humans:" << humanCount << endl;
    cout << "RandomBots:" << randomBotCount << endl;
    cout << "SmartBots:" << smartBotCount << endl;
    /*
    for (int i = 0; i < playerCount; i++) {
        Player* player = NULL;
        m_players.push_back(player);
    }*/
   
    for (int i = 0; i < humanCount; i++) {
        string name= InputManager::readString("Input Name of Player :");
        //Human human(name, 97 + i);
        m_players.push_back(new Human(name, 97 + i));
    }
    for (int i = 0; i < randomBotCount; i++) {
        //RandomBot randombot(97 + humanCount + i);
        m_players.push_back(new RandomBot(97 + humanCount + i));
    }
    for (int i = 0; i < smartBotCount; i++) {
        SmartBot smartBot(97 + humanCount + randomBotCount + i);
        m_players.push_back(new SmartBot(97 + humanCount + randomBotCount + i));
    }

    //Debug
    /*
    for (auto i : m_players) {
        cout << "Name Player : " << i.getName();
        cout << ",  Symbol Player : " << i.getSymbol() << endl;
        
    }
    */
    
    
    gameLoop();
    
}


// placing a chip per turn until someone wins
void GameManager::gameLoop()
{
    
    unsigned int counter = 0;
    bool won = false;
    auto turn = m_players.begin();
    GUI gui;
    gui.printPlayground(*getPlayground());
    
    do
    {
        //turn = m_players[counter % m_playerCount];
        std::pair<int, int> position = (*turn)->makeMove("Your turn, " + (*turn)->getName(), *getPlayground());
        bool success = getPlayground()->placeSymbol((*turn)->getSymbol(), position.first, position.second);
        if (!success)
        {
            gui.printPlayground(*getPlayground());
            cout << "Invalid move! " << (*turn)->getName() << ", go again!" << endl << endl;
            continue;
        }
        gui.printPlayground(*getPlayground());
        won = getPlayground()->checkForWin(position.first - 1, position.second - 1, (*turn)->getSymbol());
        counter++;
        if (counter % m_playerCount == 0) {
            turn = m_players.begin();
        }
        else {
            turn = std::next(turn, 1);
        }
        
        

    } while (!won);

    endGame((*turn)->getName());
}


// gameover text
void GameManager::endGame(const std::string name) const
{

    cout << "Game over" << endl;
    cout << "Winner: " << name << endl << endl;

    cout << "|@@@@|     |####| " << endl;
    cout << "|@@@@|     |####|" << endl;
    cout << "|@@@@|     |####|" << endl;
    cout << "\\@@@@|     |####/" << endl;
    cout << " \\@@@|     |###/" << endl;
    cout << "  `@@|_____|##'" << endl;
    cout << "       (O)" << endl;
    cout << "    .-'''''-." << endl;
    cout << "  .'  * * *  `." << endl;
    cout << " :  *       *  :" << endl;
    cout << " :~W I N N E R~:" << endl;
    cout << " :  *       *  :" << endl;
    cout << "  `.  * * *  .'" << endl;
    cout << "    `-.....-'" << endl;
}


Playground* GameManager::getPlayground()
{
    return &m_playground;
}
