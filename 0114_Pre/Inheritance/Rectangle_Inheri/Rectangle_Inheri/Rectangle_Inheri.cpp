#include <iostream>
using namespace std;

class Rectangle // ���簢��
{
private:
	int width;
	int height;
public:
	Rectangle(int my_width, int my_height) : width(my_width), height(my_height)
	{

	}
	void ShowAreaInfo()
	{
		cout << "���� : " << width * height << "\n";
	}
};

class Square : public Rectangle
{
public:
	Square(int value) : Rectangle(value, value)
	{

	}
};

int main(void)
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}