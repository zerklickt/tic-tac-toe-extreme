

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
        for (int i = 0; i < m_playground.getHeight(); i++) {
            for (int j = 0; j < m_playground.getWidth(); i++) {
                m_playground.placeSymbol(97, i, j);
            }
        }
    }


};

TEST(TestCaseName2, TestName2) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}


/*
TEST_F(PlaygroundTest, fieldIsFull) {
    fillField();
    EXPECT_EQ(m_playground.isFull(), true);
}
*/
