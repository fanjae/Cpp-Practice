#include <iostream>
using namespace std;
template <typename T> 
T Add(T num1, T num2)
{
	return num1 + num2;
}

int main(void)
{
	cout << Add<int>(15, 20) << endl; // T�� int�� �ؼ� ������� Add �Լ��� ȣ���Ѵ�.
	cout << Add<double>(2.9, 3.7) << endl;
	// �� �Լ��� �����Ϸ��� �Ʒ��� ���� �����.
	// double Add(double num1, double num2)
	// {
	//		return num1 + num2;
	// }
	// ������ �� �Լ��� ��������� ������ ������ �ϴµ� �ð��� �ʾ��� �� �ִ�.
	cout << Add<int>(3.2, 3.2) << endl;
	cout << Add<double>(3.14, 2.75) << endl;
	return 0;
}