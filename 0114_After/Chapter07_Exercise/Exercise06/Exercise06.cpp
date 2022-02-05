#include <iostream>
const int Size = 100;
int Fill_array(double *arr, const int Size);
void Show_array(const double *arr, const int Size);
void Reverse_array(double *arr, const int Size);

using namespace std;
int main(void)
{
	double arr[Size];
	int size = Fill_array(arr, Size);
	Show_array(arr, size);
	Reverse_array(arr, size);
	Show_array(arr, size);
}

int Fill_array(double *arr, const int Size)
{
	int size = 0;
	for (int i = 0; i < Size; i++)
	{
		cout << i + 1 << "번째 : ";
		if (!(cin >> arr[i]))
		{
			size = i;
			break;
		}
	}
	return size;
}

void Show_array(const double *arr, const int Size)
{
	for (int i = 0; i < Size; i++)
	{
		cout << i + 1 << "번째 : " << arr[i] << endl;
	}
}

void Reverse_array(double *arr, const int Size)
{
	int left = 1; // 두번째 항목
	int right = Size - 2; // 마지막 기준 두번째 항목
	for (int i = 0; i < Size / 2; i++)
	{
		double temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;

		left++;
		right--;
	}
}

	
