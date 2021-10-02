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
	int& operator[] (int idx) // 함수 반환형에 유의
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array Index out of bound exception" << "\n";
			exit(1);
		}
		return arr[idx]; // 인덱스에 해당하는 배열요소를 반환한다.
		// 참조형이 반환됨에 따라서, 값의 참조 뿐만 아니라 변경도 가능하다.
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
	for (int i = 0; i < 6; i++) // 벗어난 배열 범위 확인을 위해 범위를 0~5로 지정
	{
		cout << arr[i] << "\n";
	}
	return 0;
}