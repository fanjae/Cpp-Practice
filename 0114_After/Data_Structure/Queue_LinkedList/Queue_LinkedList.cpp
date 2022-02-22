#include <iostream>
#include "queue_node.h"
int main() 
{ 
	Queue<int> queue; 
	
	queue.Enqueue(3);
	queue.Enqueue(5);
	queue.Enqueue(2);

	cout << queue.Dequeue() << endl; 
	cout << queue.Dequeue() << endl; 
	cout << queue.Dequeue() << endl; 
	return 0; 

}
