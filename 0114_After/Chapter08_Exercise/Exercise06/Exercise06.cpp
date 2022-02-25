#include <iostream>
using namespace std;

template <class T>
T maxn(T arr[], int value);

template <> char* maxn(char* arr[], int value);
int main(void)
{
	int int_max = 0;
	int a[6] = { 1,2,3,4,5,6 };

	double double_max = 0.0;
	double b[4] = { 1.1,2.2,3.3,4.4 };

	const char *data[5] = { "data","Exercise data","Amazing Long Data","Not Final data","It's My Final String Data" };
	const char *char_max;

	int_max = maxn(a, 6);
	double_max = maxn(b, 4);
	char_max = maxn(data, 5);

	cout << int_max << endl;
	cout << double_max << endl;
	cout << char_max << endl;

	

}

template <class T>
T maxn(T arr[], int value)
{
	T max = arr[0];
	for (int i = 0; i < value; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

template<> char* maxn(char* arr[], int value)
{
	char *max = arr[0];
	for (int i = 1; i < value; i++)
	{
		if (strlen(max) < strlen(arr[i]))
		{
			max = arr[i];
		}
	}
	return max;
}