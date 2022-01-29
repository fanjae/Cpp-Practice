#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
const int str_Size = 100;
struct Society
{
	char name[str_Size];
	double dollar;
};

int main(void)
{
	int n;
	ifstream inputFile;
	Society *data;

	inputFile.open("09.txt");

	if (!inputFile.is_open())
	{
		cout << "09.txt 파일을 열 수 없습니다." << endl;
		exit(EXIT_FAILURE);
	}

	inputFile >> n;
	inputFile.get();
	/* 위 2개를 묶어서,
	(inputFile >> n).get(); 과 같이 사용해도 된다. */

	data = new Society[n];
	for (int i = 0; i < n; i++)
	{
		inputFile.getline(data[i].name, str_Size);
		inputFile >> data[i].dollar;
		inputFile.get();
	}
	
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << data[i].name << endl;
		cout << data[i].dollar << endl;
	}
}