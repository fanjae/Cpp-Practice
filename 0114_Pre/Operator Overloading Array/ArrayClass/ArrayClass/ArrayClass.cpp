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
	int& operator[] (int idx) // arr.operator[](idx);�� ���� ���·� �ؼ��ȴ�.
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out bound exception" << endl;
			exit(1);
		}
		return arr[idx]; // �ε����� �ش��ϴ� �迭��Ҹ� ��ȯ�Ѵ�. �̶� ��ȯ���� �������̴�.
		// �̸� �̿��Ͽ� ����� ���� �����Ӹ� �ƴ϶� ���浵 �����ϵ��� �����ϰ� �ִ�.
	}
	~BoundCheckIntArray()
	{
		delete[]arr;
	}
};

int main(void)
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i + 1) * 11;
	}
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}