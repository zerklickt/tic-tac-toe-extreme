#include "pch.hpp"

#include "Human.hpp"

class HumanTest : public testing::Test {

protected:

    Human* m_human;

    virtual void SetUp() override
    {
        m_human = new Human("Testhuman", 'a');
    }

};