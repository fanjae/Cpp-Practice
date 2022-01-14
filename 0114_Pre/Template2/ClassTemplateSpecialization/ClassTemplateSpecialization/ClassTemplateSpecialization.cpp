#include <iostream>
#include <cstring>

#pragma warning (disable:4996)
using namespace std;

// 클래스 템플릿을 특수화하는 이유 : 특정 자료형을 기반으로 생성된 객체에 대해 구분이 되는 다른 행동 양식을 적용하기 위해서.
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

template <typename T> // 하나의 데이터를 저장하고, 데이터에 담긴 정보를 출력하는 클래스 템플릿
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

template <> //char *형에 대한 특수화를 하였음. 문자열을 저장하기 위한 동적할당 기반 생성자와 소멸자 별도 정의
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

template <>  // Point<int>형에 대해서 특수화하는 방법을 보임.
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
	SimpleDataWrapper<int> iwrap(170); // int형에 대해서는 특수화가 진행되지 않으므로, 클래스를 기반으로 객체가 생성된다.
	iwrap.ShowDataInfo();
	SimpleDataWrapper<char *> swarp("Class Template Specialization"); // char* 형에 대해서 특수화가 진행된다. 템플릿 클래스의 객체가 생성된다.
	swarp.ShowDataInfo();
	SimpleDataWrapper<Point<int>> poswrap(3, 7); // Point<int>형에 특수화가 진행됨. 별도의 템플릿 클래스가 생성되지 않고, 템플릿 클래스 객체가 생성됨.
	poswrap.ShowDataInfo();
	return 0;
}
