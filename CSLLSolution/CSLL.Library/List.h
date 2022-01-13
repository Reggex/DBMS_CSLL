#pragma once
#include <iostream>

/**
	 * \brief ���� ������.
	 */
class Node
{
private:
	int _data;
	Node();
public:
	Node* _next;

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

/**
	* \brief ������.
	*/
class List
{
private:
	Node* _head; 
	Node* _tail;
	size_t _size_list;

	void DeleteNode(Node* node, Node* prev_node);

public:
/**
	 * \brief �������� ������. ����������� �� ���������. 
	 */
	List()
	{
		_head = nullptr;
		_tail = nullptr;
		_size_list = 0;
	}

/**
	 * \brief ��������� ������� ������.
	 * \return _size_list ������ ������.
	 */
	const size_t GetSizeList()
	{
		return _size_list;
	}

/**
	 * \brief ���������� � ����� ������ ���������.
	 * \param data ������ ����.
	 */
	void PushBack(int data);

/**
	 * \brief �������� ���� �� ������� ������.
	 * \param data ������ ����.
	 */
	void DeleteNodeByData(int data);

/**
	 * \brief �������� ���� �� ������ ����.
	 * \param number ����� ����.
	 */
	void DeleteNodeByNumber(int number);

/**
	 * \brief ��������� ���� �� ������� ������.
	 * \param data ������ ����.
	 * \return node* ���� ������.
	 */
	Node* GetFirstNodeByData(int data);

/**
	 * \brief ��������� ���� ������.
	 * \param number ����� ����.
	 * \return node* ���� ������.
	 */
	Node* GetNodeByPosition(int number);

/**
	 * \brief ������� ������ ���� ������.
	 * \param data ������ ������ ����.
	 * \param number ����� ����.
	 */
	void InsertNodeByNumber(int data, int number);

/**
	 * \brief �������� ������. ����������.
	 */
	~List()
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

};


