#include <iostream>

using namespace std;

struct Point {
	double x = 0;
	double y = 0;
	double z = 0;
	string color = "white";
};

void show_point(const Point& pt) {
	cout << "(" << pt.x << ", "
		 << pt.y << ", "
		 << pt.z << ") - "
		 << pt.color << endl;
}

void test_point() {	
	Point p1, p2;
	p1.x = 13;
	p1.y = 19;
	p1.z = 7;
	p1.color = "red";

	show_point(p1);
	show_point(p2);

	Point pnts[10];
	pnts[0] = {12, 14, 14, "black"};
	
	for (int k = 1; k < 10; k++)
		pnts[k] = { (double)k, 12, 0, "blue" };

	for (int k = 1; k < 10; k++)
		show_point(pnts[k]);

}

void main() {
	cout << "Hello git" << endl;
	cout << "Bye git" << endl;
	test_point();
}