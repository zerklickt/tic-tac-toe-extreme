#pragma once
#include <iostream>
#include <fstream>

class FileManager{

public:
	FileManager() {};

	void readFile(const std::string);

	int getFieldHeight();
	int getFieldWidth();


private:
	int m_fieldHeight;
	int m_fieldWidth;

};

