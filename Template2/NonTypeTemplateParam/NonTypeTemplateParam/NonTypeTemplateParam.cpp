#include <iostream>
using namespace std;

template <typename T, int len> // 템플릿 매게변수에 전달되는 자료형 정보를 템플릿 인자라고 한다 이때, 함수처럼 변수의 선언이 올 수 있다.
class SimpleArray
{
private:
	T arr[len]; 
public:

	T& operator[] (int idx) {
		return arr[idx];
	}
	SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref)
	{
		for (int i = 0; i < len; i++)
		{
			arr[i] = ref.arr[i];
		}
		return *this;
	}
};

int main(void)
{
	SimpleArray<int, 5> i5arr1;
	for (int i = 0; i < 5; i++)
	{
		i5arr1[i] = i * 10;
	}

	SimpleArray<int, 5> i5arr2;
	i5arr2 = i5arr1; // i5arr1과 i5arr2 모두 SimpleArray<int, 5>형이므로 대입연산이 가능하다.
	for (int i = 0; i < 5; i++)
	{
		cout << i5arr2[i] << " ,";
	}
	cout << endl;

	SimpleArray<int, 7> i7arr1;
	for (int i = 0; i < 7; i++)
	{
		i7arr1[i] = i * 10;
	}

	SimpleArray<int, 7> i7arr2;
	i7arr2 = i7arr1;
	for (int i = 0; i < 7; i++)
	{
		cout << i7arr2[i] << ", ";
	}
	cout << endl;
	return 0;
}