#include "String.h"

String::String()
{
	len = 0;
	str = NULL;
}

String::String(const char* s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const  String& s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String()
{
	if (str != NULL)
	{
		delete[] str;
	}
}

String& String::operator= (const String& s)
{
	if (str != NULL)
	{
		delete[] str;
	}
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+= (const String& s)
{
	len += (s.len - 1); // NULL 문자가 포함되어 있으므로, 하나를 뺀다.
	char * tempstr = new char[len];
	strcpy(tempstr, str);
	strcpy(tempstr, s.str);

	if (str != NULL) // str에 기존 할당되있던 경우 삭제
	{
		delete[] str;
	}
	str = tempstr;
	return *this;
}

/* 아래와 같은 형태로 정의해도 된다. 다만, 덧셈의 과정에서 객체가 추가로 생성된다.
String& String::operator+= (const String& s)
{
	*this = *this + s;
	return *this;
}
*/

bool String::operator== (const String& s)
{
	return strcmp(str, s.str) ? false : true;
}

String String::operator+(const String& s)
{
	char *tempstr = new char[len + s.len - 1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	String temp(tempstr);
	delete[]tempstr;
	return temp;
}

ostream& operator<< (ostream& os, const String& s)
{
	os << s.str;
	return os;
}

istream& operator>> (istream& is, String& s)
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}