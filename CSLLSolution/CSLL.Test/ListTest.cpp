#include "pch.h"
#include "../CSLL.Library/List.h"


class ListTest : public ::testing::Test
{
protected:
    List* list;

    virtual void SetUp() {
        list = new List();
    }
    void TearDown() 
    {   
        delete list;
    }
};

TEST_F(ListTest, DefaultList) 
{
    EXPECT_TRUE(true);
}

TEST_F(ListTest, MethodPushBack)
{
    list->PushBack(1);
    EXPECT_EQ(1, list->GetSizeList());
    EXPECT_EQ(1, list->GetNodeByPosition(0)->GetData());
    int size = 3;
    for (int data = 2; data <= size; ++data) 
    {
        list->PushBack(data);
        EXPECT_EQ(data, list->GetNodeByPosition(data-1)->GetData());
    }
    EXPECT_EQ(3, list->GetSizeList());
}

TEST_F(ListTest, MethodDeleteNodeByData)
{
    int size = 2;
    for (int data = 0; data <= size; ++data) 
    {
        list->PushBack(data);
    }
    EXPECT_EQ(3, list->GetSizeList());
    list->DeleteNodeByData(4);
    EXPECT_EQ(3, list->GetSizeList());
    for (int number = 2; number >0; number--) 
    {
        list->DeleteNodeByData(number);
        EXPECT_EQ(number, list->GetSizeList());
    }
}

TEST_F(ListTest, MethodGetNodeByPosition)
{
    int size = 2;
    for (int data = 0; data <= size; ++data) 
    {
        list->PushBack(data);
        EXPECT_EQ(data, list->GetNodeByPosition(data)->GetData());
    }
}

TEST_F(ListTest, MethodDeleteNodeByNumber)
{
    int size = 2;
    for (int data = 0; data <= size; ++data) 
    {
        list->PushBack(data);
    }
    EXPECT_EQ(3, list->GetSizeList());
    list->DeleteNodeByNumber(4);
    EXPECT_EQ(3, list->GetSizeList());
    for (int number = 2; number > 0; number--) 
    {
        list->DeleteNodeByNumber(number);
        EXPECT_EQ(number, list->GetSizeList());
    }
}

TEST_F(ListTest, MethodGetFirstNodeByData)
{
    int size = 2;
    for (int data = 0; data <= size; ++data) {
        list->PushBack(data);
        EXPECT_EQ(data, list->GetFirstNodeByData(data)->GetData());
    }
    EXPECT_EQ(nullptr, list->GetFirstNodeByData(3));
}




