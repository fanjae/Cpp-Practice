#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{

	}
	SoSimple(const SoSimple &copy) : num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple &copy)" << "\n";
	}
	SoSimple &AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData() const
	{
		cout << "num : " << num << "\n";
	}
};

SoSimple SimpleFuncObj(SoSimple ob) // ���� ���� �������� ���� ������ ȣ��
{
	cout << "return ����" << "\n";
	return ob; // ��ȯ���� �������� �ƴ� ����, ob ��ü�� ���纻�� ��������� ��ȯ�ȴ�.
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData(); // SimpleFuncObj���� obj�� ���纻�� ��ü�� �������� ���� obj�� ������� ���� �������� ����.
	obj.ShowData();
	return 0;
}