#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int *arr;
	int arrlen;
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}
	int& operator[] (int idx) // �Լ� ��ȯ���� ����
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array Index out of bound exception" << "\n";
			exit(1);
		}
		return arr[idx]; // �ε����� �ش��ϴ� �迭��Ҹ� ��ȯ�Ѵ�.
		// �������� ��ȯ�ʿ� ����, ���� ���� �Ӹ� �ƴ϶� ���浵 �����ϴ�.
	}
	~BoundCheckIntArray()
	{
		delete[] arr;
	}
};

int main(void)
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i + 1) * 11;
	}
	for (int i = 0; i < 6; i++) // ��� �迭 ���� Ȯ���� ���� ������ 0~5�� ����
	{
		cout << arr[i] << "\n";
	}
	return 0;
}