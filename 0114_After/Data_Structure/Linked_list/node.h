#include <iostream>
using namespace std;

template <typename T>
struct Node // Node Struct
{
public:
	T value;
	struct Node<T> *next = nullptr;
};

template <typename T>
class List
{
private:
	Node<T> *head;
	Node<T> *tail;
	int size = 0;
public:
	List() : head(nullptr), tail(nullptr) { } // Constructor List
	~List() { } // Destructor List

	void AddNode(T _value);
	void RemoveNode(T _value);
	void Show();
	void DeleteList();
	void RemoveTail();
	void RemoveHead();
	void AddHead(T _value);
	void AddPosition(int _indeex, T _value);
	void SearchValue(T _value);
	int Size();
};
