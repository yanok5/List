#pragma once

#include <iostream>

template <class T>
struct Node
{
	Node *next;
	T data;
	Node(T data = T(), Node *next = NULL)
	{
		this->data = data;
		this->next = next;
	}
};

template <class T>
class List
{
private:
	Node<T> *first;
	int size;
public:
	List()
	{
		first = NULL;
		size = 0;
	}

	~List()
	{
		while (size)
			pop_front();
	}

	int get_size() { return size; }

	void push_back(T data)
	{
		if (first == NULL)
			first = new Node<T>(data);
		else
		{
			Node<T> *curr = this->first;
			while (curr->next)
				curr = curr->next;
			curr->next = new Node<T>(data);
		}
		size++;
	}

	void pop_back()	{ erase(size - 1); }

	void push_front(T data)
	{
		first = new Node<T>(data, first);
		size++;
	}

	void pop_front()
	{
		Node<T> *temp = first;
		first = first->next;
		delete temp;
		size--;
	}

	void insert(T data, int index)
	{
		if (index == 0)
			push_front(data);
		else
		{
			Node<T> *prev = this->first;
			for (int i = 0; i < index - 1; i++)
				prev = prev->next;
			prev->next = new Node<T>(data, prev->next);
			size++;
		}
	}

	void insert(Node<T>* place, T data)
	{
		auto n_node = new Node<T>(data, place->next);
		place->next = n_node;
	}

	void erase(Node<T>* place)
	{
		auto temp = place->next->next;
		delete place->next;
		place->next = temp;
	}


	void erase(int index)
	{
		if (index == 0)
			pop_front();
		else
		{
			Node<T> *prev = this->first;
			for (int i = 0; i < index - 1; i++)
				prev = prev->next;
			Node<T> *temp = prev->next;
			prev->next = temp->next;
			delete temp;
			size--;
		}
	}

	int empty() const
	{
		if (size)
			return false;
		return true;
	}

	T& operator[] (const int index)
	{
		int c = 0;
		Node<T> *curr = this->first;
		while (curr)
		{
			if (c == index)
				return curr->data;
			curr = curr->next;
			c++;
		}
	}

	Node<T>* search(const int index)
	{
		int c = 0;
		Node<T> *curr = this->first;
		while (curr)
		{
			if (c == index - 1)
				return curr;
			curr = curr->next;
			c++;
		}
	}
};
