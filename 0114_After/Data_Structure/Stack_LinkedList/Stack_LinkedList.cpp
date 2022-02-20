#include <iostream>
#include "stack_node.h"
using namespace std;

int main()
{
	Stack<int> stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);

	cout << stack.Top() << endl;

}