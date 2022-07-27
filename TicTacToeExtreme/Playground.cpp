#include "pch.hpp"
#include "Playground.hpp"

//places symbol at the specified coordinates
bool Playground::placeSymbol(const char symbol, const int rawX, const int rawY) {
    //Convert to Array value
    int x = rawX - 1;
    int y = rawY - 1;
    //Check if out of bounds
    if (x >= m_width || x < 0 || y >= m_height || y < 0)
        return false;
    //Set symbol in field
    if (m_field[x][y] == ' ') {
        m_field[x][y] = symbol;
        return true;
    }
    else
        return false;
}

std::vector<std::vector<char>> Playground::getField() const {
    return m_field;
}

int Playground::getHeight() const {
    return m_height;
}

int Playground::getWidth() const {
    return m_width;
}

//checks if player with passed symbol has won
bool Playground::checkForWin(const int x, const int y, const char symbol) {
    return countCells(x - 1, y, -1, 0, symbol) + countCells(x + 1, y, 1, 0, symbol) >= 2 ||
        countCells(x, y - 1, 0, -1, symbol) + countCells(x, y + 1, 0, 1, symbol) >= 2 ||
        countCells(x - 1, y - 1, -1, -1, symbol) + countCells(x + 1, y + 1, 1, 1, symbol) >= 2 ||
        countCells(x - 1, y + 1, -1, 1, symbol) + countCells(x + 1, y - 1, 1, -1, symbol) >= 2;
}

int Playground::countCells(const int x, const int y, const int xdir, const int ydir, const char symbol) {
    if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
        if (m_field[x][y] == symbol) {
            return countCells(x + xdir, y + ydir, xdir, ydir, symbol) + 1;
        }
    }
    return 0;
}

bool Playground::canPlaceChip(const int rawX, const int rawY) const {
    //Convert to Array value
    int x = rawX - 1;
    int y = rawY - 1;
    //Check if out of bounds
    if (x >= m_width || x < 0 || y >= m_height || y < 0)
        return false;
    //Set symbol in field
    if (m_field[x][y] == ' ')
        return true;
    else
        return false;
}

//checks if all fields are occupied
bool Playground::isFull() const {
    for (int x = 1; x <= m_width; x++) {
        for (int y = m_height - 1; y >= 0; y--) {
            if (m_field.at(x).at(y) == ' ')
                return false;
        }
    }
    return true;
}