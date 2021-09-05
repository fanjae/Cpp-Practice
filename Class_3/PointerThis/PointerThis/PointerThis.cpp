#include <iostream>
#include <cstring>

using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "num= " << num << ", ";
		cout << "address= " << this << endl; 
	}
	void ShowSimpleData() const
	{
		cout << num << "\n";
	}
	SoSimple *GetThisPointer()
	{
		return this; // �ش� ��ü�� �����͸� ��ȯ�Ѵ�.
	}
};

int main(void)
{
	SoSimple sim1(100); // ��ü ������ ���ÿ� ������� �� ��ü �ڽ��� �ּҰ� ��� 
	SoSimple *ptr1 = sim1.GetThisPointer(); // �ش� ������ �����ϴ� ��ü�� ������ ��ȯ
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple *ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	return 0;
}