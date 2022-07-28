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

TEST_F(InputManagerTest, inputTypeMismatch) {
    //EXPECT_THROW(m_inputManager->readIntFromRange(1, 10), std::invalid_argument);
}