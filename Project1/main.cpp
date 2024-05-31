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

class Sceleton {
public:
	int id = 0;
	int healf_points = 100;
	int demage = 10;
	double speed = 2;
	Point position;

	void show() const {
		// const Point& pt = scelet.position; // псевдоним
		cout << "Sceleton " << id << " at("
			<< position.x << ", "
			<< position.y << ") "
			<< "HP: " << healf_points
			<< endl;
	}

	void move_sceleton() {
		if (healf_points < 0)
			return;
		// случайный поворот на 0.1 углового градуса 
		//double angle = (double)(rand() % 3600)/10;
		double angle = (rand() % 360) * M_PI / 180;
		position.x += speed * cos(angle);
		position.y += speed * sin(angle);
		if (position.x <= 0)
			position.x = 0;

		if (position.x >= 10)
			position.x = 10;

		if (position.y <= 0)
			position.y = 0;

		if (position.y >= 10)
			position.y = 10;
	}

	void attack(Sceleton& scelet) {
		if (healf_points <= 0)
			return;

		if (position.get_distance(
			scelet.position
		) < 1) {
			if (scelet.healf_points > 0) {
				// случайный урон от 7 до 10
				scelet.healf_points -= demage - rand() % 8;
				if (scelet.healf_points < 0)
					scelet.healf_points = 0;
			}
		}
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
	pnts[0] = {12, 14, 14, "black"};
	
	for (int k = 1; k < size; k++)
		pnts[k] = { (double)k, 12, 0, "blue" };

	for (int k = 1; k < size; k++)
		pnts[k].show();
}

Sceleton construct_sceleton(double x, double y) {
	Sceleton scelet;
	scelet.position.x = x;
	scelet.position.y = y;
	return scelet;
}

void run_rpg() {
	Sceleton scelet1 = construct_sceleton(1, 2);
	scelet1.id = 1;
	Sceleton scelet2 = construct_sceleton(2, 1);
	scelet2.id = 2;

	scelet1.show();
	scelet2.show();
	while (
		scelet1.position.get_distance(
			scelet2.position
		) > 0.5) {
		scelet1.move_sceleton();
		scelet2.move_sceleton();
		scelet1.show();
		scelet2.show();
	}
	while (
		scelet1.healf_points > 0 &&
		scelet2.healf_points > 0
		) {
		scelet1.attack(scelet2);
		scelet2.attack(scelet1);
		scelet1.show();
		scelet2.show();
	}
}

int main() {
	srand(time(NULL));
	//cout << "Hello git" << endl;
	//cout << "Bye git" << endl;
	//test_point();
	run_rpg();
	return 0;
}