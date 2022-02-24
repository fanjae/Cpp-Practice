#include <iostream>
#include <functional>

int Calc(int a, int b, int c)
{
	return (a + b) * c;
}

int main(void)
{
	std::function<int()> data = std::bind(Calc, 3, 4, 5);
	std::cout << data() << std::endl;
	return 0;
}