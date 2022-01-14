#include <iostream>
using namespace std;

template <typename T1, typename T2>
class MySimple
{
public:
	void WhoAreYou()
	{
		cout << "size of T1 : " << sizeof(T1) << endl;
		cout << "size of T2 : " << sizeof(T2) << endl;
		cout << "<typename T1, typename T2>" << endl;
	}
};

template <>
class MySimple<int, double>
{
public:
	void WhoAreYou()
	{
		cout << "size of int : " << sizeof(int) << endl;
		cout << "size of double : " << sizeof(double) << endl;
		cout << "<int, double>" << endl;
	}
};

// 클래스 템플릿의 부분 특수화
// T1,T2 모두에 대해서 특수화를 진행한 것이 아닌, T2 하나에 대해서만 부분적으로 특수화를 진행함.
template <typename T1>
class MySimple<T1, double> // T2를 double로 부분 특수화
{
public:
	void WhoAreYou()
	{
		cout << "size of int : " << sizeof(T1) << endl;
		cout << "size of double : " << sizeof(double) << endl;
		cout << "<int, double>" << endl;
	}
};


int main(void)
{
	MySimple<char, double> obj1;
	obj1.WhoAreYou();
	MySimple<int, long> obj2;
	obj2.WhoAreYou();
	MySimple<int, double> obj3;
	obj3.WhoAreYou();
	return 0;
}