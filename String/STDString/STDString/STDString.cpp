#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str1 = "I like ";
	string str2 = "string class";
	string str3 = str1 + str2; // ������ �����ε����� ���� string ��ü�� ���� ������ �����ϴ�.

	cout << str1 << endl; // string Ŭ������ << �����ڿ� ���ؼ��� �����ε� �Ǿ�����.
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2; 
	if (str1 == str3)
	{
		cout << "���� ���ڿ�!" << "\n";
	}
	else
	{
		cout << "�������� ���� ���ڿ�!" << "\n";
	}

	string str4;
	cout << "���ڿ� �Է� : ";
	cin >> str4; // string Ŭ������ >> �����ڿ� ���ؼ��� �����ε� �Ǿ�����.
	cout << "�Է��� ���ڿ�: " << str4 << "\n";
	return 0;
}