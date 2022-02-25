#include <iostream>
template <class T>
T max5(T arr[]);

int main()
{
	int int_max_value = 0;
	int a[5] = { 1,2,3,4,5 };

	double double_max_value = 0;
	double b[5] = { 1.1,2.2,3.3,4.4,5.5 };

	int_max_value = max5(a);
	double_max_value = max5(b);

	std::cout << int_max_value << std::endl;
	std::cout << double_max_value << std::endl;

}

template <class T>
T max5(T arr[])
{
	T max = arr[0];
	for (int i = 0; i < 5; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}