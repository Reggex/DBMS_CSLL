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

void DeleteNode();

void SearchNode();

void InserrtNode();

void DeleteList();
