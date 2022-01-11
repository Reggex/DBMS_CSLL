#pragma once
#include <iostream>

class Node
{
private:
	int _data;
public:
	Node* _next;

	Node()
	{
		_data = NULL;
		_next = nullptr;
	}

	Node(int data)
	{
		_data = data;
		_next = nullptr;
	}
	int GetData()
	{
		return _data;
	}

};

class List
{
private:
	Node* head;
	Node* tail;
	size_t size_list;

	void DeleteNode(Node* node, Node* prev_node);

public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	const size_t size();

	void PushBack(int data);

	void DeleteBookByData(int data);

	void DeleteNodeByNumber(size_t number);

	void SearchNodeByData(int data);

	void SearchNodeByNumber(size_t number);

	void InsertNodeByNumber(int data, int number);

	~List();

};


