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
	int& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const
	{
		return arrlen;
	}
	~BoundCheckIntArray()
	{
		delete[]arr;
	}
};

void ShowAllData(const BoundCheckIntArray& ref)
{
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
	{
		cout << ref[idx] << endl;
		// ref 객체는 const로 선언되어있다.
		// 하지만, 호출되는 operator[] 함수가 const가 아니기 때문에
		// 여기서는 컴파일 에러가 발생한다. 따라서 이에 대한 해결이 필요하다.
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