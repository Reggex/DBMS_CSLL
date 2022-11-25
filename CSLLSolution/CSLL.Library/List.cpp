#include "pch.h"
#include "List.h"

void List::PushBack(const int data)
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

void List::DeleteFirstNodeByData(const int data)
{
	int count = 0;
	Node* node = _head, * prev_node = _tail;
	for (size_t temp = 0; temp < this->GetSizeList() && count == 0; ++temp)
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

void List::DeleteNodeByPosition(int position)
{
	if (position < this->GetSizeList())
	{
		int temp = 0;
		Node* node = _head, * prev_node = _tail;
		while (temp < position)
		{
			node = node->_next;
			prev_node = prev_node->_next;
			temp++;
		}
		this->DeleteNode(node, prev_node);
	}
	else
	{
		std::cout << "Error delete method: nodes with number \"" << position << "\" not found" << std::endl;
	}

}

Node* List::GetFirstNodeByData(const int data)
{
	Node* node = _head;
	for (size_t temp = 0; temp < this->GetSizeList(); ++temp)
	{
		if (node->GetData() == data)
		{
			return node;
		}
		node = node->_next;
	}
	return nullptr;
}

Node* List::GetNodeByPosition(const int position)
{
	if (position < this->GetSizeList())
	{
		int temp = 0;
		Node* node = _head;
		while (temp < position)
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

List::~List()
{
	while (GetSizeList() != 0)
	{
		Node* temp = _head->_next;
		if (_head != nullptr)
		{
			delete _head;
			_head = nullptr;
		}
		_head = temp;
		_size_list--;
	}
}

std::ostream& operator<< (std::ostream& out, const List& list)
{
	Node* node = list._head;
	for (size_t temp = 0; temp < list._size_list; ++temp)
	{
		out << *node << " ";
		node = node->_next;
	}
	return out;
}

std::ostream& operator<< (std::ostream& out, const Node& node)
{
	out << node._data; 
	return out;
}
