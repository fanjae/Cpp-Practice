#include <iostream>
using namespace std;

class Base
{
public:
	void BaseFunc()
	{
		cout << "Base Function" << "\n";
	}
};

class Derived : public Base
{
public:
	void DerivedFunc()
	{
		cout << "Derived Function" << "\n";
	}
};

int main(void)
{
	Base *bptr = new Derived(); // ������ ���� ����.
	// bptr->DerivedFunc()		// ������ ����

	/* bptr�� Base�� �������̱� ������ �Ұ����ϴ�.
	C++ �����Ϸ��� ������ ������ ���ɼ� ���θ� �Ǵ��� ��, �������� �ڷ����� �������� �Ǵ��Ѵ�.
	������ ����Ű�� ��ü�� �ڷ����� �������� �Ǵ����� �ʴ´�. */

	// Derived *dptr = btpr;	// ���� ������ �� ���嵵 ������ ������ �߻��Ѵ�.
	// �����Ϸ��� �ռ� bptr�� ������ ����Ű�� ��ü�� Derived ��ü��� ����� ������� �ʴ´�.

	// �̿� �ݸ� �Ʒ��� ���� ���� �����Ϸ��� ������ ���� �ʴ´�.
	Derived *dptr = new Derived();
	Base *bptr2 = dptr;

	// dptr�� Derived Ŭ������ ������ �����̴�. �� �����Ͱ� ����Ű�� ��ü�� �и� Base Ŭ������ ���� Ȥ�� ���������� ����Ѵ�.
	// ���� ������ �����ϴ�.



}
