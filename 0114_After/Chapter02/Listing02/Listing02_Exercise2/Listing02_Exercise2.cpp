// CHAPTER 02 EX.2
#include <iostream>
using namespace std;

int main(void)
{
	int miles;
	double km;
	cout << "마일을 입력하세요 : ";
	cin >> miles;

	km = miles * 1.60934;
	cout << miles << "마일은 " << km << "킬로미터입니다.\n";
	return 0;
}
