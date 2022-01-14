#include <iostream>
using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "객체생성" << "\n";
	}
	SelfRef& Adder(int n)
	{
		num += n;
		return *this;
	}
	SelfRef& ShowTwoNumber()
	{
		cout << num << "\n";
		return *this;
	}
};

int main(void)
{
	SelfRef Obj(3);
	SelfRef &ref = Obj.Adder(2);

	Obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	// ref 객체의 Adder 함수가 호출된다.
	// Adder 함수는 참조 값을 반환한다. 이 객체의 ShowTwoNumber 함수를 반환한다.
	// 여기서 반환된 참조 값을 이용해서 다시 Adder 함수를 호출하고, 또 ShowTwoNumber함수를 호출한다.
}