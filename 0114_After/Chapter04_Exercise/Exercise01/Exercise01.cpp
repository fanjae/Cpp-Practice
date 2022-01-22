#include <iostream>
using namespace std;
int main()
{
	char last_name[50];
	char first_name[100];
	char grade;
	int age;

	cout << "영문 퍼스트 네임(이름): ";
	cin.getline(first_name, 100);
	cout << "영문 라스트 네임(성): ";
	cin.getline(last_name, 50);
	cout << "학생이 원하는 학점: ";
	cin >> grade;
	cout << "나이: ";
	cin >> age;

	cout << "성명: " << last_name  << ", " << first_name << endl;
	cout << "학점 : " << grade + 1 << endl;
	cout << "나이 : " << age << endl;

}