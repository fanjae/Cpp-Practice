#include <iostream>
#include <cstring>
#pragma warning (disable:4996)

using namespace std;

struct stringy
{
	char *str;
	int ct;
};

void set(stringy &data, const char * temp);
void show(const char *data, const int count = 1);
void show(const stringy data, const int count = 1);
void show(const char *data, const int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << data << endl;
	}
}
void show(const stringy data, const int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << data.str << endl;
	}
}
int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);

	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	return 0;
}

void set(stringy &data, const char * temp)
{
	int str_size = strlen(temp) + 1;
	data.str = new char[str_size];
	data.ct = str_size;

	strcpy(data.str, temp);
}
	