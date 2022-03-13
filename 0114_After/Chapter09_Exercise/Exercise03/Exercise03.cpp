#include <iostream>
#include <string>
#include <new>
#pragma warning (disable:4996)
struct chaff
{
	char dross[20];
	int slag;
};
char buffer1[500]; // Memory Chunk

void show(struct chaff& a);

int main(void)
{
	chaff *a = new (buffer1) chaff[2];
	std::cout << "버퍼에 정적 배열 사용" << std::endl;
	if (a == NULL)
	{
		return -1;
	}
	strcpy(a[0].dross, "abcdef");
	a[0].slag = 3;
	strcpy(a[1].dross, "qwerty");
	a[1].slag = 20;

	for (int i = 0; i < 2; i++)
	{
		show(a[i]);
	}

	std::cout << "\n보통의 new를 사용하여 버퍼 대입" << std::endl;
	char *buffer2 = new char[500];
	chaff* a2 = new (buffer2) chaff[2];
	if (a2 == NULL) return -1;
	strcpy(a2[0].dross, "twoaaa");
	a2[0].slag = 9;
	strcpy(a2[1].dross, "lkjhg");
	a2[1].slag = -3;

	for (int i = 0; i < 2; i++)
	{
		show(a2[i]);
	}
	delete[] buffer2;

	return 0;


}
void show(struct chaff &a)
{
	std::cout << a.dross << std::endl
		<< a.slag << std::endl;
}
