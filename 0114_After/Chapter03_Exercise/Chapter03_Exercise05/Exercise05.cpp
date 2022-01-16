#include <iostream>
using namespace std;
int main(void)
{
	long long world_people;
	long long usa_people;

	cout << "세계 인구수를 입력하시오: ";
	cin >> world_people;
	cout << "미국의 인구수를 입력하시오: ";
	cin >> usa_people;

	cout << "세계 인구수에서 미국이 차지하는 비중은 " << double (usa_people) / double(world_people) * 100 << "%이다." << endl;
	return 0;
}