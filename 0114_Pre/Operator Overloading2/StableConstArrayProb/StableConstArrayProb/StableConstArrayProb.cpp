#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int *arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }

public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}
	int& operator[] (int idx) const // �Լ� ��ȯ�� �� const �Լ��ӿ� ����
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array Index out of bound exception" << "\n";
			exit(1);
		}
		return arr[idx]; // �ε����� �ش��ϴ� �迭��Ҹ� ��ȯ�Ѵ�.
		// �������� ��ȯ�ʿ� ����, ���� ���� �Ӹ� �ƴ϶� ���浵 �����ϴ�.
	}
	int GetArrLen() const
	{
		return arrlen;
	}
	~BoundCheckIntArray()
	{
		delete[] arr;
	}
};

void ShowAllData(const BoundCheckIntArray& ref)
{
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
	{
		cout << ref[idx] << "\n";
		// ref.operator[] (idx);�� �ؼ��ȴ�.
		// ����, const ������ �߰��ؾ��Ѵ�.
	}
}
int main(void)
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i + 1) * 11;
	}
	ShowAllData(arr);
	return 0;
}