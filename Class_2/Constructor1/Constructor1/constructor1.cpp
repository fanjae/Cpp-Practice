#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:

	/* 생성자는 오버로딩이 가능하다. */
	SimpleClass()
	{
		num1 = 0;
		num2 = 0;
	}
	SimpleClass(int n)
	{
		num1 = n;
		num2 = 0;
	}
	SimpleClass(int n1, int n2)
	{
		num1 = n1;
		num2 = n2;
	}

	void showData() const
	{
		cout << num1 << ' ' << num2 << "\n";
	}
};

int main(void)
{
	SimpleClass sc1; 
	sc1.showData();

	SimpleClass sc2(100); // SimpleClass(int n) 형태의 객체 생성
	sc2.showData();

	SimpleClass sc3(100, 200); // SimpleClass(int n1, int n2) 형태의 객체 생성
	sc3.showData();

	// SimpleClass sc4(); 다음과 같이 생성자를 이용하여 객체를 생성하는 것은 불가능하다.
	return 0;
}