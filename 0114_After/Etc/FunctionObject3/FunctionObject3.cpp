#include <iostream>
using namespace std;

class Adder
{
	int total;
public:
	explicit Adder(int n = 0) : total(n) { }
	int operator()(int n)
	{
		return total += n;
	}
};

int main()
{
	Adder add(0);

	cout << add(10) << endl; // 10 누적 -> 10
	cout << add(20) << endl; // 20 누적 -> 20
	cout << add(30) << endl; // 30 누적 -> 30

	return 0;
}