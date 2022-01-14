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
	Person 형 포인터는 Person 객체뿐만 아니라, Person을 상속하는 유도 클래스의 객체도 가리킬 수 있다.

	C++에서 AAA형 포인터 변수는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다.

	*/
	ptr1->Sleep(); // Student는 Person을 상속함, Person형 포인터 변수는 Student 객체를 가리킬 수 있다.
	ptr2->Sleep(); // PartTimeStudent는 Person을 간접 상속하므로, Person형 포인터 변수는 PartTimeStudent 객체를 가리킬 수 있다.
	ptr3->Study(); // PartTimeStudent는 Student를 상속하므로, Student형 포인터 변수는 PartTimeStudent 객체를 가리킬 수 있다. 

	/* 객체 포인터의 다음 특성은, 상속의 IS-A 관계를 통한 이해가 가능하다.
	학생(Student)는 사람(Person)이다.
	근로학생(PartTimeStudent)는 사람(Person)이다.

	객체지향에서는 이러한 문장이 성립함으로 인해서 Person 포인터 변수로 Student 객체나 PartTimeStudent의 객체를 가리키는 것도 가능하다. */

	delete ptr1;
	delete ptr2;
	delete ptr3;
	return 0;
}