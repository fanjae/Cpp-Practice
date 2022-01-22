#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char last_name[50];
	char first_name[100];

	cout << "퍼스트 네임(이름)을 입력하시오: ";
	cin.getline(first_name, 100);
	cout << "라스트 네임(성)을 입력하시오: ";
	cin.getline(last_name, 50);
	cout << "하나의 문자열로 만들면 : " << last_name << ", " << first_name;

}