#include <iostream>
#include <functional>

using namespace std;
int Calc(int a, int b, int c,int d)
{
	return (a + b) * c + d;
}

/* std::function <int(int, int, int)> 
std::placeholders로 대체할 매개변수의 수만큼 명시*/

/* std::placeholder에 대해서 추가로 찾을 필요가 존재함 */

int main(void)
{
	std::function<int(int, int,int)> data = std::bind(Calc, 5, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	std::cout << data(1,2,5) << std::endl;
	return 0;
}