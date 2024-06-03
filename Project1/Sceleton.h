#pragma once
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

#include "Point.h"

using namespace std;

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