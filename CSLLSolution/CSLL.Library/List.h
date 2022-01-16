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

	Node(const Node&) = delete;
	Node& operator= (const Node&) = delete;
	Node (Node&&) = delete;
	Node& operator= (Node&&) = delete;

	/**
		* \brief Создание списка. Конструктор с параметром.
		* \param data Данные узла.
		*/
	Node(int data)
	{
		_data = data;
		_next = nullptr;
	}

	/**
		* \brief Получение данных узла.
		* \return _data Данные узла.
		*/
	int GetData()
	{
		return _data;
	}

	friend std::ostream& operator<< (std::ostream& out, const Node& node);

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

	/**
		* \brief Получение данных узла.
		* \param node Узел, который необходимо удалить.
		* \param prev_node Предыдущий перед удаляемым узлом узел.
		*/
	void DeleteNode(Node* node, Node* prev_node);

public:

	List(const List&) = delete;
	List& operator= (const List&) = delete;
	List(List&&) = delete;
	List& operator= (List&&) = delete;

	/**
		 * \brief Создание списка. Конструктор по умолчанию.
		 */
	List() : _head(nullptr), _tail(nullptr), _size_list(0) {};


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
	void DeleteFirstNodeByData(const int data);

	/**
		 * \brief Удаление узла по номеру узла.
		 * \param number Номер узла.
		 */
	void DeleteNodeByPosition(const int number);

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
		 * \brief Удаление списка. Деструктор.
		 */
	~List();

	friend std::ostream& operator<< (std::ostream& out, const List& list);
};