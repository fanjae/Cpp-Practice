#include <iostream>
using namespace std;
int fact(int n);
int main(void)
{
	int n;
	cout << "n을 입력하세요 : ";
	cin >> n;

	cout << n << "! : " <<fact(n);
}
int fact(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * fact(n - 1);
	}
}