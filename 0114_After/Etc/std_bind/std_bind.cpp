#include <iostream>
#include <functional>

void addAndPrint(int a, int b)
{
	int sum = a + b;
	std::cout << sum << "\n";
}

int main(void)
{
	auto func2 = std::bind(addAndPrint, 10, std::placeholders::_1);
	// auto -> std::function<void(int)>와 동일함.
	// std::bind(addAndPrint,10,std::placeholders::_1)의 의미는 addAndPrint(int, int) 함수의
	// 첫 번째 파라미터는 10, 두 번째 파라미터는 func2를 호출할 때 들어오는 첫번쨰 인자를 넣어준다.


	func2(100);

}