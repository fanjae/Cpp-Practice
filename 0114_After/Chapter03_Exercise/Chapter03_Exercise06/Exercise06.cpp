#include <iostream>
using namespace std;
int main(void)
{
	double go_distance;
	double go_gas;

	cout << "주행한 거리를 마일 단위로 입력하세요 : ";
	cin >> go_distance;

	cout << "소비한 휘발유의 양을 갤런 단위로 입력하세요 : ";
	cin >> go_gas;

	cout << "갤런당 마일 수 : " << go_distance / go_gas << endl << endl;

	cout << "==== 유럽 Ver(100킬로미터당 리터 수) ====" << endl;
	cout << "주행한 거리를 킬로미터 단위로 입력하세요 : ";
	cin >> go_distance;

	cout << "소비한 휘발유의 양을 리터 단위로 입력하세요 : ";
	cin >> go_gas;
	cout << "100킬로미터당 리터 수 : " << (go_gas / go_distance) * 100 << endl;
	
}