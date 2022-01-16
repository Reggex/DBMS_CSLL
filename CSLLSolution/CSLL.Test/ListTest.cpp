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

TEST_F(ListTest, DefaultList) //ѕроверка конструктора по умолчанию
{
    EXPECT_TRUE(true);
}

TEST_F(ListTest, PushBack_FillListFromScratch) //«аполение списка с нул€
{
    list->PushBack(1);
    EXPECT_EQ(1, list->GetSizeList());
    EXPECT_EQ(1, list->GetNodeByPosition(0)->GetData());
}

TEST_F(ListTest, PushBack_AddNodes) //«аполнение списка, когда уже есть существующие узлы
{
    list->PushBack(1);
    EXPECT_EQ(1, list->GetSizeList());
    int size = 3;
    for (int data = 2; data <= size; ++data)
    {
        list->PushBack(data);
        EXPECT_EQ(data, list->GetNodeByPosition(data - 1)->GetData());
    }
    EXPECT_EQ(3, list->GetSizeList());
}

TEST_F(ListTest, DeleteFirstNodeByData_DeleteNonexistentData) //”даление узла по несуществующим данным
{
    int size = 2;
    for (int data = 0; data <= size; ++data) 
    {
        list->PushBack(data);
    }
    EXPECT_EQ(3, list->GetSizeList());
    list->DeleteFirstNodeByData(4);
    EXPECT_EQ(3, list->GetSizeList());
}

TEST_F(ListTest, DeleteFirstNodeByData_DeleteExistentData) //”даление узла по существующим данным
{
    int size = 2;
    for (int data = 0; data <= size; ++data)
    {
        list->PushBack(data);
    }
    EXPECT_EQ(3, list->GetSizeList());
    for (int number = 2; number > 0; number--)
    {
        list->DeleteFirstNodeByData(number);
        EXPECT_EQ(number, list->GetSizeList());
    }
}

TEST_F(ListTest, DeleteFirstNodeByData_DeleteRepeatingData) //”даление одного узла, когда данные повтор€ютс€
{
    int size = 2;
    for (int data = 0; data <= size; ++data)
    {
        list->PushBack(data);
    }
    list->PushBack(2);
    EXPECT_EQ(4, list->GetSizeList());
    list->DeleteFirstNodeByData(2);
    EXPECT_EQ(3, list->GetSizeList());
}

TEST_F(ListTest, GetNodeByPosition_GetCorrectData) //Ќахождение узла по позиции
{
    int size = 2;
    for (int data = 0; data <= size; ++data) 
    {
        list->PushBack(data);
        EXPECT_EQ(data, list->GetNodeByPosition(data)->GetData());
    }
}

TEST_F(ListTest, DeleteNodeByPosition_DeleteExistingData) //”даление узла с существующими данными по позиции
{
    int size = 2;
    for (int data = 0; data <= size; ++data) 
    {
        list->PushBack(data);
    }
    EXPECT_EQ(3, list->GetSizeList());
    for (int number = 2; number > 0; number--) 
    {
        list->DeleteNodeByPosition(number);
        EXPECT_EQ(number, list->GetSizeList());
    }
}

TEST_F(ListTest, DeleteNodeByPosition_DeleteNonexistentData) //”даление узла с несуществующими данными по позиции
{
    int size = 2;
    for (int data = 0; data <= size; ++data)
    {
        list->PushBack(data);
    }
    EXPECT_EQ(3, list->GetSizeList());
    list->DeleteNodeByPosition(4);
    EXPECT_EQ(3, list->GetSizeList());
}

TEST_F(ListTest, GetFirstNodeByData_OutputCorrectData) //ѕолучение узла по правильным данным
{
    int size = 2;
    for (int data = 0; data <= size; ++data) {
        list->PushBack(data);
        EXPECT_EQ(data, list->GetFirstNodeByData(data)->GetData());
    }
}

TEST_F(ListTest, GetFirstNodeByData_OutputWrongData) //ѕолучение узла по неправильным данным
{
    int size = 2;
    for (int data = 0; data <= size; ++data) {
        list->PushBack(data);
    }
    EXPECT_EQ(nullptr, list->GetFirstNodeByData(3));
}

TEST_F(ListTest, OutputList_OutputThirdData) //¬ывод списка
{
    int size = 2;
    for (int data = 0; data <= size; ++data) {
        list->PushBack(data);
    }
    std::cout << *list <<std::endl;
}




