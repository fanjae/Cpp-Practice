#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{

	}
	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void SimpleFunc()
	{
		cout << "SimpleFunc : " << num << "\n";
	}
	void SimpleFunc() const
	{
		cout << "const SimpleFunc : " << num << "\n";
	}
};

void YourFunc(const SoSimple &obj)
{
	obj.SimpleFunc(); // const 참조자로 받았기 때문에 
	// 해당 함수호출을 할때 const 함수로 된 SimpleFunc()를 호출한다.
}

int main(void)
{
	SoSimple obj1(2);
	const SoSimple obj2(7);

	obj1.SimpleFunc();
	obj2.SimpleFunc();

	YourFunc(obj1);
	YourFunc(obj2);
	return 0;
}