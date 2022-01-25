#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(void)
{
	string ch;
	int count = -1; // done에 대한 단어 개수 제외를 위해 처음에 -1로 설정. 
	while (ch != "done") // string은 관계 연산자로 비교가 가능하다.
	{
		cin >> ch;
		count++;
	}
	cout << "총 " << count << " 단어가 입력되었습니다." << endl;
}