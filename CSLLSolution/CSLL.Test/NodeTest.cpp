
#include "pch.h"
#include "../CSLL.Library/List.h"


class NodeTest : public ::testing::Test
{
protected:
    void SetUp() 
    {
        
    }
    void TearDown() 
    {

    }
};

TEST(NodeTest, CreationNodeWithData) //Создание узла
{
    Node* node = new Node(1);
    EXPECT_NE(nullptr, node);
    EXPECT_EQ(1, node->GetData());
    delete node;
}

TEST(NodeTest, Output) //Вывод узла
{
    Node node(1);
    std::cout << node << std::endl;
}