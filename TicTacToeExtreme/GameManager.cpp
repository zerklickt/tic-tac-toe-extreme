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
    int playerCount = chooseNumberOf("Players", 2, 26);
    int humanCount = chooseNumberOf("Humans", 0, playerCount);
    int randomBotCount = chooseNumberOf("RandomBots", 0, playerCount - humanCount);
    int smartBotCount = playerCount - humanCount - randomBotCount;

    cout << "Players:" << playerCount << endl;
    cout << "Humans:" << humanCount << endl;
    cout << "RandomBots:" << randomBotCount << endl;
    cout << "SmartBots:" << smartBotCount << endl;
}

/*
// placing a chip per turn until someone wins
void GameManager::gameLoop(Player* player1, Player* player2)
{
    int counter = 0;
    bool won = false;
    Player* turn = player1;
    GUI gui;
    gui.printPlayground(*getPlayground());

    do
    {
        if (counter % 2 == 0)
        {
            turn = player1;
        }
        else
        {
            turn = player2;
        }
        int xPosition = turn->makeMove(turn->getName() + ", place chip in column: ", *getPlayground());
        int yPosition = getPlayground()->placeChip(turn->getColor(), xPosition);
        if (yPosition == -1)
        {
            gui.printPlayground(*getPlayground());
            cout << "Invalid move! " << turn->getName() << ", go again!" << endl << endl;
            continue;
        }
        gui.printPlayground(*getPlayground());
        won = getPlayground()->checkForWin(xPosition - 1, yPosition - 1, turn->getColor());
        counter++;

    } while (!won);

    endGame(turn->getName());
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

// gamemode 2 or 3 -> bot choosen
void GameManager::chooseBot(Player*& botPlayer, Color color, std::string message)
{
    cout << message << endl;
    cout << "RandomBot (Input: 1) " << endl;
    cout << "SmartBot (Input: 2) " << endl;
    cout << "HorizontalBot (Input: 3) " << endl;
    cout << "VerticalBot (Input: 4) " << endl;
    int bot = InputManager::readIntFromRange("", 1, 4);

    switch (bot)
    {
    case 1:
        botPlayer = new RandomBot(color);
        break;
    case 2:
        botPlayer = new SmartBot(color);
        break;
    case 3:
        botPlayer = new HorizontalBot(color);
        break;
    case 4:
        botPlayer = new VerticalBot(color);
        break;
    default:
        break;
    }
}

Playground* GameManager::getPlayground()
{
    return &m_playground;
}
*/