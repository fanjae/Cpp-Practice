#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "New Object : " << this << "\n";
	}
	SoSimple(const SoSimple &copy) : num(copy.num)
	{
		cout << "New Copy obj : " << this << "\n";
	}
	~SoSimple()
	{
		cout << "Destory obj : " << this << "\n";
	}
};

SoSimple SimpleFuncObj(SoSimple ob)
{
	cout << "Parm ADR : " << &ob << "\n";
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj); // SimpleFuncObj 함수의 반환으로 인해서 임시객체 생성이 됨을 확인할 수 있음.
	// 이후 매개변수 ob가 먼저 소멸된다.

	cout << "\n";
	SoSimple tempRef = SimpleFuncObj(obj); // SimpleFuncObj 함수의 반환으로 인해서 임시객체 생성이 됨을 확인할 수 있음.
	// 이후 매개변수 ob가 소멸되고, 반환되는 ob에 대한 임시객체가 생성된다.
	// 이때 생성되는 ob와 tempRef의 주소값이 동일하다.

	cout << "Return Obj " << &tempRef << "\n";
	return 0;
}
