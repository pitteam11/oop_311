#pragma once
#include <iostream>

using namespace std;

class Student {
public:
	int id;
	int year;
	string name;
	int age;

	void show() {
		cout << name << " " << age << endl;
	}
};