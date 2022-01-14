#include <iostream>
using namespace std;

class SortRule
{
public:
	virtual bool operator()(int num1, int num2) const = 0;
};

class AscendingSort : public SortRule // 오름차순
{
	public:
		bool operator()(int num1, int num2) const
		{
			if (num1 > num2)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

class DescendingSort : public SortRule // 내림차순
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 < num2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class DataStorage
{
private:
	int *arr;
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen)
	{
		arr = new int[MAX_LEN];
	}
	void AddData(int num)
	{
		if (MAX_LEN <= idx)
		{
			cout << "더 이상 저장이 불가능합니다." << endl;
			return;
		}
		arr[idx++] = num;
	}
	void ShowAllData()
	{
		for (int i = 0; i < idx; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
	void SortData(const SortRule& functor) // functor의 함수 호출 결과를 통해 정렬이 진행된다.
	// 즉, Functor가 true를 반환하는 조건에 따라서 정렬의 방식이 달라진다.
	{
		for (int i = 0; i < (idx - 1); i++)
		{
			for (int j = 0; j < (idx - 1) - i; j++)
			{
				if (functor(arr[j], arr[j + 1]))
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
};

int main(void)
{
	DataStorage storage(5);
	storage.AddData(40);
	storage.AddData(30);
	storage.AddData(50);
	storage.AddData(20);
	storage.AddData(10);

	storage.SortData(AscendingSort()); // AscendingSort를 임시객체 형태로 전달.
	storage.ShowAllData();

	storage.SortData(DescendingSort()); // DescendingSort를 임시객체 형태로 전달.
	storage.ShowAllData();
	return 0;
}

