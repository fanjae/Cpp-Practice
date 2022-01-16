#include <iostream>
using namespace std;
int main(void)
{
	int height;
	const int Meter = 100;
	
	cout << "센티미터를 입력하세요 : ";
	cin >> height;

	cout << "미터 : " << height / Meter << "m" << endl;
	cout << "센티미터 : " << height % Meter << "cm" << endl;

	return 0;
}	