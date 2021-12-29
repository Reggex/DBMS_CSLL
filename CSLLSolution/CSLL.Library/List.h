#pragma once

#include <iostream>
#include <vector>

using namespace std;


class Node
{
	int data_item;
	Node* next_item;
	friend class List;

public:
	Node(int data_item, Node* next_item)
	{
		this->next_item = next_item;
		this->data_item = data_item;
	}
};


class List
{
	Node* head;
	Node* tail;
	size_t size_list;

	const vector<int> getList();

	friend ostream& operator<< (ostream& shift, List& point_list);
public:

	List() :head(nullptr), tail(nullptr), size_list(0) {};

	const size_t size();

	void addItem(const int data_item);

	void changeNumberItem(const size_t number_item, const int selected_data_item);

	void deleteItem(const size_t number_item);

	~List();
};

