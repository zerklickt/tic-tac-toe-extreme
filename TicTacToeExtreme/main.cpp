#include "pch.hpp"
#include <iostream>

#include "Player.hpp"
#include "RandomBot.hpp"
#include "Human.hpp"
#include "SmartBot.hpp"
#include "Playground.hpp"
#include "GUI.hpp"
#include "FileManager.hpp"


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);

	//RUN_ALL_TESTS();
	//
	Player player1("Simon", 97);
	RandomBot bot1(98);
	Human human1("Nick", 99);
	SmartBot smartbot1(100);

	FileManager filemanager;
	filemanager.readFile("../test.txt");
	

	GUI gui;
	Playground playground(filemanager.getFieldWidth(), filemanager.getFieldHeight());
	playground.placeSymbol(player1.getSymbol(), 2, 4);
	playground.placeSymbol(human1.getSymbol(), 5, 5);
	playground.placeSymbol(bot1.getSymbol(), 9, 9);
	gui.printPlayground(playground);

	
	
	
	return RUN_ALL_TESTS();
	//return 0;
}