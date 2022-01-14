#include <iostream>
namespace mystd
{
	using namespace std;

	class ostream
	{
	public: // << 기본 자료형을 대상으로 << 연산자를 오버로딩
		void operator<< (const char *str) 
		{
			printf("%s", str);
		}
		void operator<< (const char str)
		{
			printf("%c", str);
		}
		void operator<< (int num)
		{
			printf("%d", num);
		}
		void operator<< (double e)
		{
			printf("%g", e);
		}
		void operator<< (ostream & (*fp)(ostream &ostm)) // 함수 포인터
		{
			fp(*this);
		}
	};

	ostream& endl(ostream &ostm) // endl은 이러한 함수 형태를 띔. (버퍼를 비우는 작업도 함께 진행함)
	{
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}

	ostream cout; // 객체의 이름
}

int main(void)
{
	using mystd::cout;
	using mystd::endl;

	cout << "Simple String"; // cout.operator<<("Simple String");
	cout << endl; // cout.operator<<(3.14); 
	cout << 3.14; // cout.operator<<(123); 위와 같이 해석된다.
	cout << endl;
	cout << 123;
	endl(cout);
	return 0;
}
