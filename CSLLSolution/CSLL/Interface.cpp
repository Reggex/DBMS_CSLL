#pragma once
#include "Interface.h"

using namespace std;

int GetSizeListByUser() 
{
	int size;
	cout << "Input size" << endl;
	cin >> size;
	while (size <= 0) 
	{
		cout << "Uncorrect size. Try again" << endl;
		cin >> size;
	}
	return size;
}

void FillList(List *circular_single_list, int size)
{
	int data;
	cout << "Input data" << endl;
	for (int temp = 0; temp<size; ++temp)
	{
		cin >> data;
		circular_single_list->PushBack(data);
	}
}

void DeleteByNumber(List* circular_single_list)
{
	int number;
	cout << "Input number, which element you want to remove" << endl;
	cin >> number;
	circular_single_list->DeleteNodeByNumber(number);
}

void DeleteByData(List* circular_single_list)
{
	int data;
	cout << "Input data, which element you want to remove" << endl;
	cin >> data;
	circular_single_list->DeleteNodeByNumber(data);
}

void SearchByNumber(List * circular_single_list)
{
	int number;
	cout << "Input number, which element you want to receive" << endl;
	cin >> number;
	circular_single_list->DeleteNodeByNumber(number);
}

void SearchByData(List* circular_single_list)
{
	int data;
	cout << "Input data, which element you want to receive" << endl;
	cin >> data;
	circular_single_list->DeleteNodeByNumber(data);
}

void InserrtNode();

void DeleteList();
