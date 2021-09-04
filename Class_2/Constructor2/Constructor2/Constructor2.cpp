#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass(int n1 = 0, int n2 = 0)
	{
		num1 = n1;
		num2 = n2;
	}
	void ShowData() const
	{
		cout << num1 << ' ' << num2 << "\n";
	}
};

int main(void)
{
	SimpleClass sc1(); // 함수의 원형을 선언한 것으로 인식하여 생성자가 아님에 유의할 것
	SimpleClass mysc = sc1(); // sc1 함수에서 반환되는 객체 값으로 mysc 객체를 초기화함.
	mysc.ShowData();
	return 0;
}

SimpleClass sc1()
{
	SimpleClass sc(20, 30);
	return sc;
}