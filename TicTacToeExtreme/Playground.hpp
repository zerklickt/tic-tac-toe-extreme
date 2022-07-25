#pragma once
#include <iostream>
#include <vector>

class Playground {
public:
    Playground(const int width, const int height) :
        m_width(width),
        m_height(height) {
        for (int x = 0; x < width; x++) {
            std::vector<char> col;
            for (int y = 0; y < height; y++) {
                col.push_back(' ');
            }
            m_field.push_back(col);
        }
    };
    ~Playground() {};

    Playground& operator=(const Playground& rhs)
    {
        this->m_width = rhs.m_width;
        this->m_height = rhs.m_height;
        this->m_field = rhs.m_field;
    };

    bool placeSymbol(const char symbol, const int rawX, const int rawY);
    std::vector<std::vector<char>> getField() const;
    bool checkForWin(const int x, const int y, const char symbol);
    int countCells(const int x, const int y, const int xdir, const int ydir, const char symbol);
    bool canPlaceChip(const int rawX, const int rawY) const;
    bool isFull() const;

    int getHeight() const;
    int getWidth() const;
private:
    int m_width;
    int m_height;
    std::vector<std::vector<char>> m_field;
};