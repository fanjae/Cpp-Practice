#include <iostream>
int main()
{
	char ch;

	std::cout << "타이핑하시면, 반복 수행하겠습니다.\n";
	std::cin.get(ch);
	while (ch != '.')
	{
		if (ch == '\n')
		{
			std::cout << ch;	// 개행 문자일 때 수행
		}
		else
		{
			std::cout << ++ch;	// 그 밖의 문자일 때 수행
		}
		std::cin.get(ch);
	}
	// ++ch 대신 ch + 1을 사용하면 어떻게 될까?
	std::cout << "\n 혼란스럽게 해서 죄송합니다.\n";
	// std::cin.get();
	// std::cin.get();
	return 0;
}

/* ++ch일때는 char형 타입이다.
하지만, ch + 1일때는 int형 타입이다. (+1 과정에서 int형으로 변환하여 수행한다.)
그 예시로 'An'을 쳤을때 66111(B의 아스키코드 값, o의 아스키코드 값 출력)
*/
