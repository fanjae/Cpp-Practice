#include <iostream>
using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "��ü����" << "\n";
	}
	SelfRef& Adder(int n)
	{
		num += n;
		return *this;
	}
	SelfRef& ShowTwoNumber()
	{
		cout << num << "\n";
		return *this;
	}
};

int main(void)
{
	SelfRef Obj(3);
	SelfRef &ref = Obj.Adder(2);

	Obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	// ref ��ü�� Adder �Լ��� ȣ��ȴ�.
	// Adder �Լ��� ���� ���� ��ȯ�Ѵ�. �� ��ü�� ShowTwoNumber �Լ��� ��ȯ�Ѵ�.
	// ���⼭ ��ȯ�� ���� ���� �̿��ؼ� �ٽ� Adder �Լ��� ȣ���ϰ�, �� ShowTwoNumber�Լ��� ȣ���Ѵ�.
}