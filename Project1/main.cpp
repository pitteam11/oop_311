#include <iostream>

using namespace std;

struct Point {
	double x = 0;
	double y = 0;
	double z = 0;
	string color = "white";
};

struct Sceleton {
	int healf_points = 100;
	int demage = 10;
	double speed = 2;
	Point position;
};

void show_sceleton(const Sceleton& scelet) {
	// const Point& pt = scelet.position; // псевдоним
	cout << "Sceleton at ("
		<< scelet.position.x << ", "
		<< scelet.position.y << ") "
		<< "HP: " << scelet.healf_points;
}

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

	const int size = 10;
	Point pnts[size];
	pnts[0] = {12, 14, 14, "black"};
	
	for (int k = 1; k < size; k++)
		pnts[k] = { (double)k, 12, 0, "blue" };

	for (int k = 1; k < size; k++)
		show_point(pnts[k]);
}

void run_rpg() {
	Sceleton scelet;
	show_sceleton(scelet);
}

void main() {
	//cout << "Hello git" << endl;
	//cout << "Bye git" << endl;
	//test_point();
	run_rpg();
}