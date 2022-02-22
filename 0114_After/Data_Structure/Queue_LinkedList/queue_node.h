#pragma once

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T value;
	Node* next;

	Node() :value(0), next(nullptr) { };
	~Node() {};
};

template <typename T>
class Queue
{
public:
	Queue() : head(nullptr), tail(nullptr), size(0) { }
	~Queue() { };

	void Enqueue(T _value);
	T Dequeue();
	bool empty();

private:
	Node<T>* head;
	Node<T>* tail;
	int size;
};

template<typename T>
void Queue<T>::Enqueue(T _value)
{
	Node<T> *newNode = new Node<T>;
	newNode->value = _value;
	size++;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = tail->next;
	}
}

template<typename T>
T Queue<T>::Dequeue()
{
	size--;

	if (empty())
	{
		return -1;
	}
	else
	{
		Node<T> *ptr = head;
		T value = head->value;

		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
			delete(head);
		}
		else
		{
			ptr = ptr->next;
			delete(head);
			head = ptr;
		}
		return value;
	}
}

template <typename T>
bool Queue<T>::empty()
{
	if (tail == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}


