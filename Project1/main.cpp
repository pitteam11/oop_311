#include <iostream>

using namespace std;

struct Point {
	double x;
	double y;
	string color;
};

void test_point() {
	Point p1;
	p1.x = 13;
	p1.y = 19;
	p1.color = "red";

	cout << p1.x << " " << p1.y << " " << p1.color << endl;
}

void main() {
	cout << "Hello git" << endl;
	cout << "Bye git" << endl;
	test_point();
}