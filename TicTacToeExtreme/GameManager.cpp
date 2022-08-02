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

void GameManager::printAsciiArt() {
    
    cout << "  ________________   _________   ______   __________  ______   _  __    __________  ________  _________" << endl;
    cout << " /_  __/  _/ ____/  /_  __/   | / ____/  /_  __/ __ \\/ ____/  | |/ /   /_  __/ __ \\/ ____/  |/  / ____/" << endl;
    cout << "  / /  / // /        / / / /| |/ /        / / / / / / __/     |   /_____/ / / /_/ / __/ / /|_/ / __/   " << endl;
    cout << " / / _/ // /___     / / / ___ / /___     / / / /_/ / /___    /   /_____/ / / _, _/ /___/ /  / / /___   " << endl;
    cout << "/_/ /___/\\____/    /_/ /_/  |_\\____/    /_/  \\____/_____/   /_/|_|    /_/ /_/ |_/_____/_/  /_/_____/   " << endl;
    cout << "                                                                                                       " << endl;

}

// initializing players and bots
void GameManager::startGame() {

    printAsciiArt();

    m_playerCount = InputManager::readIntFromRange("Players: ", 2, 26);
    int humanCount = InputManager::readIntFromRange("Humans (max. " + std::to_string(m_playerCount) + "): ", 0, m_playerCount);
    int randomBotCount = InputManager::readIntFromRange("Random Bots (max. " + std::to_string(m_playerCount - humanCount) + "): ",
        0,
        m_playerCount - humanCount);
    int smartBotCount = m_playerCount - humanCount - randomBotCount;
    
    displayPlayerInformation(humanCount, randomBotCount, smartBotCount);
    createPlayers(humanCount, randomBotCount, smartBotCount);
    gameLoop();
    
}

// displays information about amount of players and bots
void GameManager::displayPlayerInformation(int humanCount, int randomBotCount, int smartBotCount) {
    cout << "Players:\t" << m_playerCount << endl;
    cout << "Humans:\t\t" << humanCount << endl;
    cout << "RandomBots:\t" << randomBotCount << endl;
    cout << "SmartBots:\t" << smartBotCount << endl;
}

// creates all players and puts them in a list
void GameManager::createPlayers(int humanCount, int randomBotCount, int smartBotCount) {
    for (int i = 0; i < humanCount; i++) {
        string name = InputManager::readString("Input Name of Player " + std::to_string(i + 1) + ":");
        m_players.push_back(new Human(name, 97 + i));
    }
    for (int i = 0; i < randomBotCount; i++) {
        m_players.push_back(new RandomBot(97 + humanCount + i));
    }
    for (int i = 0; i < smartBotCount; i++) {
        m_players.push_back(new SmartBot(97 + humanCount + randomBotCount + i));
    }
}

// placing a chip per turn until someone wins
void GameManager::gameLoop() {
    
    unsigned int counter = 0;
    bool won = false;
    auto turn = m_players.begin();
    GUI gui;
    gui.printPlayground(*getPlayground());
    
    do {
        std::pair<int, int> position = (*turn)->makeMove("Your turn, " + (*turn)->getName(), *getPlayground());
        bool success = getPlayground()->placeSymbol((*turn)->getSymbol(), position.first, position.second);
        if (!success) {
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
        endGame(*(*turn));
    }
    else {
        cout << "TIE! The field is full!" << endl << endl;
    }
}


// gameover graphics
void GameManager::endGame(const Player& winner) const {

    cout << "Game over" << endl;
    cout << "Winner: " << winner.getName() << " (" << winner.getSymbol() << ")" << endl << endl;

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

Playground* GameManager::getPlayground() {
    return &m_playground;
}
