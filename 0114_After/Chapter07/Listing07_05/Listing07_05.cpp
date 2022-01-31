#include <iostream>
const int ArSize = 8;
int sum_arr(int arr[], int n);		// 함수 원형
int main()
{
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	// 어떤 시스템에서는 앞에 static을 넣어야 배열 초기화가 가능함.

	int sum = sum_arr(cookies, ArSize);
	cout << "먹은 과자 수 합계 : " << sum << endl;
	return 0;
}

// 정수 배열의 합계를 리턴한다.
int sum_arr(int arr[], int n) // 함수원형에서는 int *arr과 int arr[]이 동일의미이다.
{
	int total = 0;

	for (int i = 0; i < n; i++)
	{
		total = total + arr[i];
	}
	return total;
}
