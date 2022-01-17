#include <iostream>
int main()
{
	using namespace std;
	cout << "지금 사시는 아파트에 언제 입주하셨습니까\n";

	int year;
	cin >> year;
	cin.get();
	/*
	cin이 입주연도를 읽어들이고 Enter 키가 만들어내는 개행 문자를 입력 큐에 남겨 두기 때문에
	발생하는 문제이다. cin.getline()은 입력 큐에 남겨진 개행 문자를 빈 행으로 읽어들이고,
	address 배열에 널 문자를 대입한다.
	이 문제는 주소를 읽기 전에 개행 문자를 버리는 방법을 이용한다.
	cin.get(); 또는 cin.get(ch);
	*/

	cout << "사시는 도시를 말씀해 주시겠습니까?\n";

	char address[80];
	cin.getline(address, 80);		
	cout << "아파트 입주 연도 : " << year << endl;
	cout << "도시 : " << address << endl;
	cout << "등록이 완료되었습니다!\n";


	return 0;
}