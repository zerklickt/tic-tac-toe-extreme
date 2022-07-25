#include "pch.h"
#include <iostream>

#include "Player.hpp"
#include "RandomBot.hpp"
#include "Human.hpp"
#include "SmartBot.hpp"


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


	//
	return RUN_ALL_TESTS();
}