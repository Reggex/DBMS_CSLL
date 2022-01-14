#pragma once
#include <iostream>

/**
	 * \brief Узел списка.
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
	* \brief Список.
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
	 * \brief Создание списка. Конструктор по умолчанию. 
	 */
	List()
	{
		_head = nullptr;
		_tail = nullptr;
		_size_list = 0;
	}

/**
	 * \brief Получение размера списка.
	 * \return _size_list Размер списка.
	 */
	const size_t GetSizeList()
	{
		return _size_list;
	}

/**
	 * \brief Добавление в конец списка элементов.
	 * \param data Данные узла.
	 */
	void PushBack(const int data);

/**
	 * \brief Удаление узла по входным данным.
	 * \param data Данные узла.
	 */
	void DeleteNodeByData(const int data);

/**
	 * \brief Удаление узла по номеру узла.
	 * \param number Номер узла.
	 */
	void DeleteNodeByNumber(const int number);

/**
	 * \brief Получение узла по входным данным.
	 * \param data Данные узла.
	 * \return node* Узел списка.
	 */
	Node* GetFirstNodeByData(const int data);

/**
	 * \brief Получение узла номеру.
	 * \param number Номер узла.
	 * \return node* Узел списка.
	 */
	Node* GetNodeByPosition(const int number);

/**
	 * \brief Вставка нового узла номеру.
	 * \param data Данные нового узла.
	 * \param number Номер узла.
	 */
	void InsertNodeByNumber(const int data, const int number);

/**
	 * \brief Удаление списка. Деструктор.
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


