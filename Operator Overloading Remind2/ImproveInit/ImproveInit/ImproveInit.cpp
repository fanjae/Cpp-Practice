#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA(int n = 0) : num(n)
	{
		cout << "AAA(int n=0)" << endl;
	}
	AAA(const AAA& ref) : num(ref.num)
	{
		cout << "AAA(const AAA& ref)" << endl;
	}
	AAA& operator=(const AAA& ref)
	{
		num = ref.num;
		cout << "operator = (const AAA& ref)" << endl;
		return *this;
	}
};

class BBB // 이니셜라이저를 이용한 멤버 초기화
{
private:
	AAA mem;
public:
	BBB(const AAA& ref) : mem(ref) { } 
};

class CCC // 대입 연산을 이용한 멤버 초기화
{
private:
	AAA mem;
public:
	CCC(const AAA& ref) {
		mem = ref;
	}
};

int main(void)
{
	AAA obj1(12);
	cout << "*****************" << endl;
	BBB obj2(obj1);
	cout << "*****************" << endl;

	// BBB 객체는 복사 생성자만 호출되었다.
	// 이와 반면 CCC 객체는 생성자와 대입 연산자까지 호출되었다.
	// 생성자의 몸체 부분에서 대입 연산을 통한 초기화를 진행하면, 선언과 초기화를 각각 별도의 문장에서 진행하는 형태로 바이너리 코드가 생성된다.
	// 따라서, 이니셜 라이저를 이용해서 초기화를 진행하면, 함수 호출횟수를 줄일 수 있어서, 초기화의 과정을 단순화시키는 것이 가능하다.
	CCC obj3(obj1);
	return 0;
}