#include "pch.hpp"

#include "Playground.hpp"

class PlaygroundTest : public testing::Test {

protected:

    Playground m_playground;

    virtual void SetUp() override
    {
        m_playground = Playground(3,4);
    }

    void fillField() {
        for (int i = 1; i <= m_playground.getHeight(); i++) {
            for (int j = 1; j <= m_playground.getWidth(); j++) {
                m_playground.placeSymbol(97, j, i);
            }
        }
    }
};

TEST_F(PlaygroundTest, placeSymbolTest) {
    EXPECT_EQ(m_playground.placeSymbol('a', 2, 2), true);
    EXPECT_EQ(m_playground.getField()[1][1] == 'a', true);
}


TEST_F(PlaygroundTest, fieldIsFull) {
    fillField();
    EXPECT_EQ(m_playground.isFull(), true);
}

TEST_F(PlaygroundTest, spotIsOccupied) {
    int symbolX = 2;
    int symbolY = 3;
    m_playground.placeSymbol('a', symbolX, symbolY);
    EXPECT_EQ(m_playground.placeSymbol('a', symbolX, symbolY), false);
}

TEST_F(PlaygroundTest, spotIsOutOfBounds) {
    EXPECT_EQ(m_playground.placeSymbol('a', -2, -3), false);
    EXPECT_EQ(m_playground.placeSymbol('a', -2, 3), false);
    EXPECT_EQ(m_playground.placeSymbol('a', 2, -3), false);
    EXPECT_EQ(m_playground.placeSymbol('a', 6, 3), false);
}

TEST_F(PlaygroundTest, winCheck) {
    m_playground.placeSymbol('a', 3, 2);
    m_playground.placeSymbol('a', 3, 1);
    m_playground.placeSymbol('a', 3, 3);
    EXPECT_EQ(m_playground.checkForWin('a', 3, 2), true);
}

