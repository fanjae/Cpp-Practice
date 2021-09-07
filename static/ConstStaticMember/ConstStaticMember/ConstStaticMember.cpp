#include <iostream>
using namespace std;

class CountryArea
{
public:
	const static int RUSSIA = 1707540;
	const static int CANADA = 998467;
	const static int CHINA = 957290;
	const static int SOUTH_KOREA = 9922;

};

int main(void)
{
	/* 정의된 상수에 접근할때는 객체를 반드시 생성할 필요가 없이
	다음과 같이 접근하는 것도 방법이다. */
	cout << "러시아 면적 : " << CountryArea::RUSSIA << "km" << "\n";
	cout << "캐나다 면적 : " << CountryArea::CANADA << "km" << "\n";
	cout << "중국 면적 : " << CountryArea::CHINA << "km" << "\n";
	cout << "한국 면적 : " << CountryArea::SOUTH_KOREA << "km" << "\n";
	return 0;
}