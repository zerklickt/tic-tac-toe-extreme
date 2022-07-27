#pragma once
#include <iostream>
#include <fstream>

class FileManager{

public:
	FileManager()
		: m_fieldHeight(3)
		, m_fieldWidth(3)
	{};

	void readFile(const std::string);

	int getFieldHeight();
	int getFieldWidth();


private:
	int m_fieldHeight;
	int m_fieldWidth;

};

