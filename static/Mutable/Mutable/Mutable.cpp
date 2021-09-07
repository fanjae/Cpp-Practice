#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	mutable int num2; //  const 함수 내에서의 값의 변경을 예외적으로 허용한다.
public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2)
	{
	}
	void ShowSimpleData() const
	{
		cout << num1 << ", " << num2 << "\n";
	}
	void CopyTopNum2() const
	{
		num2 = num1; // num2의 값이 변경될 수 있는 이유는 num2가 mutable로 선언되어 있기 때문이다.
	}
};

int main(void)
{
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyTopNum2();
	sm.ShowSimpleData();
	return 0;
}