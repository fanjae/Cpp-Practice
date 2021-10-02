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
	int& operator[] (int idx) const // 함수 반환형 및 const 함수임에 유의
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array Index out of bound exception" << "\n";
			exit(1);
		}
		return arr[idx]; // 인덱스에 해당하는 배열요소를 반환한다.
		// 참조형이 반환됨에 따라서, 값의 참조 뿐만 아니라 변경도 가능하다.
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
		// ref.operator[] (idx);로 해석된다.
		// 따라서, const 선언을 추가해야한다.
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