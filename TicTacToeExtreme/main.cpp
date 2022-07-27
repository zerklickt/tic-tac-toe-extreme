#include "pch.hpp"
#include <iostream>

#include "Player.hpp"
#include "RandomBot.hpp"
#include "Human.hpp"
#include "SmartBot.hpp"
#include "Playground.hpp"
#include "GUI.hpp"
#include "FileManager.hpp"
#include "GameManager.hpp"


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);

	//RUN_ALL_TESTS();
	
	GameManager gameManager;
	gameManager.startGame();
	
	
	return RUN_ALL_TESTS();
	//return 0;
}