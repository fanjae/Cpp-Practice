#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "New Object : " << this << "\n";
	}
	SoSimple(const SoSimple &copy) : num(copy.num)
	{
		cout << "New Copy obj : " << this << "\n";
	}
	~SoSimple()
	{
		cout << "Destory obj : " << this << "\n";
	}
};

SoSimple SimpleFuncObj(SoSimple ob)
{
	cout << "Parm ADR : " << &ob << "\n";
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj); // SimpleFuncObj �Լ��� ��ȯ���� ���ؼ� �ӽð�ü ������ ���� Ȯ���� �� ����.
	// ���� �Ű����� ob�� ���� �Ҹ�ȴ�.

	cout << "\n";
	SoSimple tempRef = SimpleFuncObj(obj); // SimpleFuncObj �Լ��� ��ȯ���� ���ؼ� �ӽð�ü ������ ���� Ȯ���� �� ����.
	// ���� �Ű����� ob�� �Ҹ�ǰ�, ��ȯ�Ǵ� ob�� ���� �ӽð�ü�� �����ȴ�.
	// �̶� �����Ǵ� ob�� tempRef�� �ּҰ��� �����ϴ�.

	cout << "Return Obj " << &tempRef << "\n";
	return 0;
}
