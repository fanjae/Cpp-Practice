#include <iostream>
namespace mystd // cout�� endl ���� ����
{
	using namespace std;
	class ostream
	{
	public:
		// �پ��� �⺻ �ڷ��� �����͸� �������
		// << �����ڸ� �����ε� �Ѵ�. 
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
		// �Լ� ������. 
		// ostream&�� ��ȯ��, ostream &ostm ����.
		void operator<< (ostream& (*fp)(ostream &ostm))
		{
			fp(*this);
		}
	};

	// endl�� �Ʒ��� ���� �Լ� ���¸� ���.
	// ���۸� ���� �۾��� �Բ� ����ȴ�.
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
	// cout�� endl�� ����� ���ؼ� ���������� using�� �����Ͽ���.
	// mystd ���� ����� ���� �ǹ��Ѵ�.

	using mystd::cout;
	using mystd::endl;

	cout << "Simple String";
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	endl(cout);

	// cout << 123 << endl << 3.14 << endl;
	// ���� ���� ������ ������ �� ����.

	return 0;
}