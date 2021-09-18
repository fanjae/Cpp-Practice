#include <iostream>

namespace mystd
{
	using namespace std;

	class ostream
	{
	public:
		/* cout ��ü�� �������� ��ȯ�ϴ� ���·�
		Ȯ���� �����Ͽ���. */ 
		ostream& operator<< (const char *str)
		{
			printf("%s", str);
			return *this;
		}
		ostream& operator<< (const char str)
		{
			printf("%c", str);
			return *this;
		}
		ostream& operator << (int num)
		{
			printf("%d", num);
			return *this;
		}
		ostream& operator << (double e)
		{
			printf("%g", e);
			return *this;
		}
		ostream& operator << (ostream& (*fp)(ostream &ostm))
		{
			return fp(*this);
		}
	};

	ostream& endl(ostream &ostm)
	{
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}
	/* endl �Լ��� ���ڷ� ���޵� ��ü�� �������� ��ȯ�Ѵ�.
	��ȯ�� ���� �� ��ȯ�ϴ� ���·� �����ڸ� �����ε� �Ͽ���. */
	ostream cout;
}

int main(void)
{
	using mystd::cout;
	using mystd::endl;
	cout << 3.14 << endl << 123 << endl;
	return 0;
}
