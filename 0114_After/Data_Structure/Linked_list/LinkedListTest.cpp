#include "node.h"
int main()
{
	List <int> data;

	// Node �߰�
	data.AddNode(1);
	data.AddNode(2);
	data.AddNode(5);
	data.AddHead(3);
	data.AddHead(4);

	// Node Ȯ��
	data.Show();

	// Node ����
	data.RemoveHead();
	data.RemoveTail();

	// Node Ȯ��
	data.Show();

	// Node ������ Ȯ��
	data.Size();

	// Node ��ü ����
	data.DeleteList();
	
	// Node �߰�
	data.AddNode(3);

	// Node �˻�
	data.SearchValue(3);

	// Test ��� : AddPosition�� ���� �����Ͱ� �ƿ� ������ ����� �� �����͸� �߰����� ����.

}
