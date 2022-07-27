#include "pch.hpp"

#include "InputManager.hpp"

class PlaygroundTest : public testing::Test {

protected:

    InputManager* m_inputManager;

    virtual void SetUp() override
    {
        m_inputManager = new InputManager();
    }

};