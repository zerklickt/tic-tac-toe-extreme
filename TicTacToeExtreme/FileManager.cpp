#include <iostream>
#include <fstream>
#include <string>

#include "pch.hpp"
#include "FileManager.hpp"


void FileManager::readFile(const std::string path){

    std::string line;
    
	
	std::ifstream myfile(path, std::ios::in);
    if (!myfile) {
        std::cout << "Error: file could not be opened" << std::endl;
        exit(1);
    }
    if (myfile.is_open())
    {
        while(std::getline(myfile, line))
        {
            
            if (line.find("Fieldwidth") != std::string::npos) {
                std::getline(myfile, line);
                m_fieldWidth = std::stoi(line);
            }
            
            if (line.find("Fieldheight") != std::string::npos) {
                std::getline(myfile, line);
                m_fieldHeight = std::stoi(line);
            }

        }
        myfile.close();
    }

    else std::cout << "Unable to open file";
	
}

int FileManager::getFieldHeight(){

    return m_fieldHeight;
}

int FileManager::getFieldWidth()
{
    return m_fieldWidth;
}
