#include "pch.h"
#include "List.h"

void List::PushBack(int data)
{
	Node* new_node = new Node(data);
	if (_head != nullptr)
	{
		_tail->_next = new_node;
		new_node->_next = _head;
		_tail = new_node;
	}
	else
	{
		_head = _tail = new_node;
		new_node->_next = new_node;
	}
	_size_list++;
}

void List::DeleteNode(Node* node, Node* prev_node)
{
	prev_node -> _next = node->_next;
	if (node == _head)
	{
		_head = node -> _next;
	}
	if (node == _tail)
	{
		_tail = prev_node;
	}
	delete node;
	_size_list--;
}

void List::DeleteNodeByData(int data) 
{
	int count = 0;
	Node* node = _head, * prev_node = _tail;
	for (size_t temp = 0; temp <= this->GetSizeList(); ++temp)
	{
		if (node->GetData() == data)
		{
			this->DeleteNode(node, prev_node);
			count++;
		}
		node = node->_next;
		prev_node = prev_node->_next;
	}
	if (count == 0)
	{
		std::cout << "Error delete method: nodes with data \"" << data << "\" not found" << std::endl;
	}
}

void List::DeleteNodeByNumber(int number) 
{
	if (number <= this->GetSizeList())
	{
		int temp = 0;
		Node* node = _head, * prev_node = _tail;
		while (temp < number)
		{
			node = node->_next;
			prev_node = prev_node->_next;
			temp++;
		}
		this->DeleteNode(node, prev_node);
	}
	else
	{
		std::cout << "Error delete method: nodes with number \"" << number << "\" not found" << std::endl;
	}

}


Node* List::GetFirstNodeByData(int data) 
{
	Node* node = _head;
	for (size_t temp = 0; temp <= this->GetSizeList(); ++temp)
	{
		if (node->GetData() == data)
		{
			return node;
		}
		node = node->_next;
	}
	return nullptr;
}

Node* List::GetNodeByPosition(int number) 
{
	if (number <= this->GetSizeList())
	{
		int temp = 0;
		Node* node = _head;
		while (temp < number)
		{
			node = node->_next;
			temp++;
		}
		return node;
	}
	else 
	{
		return nullptr;
	}
}

void List::InsertNodeByNumber(int data, int number)  
{
	int temp = 1;
	if (number > this->GetSizeList())
	{
		this->PushBack(data);
		return;
	}
	Node* new_node = new Node(data);
	Node* prev_node = _tail;
	Node* next_node = _head;
	while (temp < number)
	{
		prev_node = prev_node->_next;
		next_node = next_node->_next;
		temp++;
	}
	prev_node->_next = new_node;
	new_node->_next = next_node;
	_size_list++;
}

