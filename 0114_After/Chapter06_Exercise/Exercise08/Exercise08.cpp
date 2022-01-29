#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main(void)
{
	int count = 0;
	char ch;
	ifstream inFile;
	inFile.open("08.txt");

	if (!inFile.is_open())
	{
		cout << "08.txt 파일을 열 수 없습니다." << endl;
		exit(EXIT_FAILURE);
	}

	while (inFile.good())
	{
		count++;
		inFile >> ch; // 파일로부터 값을 얻어옴. 해당 부분이 없을 경우 무한 루프
	}

	cout << "해당 파일의 문자 개수는 " << count << "개 입니다." << endl;
	inFile.close();
	return 0;
}
