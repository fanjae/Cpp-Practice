#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num(n)
	{
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(const Number& ref)
	{
		cout << "operator=() " << endl;
		num = ref.num;
		return *this;
	}
	operator int()
	{
		return num;
	}
	void ShowNumber()
	{
		cout << num << endl;
	}
};

int main(void)
{
	Number num1;
	num1 = 30;
	Number num2 = num1 + 20; // operator+가 정의되어있지 않으므로, num1이 int형으로 변환되어야 한다.
	// 따라서, 호출되는 것이 형 변환 연산자이다.
	num2.ShowNumber();
	return 0;
}