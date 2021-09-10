#include <iostream>
using namespace std;

class Person
{
public:
	void Sleep()
	{
		cout << "Sleep" << "\n";
	}
};

class Student : public Person
{
public:
	void Study()
	{
		cout << "Study" << "\n";
	}
};

class PartTimeStudent : public Student
{
public:
	void Work()
	{
		cout << "Work" << "\n";
	}
};

int main(void)
{
	Person *ptr1 = new Student();
	Person *ptr2 = new PartTimeStudent();
	Student *ptr3 = new PartTimeStudent();

	/*
	Person �� �����ʹ� Person ��ü�Ӹ� �ƴ϶�, Person�� ����ϴ� ���� Ŭ������ ��ü�� ����ų �� �ִ�.

	C++���� AAA�� ������ ������ AAA ��ü �Ǵ� AAA�� ���� Ȥ�� ���������� ����ϴ� ��� ��ü�� ����ų �� �ִ�.

	*/
	ptr1->Sleep(); // Student�� Person�� �����, Person�� ������ ������ Student ��ü�� ����ų �� �ִ�.
	ptr2->Sleep(); // PartTimeStudent�� Person�� ���� ����ϹǷ�, Person�� ������ ������ PartTimeStudent ��ü�� ����ų �� �ִ�.
	ptr3->Study(); // PartTimeStudent�� Student�� ����ϹǷ�, Student�� ������ ������ PartTimeStudent ��ü�� ����ų �� �ִ�. 

	/* ��ü �������� ���� Ư����, ����� IS-A ���踦 ���� ���ذ� �����ϴ�.
	�л�(Student)�� ���(Person)�̴�.
	�ٷ��л�(PartTimeStudent)�� ���(Person)�̴�.

	��ü���⿡���� �̷��� ������ ���������� ���ؼ� Person ������ ������ Student ��ü�� PartTimeStudent�� ��ü�� ����Ű�� �͵� �����ϴ�. */

	delete ptr1;
	delete ptr2;
	delete ptr3;
	return 0;
}