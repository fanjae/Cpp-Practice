#include <iostream>
const int Len = 66;
const int Divs = 6;
void subdivide(char ar[], int low, int high, int level);
int main()
{
	char ruler[Len];
	int i;

	for (i = 1; i < Len - 2; i++)
	{
		ruler[i] = ' ';
	}
	ruler[Len - 1] = '\0';

	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	std::cout << ruler << std::endl;

	for (i = 1; i <= Divs; i++)
	{
		subdivide(ruler, min, max, i);
		std::cout << ruler << std::endl;
		for (int j = 1; j < Len - 2; j++)
		{
			ruler[j] = ' ';									// 빈 눈금자로 초기화
		}
	}
	return 0;
}

void subdivide(char ar[], int low, int high, int level)
{
	if (level == 0) // level 0인 함수는 종료된다.
	{
		return;
	}
	int mid = (high + low) / 2; 
	ar[mid] = '|';

	subdivide(ar, low, mid, level - 1); // 왼쪽 구획을 나누기 위함.
	subdivide(ar, mid, high, level - 1); // 오른쪽 구획을 나누기 위함.
}
