#include <iostream>
using namespace std;

// ��ü�� ����Լ��� ��������� ��� ���·� �����Ǵ��� �����ϱ� ����
// ���� �� C++ �ڵ�
class Data
{
private:
	int data;
public:
	Data(int num) : data(num)
	{

	}
	void ShowData()
	{
		cout << "Data : " << data << "\n";
	}
	void Add(int num)
	{
		data += num;
	}
};

int main(void)
{
	Data obj(15);
	obj.Add(17);
	obj.ShowData();
	return 0;
}