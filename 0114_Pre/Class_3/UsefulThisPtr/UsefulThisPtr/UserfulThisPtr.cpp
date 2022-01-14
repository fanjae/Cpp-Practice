#include <iostream>
using namespace std;

class TwoNumber
{
private:
	int num1;
	int num2;
public:
	
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1; 
		this->num2 = num2;
	}
	
	/* 멤버 이니셜라이저에서는 this 포인터를 사용할 수 없다.
	TwoNumber(int num1, int num2) : num1(num1), num2(num2)
	{

	}*/
	
	void ShowTwoNumber() const
	{
		cout << this->num1 << "\n"; // this 포인터를 사용하여 멤버변수에 접근함을 명확히 할 수 있다.
		cout << this->num2 << "\n";
	}
};

int main(void)
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	return 0;
}