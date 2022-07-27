#include "pch.hpp"

#include "SmartBot.hpp"

class SmartBotTest : public testing::Test {

protected:

    SmartBot* m_smartBot;

    virtual void SetUp() override
    {
        m_smartBot = new SmartBot('a');
    }

};