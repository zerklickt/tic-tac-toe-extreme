#include "pch.hpp"
#include "FileManager.hpp"

class FileManagerTest : public testing::Test {

protected:
	FileManager m_filemanager;

    virtual void SetUp() override
    {
        m_filemanager = FileManager();
    }

    

};

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}


TEST_F(FileManagerTest, correctFileReading) {
    m_filemanager.readFile("../test.txt");
    EXPECT_EQ(m_filemanager.getFieldHeight(), 15);
    EXPECT_EQ(m_filemanager.getFieldWidth(), 12);
    
}