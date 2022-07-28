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

    Playground() :
        m_width(3),
        m_height(3) {
        for (int x = 0; x < m_width; x++) {
            std::vector<char> col;
            for (int y = 0; y < m_height; y++) {
                col.push_back(' ');
            }
            m_field.push_back(col);
        }
    };
    ~Playground() {};

    bool placeSymbol(const char symbol, const int rawX, const int rawY);
    std::vector<std::vector<char>> getField() const;
    bool checkForWin(const char symbol, const int rawX, const int rawY) const;
    int countCells(const int x, const int y, const int xdir, const int ydir, const char symbol) const;
    bool canPlaceChip(const int rawX, const int rawY) const;
    bool isFull() const;

    int getHeight() const;
    int getWidth() const;
private:
    int m_width;
    int m_height;
    std::vector<std::vector<char>> m_field;
};