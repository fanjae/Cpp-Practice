#include <iostream>
#include <string>
using namespace std;

template <typename RetType, typename ArgType>
class Functor
{
public:
	RetType operator() (ArgType data)
	{
		cout << data << endl;
		return RetType();
	}
};

int main()
{
	Functor<void, int> functor1;
	functor1(10);
	Functor<bool, string> functor2;

	functor2("Hello");

	return 0;
}
// 반환 타입과 매개변수를 가지는 함수 객체
