#include <iostream>
#include <new>
using namespace std;

int main(void)
{
	int num = 0;

	try
	{
		while (1)
		{
			num++;
			cout << num << "��° �Ҵ� �õ�" << endl;
			new int[10000][10000]; // �޸� �Ҵ� ���� ���ܸ� �߻��� ���ؼ� �ݺ��ؼ� �޸� ������ �Ҵ縸 �ϰ� �ִ�.
		}
	}
	catch (bad_alloc &bad) // ������ �߻��� Ȯ���ϱ� ���� catch ����̴�.
	{
		cout << bad.what() << endl; // what �Լ��� ������ ���� ������ ���ڿ��� ���·� ��ȯ��. 
		cout << "�� �̻� �Ҵ� �Ұ�!" << endl; // ��ȯ ���ڿ��� ������ �����Ϸ��� ���� �޶�����.
	}
	return 0;
}