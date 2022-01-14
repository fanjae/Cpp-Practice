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
	int& operator[] (int idx) // const가 없는 형태의 연산자 오버로딩
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int operator[] (int idx) const // const를 선언한 형태의 연산자 오버로딩 
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
		delete[] arr;
	}
};

typedef BoundCheckIntArray* BoundCheckIntArrayPtr;

class BoundCheck2DIntArray
{
private:
	BoundCheckIntArray **arr; // 기존 구현되어 있던 BoundCheckIntArray를 활용하여 구현한다.
	int arrlen;
	BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) { }
	BoundCheck2DIntArray& operator=(const BoundCheckIntArray& arr) { }
public:
	BoundCheck2DIntArray(int col, int row) : arrlen(col)
	{
		arr = new BoundCheckIntArrayPtr[col];
		for (int i = 0; i < col; i++)
		{
			arr[i] = new BoundCheckIntArray(row);
		}
	}
	BoundCheckIntArray& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return *(arr[idx]);
	}
	~BoundCheck2DIntArray()
	{
		for (int i = 0; i < arrlen; i++)
		{
			delete arr[i];
		}
		delete[]arr;
	}
};

int main(void)
{
	BoundCheck2DIntArray arr2D(3, 4);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr2D[i][j] = i + j;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr2D[i][j] << ' ';
		}
		cout << "\n";
	}
	return 0;
}