#include <iostream>
int main()
{
	using namespace std;
	float a = 2.34E+22f;
	float b = a + 1.0f;

	cout << "a = " << a << endl;
	cout << "b - a = " << b - a << endl;
	return 0;
}

/* �ε� �Ҽ����� ����� �⺻������ double������ ����ȴ�.
�ε� �Ҽ����� ����� float������ �����ϰ� ������, f�� F�� ���̾��,
long double������ �����ϰ� ������ l�̳� L�� ���̾�� ����ؾ� �Ѵ�.
*/
