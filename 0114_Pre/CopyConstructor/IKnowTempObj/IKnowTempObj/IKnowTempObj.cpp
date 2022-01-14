#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	{
		cout << "create obj : " << num << "\n";
	}
	~Temporary()
	{
		cout << "destroy obj : " << num << "\n";
	}
	void ShowTempInfo()
	{
		cout << "My num is " << num << "\n";
	}
};

int main(void)
{
	Temporary(100); // �ӽ� ��ü ���� ���
	cout << "********* after make!" << "\n" << "\n";
	

	Temporary(200).ShowTempInfo(); // �ӽ� ��ü ���� �� Ư�� �Լ� ȣ��, ��ü�� ���� �� ��ȯ�Ǹ� ��ȯ ��ġ�� ��ü�� ������ �� �ִ� �������� ��ȯ�ȴ�.
	cout << "********* after make!" << "\n" << "\n";

	const Temporary &ref = Temporary(300); // �����ڸ� �̿��Ͽ� �ӽð�ü�� ������. �̶��� �ӽð�ü�� �ٷ� �Ҹ���� �ʴ´�.
	cout << "********* after make!" << "\n" << "\n";
	return 0;
}