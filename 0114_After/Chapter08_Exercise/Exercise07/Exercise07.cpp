#include <iostream>


template <typename T>
T ShowArray(T arr[], int n);

template <typename T>
T ShowArray(T *arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

int main(void)
{
	using namespace std;
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	struct debts mr_E[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double *pd[3];
	double sum = 0;

	for (int i = 0; i < 3; i++)
	{
		pd[i] = &mr_E[i].amount;
	}

	cout << "Mr. E의 재산 합계: \n";
	sum = ShowArray(things, 6);
	cout << sum << endl;

	sum = 0;
	cout << "Mr. E의 채무 합계: \n";
	sum = ShowArray(pd, 3);
	cout << sum << endl;

	return 0;
}

template <typename T>
T ShowArray(T arr[], int n)
{
	using namespace std;
	T sum = 0;
	cout << "템플릿 A\n";
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

template <typename T>
T ShowArray(T *arr[], int n)
{
	using namespace std;
	T sum = 0;
	cout << "템플릿 B\n";
	for (int i = 0; i < n; i++)
	{
		sum += *arr[i];
	}
	return sum;
}
