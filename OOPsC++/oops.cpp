#include <iostream>

using namespace std;

class Person {
private:
	int age = 10 ;
public:
	Person() {
		cout << "In this Person" << endl;
	}
	~Person() {
		cout << "In this Person Des" << endl;
	}
	virtual void MainFunction() {
		cout << "In main function" << endl;
	}
	friend void friendFunction(Person p);
};

void friendFunction(Person pp ) {
	cout << pp.age << endl;
}

class Student : public Person
{
public:
	Student() {
		cout << "In this Student" << endl;
	}
	~Student() {
		cout << "In this Student Des" << endl;
	}
	void MainFunction() {
		cout << "In main function st" << endl;
	}
};

class GStudent : public Student
{
public:
	GStudent() {
		cout << "In this GStudent" << endl;
	}
	~GStudent() {
		cout << "In this GStudent Des"  << endl;
	}
	void MainFunction() {
		cout << "In main function Gst" << endl;
	}
};

void tryVirtual(Person *p) {
	p->MainFunction();
}
int main() {

	Student gstd;
	tryVirtual(&gstd);
	return  0 ;
}