#include <iostream>
#include <array>
#include <string>
// 상수 (constant) 데이터

struct Season
{
	double cost[4];
};

const int Seasons = 4;
const char *Sname[4] = { "Spring","Summer","Fail","Winter" };

// Array 객체를 수정하는 기능
void fill(struct Season *a);

// 수정하지 않고 객체를 사용하는 기능
void show(const struct Season *a);

int main()
{
	Season data;
	fill(&data);
	show(&data);
	return 0;
}

void fill(struct Season *a)
{
	using namespace std;
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << "에 소요되는 비용:";
		cin >> a->cost[i];
	}
}

void show(const struct Season *a)
{
	using namespace std;
	double total = 0.0;
	cout << "\n계절별 비용\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << " : $" << a->cost[i] << endl;
		total += a->cost[i];
	}
	cout << "총 비용 : $" << total << endl;
}
