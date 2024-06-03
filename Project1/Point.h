#pragma once

#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Point {
public:
	double x = 0;
	double y = 0;
	double z = 0;
	string color = "white";

	void show() {
		cout << "(" << x << ", "
			<< y << ", "
			<< z << ") - "
			<< color << endl;
	}

	double get_distance(const Point& pt) {
		double dx = x - pt.x;
		double dy = y - pt.y;
		return sqrt(dx * dx + dy * dy);
	}
};

void test_point() {
	Point p1, p2;
	p1.x = 13;
	p1.y = 19;
	p1.z = 7;
	p1.color = "red";

	p1.show();
	p2.show();

	const int size = 10;
	Point pnts[size];
	pnts[0] = { 12, 14, 14, "black" };

	for (int k = 1; k < size; k++)
		pnts[k] = { (double)k, 12, 0, "blue" };

	for (int k = 1; k < size; k++)
		pnts[k].show();
}
