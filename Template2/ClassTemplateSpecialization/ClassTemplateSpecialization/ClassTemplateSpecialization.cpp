#include <iostream>
#include <cstring>

#pragma warning (disable:4996)
using namespace std;

// Ŭ���� ���ø��� Ư��ȭ�ϴ� ���� : Ư�� �ڷ����� ������� ������ ��ü�� ���� ������ �Ǵ� �ٸ� �ൿ ����� �����ϱ� ���ؼ�.
template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y)
	{
	}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

template <typename T> // �ϳ��� �����͸� �����ϰ�, �����Ϳ� ��� ������ ����ϴ� Ŭ���� ���ø�
class SimpleDataWrapper
{
private:
	T mdata;
public:
	SimpleDataWrapper(T data) : mdata(data)
	{
	}
	void ShowDataInfo(void)
	{
		cout << "Data : " << mdata << endl;
	}
};

template <> //char *���� ���� Ư��ȭ�� �Ͽ���. ���ڿ��� �����ϱ� ���� �����Ҵ� ��� �����ڿ� �Ҹ��� ���� ����
class SimpleDataWrapper <char *>
{
private:
	char * mdata;
public:
	SimpleDataWrapper(const char *data)
	{
		mdata = new char[strlen(data) + 1];
		strcpy(mdata, data);
	}
	void ShowDataInfo(void)
	{
		cout << "String : " << mdata << endl;
		cout << "Length : " << strlen(mdata) << endl;
	}
	~SimpleDataWrapper() {
		delete[] mdata;
	}
};

template <>  // Point<int>���� ���ؼ� Ư��ȭ�ϴ� ����� ����.
class SimpleDataWrapper <Point<int>>
{
private:
	Point<int> mdata;
public:
	SimpleDataWrapper(int x, int y) : mdata(x, y)
	{
	}
	void ShowDataInfo(void)
	{
		mdata.ShowPosition();
	}
};

int main(void)
{
	SimpleDataWrapper<int> iwrap(170); // int���� ���ؼ��� Ư��ȭ�� ������� �����Ƿ�, Ŭ������ ������� ��ü�� �����ȴ�.
	iwrap.ShowDataInfo();
	SimpleDataWrapper<char *> swarp("Class Template Specialization"); // char* ���� ���ؼ� Ư��ȭ�� ����ȴ�. ���ø� Ŭ������ ��ü�� �����ȴ�.
	swarp.ShowDataInfo();
	SimpleDataWrapper<Point<int>> poswrap(3, 7); // Point<int>���� Ư��ȭ�� �����. ������ ���ø� Ŭ������ �������� �ʰ�, ���ø� Ŭ���� ��ü�� ������.
	poswrap.ShowDataInfo();
	return 0;
}
