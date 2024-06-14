#include <iostream>

using namespace std;

class Point {
private:
	int x;
	int y;
public:
	static int count;

	Point() :x{ 0 }, y{ 0 }{
		count++;
	}

	Point(int x, int y) : x{ x }, y{ y }{
		count++;
	}

	Point(const Point& p) : x{ p.x }, y{p.y} {
		count++;
		cout << "Hello I'm copy constructor" << endl;
	}
	/*
	int get_count() {
		return count;
	}
	*/
	int get_x() {
		return x;
	}

	void set_x(int val) {
		x = val;
	}

	void show() {
		cout << x << " " << y << endl;
	}

	static void show_class_name() {		
		cout << "Point" << " " << count << endl;
	}	
};

int Point::count = 0;

void test_point() {

	for (int k = 0; k < 5; k++) {
		Point pnt(k, k+1);
		cout << "Point count: " << pnt.count << endl;
		pnt.show();
		pnt.show_class_name();
	}

	cout << Point::count << endl;
	Point::show_class_name();

	cout << "Tochki" << endl;
	Point tochka1(12, 17);
	cout << "count after tochka1 " << Point::count << endl;
	Point tochka2 = tochka1;
	cout << "count after tochka2 " << Point::count << endl;
	tochka1.set_x(15);
	tochka1.show();
	tochka2.show();

	

	/*	
	pnt.get_x() > 13 ? pnt.set_x(18) : pnt.set_x(100);
	pnt.show();
	*/
}

int main() {
	test_point();
	return 0;
}
