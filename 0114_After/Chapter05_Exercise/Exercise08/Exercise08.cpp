#include <iostream>
#include <cstring>
using namespace std;

const int Size = 100;
int main(void)
{
	char ch[Size];
	int count = -1; // done에 대한 단어 개수 제외를 위해 처음에 -1로 설정. 
	while (strcmp(ch,"done") != 0)
	{
		cin >> ch;
		count++;
	}
	cout << "총 " << count << " 단어가 입력되었습니다." << endl;
}