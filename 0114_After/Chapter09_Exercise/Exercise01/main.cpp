#include <iostream>
#include "golf.h"

int main(void)
{
	golf ann;
	golf andy;
	setgolf(ann, "Ann Birdfree", 24);
	showgolf(ann);

	std::cout << "ann의 핸디캡 수정\n";
	handicap(ann, 30);
	showgolf(ann);

	std::cout << "andy의 정보 입력\n";
	if (setgolf(andy) == 1)
	{
		showgolf(andy);
	}

	std::cout << "\n\ngolf 구조체의 배열에 입력을 요구\n\n";

	golf ar[5];
	int i;
	for (i = 0; i < 5; i++)
	{
		if (setgolf(ar[i]) == 0)
		{
			break;
		}
	}

	std::cout << "\n\ngolf 구조체의 배열출력\n\n";
	for (int j = 0; j < i; j++)
	{
		showgolf(ar[j]);
	}
}
