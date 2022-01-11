#include "pch.h"
#include "List.h"


const size_t List::size()
{
	return size_list;
}

void List::PushBack(int data)
{
	Node* new_node = new Node(data);
	if (head != nullptr)
	{
		tail->_next = new_node;
		new_node->_next = head;
		tail = new_node;
	}
	else
	{
		head = tail = new_node;
		new_node->_next = new_node;
	}
	size_list++;
}

void List::DeleteNode(Node* node, Node* prev_node)
{
	prev_node -> _next = node->_next;
	if (node == head) 
	{
		head = node -> _next;
	}
	if (node == tail)
	{
		tail = prev_node;
	}
	delete node;
	size_list--;
}

void List::DeleteBookByData(int data) //надо выполнить проверку на сущестование данных
{
	Node* node = head, * prev_node = tail;
	for (size_t size = 0; size <= size_list; ++size)
	{
		if (node->GetData() == data)
		{
			DeleteNode(node, prev_node);
		}
		node = node->_next;
		prev_node = prev_node->_next;
	}
}

void List::DeleteNodeByNumber(size_t number) //надо выполнить проверку на намбер
{
	int size = 0;
	Node* node = head, * prev_node = tail;
	while (size < number)
	{
		node = node->_next;
		prev_node = prev_node->_next;
	}
	DeleteNode(node, prev_node);
}

List::~List()
{
	while (size() != 0)
	{
		Node* temp = head->_next;
		if (head != nullptr)
		{
			delete head;
			head = nullptr;
		}
		head = temp;
		size_list--;
	}
}

void List::SearchNodeByData(int data)  //надо выполнить проверку на сущестование данных
{
	Node* node = head;
	for (size_t size = 0; size <= size_list; ++size)
	{
		if (node->GetData() == data)
		{
			std::cout << node;
		}
		node = node->_next;
	}
}

void List::SearchNodeByNumber(size_t number) //надо выполнить проверку на намбер
{
	int size = 0;
	Node* node = head;
	while (size < number)
	{
		node = node->_next;
	}
	std::cout << node;
}

void List::InsertNodeByNumber(int data, int number)  //надо выполнить проверку на намбер
{
	int size = 0;
	Node* new_node = new Node(data);
	Node* node = head;
	while (size < number)
	{
		node = node->_next;
	}
	tail->_next = new_node;
	new_node->_next = head;
	tail = new_node;
}
