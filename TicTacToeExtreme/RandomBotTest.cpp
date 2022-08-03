#include "pch.hpp"

#include "RandomBot.hpp"

class RandomBotTest : public testing::Test {

protected:

    RandomBot* m_randomBot;

    virtual void SetUp() override
    {
        m_randomBot = new RandomBot('b');
    }

};

TEST_F(RandomBotTest, randomMovesInbound) {
    bool success = true;
    int runs = 1000;
    for (int i = 0; i < runs; i++) {
        Playground playground(3, 3);
        std::pair<int, int> returnValue = m_randomBot->makeMove("Lorem ipsum", playground);
        if (returnValue.first < 1 || returnValue.first > playground.getWidth() || returnValue.second < 1 || returnValue.second > playground.getHeight()) {
            success = false;
        }
    }
    EXPECT_EQ(success, true);
}