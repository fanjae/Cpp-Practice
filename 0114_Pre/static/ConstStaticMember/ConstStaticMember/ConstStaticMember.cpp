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
	/* ���ǵ� ����� �����Ҷ��� ��ü�� �ݵ�� ������ �ʿ䰡 ����
	������ ���� �����ϴ� �͵� ����̴�. */
	cout << "���þ� ���� : " << CountryArea::RUSSIA << "km" << "\n";
	cout << "ĳ���� ���� : " << CountryArea::CANADA << "km" << "\n";
	cout << "�߱� ���� : " << CountryArea::CHINA << "km" << "\n";
	cout << "�ѱ� ���� : " << CountryArea::SOUTH_KOREA << "km" << "\n";
	return 0;
}