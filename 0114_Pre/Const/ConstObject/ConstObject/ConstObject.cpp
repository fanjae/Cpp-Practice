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

int main(void)
{
	const SoSimple obj(7); // ��ü�� ������ ������ ���ġ �ʴ´�.
	// obj.AddNum(20); const �Լ��� �ƴϹǷ� ȣ���� �Ұ����ϴ�.
	obj.ShowData(); // const �Լ��̱� ������ const ��ü�� ������� ȣ���� �����ϴ�.
	return 0;
}