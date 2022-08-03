#include "pch.hpp"
#include <iostream>

#include "GameManager.hpp"
#include "GUI.hpp"
#include "Playground.hpp"
#include "Human.hpp"
#include "InputManager.hpp"
#include "RandomBot.hpp"
#include "SmartBot.hpp"

using namespace std;

void GameManager::printAsciiArt() const {
    
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
    int humanCount{ 0 };
    int randomBotCount{ 0 };
    int smartBotCount{ 0 };

    playerSetup(humanCount, randomBotCount, smartBotCount);
    createPlayers(humanCount, randomBotCount, smartBotCount);
    gameLoop();
    
}

// reads in amount of players and bots
void GameManager::playerSetup(int& humanCount, int& randomBotCount, int& smartBotCount) {

    m_playerCount = InputManager::readIntFromRange("Players: ", 2, 26);
    humanCount = InputManager::readIntFromRange("Humans (max. " + std::to_string(m_playerCount) + "): ", 0, m_playerCount);
    // checks if all players are humans
    if (humanCount == m_playerCount) {
        cout << "Continuing without any bots" << endl;
    }
    else {
        randomBotCount = InputManager::readIntFromRange("Random Bots (max. " + std::to_string(m_playerCount - humanCount) + "): ",
            0,
            m_playerCount - humanCount);
        smartBotCount = m_playerCount - humanCount - randomBotCount;
        displayPlayerInformation(humanCount, randomBotCount, smartBotCount);
    }
}

// displays information about amount of players and bots
void GameManager::displayPlayerInformation(const int& humanCount, const int& randomBotCount, const int& smartBotCount) const {
    cout << "Players:\t" << m_playerCount << endl;
    cout << "Humans:\t\t" << humanCount << endl;
    cout << "RandomBots:\t" << randomBotCount << endl;
    cout << "SmartBots:\t" << smartBotCount << endl;
}

// creates all players and puts them in a list
void GameManager::createPlayers(const int humanCount, const int randomBotCount, const int smartBotCount) {
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
    unsigned int counter{ 0 };
    bool won{ false };
    auto turn = m_players.begin();
    Player* currentPlayer = (*turn);
    m_gui.printPlayground(getPlayground());
    
    do {
        std::pair<int, int> position = promptMove(currentPlayer);
        won = getPlayground().checkForWin(currentPlayer->getSymbol(),position.first, position.second);
        if (won) {
            break;
        }
        counter++;
        currentPlayer = turnToNextPlayer(turn, counter);        
    } while (!won && !getPlayground().isFull());

    if (!won) {
        currentPlayer = NULL;
    }
    endGame(currentPlayer);
}

// prompts player to make their move until they provide a valid move
std::pair<int, int> GameManager::promptMove(Player* currentPlayer) {
    std::pair<int, int> position;
    bool success;
    do {
        position = currentPlayer->makeMove("Your turn, " + currentPlayer->getName(), getPlayground());
        success = getPlayground().placeSymbol(currentPlayer->getSymbol(), position.first, position.second);
        m_gui.printPlayground(getPlayground());
        if (!success) {
            cout << "Invalid move! " << currentPlayer->getName() << ", go again!" << endl << endl;
        }
    } while (!success);
    return position;
}

// sets turn and currentPlayer to the next player
Player* GameManager::turnToNextPlayer(std::list<Player*>::iterator& turn, const unsigned int& counter) {
    if (counter % m_playerCount == 0) {
        turn = m_players.begin();
    }
    else {
        turn = std::next(turn, 1);
    }
    return *turn;
}

// gameover screen
void GameManager::endGame(const Player* winner) const {
    // check if tie
    if (winner == NULL) {
        cout << "TIE! The field is full!" << endl << endl;
    }
    else {
        cout << "Game over" << endl;
        cout << "Winner: " << winner->getName() << " (" << winner->getSymbol() << ")" << endl << endl;
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
}

Playground& GameManager::getPlayground() {
    return m_playground;
}
