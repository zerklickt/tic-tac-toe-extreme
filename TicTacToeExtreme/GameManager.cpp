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


using namespace std;

// choosing a gamemode 
int GameManager::chooseNumberOf(std::string text, int lowest, int highest){

    int Count = InputManager::readIntFromRange("Insert number of " + text + ":", lowest, highest);
    
    return Count;
}

void GameManager::printAsciiArt() {
    
    cout << "  ________________   _________   ______   __________  ______   _  __    __________  ________  _________" << endl;
    cout << " /_  __/  _/ ____/  /_  __/   | / ____/  /_  __/ __ \\/ ____/  | |/ /   /_  __/ __ \\/ ____/  |/  / ____/" << endl;
    cout << "  / /  / // /        / / / /| |/ /        / / / / / / __/     |   /_____/ / / /_/ / __/ / /|_/ / __/   " << endl;
    cout << " / / _/ // /___     / / / ___ / /___     / / / /_/ / /___    /   /_____/ / / _, _/ /___/ /  / / /___   " << endl;
    cout << "/_/ /___/\\____/    /_/ /_/  |_\\____/    /_/  \\____/_____/   /_/|_|    /_/ /_/ |_/_____/_/  /_/_____/   " << endl;
    cout << "                                                                                                       " << endl;


}

// initializing players or bots depending on the gamemode
void GameManager::startGame(){

    printAsciiArt();

    cout << "READY PLAYER 1" << endl;
    m_playerCount = chooseNumberOf("Players", 2, 26);
    int humanCount = chooseNumberOf("Humans", 0, m_playerCount);
    int randomBotCount = chooseNumberOf("RandomBots", 0, m_playerCount - humanCount);
    int smartBotCount = m_playerCount - humanCount - randomBotCount;

    cout << "Players:" << m_playerCount << endl;
    cout << "Humans:" << humanCount << endl;
    cout << "RandomBots:" << randomBotCount << endl;
    cout << "SmartBots:" << smartBotCount << endl;
   
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
        won = getPlayground()->checkForWin((*turn)->getSymbol(),position.first, position.second);
        if (won) {
            break;
        }
        counter++;
        if (counter % m_playerCount == 0) {
            turn = m_players.begin();
        }
        else {
            turn = std::next(turn, 1);
        }
        
        

    } while (!won && !getPlayground()->isFull());

    if (won) {
        endGame((*turn)->getName());
    }
    else {
        cout << "You sock. TIE!" << endl;
    }
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
