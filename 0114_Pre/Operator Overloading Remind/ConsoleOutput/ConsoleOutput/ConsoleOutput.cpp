#include <iostream>
namespace mystd // cout과 endl 직접 구현
{
	using namespace std;
	class ostream
	{
	public:
		// 다양한 기본 자료형 데이터를 대상으로
		// << 연산자를 오버로딩 한다. 
		void operator<< (const char * str)
		{
			printf("%s", str);
		}
		void operator<< (char str)
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
		// 함수 포인터. 
		// ostream&이 반환형, ostream &ostm 인자.
		void operator<< (ostream& (*fp)(ostream &ostm))
		{
			fp(*this);
		}
	};

	// endl는 아래와 같이 함수 형태를 띈다.
	// 버퍼를 비우는 작업도 함께 진행된다.
	ostream& endl(ostream &ostm)
	{
		ostm << "\n";
		fflush(stdout);
		return ostm;
	}
	ostream cout;
}

int main(void)
{
	// cout과 endl의 사용을 위해서 지역적으로 using을 선언하였다.
	// mystd 내에 선언된 것을 의미한다.

	using mystd::cout;
	using mystd::endl;

	cout << "Simple String";
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	endl(cout);

	// cout << 123 << endl << 3.14 << endl;
	// 위와 같은 문장은 실행할 수 없다.

	return 0;
}