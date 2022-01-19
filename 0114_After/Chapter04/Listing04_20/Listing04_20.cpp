#include <iostream>
#include <cstring>				// strlen(), strcpy() 선언

#pragma warning (disable:4996)
int main()
{
	using namespace std;
	char animal[20] = "bear";	// animal에 bear에 들어 있다.
	const char *bird = "wren";	// bird에 문자열의 주소가 들어가 있다.
	char *ps;					// 초기화되지 않았다.

	cout << animal << "and ";	// bear를 출력한다.
	cout << bird << "\n";		// wren을 출력한다.
	// cout << ps << "\n";		// 쓰레기를 출력하거나 먹통이 될 수도 있다.


	cout << "동물의 종류를 입력하십시오: ";
	cin >> animal;
	// cin >> ps; (절대 해서는 안됨)
	// ps가 대입된 공간을 지시하고 있지 있다.

	ps = animal;				// ps를 문자열을 지시하도록 설정한다.
	cout << ps << "s!\n";		// 맞다, animal을 사용하는 것과 동등 
	cout << "strcpy() 사용 전:\n";
	cout << (int *)animal << ": " << animal << endl;
	cout << (int *)ps << ": " << ps << endl;

	/*
	ps는 "fox"를 출력하지만 (int *) ps는 그 문자열이 저장된 주소를 출력한다.
	ps에 ainimal을 대입하면 문자열이 아닌 주소가 복사되므로, 두 포인터는 같은 메모리 위치와 같은 문자열을 지시한다.
	*/

	ps = new char[strlen(animal) + 1];		// 새 메모리를 대입한다.
	strcpy(ps, animal);						// 새 메모리에 문자열을 복사
	cout << "strcpy() 사용 후:\n";
	cout << (int *)animal << ": " << animal << endl;
	cout << (int *)ps << ": " << ps << endl;
	delete[] ps;
	return 0;
}
