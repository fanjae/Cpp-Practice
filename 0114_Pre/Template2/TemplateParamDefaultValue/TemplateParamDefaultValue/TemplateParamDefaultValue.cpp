#include <iostream>
using namespace std;

template <typename T=int, int len = 7> // Default Value 지정!
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
	SimpleArray<> arr; // 탬플릿 매개변수에 디폴트값이 지정되어도 템플릿 클래스의 객체성생얼 의미하는 <> 기호는 반드시 있어야 한다.
	for (int i = 0; i < 7; i++)
	{
		arr[i] = i + 1;
	}
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}