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
	int& operator[] (int idx) // arr.operator[](idx);와 같은 형태로 해석된다.
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out bound exception" << endl;
			exit(1);
		}
		return arr[idx]; // 인덱스에 해당하는 배열요소를 반환한다. 이때 반환형은 참조형이다.
		// 이를 이용하여 저장된 값의 참조뿐만 아니라 변경도 가능하도록 유도하고 있다.
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