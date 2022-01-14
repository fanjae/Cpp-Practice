#include <iostream>
using namespace std;

template <typename T>
T SumArray(T arr[], int len)
{
	T sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main(void)
{
	int arr[5] = { 5,8,9,1,0 };
	double arr2[5] = { 10.5, 9.3, 8.6, 11.5, 5.6 };

	cout << SumArray(arr, 5) << endl;
	cout << SumArray(arr2, 5) << endl;

}
