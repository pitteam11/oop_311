#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

#include "Point.h"
#include "Sceleton.h"
#include "Student.h"
#include "Fraction.h"

using namespace std;

void test_student() {
	Student student("Goncharov Petr Petrovich");

	string s;
	cout << "Enter the phone" << endl;
	//cin >> s;
	s = "89281234567";
	student.set_phone(s);
	cout << "This is phone: ";
	cout << student.get_phone() << endl;

	student.show();
}

int main() {
	srand(time(NULL));
	//cout << "Hello git" << endl;
	//cout << "Bye git" << endl;
	//test_point();
	//run_rpg();
	//test_student();

	Fraction frac1(1, 2);
	Fraction frac2(2, 3);
	Fraction res = frac1.mul(frac2);

	frac1.show();
	cout << " * ";
	frac2.show();
	cout << " = ";
	res.show();
	cout << endl;

	return 0;
}