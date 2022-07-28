#include "pch.hpp"

#include "InputManager.hpp"

class InputManagerTest : public testing::Test {

protected:

    InputManager* m_inputManager;

    virtual void SetUp() override
    {
        m_inputManager = new InputManager();
    }

};