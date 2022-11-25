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

	Node(const Node&) = delete;
	Node& operator= (const Node&) = delete;
	Node (Node&&) = delete;
	Node& operator= (Node&&) = delete;

	/**
		* \brief �������� ������. ����������� � ����������.
		* \param data ������ ����.
		*/
	Node(int data)
	{
		_data = data;
		_next = nullptr;
	}

	/**
		* \brief ��������� ������ ����.
		* \return _data ������ ����.
		*/
	int GetData()
	{
		return _data;
	}

	friend std::ostream& operator<< (std::ostream& out, const Node& node);

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

	/**
		* \brief ��������� ������ ����.
		* \param node ����, ������� ���������� �������.
		* \param prev_node ���������� ����� ��������� ����� ����.
		*/
	void DeleteNode(Node* node, Node* prev_node);

public:

	List(const List&) = delete;
	List& operator= (const List&) = delete;
	List(List&&) = delete;
	List& operator= (List&&) = delete;

	/**
		 * \brief �������� ������. ����������� �� ���������.
		 */
	List() : _head(nullptr), _tail(nullptr), _size_list(0) {};


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
	void PushBack(const int data);

	/**
		 * \brief �������� ���� �� ������� ������.
		 * \param data ������ ����.
		 */
	void DeleteFirstNodeByData(const int data);

	/**
		 * \brief �������� ���� �� ������ ����.
		 * \param number ����� ����.
		 */
	void DeleteNodeByPosition(const int number);

	/**
		 * \brief ��������� ���� �� ������� ������.
		 * \param data ������ ����.
		 * \return node* ���� ������.
		 */
	Node* GetFirstNodeByData(const int data);

	/**
		 * \brief ��������� ���� ������.
		 * \param number ����� ����.
		 * \return node* ���� ������.
		 */
	Node* GetNodeByPosition(const int number);

	/**
		 * \brief �������� ������. ����������.
		 */
	~List();

	friend std::ostream& operator<< (std::ostream& out, const List& list);
};