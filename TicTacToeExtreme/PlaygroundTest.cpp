

#include "pch.hpp"

#include "Playground.hpp"

class PlaygroundTest : public testing::Test {

protected:

    Playground m_playground;

    virtual void SetUp() override
    {
        m_playground = Playground(5, 6);
    }

    void fillField() {
        for (int i = 1; i <= m_playground.getHeight(); i++) {
            for (int j = 1; j <= m_playground.getWidth(); j++) {
                m_playground.placeSymbol(97, j, i);
            }
        }
    }

    bool setSymbol(const char symbol, const int x, const int y) {
        return m_playground.placeSymbol(symbol, x, y);
    }
};

TEST_F(PlaygroundTest, fieldIsFull) {
    fillField();
    EXPECT_EQ(m_playground.isFull(), true);
}

TEST_F(PlaygroundTest, spotIsOccupied) {
    int symbolX = 2;
    int symbolY = 3;
    setSymbol('a', symbolX, symbolY);
    EXPECT_EQ(setSymbol('a', symbolX, symbolY), false);
}

TEST_F(PlaygroundTest, spotIsOutOfBounds) {
    EXPECT_EQ(setSymbol('a', -2, -3), false);
    EXPECT_EQ(setSymbol('a', -2, 3), false);
    EXPECT_EQ(setSymbol('a', 2, -3), false);
    EXPECT_EQ(setSymbol('a', 6, 3), false);
}

TEST_F(PlaygroundTest, winCheck) {
    setSymbol('a', 4, 2);
    setSymbol('a', 2, 2);
    setSymbol('a', 3, 2);
    EXPECT_EQ(m_playground.checkForWin('a', 3, 2), true);
}