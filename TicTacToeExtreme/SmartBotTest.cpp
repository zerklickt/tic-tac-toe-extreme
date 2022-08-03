#include "pch.hpp"

#include "SmartBot.hpp"
#include "RandomBot.hpp"
#include "Playground.hpp"

class SmartBotTest : public testing::Test {

protected:

    SmartBot* m_smartBot;

    virtual void SetUp() override{
        m_smartBot = new SmartBot('a');
        
    }

    void setlastPlaced(int x, int y) {
        m_smartBot->m_lastX = x;
        m_smartBot->m_lastY = y;
    }
    
    //gameLoop adjusted for a SmartBot vs. RandomBot - Match 
    Player* gameLoop(Player* player1, Player* player2, Playground& playground){    
        int counter = 0;
        bool won = false;
        Player* turn = player1;
        
        do
        {
            if (counter % 2 == 0){
                turn = player1;
            }
            else{
                turn = player2;
            }
            std::pair<int, int> position = turn->makeMove("Your turn, " + turn->getName(), playground);
            bool success = playground.placeSymbol(turn->getSymbol(), position.first, position.second);
            if (!success){
                continue;
            }
            won = playground.checkForWin(turn->getSymbol(), position.first, position.second);
            if (won) {
                break;
            }
            counter++;
        } while (!won && !playground.isFull());
        if (won) {
            return turn;
        }
        else {
            return NULL;
        } 
    }
};

//The smartBot should win, if it has a pair (|x|x| |)
TEST_F(SmartBotTest, winWithPair) {
    Playground playground(3, 3);
    playground.placeSymbol('a', 1, 1);
    playground.placeSymbol('a', 1, 2);
    setlastPlaced(1, 2);
    std::pair<int, int> returnedPair = m_smartBot->makeMove("Test", playground);
    EXPECT_EQ(returnedPair.first, 1);
    EXPECT_EQ(returnedPair.second, 3); 
}

//The smartBot should win, if it has a split (|x| |x|)
TEST_F(SmartBotTest, winWithSplit) {
    Playground playground(3, 3);
    playground.placeSymbol('a', 1, 1);
    playground.placeSymbol('a', 1, 3);
    setlastPlaced(1, 3);
    std::pair<int, int> returnedPair = m_smartBot->makeMove("Test", playground);
    EXPECT_EQ(returnedPair.first, 1);
    EXPECT_EQ(returnedPair.second, 2);
}

//The smartBot should be able to prevent his opponent from winning with a pair
TEST_F(SmartBotTest, preventWinByPair) {
    Playground playground(3, 3);
    playground.placeSymbol('b', 1, 1);
    playground.placeSymbol('b', 2, 2);
    setlastPlaced(3, 3);
    std::pair<int, int> returnedPair = m_smartBot->makeMove("Test", playground);
    EXPECT_EQ(returnedPair.first, 3);
    EXPECT_EQ(returnedPair.second, 3);
}

//The smartBot should be able to prevent his opponent from winning wit a split
TEST_F(SmartBotTest, preventWinBYSplit) {
    Playground playground(3, 3);
    playground.placeSymbol('b', 1, 1);
    playground.placeSymbol('b', 2, 2);
    setlastPlaced(3, 3);
    std::pair<int, int> returnedPair = m_smartBot->makeMove("Test", playground);
    EXPECT_EQ(returnedPair.first, 3);
    EXPECT_EQ(returnedPair.second, 3);
}

//The smartBot should win more than 75% of the games against a randomBot 
TEST_F(SmartBotTest, smartBotVsRandomBot) {
    RandomBot* randomBot =  new RandomBot('b');
    int smartBotWins = 0;
    int randomBotWins = 0;
    int runs = 100;
    for (int i = 0; i < runs; i++) {
        Playground playground(4, 4);
        Player* winner = gameLoop(m_smartBot, randomBot, playground);
        if (winner == NULL){
            i--;
            continue;
        }
        if (winner == m_smartBot) {
            smartBotWins++;
        }
        else {
            randomBot++;
        }
        setlastPlaced(0, 0);
    }
    
    EXPECT_EQ((smartBotWins > 0.75 * runs), true);
    EXPECT_EQ((randomBotWins < 0.25 * runs), true);
}

