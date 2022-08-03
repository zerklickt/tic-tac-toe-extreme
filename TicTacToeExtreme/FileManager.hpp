#pragma once

#include <iostream>
#include <fstream>

class FileManager {

public:
	FileManager() {
		readFile("../config.txt");
	};
	void readFile(const std::string);
	int getFieldHeight();
	int getFieldWidth();

private:
	int m_fieldHeight;
	int m_fieldWidth;

	std::ifstream m_configFile;
	void FileManager::tryToReadProperties();
	int readInInt(std::string line, const std::string parameter, const int _default);
};

