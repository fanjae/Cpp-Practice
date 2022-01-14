#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA(int n = 0) : num(n)
	{
		cout << "AAA(int n=0)" << "\n";
	}
	AAA(const AAA& ref) : num(ref.num)
	{
		cout << "AAA(const AAA& ref)" << "\n";
	}
	AAA& operator=(const AAA& ref)
	{
		num = ref.num;
		cout << "operator=(const AAA& ref)" << "\n";
		return *this;
	}
};

class BBB
{
private:
	AAA mem;
public:
	BBB(const AAA& ref) : mem(ref) // 멤버 이니셜라이저를 이용해 멤버를 초기화하고 있다.
	{
	}
};

class CCC
{
private:
	AAA mem;
public:
	CCC(const AAA& ref) // 대입연산을 이용하여 멤버를 초기화 하고 있다.
	{
		// 생성자의 몸체 부분에서 대입연산을 통한 초기화를 진행하였다.
		// 따라서, 생성자와 대입 연산자가 각각 한번씩 호출된다.

		mem = ref;
	}
};

int main(void)
{
	AAA obj1(12);
	cout << "****************************" << "\n";
	// 이니셜라이저를 이용하면 선언과 동시에 초기화가 이뤄지는 형태로
	// 바이너리 코드가 생성된다.
	BBB obj2(obj1);
	cout << "****************************" << "\n";
	CCC obj3(obj1);
	return 0;
}