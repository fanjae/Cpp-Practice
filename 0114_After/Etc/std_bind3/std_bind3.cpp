#include <iostream>
#include <functional>

int Calc(int a, int b, int c)
{
	return (a + b) * c;
}

int main(void)
{
	std::function<int()> data = std::bind(Calc, 5, std::placeholders::_1, std::placeholders::_2);
	std::cout << data() << std::endl;
	return 0;
}