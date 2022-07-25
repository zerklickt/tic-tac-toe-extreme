#include "pch.h"
#include <iostream>

#include "Player.hpp"
#include "RandomBot.hpp"
#include "Human.hpp"
#include "SmartBot.hpp"
#include "Playground.hpp"
#include "GUI.hpp"


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	//
	Player player1("Simon", 97);
	RandomBot bot1(98);
	Human human1("Nick", 99);
	SmartBot smartbot1(100);
	std::cout << player1.getName() << std::endl << player1.getSymbol() << std::endl;
	std::cout << bot1.getName() << std::endl << bot1.getSymbol() << std::endl;
	std::cout << human1.getName() << std::endl << human1.getSymbol() << std::endl;
	std::cout << smartbot1.getName() << std::endl << smartbot1.getSymbol() << std::endl;

	GUI gui;
	Playground playground(23, 25);
	gui.printPlayground(playground);
	playground.placeSymbol(player1.getSymbol(), 2, 4);
	playground.placeSymbol(human1.getSymbol(), 5, 5);
	playground.placeSymbol(bot1.getSymbol(), 9, 9);
	playground.placeSymbol(smartbot1.getSymbol(), 15, 15);
	gui.printPlayground(playground);
	//
	return RUN_ALL_TESTS();
}