#include <iostream>
using namespace std;

// 클래스 Data를 흉내낸 영역
typedef struct Data
{
	int data;
	void(*ShowData)(Data *); // 함수 포인터. ShowData 함수의 주소값을 저장하기 위한 함수이다.
	void(*Add)(Data *, int); // 함수 포인터. Add 함수의 주소값을 저장하기 위한 함수이다.

} Data;

void ShowData(Data* THIS)
{
	cout << "Data : " << THIS->data << "\n";
}
void Add(Data * THIS, int num)
{
	THIS->data += num;
}
int main(void)
{
	Data obj1 = { 15, ShowData, Add }; 
	Data obj2 = { 7, ShowData, Add };

	// 위 두 객체는 ShowData 함수와 Add 함수를 공유하는 셈이 된다. (두 함수를 이용해서 멤버인 함수 포인터 변수를 초기화 하였다.)

	obj1.Add(&obj1, 17);
	obj2.Add(&obj2, 9);

	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);

	// 두 개의 구조체 변수(객체)가 함수를 공유하고 있다는 사실이다.
	// C++의 객체와 멤버함수는 이러한 관계를 갖는다.
	// 객체가 생성되는 멤버변수는 객채 내에 존재한다. 하지만, 멤버 함수는 메모리의 한 공간에 별도로 위치하고,
	// 정의된 클래스의 모든 객체가 이를 공유하는 형태를 취한다.
	return 0;
}