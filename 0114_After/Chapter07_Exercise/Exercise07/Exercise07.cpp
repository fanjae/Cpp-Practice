#include <iostream>
const int Max = 5;
// 함수 원형
double* fill_array(double *start, double *end);
void show_array(double *start, double *end);
void revalue(double r, double *, double *);

int main()
{
	using namespace std;
	double properties[Max];
	
	double *end = fill_array(properties, properties + Max);
	show_array(properties, end);

	if (properties != end)
	{
		cout << "재평가율을 입력하십시오 : ";
		double factor;
		while (!(cin >> factor)) // 잘못된 입력임.
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "잘못 입력했습니다, 수치를 입력하세요 : ";
		}
		revalue(factor, properties, end);
		show_array(properties, end);
	}
	cout << "프로그램을 종료합니다,.\n";
	cin.get();
	cin.get();
	return 0;
}

double* fill_array(double *start, double *end)
{
	using namespace std;
	int i;
	double temp;

	for( i = 0 ; i < Max; i++)
	{
		cout << (i + 1) << "번 부동산의 가격: $";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "입력 불량; 입력 과정을 끝내겠습니다.\n";
			break;
		}
		else if (temp < 0)
		{
			break;
		}
		*(start + i) = temp;
	}
	return (start + i);
}

// 다음 함수는 주소가 ar인 배열을
// 사용할 수는 있으나, 변경할 수는 없다.
void show_array(double *start, double *end)
{
	using namespace std;
	for (int i = 0; (start + i) != end; i++)
	{
		cout << (i + 1) << "번 부동산 $";
		cout << *(start + i) << endl;
	}
}

// ar[]의 각 원소에 재평가율 r을 곱한다.
void revalue(double r, double *start, double *end)
{
	for (int i = 0; (start + i) != end; i++)
	{
		start[i] *= r;
	}
}

/* 부분에서 전체로 설계를 진행하는 절차를 상향식 프로그래밍이라고 부른다.
상향식 접근 방법은 데이터 표현과 데이터 조작에 중점을 두는 OOP에 적절하다.
*/
