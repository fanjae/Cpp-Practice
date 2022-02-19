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

	void AddNode(T _value)
	{
		Node<T> *node = new Node<T>;

		node->value = _value;
		node->next = nullptr;

		if (head == nullptr) // head가 없는 경우
		{
			head = node;
			tail = node;
		}
		else // head가 있는 경우 뒤에 연결함.
		{
			tail->next = node;
			tail = tail->next;
		}
	}
	void RemoveNode(T _value)
	{
		Node<T> *ptr = head;
		Node<T> *tmp = ptr;

		while (ptr != nullptr)
		{
			if (ptr->value == _value) // 값을 찾은 경우
			{
				break;
			}
			else
			{
				tmp = ptr;	// 목표의 전 노드
				ptr = ptr->next;
			}
		}
		if (ptr == nullptr)
		{
			cout << "찾을 수 없는 노드입니다." << endl;
		}
		else
		{
			size--;
			cout << "삭제된 노드의 값 : " << ptr->value << endl;
			tmp->next = ptr->next; // 삭제할 노드를 제외한 이후에 연결한다.
			delete ptr;		       // 동적 할당 해제
		}
	}

	void Show() // 리스트 안에 값 보여주기
	{
		Node<T> *node = head;

		while (node != nullptr) //  노드값이 Null인 경우
		{
			cout << node->value << "->";
			node = node->next;
		}
		cout << endl;
	}
	void DeleteList() // 리스트 삭제하기 (동적할당 풀기)
	{
		Node<T> *ptr = head;

		while (ptr != nullptr)
		{
			head = ptr->next;
			delete ptr;
			ptr = head;
		}
		delete head; // null 포인터 삭제
		size = 0;
		cout << "리스트가 삭제 되었습니다." << endl;
	}
	void RemoveTail() // 꼬리(back) 삭제하기
	{
		Node<T> *ptr = head;
		Node<T> *tmp = new Node<T>;

		while (ptr->next != nullptr)
		{
			tmp = ptr;
			ptr = ptr->next;
		}
		size--;
		tail = tmp;
		tail->next = nullptr;
		delete ptr; // 꼬리 동적할당 해제
	}
	void RemoveHead() // 헤드(front) 삭제하기
	{
		Node<T> *ptr = head;
		head = ptr->next;
		size--;
		delete ptr;
	}
	void AddHead(T _value) // 헤드(front)에 값 넣기
	{
		Node <T> *ptr = new Node<T>;

		size++;
		ptr->next = head;
		ptr->value = _value;
		head = ptr;
	}
	void AddPosition(int _index, T _value)
	{
		if (size < _index || _index > 0) // 인덱스가 잘못될 경우
		{
			cout << "해당하는 인덱스 값은 없습니다." << endl;
			return;
		}

		Node <T> *ptr = head;
		Node <T> *tmp = ptr;
		Node <T> *node = new Node<T>; // 새로 추가된 노드

		node->value = _value;
		node->next = nullptr;

		for (int i = 0; i < _index - 1; i++)
		{
			tmp = ptr; // 들어갈 노드의 전 위치
			ptr = ptr->next; // 들어갈 노드의 위치
		}
		tmp->next = node;
		node->next = ptr; // 새 노드는 기존에 있는 노드 위치를 가리킴.
		size++;
	}
	void SearchValue(T _value)
	{
		Node<T> *ptr = head;
		int index = 0;
		bool isFind = false;

		while (ptr != nullptr)
		{
			index++;
			if (ptr->value == _value)
			{
				cout << _value << " 값은 인덱스 " << index << " 번째에 있습니다." << endl;
				isFind = true;
				break;
			}
			ptr = ptr->next;
		}

		// 못 찾음.
		if (isFind == false)
		{
			cout << _value << " 값은 리스트 안에 없습니다. " << endl;
		}
	}
	int Size() // 리스트 크기를 반환
	{
		return size;
	}
};