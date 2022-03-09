#include "golf.h"
#include <string>
#include <iostream>
#pragma warning (disable:4996)

void setgolf(golf &g, const char * name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf &g)
{
	std::cout << "이름 입력 : ";
	std::cin.getline(g.fullname, 40);
	if (g.fullname[0] == '\0')
	{
		std::cout << "이름이 입력되지 않았습니다.\n";
		return 0;
	}
	std::cout << "핸디캡 입력 : ";
	(std::cin >> g.handicap).get();
	return 1;
}

void handicap(golf &g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf &g)
{
	std::cout << "이름 : " << g.fullname << std::endl
		<< "핸디캡 : " << g.handicap << std::endl;
}