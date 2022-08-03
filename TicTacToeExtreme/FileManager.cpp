#include <iostream>
#include <fstream>
#include <string>

#include "pch.hpp"
#include "FileManager.hpp"


void FileManager::readFile(const std::string path) {
	
    m_configFile = std::ifstream(path, std::ios::in);

    if (!m_configFile) {
        std::cout << "Error: file could not be opened" << std::endl;
        exit(1);
    }
    if (m_configFile.is_open()) {
        tryToReadProperties();
        m_configFile.close();
    }
    else std::cout << "Unable to open file";
}

void FileManager::tryToReadProperties() {

    std::string line;
    while (std::getline(m_configFile, line)) {
        if (line.find("Fieldwidth") != std::string::npos) {
            m_fieldWidth = readInInt(line, "Fieldwidth", 3);
        }
        if (line.find("Fieldheight") != std::string::npos) {
            m_fieldHeight = readInInt(line, "Fieldheight", 3);
        }
    }
}

int FileManager::readInInt(std::string line, const std::string parameter, const int _default) {
    int value;
    std::getline(m_configFile, line);
    try {
        value = std::stoi(line);
    }
    catch (std::invalid_argument) {
        std::cout << "Malformed " << parameter << " parameter, choosing " << _default << " as default";
        value = _default;
    }
    return value;
}

int FileManager::getFieldHeight() {
    return m_fieldHeight;
}

int FileManager::getFieldWidth() {
    return m_fieldWidth;
}
