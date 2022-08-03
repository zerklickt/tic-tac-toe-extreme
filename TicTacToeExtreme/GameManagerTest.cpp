#include "pch.hpp"

#include "GameManager.hpp"


class GameManagerTest : public testing::Test {

protected:

    GameManager m_gamemanager;

    virtual void SetUp() override
    {
        m_gamemanager = GameManager();
    }

};


