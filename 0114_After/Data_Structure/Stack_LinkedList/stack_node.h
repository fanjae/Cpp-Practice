#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T value;
	Node<T> *next = nullptr;
	Node() {};
	~Node() {};
};

template <typename T>
class Stack
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	Stack() :head(nullptr), tail(nullptr) { }
	~Stack() { }
	void Push(T value);
	T Pop();
	bool isEmpty();
	T Top();
};


template <typename T>
bool Stack<T>::isEmpty()
{
	return tail == nullptr ? true : false;
}

template <typename T>
T Stack<T>::Top()
{
	return tail->value;
}

template<typename T>
void Stack<T>::Push(T _value)
{
	Node<T> *node = new Node<T>;
	node->value = _value;

	if (head == nullptr)
	{
		head = node;
		tail = node;
	}
	else
	{
		tail->next = node;
		tail = tail->next;
	}
}

template<typename T>
T Stack<T>::Pop()
{
	if (isEmpty()) // Stack Empty
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
		else // Data가 하나가 아니면
		{
			while (ptr != nullptr)
			{
				// 꼬리(top)값 삭제 후 새 꼬리 대입
				if (ptr->next == tail)
				{
					value = tail->value;
					ptr->next = nullptr;
					delete(tail);
					tail = ptr;
					break;
				}
				ptr = ptr->next;
			}
			return value;
		}

		return value;
	}
}


