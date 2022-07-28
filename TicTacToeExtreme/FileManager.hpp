#pragma once
#include <iostream>
#include <fstream>

class FileManager{

public:
	FileManager(){

		readFile("../config.txt");
	};

	void readFile(const std::string);

	int getFieldHeight();
	int getFieldWidth();


private:
	int m_fieldHeight;
	int m_fieldWidth;

};

