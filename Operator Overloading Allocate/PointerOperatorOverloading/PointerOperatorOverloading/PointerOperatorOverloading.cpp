#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n) : num(n) { }
	void ShowData() {
		cout << num << endl;
	}

	Number* operator->() // �ּҰ��� ��ȯ�ϵ��� -> �����ڸ� �����ε� �ϰ� �Ӥ���.
	{
		return this;
	}
	Number& operator*() // ��ü �ڽ��� ������ ���·� ��ȯ�ϵ��� * �����ڸ� �����ε�.
	{
		return *this;
	}
};

int main(void)
{
	Number num(20);
	num.ShowData();

	(*num) = 30;
	num->ShowData(); // num.operator->() ���� ��ȯ�ϴ� ���� �ּҰ��̴�.
	// ����, �� ������. num.operator->()->ShowData(); �� '->' �����ڸ� �ϳ� �� �߰� ���Ѽ� �ؼ��� ���̴�.
	(*num).ShowData();
	return 0;
}