#include "pch.h"
#include "List.h"

const size_t List::size()
{
	return size_list;
}

const vector<int> List::getList()
{
	Node* selected_head = head;
	vector<int> list;
	for (size_t count = 0; count < this->size(); count++) {
		list.push_back(selected_head->data_item);
		selected_head = selected_head->next_item;
	}
	return list;
}

void List::addItem(const int data_item)
{
	Node* temp = new Node(data_item, head);
	if (head != nullptr)
	{
		tail->next_item = temp;
		tail = temp;
	}
	else
	{
		head = tail = temp;
	}
	size_list++;
}

void List::changeNumberItem(const size_t number_selected_item, const int selected_data_item)
{
	Node* selected_head = head;
	size_t number = number_selected_item;
	const size_t first_item = 1;
	while (number != first_item)
	{
		selected_head = selected_head->next_item;
		number--;
	}
	selected_head->data_item = selected_data_item;
}

void List::deleteItem(const size_t number_item)
{
	
}

ostream& operator<< (ostream& shift, List& point)
{
	vector<int> list = point.getList();
	for (vector<int>::iterator it = list.begin(); it != list.end(); it++)
		shift << *it << " ";
	return shift;
}

List::~List()
{
	while (this->size() != 0)
	{
		Node* temp = head->next_item;
		if (head != nullptr)
		{
			delete head;
			head = nullptr;
		}
		head = temp;
		size_list--;
	}
}