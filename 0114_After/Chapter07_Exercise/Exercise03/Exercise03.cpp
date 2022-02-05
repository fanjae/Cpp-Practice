#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void print_box(const box *data);
void cal_box(box *data);
int main(void)
{
	box data;
	strcpy(data.maker, "Nike Shoes");
	data.height = 10.5;
	data.width = 2.5;
	data.length = 2.0;
	cal_box(&data);
	print_box(&data);
}

void print_box(const box *data)
{
	cout << "Maker : " << data->maker << endl;
	cout << "height : " << data->height << endl;
	cout << "width : " << data->width << endl;
	cout << "length : " << data->length << endl;
	cout << "volume : " << data->volume << endl;
}

void cal_box(box *data)
{
	data->volume = data->height * data->width * data->length;
}