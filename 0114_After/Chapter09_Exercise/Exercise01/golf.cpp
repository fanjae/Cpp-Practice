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
	std::cout << "�̸� �Է� : ";
	std::cin.getline(g.fullname, 40);
	if (g.fullname[0] == '\0')
	{
		std::cout << "�̸��� �Էµ��� �ʾҽ��ϴ�.\n";
		return 0;
	}
	std::cout << "�ڵ�ĸ �Է� : ";
	(std::cin >> g.handicap).get();
	return 1;
}

void handicap(golf &g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf &g)
{
	std::cout << "�̸� : " << g.fullname << std::endl
		<< "�ڵ�ĸ : " << g.handicap << std::endl;
}