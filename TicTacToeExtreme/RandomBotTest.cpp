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