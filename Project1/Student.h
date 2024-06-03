#pragma once
#include <iostream>

using namespace std;

class Student {
private:
	int id;
	int year;
	string name;
	int age;

public:
	void show() {
		cout << name << " " << age << endl;
	}

	Student() {
		id = 1;
		name = "Vasya";
		age = 20;
	}

	~Student(){
		cout << "Hello I am destructor" << endl;
	}
};

void test_student() {
	Student student;	
	student.show();

	
}